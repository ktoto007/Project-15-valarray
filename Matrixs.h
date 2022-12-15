#pragma once

#include <vector>
#include <valarray>

//������������ �������� ���� std
using namespace std;

//���� Matrixs
class Matrixs
{
public:
	//����������� �� �������������
	Matrixs();
	//������� �� ����������
	void UkazAdd();//���������� ������
	void UkazFile();//���������� � �����
	void UkazPrint();//��������� ������� �� �������

	//������� �� valarray
	void ValarrayAdd();//���������� ������
	void ValarrayFile();//���������� � �����
	void ValarrayPrint();//��������� ������� �� �������

	//������� �� vector
	void VectorAdd();//���������� ������
	void VectorFile();//���������� � �����
	void VectorPrint();//��������� ������� �� �������
	
	//���������� �������
	void ConvolutionM1();
	void ConvolutionM2();
	void ConvolutionM3();
	//����������
	~Matrixs();
private:
	double **M1;
	valarray<valarray<double>> M2;
	vector<vector<double>> M3;
	int row;
	int col;
};

