#include <string>
#include <stdio.h>
#include <iostream>
#include "math.h"
#include "MuSoenMath.h"

int main(void) {

	vec3 v(new float[3] { 1, 1, 1 });//vec값
	vec3 p(new float[3]);//배열 출력하는곳
	//이동함수
	mat3 Translate(new float[3][3]{
		{ 1, 0, 0 },
		{ 0, 1, 0 },
		{ 3, 5, 1 } });
	//크기함수
	mat3 Scale(new float[3][3]{
		{ 2, 0, 0 },
		{ 0, 2, 0 },
		{ 0, 0, 1 } });
	//회전함수
	mat3 Rotate(new float[3][3]{
	{ (float)cos(PI / 6), -(float)sin(PI / 6), 0},
	{ (float)sin(PI / 6), (float)cos(PI / 6), 0},
	{ 0, 0, 1 } });

	//계산하는 식
	p = v * Translate * Rotate * Scale;
	std::cout << "p = v * Translate * Rotate * Scale" << "\n";
	for (int i = 0; i < 3; i++) {
		std::cout << p.vec[i];
		std::cout << " ";
	}
}
