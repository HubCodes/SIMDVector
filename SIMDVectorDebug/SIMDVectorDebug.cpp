#include "stdafx.h"
#include "..\SIMDVector\SIMDVector.h"

#include <iostream>

int main() {
	hub::vector4 v1(1.0f, 2.0f, 3.0f, 4.0f);
	hub::vector4 v2(6.0f, 2.2f, -3.7f, 4.0f);
	hub::vector4 v3(v1);

	std::cout << v1 << '\n';
	std::cout << v2 << '\n';
	std::cout << v1 + v2 << '\n';
	std::cout << v1 - v2 << '\n';
	std::cout << v1 * v2 << '\n';
	std::cout << v1.normalize() << '\n';
	std::cout << v1.at<0>() << '\n';
	std::cout << v1 << '\n';
	std::cout << v2 << '\n';

	return 0;
}

