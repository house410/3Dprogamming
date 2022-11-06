#pragma once
#include <iostream> 
#include <math.h> 

#define PI 3.141592 //PI근사값

//클래스 mat3
class mat3 {
public:
	float mat[3][3];//3x3 행렬


	//생성자, float형 3x3행렬을 받아온후에 this를통해 mat에 행렬을 넣어준다.
	mat3(float mat[3][3]) {
		for (int i = 0; i < 3; i++) { 
			for (int j = 0; j < 3; j++) {
				this->mat[i][j] = mat[i][j];
			}
		}
	}

	//3x3행렬 오버로딩 곱셈함수이다.
	mat3 operator*(const mat3& ref) {

		mat3 savemat(new float[3][3]);//배열만들고 값을 반환한다.
		////i 값은 0부터 3 미만까지 1씩 증가하며 반복
       //j 값은 0부터 3 미만까지 1씩 증가하며 반복
      //k 값은 0부터 3 미만까지 1씩 증가하며 반복
      //두 행렬을 곱하는 식으로로 인해 반복될 때마다 계산된 값을 savemat[i][j]에 저장함
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++)
					savemat.mat[i][j] += (mat[k][j] * ref.mat[i][k]);
			}
		}
		return savemat;
	}

};

//클래스 vec3
class vec3
{
public:
	float vec[3];

	//생성자, float형 3x1행렬을 받아온후에 this를통해 vec에 행렬을 넣어준다.
	vec3(float vec[3]) {
		for (int i = 0; i < 3; i++) {
			this->vec[i] = vec[i];
		}
	}

	//vec와mat의 행렬 곱하기 오버로딩 함수
	vec3 operator*(const mat3& ref)
	{
		vec3 savevec(new float[3] {0, 0, 0});//배열만들고 값을 반환한다.
		////i 값은 0부터 3 미만까지 1씩 증가하며 반복
        //j 값은 0부터 3 미만까지 1씩 증가하며 반복
        //두 행렬을 곱하는 식으로로 인해 반복될 때마다 계산된 값을 savevec[i][j]에 저장함
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				savevec.vec[i] += (vec[j] * ref.mat[j][i]);
			}
		}
		return savevec;
	}
};