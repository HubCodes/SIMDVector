// SIMDVector.cpp : DLL 응용 프로그램을 위해 내보낸 함수를 정의합니다.
//

#include "stdafx.h"
#include "SIMDVector.h"

// public 
hub::vector4::vector4() noexcept {
	set_data(0.0f, 0.0f, 0.0f, 0.0f);
}

hub::vector4::vector4(const float f1, const float f2, const float f3, const float f4) noexcept {
	set_data(f1, f2, f3, f4);
}

hub::vector4::vector4(const std::array<float, 4>& other) noexcept {
	set_data(other[0], other[1], other[2], other[3]);
}

hub::vector4::vector4(const std::vector<float>& other) noexcept(false) {
	if (other.size() != 4)
		throw std::exception("Bad vector: invalid length.");

	set_data(other[0], other[1], other[2], other[3]);
}

hub::vector4::vector4(const vector4& other) noexcept : vec4(other.vec4) {

}

hub::vector4& hub::vector4::operator=(const vector4& other) noexcept {
	set_data(other.vec4.data[0], other.vec4.data[1], other.vec4.data[2], other.vec4.data[3]);
	return *this;
}

hub::vector4::~vector4() noexcept {
}

const hub::vector4& hub::vector4::operator+(const vector4& other) {
	vec4.reg = _mm_add_ps(vec4.reg, other.vec4.reg);
	return *this;
}

const hub::vector4& hub::vector4::add(const vector4& other) {
	return operator+(other);
}

const hub::vector4& hub::vector4::operator-(const vector4& other) {
	vec4.reg = _mm_sub_ps(vec4.reg, other.vec4.reg);
	return *this;
}

const hub::vector4& hub::vector4::sub(const vector4& other) {
	return operator-(other);
}

const float hub::vector4::operator*(const vector4& other) {
	union {
		__m128 result;
		float d[4];
	};
	result = _mm_dp_ps(vec4.reg, other.vec4.reg, 0xff);

	return d[0];
}

const float hub::vector4::dot_product(const vector4& other) {
	return operator*(other);
}

const float hub::vector4::sum() const noexcept {
	return vec4.data[0] + vec4.data[1] + vec4.data[2] + vec4.data[3];
}

const std::string hub::vector4::to_string() const noexcept {
	return std::string(
		"vector4(" + 
		std::to_string(vec4.data[0]) + 
		", " + std::to_string(vec4.data[1]) + 
		", " + std::to_string(vec4.data[2]) + 
		", " + std::to_string(vec4.data[3]) + ")");
}


// private
void hub::vector4::set_data(const float f1, const float f2, const float f3, const float f4) noexcept {
	vec4.data[0] = f4;
	vec4.data[1] = f3;
	vec4.data[2] = f2;
	vec4.data[3] = f1;
}
