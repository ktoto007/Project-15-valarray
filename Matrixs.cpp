//ϳ��������� �������
#include "Matrixs.h"
#include <iostream>
#include <string>
#include <fstream>

//������������ �������� ���� std
using namespace std;

//�����������
Matrixs::Matrixs()
{
	col = 0;
	row = 0;
}

//���������� ������ ������ �� ��������� ���������
void Matrixs::UkazAdd()
{
	//�������� ������ ������
	cout << "������ ������ ������� (row, col)" << endl;
	cin >> row >> col;
	//�������� ���'�� �� �����
	M1= new double*[row];
	for (int i = 0; i < row; ++i)
		M1[i] = new double[col];
	//���������� ������
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			//�������� ��������
			double num;
			cout << "������ �������� ������ [" << i << "," << j << "]" << endl;
			cin >> num;
			M1[i][j] = num;
		}
}

//���������� ������ � �����
void Matrixs::UkazFile()
{
	string line;
	string file_name;
	//�������� ����� �����
	cout << "������ ��'� �����" << endl;
	cin >> file_name;
	std::ifstream in(file_name);
	int countcol = 0;
	int countrow = 0;
	if (in.is_open())
	{
		while (getline(in, line))//���������� ���������� �����
		{
			vector<double> tmp;//���������� ������
			string word = "";
			for (int i = 0; i < line.size(); ++i)
			{
				if (line[i] != ' ') //�������� ������ �� �����
					word += line[i];
				else {
					countcol++;
					word = "";
				}
			}
			if (word != "")
				countcol++;
			countrow++;
		}
	}
	in.close();

	row = countrow;
	col = countcol / countrow;

	countcol = 0;
	countrow = 0;
	//�������� ���'�� �� �����
	M1 = new double* [row];
	for (int i = 0; i < row; ++i)
		M1[i] = new double[col];

	std::ifstream in2(file_name);
	if (in2.is_open())
	{
		while (getline(in2, line))//���������� ���������� �����
		{
			string word = "";
			for (int i = 0; i < line.size(); ++i)
			{
				if (line[i] != ' ') //�������� ������ �� �����
					word += line[i];
				else {
					M1[countrow][countcol % col] = stod(word);
					countcol++;
					word = "";
				}
			}
			if (word != "")
			{
				M1[countrow][countcol % col] = stod(word);
				countcol++;
			}
			countrow++;
		}
	}
	in2.close();
}

//��������� ������ �� �������
void Matrixs::UkazPrint()
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			cout << M1[i][j] << "\t";
		cout << endl;
	}
}

//���������� ������ ������ �� ��������� valarray;
void Matrixs::ValarrayAdd()
{
	cout << "������ ������ ������� (row, col)" << endl;
	cin >> row >> col;
	M2.resize(row);
	for (int i = 0; i < row; ++i) {
		valarray<double> tmp;
		tmp.resize(col);
		for (int j = 0; j < col; ++j)
		{
			double num;
			cout << "������ �������� ������ [" << i << "," << j << "]" << endl;
			cin >> num;
			tmp[j]=num;
		}
		M2[i]=tmp;
	}
}

//���������� ������ � �����
void Matrixs::ValarrayFile()
{
	string line;
	string file_name;
	//�������� ����� �����
	cout << "������ ��'� �����" << endl;
	cin >> file_name;
	std::ifstream in(file_name);
	int countcol = 0;
	int countrow = 0;
	if (in.is_open())
	{
		while (getline(in, line))//���������� ���������� �����
		{
			vector<double> tmp;//���������� ������
			string word = "";
			for (int i = 0; i < line.size(); ++i)
			{
				if (line[i] != ' ') //�������� ������ �� �����
					word += line[i];
				else {
					countcol++;
					word = "";
				}
			}
			if (word != "")
				countcol++;
			countrow++;
		}
	}
	in.close();

	row = countrow;
	col = countcol / countrow;

	countcol = 0;
	countrow = 0;
	M2.resize(row);

	std::ifstream in2(file_name);
	if (in2.is_open())
	{
		while (getline(in2, line))//���������� ���������� �����
		{
			valarray<double> tmp;
			tmp.resize(col);
			string word = "";
			for (int i = 0; i < line.size(); ++i)
			{
				if (line[i] != ' ') //�������� ������ �� �����
					word += line[i];
				else {
					tmp[countcol % col] = stod(word);
					countcol++;
					word = "";
				}
			}
			if (word != "")
			{
				tmp[countcol % col] = stod(word);
				countcol++;
			}
			M2[countrow] = tmp;
			countrow++;
		}
	}
	in2.close();
}

//���� ������ �� �����
void Matrixs::ValarrayPrint()
{
	for (int i = 0; i < M2.size(); ++i)
	{
		for (int j = 0; j < M2[i].size(); ++j)
			cout << M2[i][j] << "\t";
		cout << endl;
	}
}

//���������� ������ ������ 
void Matrixs::VectorAdd()
{
	//�������� ������ ������
	cout << "������ ������ ������� (row, col)" << endl;
	cin >> row >> col;
	//���������� ������
	for (int i = 0; i < row; ++i) {
		vector<double> tmp; //���������� ������
		for (int j = 0; j < col; ++j)
		{
			double num;
			cout << "������ �������� ������ [" << i << "," << j << "]" << endl;
			cin >> num;
			tmp.push_back(num);
		}
		M3.push_back(tmp);
	}
}

//���������� ������ � �����
void Matrixs::VectorFile()
{
	string line;
	string file_name;
	//�������� ����� �����
	cout << "������ ��'� �����" << endl;
	cin >> file_name;
	std::ifstream in(file_name);
	if (in.is_open())
	{
		while (getline(in, line))//���������� ���������� �����
		{
			vector<double> tmp;//���������� ������
			string word = "";
			for (int i = 0; i < line.size(); ++i)
			{
				if (line[i] != ' ') //�������� ������ �� �����
					word += line[i];
				else {
					tmp.push_back(stod(word));
					word = "";
				}
			}
			if (word != "")
				tmp.push_back(stod(word));
			M3.push_back(tmp);
		}
	}
	in.close();
	row = M3.size();
	col = M3[0].size();
}

//���� ������ �� �����
void Matrixs::VectorPrint()
{
	for (int i = 0; i < M3.size(); ++i)
	{
		for (int j = 0; j < M3[i].size(); ++j)
			cout << M3[i][j] << "\t";
		cout << endl;
	}
}

//���������� ������� �1
void Matrixs::ConvolutionM1()
{
	double MC[3][3] = { {0, 1, 0},
					   {0,-1, 0},
					   {0, 0, 0} };
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int i0 = (i - 1 + row) % row;
			int j0 = (j - 1 + col) % col;
			int i1 = (i + row) % row;
			int j1 = (j + col) % col;
			int i2 = (i + 1 + row) % row;
			int j2 = (j + 1 + col) % col;
			M1[i][j] = M1[i0][j0] * MC[0][0] + M1[i0][j1] * MC[0][1] + M1[i0][j2] * MC[0][2] +
					   M1[i1][j0] * MC[1][0] + M1[i1][j1] * MC[1][1] + M1[i1][j2] * MC[1][2] +
					   M1[i2][j0] * MC[2][0] + M1[i2][j1] * MC[2][1] + M1[i2][j2] * MC[2][2];
		}
	}
	
}

//���������� ������� �2
void Matrixs::ConvolutionM2()
{
	valarray<valarray<double>> MC = {{0, 1, 0},
									 {0,-1, 0},
									 {0, 0, 0}};
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int i0 = (i - 1 + row) % row;
			int j0 = (j - 1 + col) % col;
			int i1 = (i + row) % row;
			int j1 = (j + col) % col;
			int i2 = (i + 1 + row) % row;
			int j2 = (j + 1 + col) % col;
			M2[i][j] = M2[i0][j0] * MC[0][0] + M2[i0][j1] * MC[0][1] + M2[i0][j2] * MC[0][2] +
					   M2[i1][j0] * MC[1][0] + M2[i1][j1] * MC[1][1] + M2[i1][j2] * MC[1][2] +
					   M2[i2][j0] * MC[2][0] + M2[i2][j1] * MC[2][1] + M2[i2][j2] * MC[2][2];
		}
	}
}

//���������� ������� �3
void Matrixs::ConvolutionM3()
{
	vector<vector<double>> MC = {{0, 1, 0},
								 {0,-1, 0},
								 {0, 0, 0}};
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int i0 = (i - 1 + row) % row;
			int j0 = (j - 1 + col) % col;
			int i1 = (i + row) % row;
			int j1 = (j + col) % col;
			int i2 = (i + 1 + row) % row;
			int j2 = (j + 1 + col) % col;
			M3[i][j] = M3[i0][j0] * MC[0][0] + M3[i0][j1] * MC[0][1] + M3[i0][j2] * MC[0][2] +
					   M3[i1][j0] * MC[1][0] + M3[i1][j1] * MC[1][1] + M3[i1][j2] * MC[1][2] +
					   M3[i2][j0] * MC[2][0] + M3[i2][j1] * MC[2][1] + M3[i2][j2] * MC[2][2];
		}
	}
}

//����������
Matrixs::~Matrixs()
{
}
