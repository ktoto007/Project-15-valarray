#pragma once

#include <vector>
#include <valarray>

//використання простору імен std
using namespace std;

//клас Matrixs
class Matrixs
{
public:
	//конструктор за замовчуванням
	Matrixs();
	//матриця із вказівником
	void UkazAdd();//заповнення вручну
	void UkazFile();//заповнення з файлу
	void UkazPrint();//виведення матриці на консоль

	//матриця із valarray
	void ValarrayAdd();//заповнення вручну
	void ValarrayFile();//заповнення з файлу
	void ValarrayPrint();//виведення матриці на консоль

	//матриця із vector
	void VectorAdd();//заповнення вручну
	void VectorFile();//заповнення з файлу
	void VectorPrint();//виведення матриці на консоль
	
	//Конволюція матриць
	void ConvolutionM1();
	void ConvolutionM2();
	void ConvolutionM3();
	//Деструктор
	~Matrixs();
private:
	double **M1;
	valarray<valarray<double>> M2;
	vector<vector<double>> M3;
	int row;
	int col;
};

