#pragma once
#include <iostream> 
#include <math.h> 

#define PI 3.141592 //PI근사값

//클래스 mat3
class mat3 {
public:

	mat3() {};
	float mat[3][3];//3x3 행렬

	friend std::ostream& operator << (std::ostream& out, const mat3& point)
	{
		out << "( " << point.mat[0][0] << ", " << point.mat[0][1] << ", " << point.mat[0][2]
			<<point.mat[1][0]<< ","<<point.mat[1][1]<<","<<point.mat[1][2]<<","
			<<point.mat[2][0]<<","<<point.mat[2][1]<<","<<point.mat[2][2] ;
		return out;
	}

	void identity() //단위행렬
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == j)mat[i][j] = 1;
				else mat[i][j] = 0;
			}
		}
	}

	mat3 transpose()
	{
		float temp;
		for (int i = 0; i < 3; i++)
		{
			for (int j = i; j < 3; j++)
			{
				temp = this->mat[i][j];
				this->mat[i][j] = this->mat[j][i];
				this->mat[j][i] = temp;
			}
		}
		return *this;
	}


	//생성자, float형 3x3행렬을 받아온후에 this를통해 mat에 행렬을 넣어준다.
	mat3(float m[3][3]) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				this->mat[i][j] = m[i][j];
			}
		}
	}

	//3x3행렬 오버로딩 곱셈함수이다.
	mat3 operator*(const mat3& ref) {

		mat3 savemat=ref;//배열만들고 값을 반환한다.
		mat3 savemat2 = (*this);
		////i 값은 0부터 3 미만까지 1씩 증가하며 반복
	   //j 값은 0부터 3 미만까지 1씩 증가하며 반복
	  //k 값은 0부터 3 미만까지 1씩 증가하며 반복
	  //두 행렬을 곱하는 식으로로 인해 반복될 때마다 계산된 값을 savemat[i][j]에 저장함
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				savemat.mat[j][i] = 0;
				for (int k = 0; k < 3; k++) {
					savemat.mat[j][i] += (savemat2.mat[j][k] * ref.mat[k][i]);
				}
			}
		}
		return savemat;
	}

	mat3 operator+(const mat3& ref) { //연산자 오버로딩으로 3x3행렬 덧셈연산

		mat3 savemat(new float[3][3]);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				savemat.mat[i][j] = (mat[i][j] + ref.mat[i][j]);
			}
		}
		return savemat;
	}

	mat3 operator-(const mat3& ref) { //연산자 오버로딩으로 3x3행렬 뺄셈연산

		mat3 savemat(new float[3][3]);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				savemat.mat[i][j] = (mat[i][j] - ref.mat[i][j]);
			}
		}
		return savemat;
	}


	mat3 operator/(float ref) { //연산자 오버로딩으로 3x3행렬과 상수 나눗셈 연산

		mat3 savemat(new float[3][3]);//배열만들고 값을 반환한다.
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				savemat.mat[i][j] = mat[i][j] / ref;

		}
		return savemat;
	}

	mat3 operator*(float ref) { //연산자 오버로딩으로 3x3행렬과 상수 곱셈 연산

		mat3 savemat(new float[3][3]);//배열만들고 값을 반환한다.
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				savemat.mat[i][j] = mat[i][j] * ref;

		}
		return savemat;
	}


};

class mat4 {
public:
	float mat[4][4];

	void identity() //단위행렬
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (i == j)mat[i][j] = 1;
				else mat[i][j] = 0;
			}
		}
	}

	mat4 transpose() //mat4 전치행렬
	{
		float temp;
		for (int i = 0; i < 4; i++)
		{
			for (int j = i; j < 4; j++)
			{
				temp = this->mat[i][j];
				this->mat[i][j] = this->mat[j][i];
				this->mat[j][i] = temp;
			}
		}
		return *this;
	}

	mat4(float m[4][4])
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				this->mat[i][j] = m[i][j];
			}
		}
	}

	mat4 operator*(const mat4& ref)
	{
		mat4 savemat(new float[4][4]{ {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });  //연산자 오버로딩으로 4x4행렬 곱셈

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
					savemat.mat[i][j] += this->mat[i][k] * ref.mat[k][j];
			}
		}
		return savemat;
	}


	mat4 operator+(const mat4& ref) { //연산자 오버로딩으로 4x4 행렬간 덧셈연산

		mat4 savemat(new float[4][4]{ {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				savemat.mat[i][j] = (mat[i][j] + ref.mat[i][j]);
			}
		}
		return savemat;
	}


	mat4 operator-(const mat4& ref) { //연산자 오버로딩으로 4x4행렬 뺄셈연산

		mat4 savemat(new float[4][4]{ {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				savemat.mat[i][j] = (mat[i][j] - ref.mat[i][j]);
			}
		}
		return savemat;
	}

	mat4 operator/(float ref) { //연산자 오버로딩으로 4x4행렬과 상수 나눗셈 연산

		mat4 savemat(new float[4][4]{ {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });//배열만들고 값을 반환한다.
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				savemat.mat[i][j] = mat[i][j] / ref;

		}
		return savemat;
	}

	mat4 operator*(float ref) { //연산자 오버로딩으로 4x4행렬과 상수 곱셈 연산

		mat4 savemat(new float[4][4]{ {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });//배열만들고 값을 반환한다.
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				savemat.mat[i][j] = mat[i][j] * ref;

		}
		return savemat;
	}



};

//클래스 vec3
class vec3
{
public:
	vec3() {};
	float vec[3];
	friend std::ostream& operator << (std::ostream& out, const vec3& point) 
	{ out << "( " << point.vec[0] << ", " << point.vec[1] << ", " << point.vec[2] << " )";
	return out; }
	vec3 transposevec(vec3 v) { //vec3 전치
		vec3 save(new float[3]);
		for (int i = 0; i < 3; i++)
			save.vec[i] = v.vec[i];
		return save;
	}

	//생성자, float형 3x1행렬을 받아온후에 this를통해 vec에 행렬을 넣어준다.
	vec3(float v[3]) {
		for (int i = 0; i < 3; i++) {
			this->vec[i] = v[i];
		}
	}

	//vec와mat의 행렬 곱하기 오버로딩 함수
	vec3 operator*(const mat3& ref)
	{
		vec3 savevec(new float[3] {0, 0, 0});//배열만들고 값을 반환한다.
		vec3 savevec2 = (*this);
		////i 값은 0부터 3 미만까지 1씩 증가하며 반복
		//j 값은 0부터 3 미만까지 1씩 증가하며 반복
		//두 행렬을 곱하는 식으로로 인해 반복될 때마다 계산된 값을 savevec[i][j]에 저장함
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
					savevec.vec[i] += (ref.mat[i][j]*savevec2.vec[j]);
			}
		}
		return savevec;
	}



	vec3 operator+(const vec3& ref) //3x1벡터간 덧셈
	{
		vec3 savevec(new float[3] {0, 0, 0});

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				savevec.vec[i] = this->vec[i] + ref.vec[i];
			}
		}
		return savevec;
	}

	vec3 operator-(const vec3& ref) //3x1벡터간 뺄셈
	{
		vec3 savevec(new float[3] {0, 0, 0});

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				savevec.vec[i] = this->vec[i] - ref.vec[i];
			}
		}
		return savevec;
	}

	vec3 operator*(float ref) //연산자 오버로딩으로 3x1벡터와 상수 곱셈연산
	{
		vec3 savevec(new float[3] {0, 0, 0});
		for (int i = 0; i < 3; i++) {
			savevec.vec[i] = this->vec[i] * ref;
		}
		return savevec;
	}

	vec3 operator/(float ref) //연산자 오버로딩으로 3x1벡터와 상수 나눗셈연산
	{
		vec3 savevec(new float[3] {0, 0, 0});
		for (int i = 0; i < 3; i++) {
			savevec.vec[i] = this->vec[i] / ref;
		}
		return savevec;
	}

	vec3 operator*(vec3& ref)
	{
		vec3 savevec(new float[3] { 0, 0, 0 });
		savevec.vec[0] = vec[1] * ref.vec[2] - vec[2] * ref.vec[1];
		savevec.vec[1] = vec[2] * ref.vec[0] - vec[0] * ref.vec[2];
		savevec.vec[2] = vec[0] * ref.vec[1] - vec[1] * ref.vec[0];

		return savevec;
	}

	friend vec3 operator*(mat3& ref, const vec3& ref2);

};

vec3 operator*(mat3& ref, const vec3& ref2) //matxvec 곱셈구현
{
	vec3 savevec(new float[3] {0, 0, 0});//배열만들고 값을 반환한다.
	////i 값은 0부터 3 미만까지 1씩 증가하며 반복
	//j 값은 0부터 3 미만까지 1씩 증가하며 반복
	//두 행렬을 곱하는 식으로로 인해 반복될 때마다 계산된 값을 savevec[i][j]에 저장함
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			savevec.vec[i] += (ref2.vec[j]*ref.mat[i][j]);
		}
	}
	return savevec;
}

class vec1x3
{
public:
	float vec[1][3];

	vec1x3(float v[1][3]) {
		for (int i = 0; i < 3; i++) {
			this->vec[0][i] = v[0][i];
		}
	}

	vec1x3 transposevec(vec1x3 v) { //vec1x3 전치
		vec1x3 save(new float[1][3]);
		for (int i = 0; i < 3; i++)
			save.vec[0][i] = v.vec[0][i];
		return save;
	}

	vec1x3 operator+(vec1x3& ref) //연산자 오버로딩으로 1x3 벡터간 덧셈연산
	{
		vec1x3 savevec(new float[1][3]);
		for (int i = 0; i < 3; i++)
		{
			savevec.vec[0][i] = this->vec[0][i] + ref.vec[0][i];
		}
		return savevec;
	}

	vec1x3 operator-(vec1x3& ref) //연산자 오버로딩으로 1x3 벡터간 뺄셈연산
	{
		vec1x3 savevec(new float[1][3]{ 0, 0, 0 });
		for (int i = 0; i < 3; i++)
		{
			savevec.vec[0][i] = this->vec[0][i] - ref.vec[0][i];
		}
		return savevec;
	}

	vec1x3 operator*(float ref) //연산자 오버로딩으로 1x3벡터와 상수 곱셈연산
	{
		vec1x3 savevec(new float[1][3]{ 0, 0, 0 });
		for (int i = 0; i < 3; i++) {
			savevec.vec[0][i] = this->vec[0][i] * ref;
		}
		return savevec;
	}
	vec1x3 operator/(float ref) //연산자 오버로딩으로 1x3벡터와 상수 나눗셈연산
	{
		vec1x3 savevec(new float[1][3]{ 0, 0, 0 });
		for (int i = 0; i < 3; i++) {
			savevec.vec[0][i] = this->vec[0][i] / ref;
		}
		return savevec;
	}


};

class vec4
{
public:
	float vec[4];

	vec4 transposevec(vec4 v) { //vec4전치
		vec4 save(new float[4]);
		for (int i = 0; i < 4; i++)
			save.vec[i] = v.vec[i];
		return save;
	}

	//생성자, float형 3x1행렬을 받아온후에 this를통해 vec에 행렬을 넣어준다.
	vec4(float v[4]) {
		for (int i = 0; i < 4; i++) {
			this->vec[i] = v[i];
		}
	}

	//vec와mat의 행렬 곱하기 오버로딩 함수
	vec4 operator*(const mat4& ref)
	{
		vec4 savevec(new float[4] {0, 0, 0, 0 });//배열만들고 값을 반환한다.
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				savevec.vec[i] += (vec[j] * ref.mat[j][i]);
			}
		}
		return savevec;
	}

	vec4 operator+(const vec4& ref) //4x1벡터간 덧셈
	{
		vec4 savevec(new float[4] {0, 0, 0, 0 });

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				savevec.vec[i] = this->vec[i] + ref.vec[i];
			}
		}
		return savevec;
	}

	vec4 operator-(const vec4& ref) //4x1벡터간 뺄셈
	{
		vec4 savevec(new float[4] {0, 0, 0, 0 });

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				savevec.vec[i] = this->vec[i] - ref.vec[i];
			}
		}
		return savevec;
	}

	vec4 operator*(float ref) //연산자 오버로딩으로 4x1벡터와 상수 곱셈연산
	{
		vec4 savevec(new float[4] {0, 0, 0, 0 });
		for (int i = 0; i < 4; i++) {
			savevec.vec[i] = this->vec[i] * ref;
		}
		return savevec;
	}

	vec4 operator/(float ref) //연산자 오버로딩으로 4x1벡터와 상수 나눗셈연산
	{
		vec4 savevec(new float[4] {0, 0, 0, 0 });
		for (int i = 0; i < 4; i++) {
			savevec.vec[i] = this->vec[i] / ref;
		}
		return savevec;
	}

};

class vec1x4
{
public:
	float vec[1][4];

	vec1x4(float v[1][4]) {
		for (int i = 0; i < 4; i++) {
			this->vec[0][i] = v[0][i];
		}
	}

	vec1x4 transposevec(vec1x4 v) {
		vec1x4 save(new float[1][4]);
		for (int i = 0; i < 4; i++)
			save.vec[0][i] = v.vec[0][i];
		return save;
	}

	vec1x4 operator+(vec1x4& ref) //연산자 오버로딩으로 1x4 벡터간 덧셈연산
	{
		vec1x4 savevec(new float[1][4]);
		for (int i = 0; i < 4; i++)
		{
			savevec.vec[0][i] = this->vec[0][i] + ref.vec[0][i];
		}
		return savevec;
	}

	vec1x4 operator-(vec1x4& ref) //연산자 오버로딩으로 1x4 벡터간 뺄셈연산
	{
		vec1x4 savevec(new float[1][4]);
		for (int i = 0; i < 4; i++)
		{
			savevec.vec[0][i] = this->vec[0][i] - ref.vec[0][i];
		}
		return savevec;
	}

	vec1x4 operator*(float ref) //연산자 오버로딩으로 1x4벡터와 상수 곱셈연산
	{
		vec1x4 savevec(new float[1][4]);
		for (int i = 0; i < 4; i++) {
			savevec.vec[0][i] = this->vec[0][i] * ref;
		}
		return savevec;
	}
	vec1x4 operator/(float ref) //연산자 오버로딩으로 1x4벡터와 상수 나눗셈연산
	{
		vec1x4 savevec(new float[1][4]);
		for (int i = 0; i < 4; i++) {
			savevec.vec[0][i] = this->vec[0][i] / ref;
		}
		return savevec;
	}

};

float radians(float r) {
	//각도 * 3.14 /180
	r = r * 3.14 / 180;
	return r;
}