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
		vector4(const vector4& other) noexcept;
		vector4& operator=(const vector4& other) noexcept;
		virtual ~vector4() noexcept;

		/* Vector add */
		const vector4& operator+(const vector4& other);
		const vector4& add(const vector4& other);

		/* Vector subtract */
		const vector4& operator-(const vector4& other);
		const vector4& sub(const vector4& other);

		/* Vector inner product */
		const float operator*(const vector4& other);
		const float dot_product(const vector4& other);

		/* Get summary */
		const float sum() const noexcept;

		const std::string to_string() const noexcept;
	private:
		/* Initializer function */
		void set_data(const float f1, const float f2, const float f3, const float f4) noexcept;

		__declspec(align(16)) union {
			__m128 reg;
			float data[4];
		} vec4;
	};
}