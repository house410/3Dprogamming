#pragma once
#include <iostream> 
#include <math.h> 

#define PI 3.141592 //PI�ٻ簪

//Ŭ���� mat3
class mat3 {
public:
	float mat[3][3];//3x3 ���


	void identity() //�������
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


	//������, float�� 3x3����� �޾ƿ��Ŀ� this������ mat�� ����� �־��ش�.
	mat3(float m[3][3]) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				this->mat[i][j] = m[i][j];
			}
		}
	}

	//3x3��� �����ε� �����Լ��̴�.
	mat3 operator*(const mat3& ref) {

		mat3 savemat(new float[3][3]);//�迭����� ���� ��ȯ�Ѵ�.
		////i ���� 0���� 3 �̸����� 1�� �����ϸ� �ݺ�
	   //j ���� 0���� 3 �̸����� 1�� �����ϸ� �ݺ�
	  //k ���� 0���� 3 �̸����� 1�� �����ϸ� �ݺ�
	  //�� ����� ���ϴ� �����η� ���� �ݺ��� ������ ���� ���� savemat[i][j]�� ������
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++)
					savemat.mat[i][j] += (mat[k][j] * ref.mat[i][k]);
			}
		}
		return savemat;
	}

	mat3 operator+(const mat3& ref) { //������ �����ε����� 3x3��� ��������

		mat3 savemat(new float[3][3]);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				savemat.mat[i][j] = (mat[i][j] + ref.mat[i][j]);
			}
		}
		return savemat;
	}

	mat3 operator-(const mat3& ref) { //������ �����ε����� 3x3��� ��������

		mat3 savemat(new float[3][3]);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				savemat.mat[i][j] = (mat[i][j] - ref.mat[i][j]);
			}
		}
		return savemat;
	}


	mat3 operator/(float ref) { //������ �����ε����� 3x3��İ� ��� ������ ����

		mat3 savemat(new float[3][3]);//�迭����� ���� ��ȯ�Ѵ�.
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) 
					savemat.mat[i][j] = mat[i][j] / ref;
			
		}
		return savemat;
	}

	mat3 operator*(float ref) { //������ �����ε����� 3x3��İ� ��� ���� ����

		mat3 savemat(new float[3][3]);//�迭����� ���� ��ȯ�Ѵ�.
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

	void identity() //�������
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

	mat4 transpose() //mat4 ��ġ���
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
		for(int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				this->mat[i][j] = m[i][j];
			}
		}
	}

	mat4 operator*(const mat4& ref)
	{
		mat4 savemat(new float[4][4]{ {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });  //������ �����ε����� 4x4��� ����

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


	mat4 operator+(const mat4& ref) { //������ �����ε����� 4x4 ��İ� ��������

		mat4 savemat(new float[4][4]{ {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				savemat.mat[i][j] = (mat[i][j] + ref.mat[i][j]);
			}
		}
		return savemat;
	}


	mat4 operator-(const mat4& ref) { //������ �����ε����� 4x4��� ��������

		mat4 savemat(new float[4][4]{ {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				savemat.mat[i][j] = (mat[i][j] - ref.mat[i][j]);
			}
		}
		return savemat;
	}

	mat4 operator/(float ref) { //������ �����ε����� 4x4��İ� ��� ������ ����

		mat4 savemat(new float[4][4]{ {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });//�迭����� ���� ��ȯ�Ѵ�.
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				savemat.mat[i][j] = mat[i][j] / ref;

		}
		return savemat;
	}

	mat4 operator*(float ref) { //������ �����ε����� 4x4��İ� ��� ���� ����

		mat4 savemat(new float[4][4]{ {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });//�迭����� ���� ��ȯ�Ѵ�.
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				savemat.mat[i][j] = mat[i][j] * ref;

		}
		return savemat;
	}



};

//Ŭ���� vec3
class vec3
{
public:
	float vec[3];
	vec3 transposevec(vec3 v) { //vec3 ��ġ
		vec3 save(new float[3]);
		for (int i = 0; i < 3; i++)
			save.vec[i] = v.vec[i];
		return save;
	}

	//������, float�� 3x1����� �޾ƿ��Ŀ� this������ vec�� ����� �־��ش�.
	vec3(float v[3]) {
		for (int i = 0; i < 3; i++) {
			this->vec[i] = v[i];
		}
	}

	//vec��mat�� ��� ���ϱ� �����ε� �Լ�
	vec3 operator*(const mat3& ref)
	{
		vec3 savevec(new float[3] {0, 0, 0});//�迭����� ���� ��ȯ�Ѵ�.
		////i ���� 0���� 3 �̸����� 1�� �����ϸ� �ݺ�
		//j ���� 0���� 3 �̸����� 1�� �����ϸ� �ݺ�
		//�� ����� ���ϴ� �����η� ���� �ݺ��� ������ ���� ���� savevec[i][j]�� ������
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				savevec.vec[i] += (vec[j] * ref.mat[j][i]);
			}
		}
		return savevec;
	}



	vec3 operator+(const vec3& ref) //3x1���Ͱ� ����
	{
		vec3 savevec(new float[3] {0, 0, 0});

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				savevec.vec[i] = this->vec[i] + ref.vec[i];
			}
		}
		return savevec;
	}

	vec3 operator-(const vec3& ref) //3x1���Ͱ� ����
	{
		vec3 savevec(new float[3] {0, 0, 0});

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				savevec.vec[i] = this->vec[i] - ref.vec[i];
			}
		}
		return savevec;
	}

	vec3 operator*(float ref) //������ �����ε����� 3x1���Ϳ� ��� ��������
	{
		vec3 savevec(new float[3] {0, 0, 0});
		for (int i = 0; i < 3; i++) {
			savevec.vec[i] = this->vec[i] * ref;
		}
		return savevec;
	}

	vec3 operator/(float ref) //������ �����ε����� 3x1���Ϳ� ��� ����������
	{
		vec3 savevec(new float[3] {0, 0, 0});
		for (int i = 0; i < 3; i++) {
			savevec.vec[i] = this->vec[i] / ref;
		}
		return savevec;
	}
	friend vec3 operator*(mat3& ref, const vec3 ref2);

};

vec3 operator*(mat3& ref, const vec3 ref2) //matxvec ��������
{
	vec3 savemat(new float[3] {0, 0, 0});
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			savemat.vec[i] += ref.mat[i][j] * ref2.vec[j];
	}
	return savemat;
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

	vec1x3 transposevec(vec1x3 v) { //vec1x3 ��ġ
		vec1x3 save(new float[1][3]);
		for (int i = 0; i < 3; i++)
			save.vec[0][i] = v.vec[0][i];
		return save;
	}

	vec1x3 operator+(vec1x3& ref) //������ �����ε����� 1x3 ���Ͱ� ��������
	{
		vec1x3 savevec(new float[1][3]);
		for (int i = 0; i < 3; i++)
		{
			savevec.vec[0][i] = this->vec[0][i] + ref.vec[0][i];
		}
		return savevec;
	}

	vec1x3 operator-(vec1x3& ref) //������ �����ε����� 1x3 ���Ͱ� ��������
	{
		vec1x3 savevec(new float[1][3] {0, 0, 0});
		for (int i = 0; i < 3; i++)
		{
			savevec.vec[0][i] = this->vec[0][i] - ref.vec[0][i];
		}
		return savevec;
	}

	vec1x3 operator*(float ref) //������ �����ε����� 1x3���Ϳ� ��� ��������
	{
		vec1x3 savevec(new float[1][3] {0, 0, 0});
		for (int i = 0; i < 3; i++) {
			savevec.vec[0][i] = this->vec[0][i] * ref;
		}
		return savevec;
	}
	vec1x3 operator/(float ref) //������ �����ε����� 1x3���Ϳ� ��� ����������
	{
		vec1x3 savevec(new float[1][3] {0, 0, 0});
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

	vec4 transposevec(vec4 v) { //vec4��ġ
		vec4 save(new float[4]);
		for (int i = 0; i < 4; i++)
			save.vec[i] = v.vec[i];
		return save;
	}

	//������, float�� 3x1����� �޾ƿ��Ŀ� this������ vec�� ����� �־��ش�.
	vec4(float v[4]) {
		for (int i = 0; i < 4; i++) {
			this->vec[i] = v[i];
		}
	}

	//vec��mat�� ��� ���ϱ� �����ε� �Լ�
	vec4 operator*(const mat4& ref)
	{
		vec4 savevec(new float[4] {0, 0, 0, 0 });//�迭����� ���� ��ȯ�Ѵ�.
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				savevec.vec[i] += (vec[j] * ref.mat[j][i]);
			}
		}
		return savevec;
	}

	vec4 operator+(const vec4& ref) //4x1���Ͱ� ����
	{
		vec4 savevec(new float[4] {0, 0, 0, 0 });

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				savevec.vec[i] = this->vec[i] + ref.vec[i];
			}
		}
		return savevec;
	}

	vec4 operator-(const vec4& ref) //4x1���Ͱ� ����
	{
		vec4 savevec(new float[4] {0, 0, 0, 0 });

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				savevec.vec[i] = this->vec[i] - ref.vec[i];
			}
		}
		return savevec;
	}

	vec4 operator*(float ref) //������ �����ε����� 4x1���Ϳ� ��� ��������
	{
		vec4 savevec(new float[4] {0, 0, 0, 0 });
		for (int i = 0; i < 4; i++) {
			savevec.vec[i] = this->vec[i] * ref;
		}
		return savevec;
	}

	vec4 operator/(float ref) //������ �����ε����� 4x1���Ϳ� ��� ����������
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

	vec1x4 operator+(vec1x4& ref) //������ �����ε����� 1x4 ���Ͱ� ��������
	{
		vec1x4 savevec(new float[1][4]);
		for (int i = 0; i < 4; i++)
		{
			savevec.vec[0][i] = this->vec[0][i] + ref.vec[0][i];
		}
		return savevec;
	}

	vec1x4 operator-(vec1x4& ref) //������ �����ε����� 1x4 ���Ͱ� ��������
	{
		vec1x4 savevec(new float[1][4]);
		for (int i = 0; i < 4; i++)
		{
			savevec.vec[0][i] = this->vec[0][i] - ref.vec[0][i];
		}
		return savevec;
	}

	vec1x4 operator*(float ref) //������ �����ε����� 1x4���Ϳ� ��� ��������
	{
		vec1x4 savevec(new float[1][4]);
		for (int i = 0; i < 4; i++) {
			savevec.vec[0][i] = this->vec[0][i] * ref;
		}
		return savevec;
	}
	vec1x4 operator/(float ref) //������ �����ε����� 1x4���Ϳ� ��� ����������
	{
		vec1x4 savevec(new float[1][4]);
		for (int i = 0; i < 4; i++) {
			savevec.vec[0][i] = this->vec[0][i] / ref;
		}
		return savevec;
	}

};
