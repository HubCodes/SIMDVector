#include "stdafx.h"
#include "..\SIMDVector\SIMDVector.h"

#include <iostream>

int main() {
	hub::vector4 v1(1.0f, 2.0f, 3.0f, 4.0f);
	hub::vector4 v2(1.0f, 2.0f, 3.0f, 4.0f);

	std::cout << &v1 << '\n';
	std::cout << &v2 << '\n';

	auto v = v1 - v2;

	return 0;
}

