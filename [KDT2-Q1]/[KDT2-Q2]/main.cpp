#include <iostream>
#include <vector>
#include <format>
#include <map>
#include "vector.h"

using std::cout;
using std::endl;

struct FStruct
{
	size_t Value = 0;
	size_t* Pointer = new size_t(Value);

	FStruct() = default;
	FStruct(const size_t InValue)
		: Value(InValue)
		, Pointer(new size_t(Value)) {}
	FStruct(const FStruct& InStruct)
		: Value(InStruct.Value)
		, Pointer(new size_t(Value)) {}
	FStruct(FStruct&& InStruct) noexcept
		: Value(InStruct.Value)
		, Pointer(InStruct.Pointer)
	{
		InStruct.Value = 0;
		InStruct.Pointer = nullptr;
	}
	~FStruct()
	{
		if (Pointer)
		{
			delete Pointer;
			Pointer = nullptr;
		}
	}
};

int main()
{
	int Value = KDT::Test();
	{
		cout << "KDT::vector" << endl;
		KDT::vector<int> Vector;
		for (int i = 0; i < 10; ++i)
		{
			cout << i << endl;
			Vector.push_back(i);
		}

		auto ItInt = Vector.begin();
		int Val = *ItInt;

		KDT::vector<FStruct> Vector2;

		for (int i = 0; i < 10; ++i)
		{
			Vector2.push_back(FStruct(i));

		}
		Vector2.resize(2);
		Vector2.resize(1);
		Vector2.resize(2);
		Vector2.clear();
		for (int i = 0; i < 5; ++i)
		{
			Vector2.push_back(FStruct(i));
		}

		size_t Size = Vector2.size();
		size_t Cap = Vector2.capacity();

		FStruct& Data = Vector2[0];
		KDT::vector<FStruct>::iterator It = Vector2.begin();
		KDT::vector<FStruct>::iterator It2 = ++It;
		KDT::vector<FStruct>::iterator It3 = It++;
		++It;
		--It;
		(*It).Value;
		It->Value;

		KDT::vector<FStruct>::iterator It4 = It;
		KDT::vector<FStruct>::iterator ItEnd = Vector2.end();

		for (FStruct& Value : Vector2)
		{
			cout << std::format("Value: {}\n", Value.Value);
		}

		Data.Value = 89;
		FStruct& Data2 = Vector2[1];

		Data2.Value = 999;
	}
	{

		cout << "std::vector" << endl;
		std::vector<int> Vector;
		Vector.reserve(10);
		for (int i = 0; i < 10; ++i)
		{
			cout << i << endl;
			Vector.push_back(i);
		}

		for (int i : Vector)
		{
			cout << i << endl;
		}

		std::vector<int>::iterator ItEnd = Vector.end();
		for (std::vector<int>::iterator It = Vector.begin(); It != ItEnd; ++It)
		{
			cout << *It << endl;
		}

		std::vector<int>::iterator It = Vector.begin();
		++It;
		++It;
		--It;
	}

	// vector 사용시 주의사항.
	{		
	std::vector<int> Vector;
	Vector.push_back(10);
	std::vector<int>::iterator It = Vector.begin();
	int& Value = Vector.back();

	Vector.push_back(20);
	std::vector<int>::iterator It2 = Vector.begin();
	Vector.erase(Vector.begin()); 
	}

	{
		KDT::vector<int> Vector;
		Vector.push_back(10);
		KDT::vector<int>::iterator It = Vector.begin();
		int& Value = Vector[0];
		Vector.push_back(20);

		Vector.push_back(30);
	}

	{
		std::map<int, int> Map;
		std::pair<std::map<int, int>::iterator, bool> It = Map.insert(std::make_pair(0, 100));
		It.second; 
		It.first->first;	
		It.first->second;	
		std::pair<std::map<int, int>::iterator, bool> It2 = Map.insert(std::make_pair(1, 100));

		for (int i = 0; i < 10000; ++i)
		{
			Map.insert(std::make_pair(i, 100));
		}
	}
}