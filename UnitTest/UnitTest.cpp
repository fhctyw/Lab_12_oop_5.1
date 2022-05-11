#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_12_oop_5.1\NumberException.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			NumberException e("some msg");
			Assert::AreEqual("some msg", e.what());
		}
	};
}
