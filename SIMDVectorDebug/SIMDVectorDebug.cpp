#include "stdafx.h"
#include "..\SIMDVector\SIMDVector.h"

int main() {

	hub::vector4 v1(1.0f, 2.0f, 3.0f, 4.0f);
	hub::vector4 v2(1.0f, 2.0f, 3.0f, 4.0f);
	float dot = v1 * v2;
	
	return 0;
}

