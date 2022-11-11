#include <string>
#include <stdio.h>
#include <iostream>
#include "math.h"
#include "MuSoenMath.h"

int main(void) {
	vec3 v(new float[3] { 1, 1, 1 });//vec��
	vec3 v1(new float[3] {1, 1, 1});
	vec3 sum2(new float[3] { 1, 1, 1 });
	vec3 p(new float[3]);//�迭 ����ϴ°�

	vec4 v2(new float[4] {3, 5, 1, 1});
	vec4 v3(new float[4] {1, 1, 1, 1});
	vec3 sum3(new float[3] { 1, 1, 1 });
	vec4 p1(new float[4]);//�迭 ����ϴ°�

	vec1x3 v4(new float[1][3] {1,1,1});
	vec1x3 v5(new float[1][3]{ 1,1,1 });
	vec1x3 sum4(new float[1][3] { 1, 1, 1 });
	vec1x3 p3(new float[1][3]);

	vec1x4 v6(new float[1][4]{ 1,1,1,1 });
	vec1x4 v7(new float[1][4]{ 1,1,1,1 });
	vec1x4 sum5(new float[1][4]{ 1, 1, 1, 1 });
	vec1x4 p4(new float[1][4]);

	mat3 a(new float[3][3]);
	mat4 a1(new float[4][4]);

	mat3 Translate(new float[3][3]{
	{ 1, 0, 3 },
	{ 0, 1, 5 },
	{ 0, 0, 1 } });
	mat3 Scale(new float[3][3]{
	{ 2, 0, 0 },
	{ 0, 2, 0 },
	{ 0, 0, 1 } });
	mat3 sum(new float[3][3]{
	{ 1, 0, 0 },
	{ 0, 1, 0 },
	{ 0, 0, 1 } });

	mat4 Translate1(new float[4][4]{ //mat4����Ҷ� ���� ����
	{ 1, 0, 0, 3 },
	{ 0, 1, 0, 5 },
	{ 0, 0, 1 ,1 },
	{ 0, 0, 0 ,1 } });
	mat4 Scale1(new float[4][4]{
	{ 2, 0, 0, 0 },
	{ 0, 2, 0, 0 },
	{ 0, 0, 2, 0 },
	{ 0, 0, 0, 1 } });
	mat4 sum1(new float[4][4]{
	{ 1, 0, 0, 0 },
	{ 0, 1, 0, 0 },
	{ 0, 0, 1, 0 }, 
	{ 0, 0, 0, 1 } });

	//Translate.transpose(); //3x1���Ϳ� 3x3��� ����
	//p = v*Translate;
	//for (int i = 0; i < 3; i++)
	//{
	//	std::cout << p.vec[i];
	//	std::cout << " ";
	//}


	//a = Scale + Translate; //3x3��İ� ����
	//for (int i = 0; i < 3; i++)
	//	{
	//		for (int j = 0; j < 3; j++)
	//		{
	//			std::cout << a.mat[i][j];
	//			std::cout << " ";
	//		}
	//		std::cout << std::endl;
	//	}

	//a = Scale - Translate; //3x3��İ� ����
	//for (int i = 0; i < 3; i++)
	//	{
	//		for (int j = 0; j < 3; j++)
	//		{
	//			std::cout << a.mat[i][j];
	//			std::cout << " ";
	//		}
	//		std::cout << std::endl;
	//	}

	//sum = Translate / 2; //mat3�� ���������
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		std::cout << sum.mat[i][j];
	//		std::cout << " ";
	//	}
	//	std::cout << std::endl;
	//}

	//sum = Translate * 2; //mat3�� �������
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		std::cout << sum.mat[i][j];
	//		std::cout << " ";
	//	}
	//	std::cout << std::endl;
	//}

	// 
	//Translate.identity();//mat3���� ��� ���
	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		std::cout << Translate.mat[i][j];
	//		std::cout << " ";
	//	}
	//	std::cout << std::endl;
	//}

	//Translate.transpose();//mat3��ġ ��� ���
	//for (int i = 0; i < 3; i++) 
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		std::cout << Translate.mat[i][j];
	//		std::cout << " ";
	//	}
	//	std::cout << std::endl;
	//}

	//	Translate1.transpose(); //4x1���Ϳ� 4x4��� ����
	//p1 = v2*Translate1;
	//for (int i = 0; i < 4; i++)
	//{
	//	std::cout << p1.vec[i];
	//	std::cout << " ";
	//}


	//mat4 a(new float[4][4]); //4x4 ��İ�
	//a = Scale1 * Translate1;
	//for (int i = 0; i < 4; i++)
	//{
	//	for (int j = 0; j < 4; j++)
	//	{
	//		std::cout << a.mat[i][j];
	//		std::cout << " ";
	//	}
	//	std::cout << std::endl;
	//}

	//	a1 = Scale1 + Translate1; //4x4��İ� ����
	//for (int i = 0; i < 4; i++)
	//	{
	//		for (int j = 0; j < 4; j++)
	//		{
	//			std::cout << a1.mat[i][j];
	//			std::cout << " ";
	//		}
	//		std::cout << std::endl;
	//	}

	//	a1 = Scale1 - Translate1; //4x4��İ� ����
	//for (int i = 0; i < 4; i++)
	//	{
	//		for (int j = 0; j < 4; j++)
	//		{
	//			std::cout << a1.mat[i][j];
	//			std::cout << " ";
	//		}
	//		std::cout << std::endl;
	//	}


	//sum1 = Translate1 / 2; //mat4�� ���������
	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		std::cout << sum1.mat[i][j];
	//		std::cout << " ";
	//	}
	//	std::cout << std::endl;
	//}

	//sum1 = Translate1 * 2; //mat4�� �������
	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		std::cout << sum1.mat[i][j];
	//		std::cout << " ";
	//	}
	//	std::cout << std::endl;
	//}

	//	Translate1.identity();//mat4���� ��� ���
	//for (int i = 0; i < 4; i++)
	//{
	//	for (int j = 0; j < 4; j++)
	//	{
	//		std::cout << Translate1.mat[i][j];
	//		std::cout << " ";
	//	}
	//	std::cout << std::endl;
	//}

	//Translate1.transpose();//mat4��ġ ��� ���
	//for (int i = 0; i < 4; i++) 
	//{
	//	for (int j = 0; j < 4; j++)
	//	{
	//		std::cout << Translate1.mat[i][j];
	//		std::cout << " ";
	//	}
	//	std::cout << std::endl;
	//}


	//p = v1 + v; //3x1���Ͱ� ����
	//for (int i = 0; i < 3; i++)
	//	{
	//		std::cout << p.vec[i];
	//		std::cout << " ";

	//		std::cout << std::endl;
	//	}

	//p = v1 - v; //3x1���Ͱ� ����
	//for (int i = 0; i < 3; i++)
	//	{
	//		std::cout << p.vec[i];
	//		std::cout << " ";

	//		std::cout << std::endl;
	//	}

	//p = Translate * v; //matxvec ���� ���
	//for (int i = 0; i < 3; i++)
	//{
	//	std::cout << p.vec[i];
	//	std::cout << " ";

	//	std::cout << std::endl;
	//}

	//sum2 = v / 2; //3x1���Ϳͻ�� ������
	//for (int i = 0; i < 3; i++)
	//{
	//	std::cout << sum2.vec[i];
	//	std::cout << " ";

	//	std::cout << std::endl;
	//}

	//sum2 = v * 2; //3x1���Ϳͻ�� ����
	//for (int i = 0; i < 3; i++)
	//{
	//	std::cout << sum2.vec[i];
	//	std::cout << " ";

	//	std::cout << std::endl;
	//}

	//v.transposevec(v);//vec3���� ��ġ
	//for (int i = 0; i < 3; i++)
	//{
	//std::cout << v.vec[i];
	//std::cout << " ";
	//}

	//v2.transposevec(v2);//vec4���� ��ġ
	//for (int i = 0; i < 4; i++)
	//{
	//std::cout << v2.vec[i];
	//std::cout << " ";
	//}

	//p1 = v2 + v3; //4x1���Ͱ� ����
	//for (int i = 0; i < 4; i++)
	//	{
	//		std::cout << p1.vec[i];
	//		std::cout << " ";

	//	}

	//p1 = v2 - v3; //4x1���Ͱ� ����
	//for (int i = 0; i < 4; i++)
	//	{
	//		std::cout << p1.vec[i];
	//		std::cout << " ";

	//	}

	//sum2 = v / 2; //4x1���Ϳͻ�� ������
	//for (int i = 0; i < 3; i++)
	//{
	//	std::cout << sum2.vec[i];
	//	std::cout << " ";

	//}

	//sum3 = v * 2; //4x1���Ϳͻ�� ����
	//for (int i = 0; i < 4; i++)
	//{
	//	std::cout << sum3.vec[i];
	//	std::cout << " ";

	//}

	//v3.transposevec(v3);//vec4x1���� ��ġ
	//for (int i = 0; i < 4; i++)
	//{
	//std::cout << v3.vec[i];
	//std::cout << " ";
	//}
	
	//p3 = v4 + v5; //1x3���Ͱ� ����
	//for (int i = 0; i < 3; i++)
	//	{
	//		std::cout << p3.vec[0][i];
	//		std::cout << " ";

	//	}

	//p3 = v4 - v5; //1x3���Ͱ� ����
	//for (int i = 0; i < 3; i++)
	//	{
	//		std::cout << p3.vec[0][i];
	//		std::cout << " ";

	//	}

	//sum4 = v4 / 2; //1x3���Ϳͻ�� ������
	//for (int i = 0; i < 3; i++)
	//{
	//	std::cout << sum4.vec[0][i];
	//	std::cout << " ";

	//}

	//sum4 = v4 * 2; //1x3���Ϳͻ�� ����
	//for (int i = 0; i < 3; i++)
	//{
	//	std::cout << sum4.vec[0][i];
	//	std::cout << " ";

	//}

	//v4.transposevec(v4);//vec1x3���� ��ġ
	//for (int i = 0; i < 3; i++)
	//{
	//std::cout << v4.vec[0][i];
	//std::cout << " ";
	//}

	//p4 = v6 + v7; //1x4���Ͱ� ����
	//for (int i = 0; i < 4; i++)
	//	{
	//		std::cout << p4.vec[0][i];
	//		std::cout << " ";

	//	}

	//p4 = v6 - v7; //1x4���Ͱ� ����
	//for (int i = 0; i < 4; i++)
	//	{
	//		std::cout << p4.vec[0][i];
	//		std::cout << " ";

	//	}

	//sum5 = v6 / 2; //1x4���Ϳͻ�� ������
	//for (int i = 0; i < 3; i++)
	//{
	//	std::cout << sum5.vec[0][i];
	//	std::cout << " ";

	//}

	//sum5 = v6 * 2; //1x4���Ϳͻ�� ����
	//for (int i = 0; i < 4; i++)
	//{
	//	std::cout << sum5.vec[0][i];
	//	std::cout << " ";

	//}

	//v6.transposevec(v6);//vec1x4���� ��ġ
	//for (int i = 0; i < 4; i++)
	//{
	//std::cout << v6.vec[0][i];
	//std::cout << " ";
	//}


	
}
