#include "pch.h"
#include "CppUnitTest.h"
#include "F:\Code\c++\SE\Lab2_ext\Lab2_ext\Lab2_ext.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(Calc_Tests)
	{
	public:

		TEST_METHOD(doRealCalculation_get2and5_0returned)
		{
			double x = 2;
			int n = 5;

			double expected = 0;

			double actual = doRealCalculation(x, n);

			Assert::AreEqual(expected, actual);
		}
	public:

		TEST_METHOD(doRealCalculation_get7and2_125_583returned)
		{
			double x = 7;
			int n = 2;

			double expected = 125.583;

			double tolerance = 0.001;

			double actual = doRealCalculation(x, n);

			Assert::AreEqual(expected, actual, tolerance);
		}
	};

	TEST_CLASS(CheckParams_Tests)
	{
	public:

		TEST_METHOD(checkNParam_get2_ExceptionNotThrown)
		{

			int n = 2;

			try {
				checkNParam(n, "");
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
			
		}

	public:

		TEST_METHOD(checkNParam_get1_ExceptionThrown)
		{

			int n = 1;

			try {
				checkNParam(n, "");
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}

		}

	public:

		TEST_METHOD(checkX2Param_get5and8_ExceptionNotThrown)
		{

			double x1 = 5;
			double x2 = 8;

			try {
				checkX2Param(x1, x2, "");
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}

		}

	public:

		TEST_METHOD(checkX2Param_get8and5_ExceptionThrown)
		{

			double x1 = 8;
			double x2 = 5;
			

			try {
				checkX2Param(x1, x2, "");
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}

		}

	public:

		TEST_METHOD(checkStepParam_get2and5and8_ExceptionNotThrown)
		{
			double step = 2;
			double x1 = 5;
			double x2 = 8;
			

			try {
				checkStepParam(step, x1, x2, "");
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}

		}

	public:

		TEST_METHOD(checkStepParam_get_1and5and8_ExceptionThrown)
		{

			double step = -1;
			double x1 = 5;
			double x2 = 8;


			try {
				checkStepParam(step, x1, x2, "");
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}

		}

	public:

		TEST_METHOD(checkStepParam_get4and5and8_ExceptionThrown)
		{

			double step = 4;
			double x1 = 5;
			double x2 = 8;


			try {
				checkStepParam(step, x1, x2, "");
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}

		}

	public:

		TEST_METHOD(checkDenominatorIsZero_get6_ExceptionNotThrown)
		{

			double x = 6;

			try {
				checkDenominatorIsZero(x, "");
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}

		}

	public:

		TEST_METHOD(checkDenominatorIsZero_get_01_ExceptionThrown)
		{

			double x = -0.1;

			try {
				checkDenominatorIsZero(x, "");
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}

		}
	};
}
