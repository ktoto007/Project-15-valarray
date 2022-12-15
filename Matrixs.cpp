//Підключення бібліотек
#include "Matrixs.h"
#include <iostream>
#include <string>
#include <fstream>

//використання простору імен std
using namespace std;

//Конструктор
Matrixs::Matrixs()
{
	col = 0;
	row = 0;
}

//Заповнення масиву вручну за допомогою вказівника
void Matrixs::UkazAdd()
{
	//введення розміру масиву
	cout << "Введіть розміри матриці (row, col)" << endl;
	cin >> row >> col;
	//виділення пам'яті під масив
	M1= new double*[row];
	for (int i = 0; i < row; ++i)
		M1[i] = new double[col];
	//заповнення масиву
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			//введення значення
			double num;
			cout << "Введіть значення матріці [" << i << "," << j << "]" << endl;
			cin >> num;
			M1[i][j] = num;
		}
}

//заповнення масиву з файлу
void Matrixs::UkazFile()
{
	string line;
	string file_name;
	//введення назви файлу
	cout << "Введіть ім'я файлу" << endl;
	cin >> file_name;
	std::ifstream in(file_name);
	int countcol = 0;
	int countrow = 0;
	if (in.is_open())
	{
		while (getline(in, line))//построкове зчитування файлу
		{
			vector<double> tmp;//тимчасовий вектор
			string word = "";
			for (int i = 0; i < line.size(); ++i)
			{
				if (line[i] != ' ') //розбиття строки на слова
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
	//виділення пам'яті під масив
	M1 = new double* [row];
	for (int i = 0; i < row; ++i)
		M1[i] = new double[col];

	std::ifstream in2(file_name);
	if (in2.is_open())
	{
		while (getline(in2, line))//построкове зчитування файлу
		{
			string word = "";
			for (int i = 0; i < line.size(); ++i)
			{
				if (line[i] != ' ') //розбиття строки на слова
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

//виведення масиву на консоль
void Matrixs::UkazPrint()
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			cout << M1[i][j] << "\t";
		cout << endl;
	}
}

//заповнення масиву вручну за допомогою valarray;
void Matrixs::ValarrayAdd()
{
	cout << "Введіть розміри матриці (row, col)" << endl;
	cin >> row >> col;
	M2.resize(row);
	for (int i = 0; i < row; ++i) {
		valarray<double> tmp;
		tmp.resize(col);
		for (int j = 0; j < col; ++j)
		{
			double num;
			cout << "Введіть значення матріці [" << i << "," << j << "]" << endl;
			cin >> num;
			tmp[j]=num;
		}
		M2[i]=tmp;
	}
}

//заповнення масиву з файлу
void Matrixs::ValarrayFile()
{
	string line;
	string file_name;
	//введення назви файлу
	cout << "Введіть ім'я файлу" << endl;
	cin >> file_name;
	std::ifstream in(file_name);
	int countcol = 0;
	int countrow = 0;
	if (in.is_open())
	{
		while (getline(in, line))//построкове зчитування файлу
		{
			vector<double> tmp;//тимчасовий вектор
			string word = "";
			for (int i = 0; i < line.size(); ++i)
			{
				if (line[i] != ' ') //розбиття строки на слова
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
		while (getline(in2, line))//построкове зчитування файлу
		{
			valarray<double> tmp;
			tmp.resize(col);
			string word = "";
			for (int i = 0; i < line.size(); ++i)
			{
				if (line[i] != ' ') //розбиття строки на слова
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

//Вивід масиву на екран
void Matrixs::ValarrayPrint()
{
	for (int i = 0; i < M2.size(); ++i)
	{
		for (int j = 0; j < M2[i].size(); ++j)
			cout << M2[i][j] << "\t";
		cout << endl;
	}
}

//заповнення масиву вручну 
void Matrixs::VectorAdd()
{
	//Введення розмірів масиву
	cout << "Введіть розміри матриці (row, col)" << endl;
	cin >> row >> col;
	//заповнення масиву
	for (int i = 0; i < row; ++i) {
		vector<double> tmp; //тимчасовий вектор
		for (int j = 0; j < col; ++j)
		{
			double num;
			cout << "Введіть значення матріці [" << i << "," << j << "]" << endl;
			cin >> num;
			tmp.push_back(num);
		}
		M3.push_back(tmp);
	}
}

//заповнення масиву з файлу
void Matrixs::VectorFile()
{
	string line;
	string file_name;
	//введення назви файлу
	cout << "Введіть ім'я файлу" << endl;
	cin >> file_name;
	std::ifstream in(file_name);
	if (in.is_open())
	{
		while (getline(in, line))//построкове зчитування файлу
		{
			vector<double> tmp;//тимчасовий вектор
			string word = "";
			for (int i = 0; i < line.size(); ++i)
			{
				if (line[i] != ' ') //розбиття строки на слова
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

//Вивід масиву на екран
void Matrixs::VectorPrint()
{
	for (int i = 0; i < M3.size(); ++i)
	{
		for (int j = 0; j < M3[i].size(); ++j)
			cout << M3[i][j] << "\t";
		cout << endl;
	}
}

//конволюція матриці М1
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

//конволюція матриці М2
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

//конволюція матриці М3
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

//Деструктор
Matrixs::~Matrixs()
{
}
