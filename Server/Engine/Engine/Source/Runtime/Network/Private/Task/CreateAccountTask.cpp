#include "Task/CreateAccountTask.h"
#include "DBNetDriver.h"

void FCreateAccountTask::CheckID()
{
	if (!DBNetDriver)
	{
		E_LOG(error, "DBNetDriver is nullptr");
		FinishTask();
		return;
	}

	CurrentInternalTask = ECheckID;

	DBNetDriver->AsyncGetConnection([this](shared_ptr<boost::mysql::pooled_connection> Connection)
		{
			// 여기까지는 MainThread임.
			// 
			// DB Thread에서 쿼리를 날리기 위함.
			AsyncTask(DBNetDriver->GetDBThreadPool(), [this, Connection]()
				{
					const string SQL = "SELECT * FROM Account where ID=?";
					FStatement Statement;
					if (!DBNetDriver->Send_CreateStatement(Connection, SQL, Statement)) { return; }

					boost::mysql::error_code ErrorCode;
					boost::mysql::diagnostics Diagnostics;
					boost::mysql::static_results<FAccountID> Result;

					if (DBNetDriver->SendSQL(Connection, Statement.bind(ID), Result, ErrorCode, Diagnostics))
					{
						if (Result.rows().empty())
						{
							//
						}
					}
					else
					{
						E_LOG(fatal, "error");
					}
				});
		}
	);
}
