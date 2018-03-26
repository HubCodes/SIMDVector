#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\SIMDVector\SIMDVector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SIMDVectorUnitTest
{		
	TEST_CLASS(VectorTest)
	{
	public:
		
		TEST_METHOD(VecAdd)
		{
			hub::vector4 v1(1.0f, 2.0f, 3.0f, 4.0f);
			hub::vector4 v2(-1.0f, -2.0f, -3.0f, -4.0f);
			hub::vector4 v3(v1 + v2);

			Assert::AreEqual(0.0f, v3.sum(), 0.0000001f, L"[ERROR] Vector addition was failed!", LINE_INFO());
		}

		TEST_METHOD(VecSub) 
		{
			hub::vector4 v1(1.0f, 2.0f, 3.0f, 4.0f);
			hub::vector4 v2(1.0f, 2.0f, 3.0f, 4.0f);
			hub::vector4 v3(v1 - v2);

			Assert::AreEqual(0.0f, v3.sum(), 0.0000001f, L"[ERROR] Vector subtration was failed!", LINE_INFO());
		}

		TEST_METHOD(VecDotProduct) 
		{
			hub::vector4 v1(1.0f, 2.0f, 3.0f, 4.0f);
			hub::vector4 v2(1.0f, 2.0f, 3.0f, 4.0f);
			float dot = v1 * v2;

			Assert::AreEqual(30.0f, dot, 0.0000001f, L"[ERROR] Vector dot production was failed!", LINE_INFO());
		}
	};

	
}