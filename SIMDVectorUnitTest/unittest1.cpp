#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\SIMDVector\SIMDVector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SIMDVectorUnitTest
{		
	TEST_CLASS(VectorTest)
	{
	public:

		TEST_METHOD(VecConstruct) 
		{
			__m128 s = _mm_set_ps(1.f, 2.f, 3.f, 4.f);
			hub::vector4 v1(s);
		}
		
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
			float dot2 = v2 * v1;

			Assert::AreEqual(30.0f, dot, 0.0000001f, L"[ERROR] Vector dot production was failed!", LINE_INFO());
			Assert::AreEqual(30.0f, dot2, 0.0000001f, L"[ERROR] Vector dot production was failed!", LINE_INFO());
		}

		TEST_METHOD(VecSize) 
		{
			hub::vector4 vec(1.0f, 2.0f, 3.0f, 4.0f);

			Assert::AreEqual(5.47722557f, vec.size(), 0.000001f, L"[ERROR] Vector size operation was failed!", LINE_INFO());
		}

		TEST_METHOD(VecNormalize) 
		{
			hub::vector4 vec(1.0f, 2.0f, 3.0f, 4.0f);
			auto factor = 1.f / vec.size();
			Assert::AreEqual(hub::vector4(1.0f * factor, 2.0f * factor, 3.0f * factor, 4.0f * factor).size(),
				vec.normalize().size(), L"[ERROR] Vector normalize operation was failed!", LINE_INFO());
		}

		TEST_METHOD(VecIndexAccess) 
		{
			hub::vector4 v1(1.0f, 2.0f, 3.0f, 4.0f);
			v1[0] = 2.0f;
			Assert::AreEqual(2.0f, v1[0], 0.0000001f, L"[ERROR] Vector index access was failed.", LINE_INFO());

		}

		TEST_METHOD(VecIndexAccessAt) 
		{
			hub::vector4 v1(1.0f, 2.0f, 3.0f, 4.0f);
			v1.at<0>() = 2.0f;

			hub::vector4 v2(1.0f, 2.0f, 3.0f, 4.0f);
			Assert::AreEqual(1.0f, v2.at<0>(), 0.0000001f, L"[ERROR] Vector index access was failed.", LINE_INFO());
			Assert::AreEqual(2.0f, v1.at<0>(), 0.0000001f, L"[ERROR] Vector index access was failed.", LINE_INFO());

		}

		TEST_METHOD(VecCompare) 
		{
			hub::vector4 v1(1.0f, 2.0f, 3.0f, 4.0f);
			hub::vector4 v2(0.0f, 2.0f, 3.0f, 4.0f);

			Assert::AreEqual(false, v1 != v2, L"[ERROR] Wrong result of vector comparing.", LINE_INFO());
		}
	};

	
}