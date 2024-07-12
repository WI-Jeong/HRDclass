#pragma once
#include <EngineMinimal.h>
#include <boost/describe/class.hpp>

struct FAccountID
{
	string ID;
};
BOOST_DESCRIBE_STRUCT(FAccountID, (), (ID))

struct NETWORK_API FCreateAccountTask : public FTask
{
public:
	enum class EResult : uint8
	{
		ESuccessed,
		EDuplicateAccount,
	};

	FCreateAccountTask(string_view InID, string_view InPassword,
		engine_weak_ptr<class UDBNetDriver> InDBNetDriver,
		function<void(FCreateAccountTask*, FCreateAccountTask::EResult)> InMainThreadCallback)
		: ID(InID), Password(InPassword), DBNetDriver(InDBNetDriver), MainThreadCallback(InMainThreadCallback)
	{
		E_LOG(trace, "ID: {}, Password: {}", InID, InPassword);
		// - 요청한 ID가 이미 DB에 있는지 확인
		//	- 있는 경우: 실패(EDuplicateAccount)
		//	- 없는 경우: 계정 생성
		//		- BulkInsert준비
		//			- 성공시 ESuccessed
		CheckID();
	}

private:
	void CheckID();

private:
	enum EInternalTask
	{
		ENone,
		ECheckID,
		ECreateAccount,
	};
	EInternalTask CurrentInternalTask = EInternalTask::ENone;

	const string ID;
	const string Password;
	engine_weak_ptr<class UDBNetDriver> DBNetDriver;
	function<void(FCreateAccountTask*, FCreateAccountTask::EResult)> MainThreadCallback;
};