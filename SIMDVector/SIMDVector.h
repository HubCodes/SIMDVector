#include "stdafx.h"

#ifdef SIMDVECTOR_EXPORTS
#define SIMDVECTOR_API __declspec(dllexport)
#else
#define SIMDVECTOR_API __declspec(dllimport)
#endif

namespace hub {
	class SIMDVECTOR_API vector4 {
	public:
		explicit vector4() noexcept;
		explicit vector4(const float f1, const float f2, const float f3, const float f4 = 1.0f) noexcept;
		explicit vector4(const std::array<float, 4>& other) noexcept;
		explicit vector4(const std::vector<float>& other) noexcept(false);
		explicit vector4(const __m128 other) noexcept;
		vector4(const vector4& other) noexcept;
		vector4& operator=(const vector4& other) noexcept;
		virtual ~vector4() noexcept;

		/* Vector add */
		const vector4 operator+(const vector4& other) const noexcept;
		const vector4 add(const vector4& other) const noexcept;

		/* Vector subtract */
		const vector4 operator-(const vector4& other) const noexcept;
		const vector4 sub(const vector4& other) const noexcept;

		/* Vector inner product */
		const float operator*(const vector4& other) const noexcept;
		const float dot_product(const vector4& other) const noexcept;

		/* Vector size (length) */
		const float size() const noexcept;

		/* Vector normalize */
		const vector4 normalize() const noexcept;

		/* Access vector element */
		const float& operator[](size_t index) const noexcept;
		float& operator[](size_t index) noexcept;

		template <int n>
		const float& at() const noexcept;

		template <int n>
		float& at() noexcept;

		/* Get summary */
		const float sum() const noexcept;

		/* To string object */
		const std::string to_string() const noexcept;
	private:
		union regdata {
			__m128 reg;
			float data[4];
		};

		/* Initializer function */
		void set_data(const float f1, const float f2, const float f3, const float f4) noexcept;

		__declspec(align(16)) regdata vec4;
	};

	template<int n>
	inline const float& vector4::at() const noexcept {
		return operator[](n);
	}

	template<int n>
	inline float& vector4::at() noexcept {
		return const_cast<float&>(static_cast<const hub::vector4*>(this)->at<n>());
	}
}