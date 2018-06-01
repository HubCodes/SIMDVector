#include "stdafx.h"
#include "SIMDVector.h"

// non-member functions
std::ostream& hub::operator<<(std::ostream& stream, const hub::vector4& vec) {
	stream << "hub::vector4{" << vec[0] << ", " << vec[1] << ", " << vec[2] << ", " << vec[3] << '}';
	return stream;
}

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

hub::vector4::vector4(const __m128 other) noexcept {
	__declspec(align(16)) regdata control;
	control.reg = other;
	set_data(control.data[3], control.data[2], control.data[1], control.data[0]);
}

hub::vector4::vector4(const vector4& other) noexcept : vec4(other.vec4) {

}

hub::vector4& hub::vector4::operator=(const vector4& other) noexcept {
	set_data(other.vec4.data[0], other.vec4.data[1], other.vec4.data[2], other.vec4.data[3]);
	return *this;
}

bool hub::vector4::operator==(const vector4& other) const noexcept {
	__m128 compared = _mm_cmpeq_ps(vec4.reg, other.vec4.reg);
	return compared.m128_i64[0] && compared.m128_i64[1];
}

bool hub::vector4::operator!=(const vector4& other) const noexcept {
	return !operator==(other);
}

hub::vector4::~vector4() noexcept {
}

const hub::vector4 hub::vector4::operator+(const vector4& other) const noexcept {
	return hub::vector4(_mm_add_ps(vec4.reg, other.vec4.reg));
}

const hub::vector4 hub::vector4::add(const vector4& other) const noexcept {
	return operator+(other);
}

const hub::vector4 hub::vector4::operator-(const vector4& other) const noexcept {
	return hub::vector4(_mm_sub_ps(vec4.reg, other.vec4.reg));
}

const hub::vector4 hub::vector4::sub(const vector4& other) const noexcept {
	return operator-(other);
}

const float hub::vector4::operator*(const vector4& other) const noexcept {
	__declspec(align(16)) regdata result;
	result.reg = _mm_dp_ps(vec4.reg, other.vec4.reg, 0xff);
	return result.data[0];
}

const float hub::vector4::dot_product(const vector4& other) const noexcept {
	return operator*(other);
}

const float hub::vector4::size() const noexcept {
	__declspec(align(16)) regdata result;
	result.reg = _mm_mul_ps(vec4.reg, vec4.reg);
	return sqrtf(result.data[0] + result.data[1] + result.data[2] + result.data[3]);
}

const hub::vector4 hub::vector4::normalize() const noexcept {
	__declspec(align(16)) regdata multiplier;
	float size_ = 1.0f / size();
	multiplier.reg = _mm_set_ps(size_, size_, size_, size_);
	return vector4(_mm_mul_ps(vec4.reg, multiplier.reg));
}

const float& hub::vector4::operator[](size_t index) const noexcept {
	return vec4.data[3 - index];
}

float& hub::vector4::operator[](size_t index) noexcept {
	return const_cast<float&>(static_cast<const hub::vector4*>(this)->operator[](index));
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

void hub::vector4::reverse() noexcept {
	vec4.reg = _mm_shuffle_ps(vec4.reg, vec4.reg, _MM_SHUFFLE(0, 1, 2, 3));
}


// private
void hub::vector4::set_data(const float f1, const float f2, const float f3, const float f4) noexcept {
	vec4.data[0] = f4;
	vec4.data[1] = f3;
	vec4.data[2] = f2;
	vec4.data[3] = f1;
}
