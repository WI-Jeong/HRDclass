#include <iostream>
#include "ClassClass.h"

int main()
{
	{
		// FClass라는 설계도를 기반으로
		// 실체화된 사례(instance)를 만든다
		// An Object is an instance of a class (객체는 클래스의 인스턴스입니다)
		FClass ClassInstnace = FClass();
		FClass ClassInstnace2 = FClass(TEXT("Text"));
		FClass ClassInstance3 = FClass(ClassInstnace2);

		int a = 0, b = 10;
		a = b = 30;

		ClassInstance3 = (ClassInstnace = ClassInstnace2);
		ClassInstance3.operator=(ClassInstnace.operator=(ClassInstnace2));

		ClassInstance3 = 30;

		FClass* Class = new FClass;
		FClass* Class2 = new FClass;

		// 주소 전달
		//Class = Class2;

		*Class = *Class2;

		delete Class;
		delete Class2;
	}

	// static
	{
		FClass::StaticStructInClassMember.Value = 100;
		FClass ClassInstnace_ = FClass();
		FClass ClassInstnace__ = FClass();
		FClass ClassInstnace___ = FClass();

		FClass::StaticStructInClassMember.Value = 200;
		FClass::Test();
		ClassInstnace___.Test();

		FUtils::Func();
	}
	{
		FClass* Class = nullptr;
		// Hello 함수 내부에서 this에 접근하는 코드가 없어서
		// 문제가 발생하지 않는다.
		Class->Hello();
	}
}