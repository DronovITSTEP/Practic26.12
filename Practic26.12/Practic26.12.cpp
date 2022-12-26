#include <iostream>
#include <Windows.h>

using namespace std;

// макросы
#define SUM(X, Y) ((X) + (Y))
#define SQR(X) (X)*(X)
#define CUBE(X) SQR(X)*(X)

//инлайн функции (вместо вызова происходит вставка кода)
inline int maximum(int a, int b) {
	return a > b ? a : b;
}

//перегрузка функции (одно и то же имя, но разные либо типы, либо кол-во
//параметров
inline int sum(int a, int b) {
	return a + b;
}
inline int sum(int a, int b, int c) {
	return a + b + c;
}
inline double sum(double a, double b) {
	return a + b;
}


//шаблонная функция (вместо Т устанавливается тот тип данных,
//который был передан в параметры при вызове функции)
template <typename T>
T printArr(T arr[], int n) {
	T temp = arr[2];
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return temp;
}

//перегрузка шаблонной функции
template <typename T>
T sum(T a, T b) {
	return a + b;
}
template <typename R, typename S>
void sum(R a, S b) {
	cout << a + b << endl;
}

// прототипы функций (реализация происходит под main)
template <typename T> T avg(T arr[], int s); 
template <typename T> T maximum(T arr[], int s);
template <typename T> T maximum(T arr[][5], int s, int k);
template <typename T> T maximum(T arr[][5][4], int s, int k, int h);

int max1(int a, int b);
int max1(int a, int b, int c);


double roundingNumber(double d, int n);


int main()
{
	/*int arr1[3]{6,7,3};
	double arr2[3]{5.5, 7, 3.2};
	char arr3[3]{'5','d','!'};
	bool arr4[3]{true, true, false};
	cout << printArr(arr1, 3) << endl;
	cout << printArr(arr2, 3) << endl;
	cout << printArr(arr3, 3) << endl;
	cout << printArr(arr4, 3) << endl;*/

	//sum(5, 1.8);
	//double arr[]{ 5,7,8.6,1 };
	//cout << avg(arr, 4);

	cout << roundingNumber(5.4556, 2);
}


/*
Написать шаблон функции для поиска среднего арифметического
значений массива.
*/
template <typename T>
T avg(T arr[], int s) {
	T sum = NULL;
	for (int i = 0; i < s; i++) {
		sum += arr[i];
	}
	return sum / s;
}

/*
Написать перегруженные шаблоны функций для нахождения 
корней линейного (ax + b = 0) и квадратного
(ax2+b*x + c = 0) уравнений. Замечание: в функции
передаются коэффициенты уравнений.
*/
template <typename T>
void Equations(T a, T b)
{
	cout << -b / a << endl;
}

template <typename T1, typename T2, typename T3>
void Equations(T1 a, T2 b, T3 c) {
	double dis = b * b - 4 * a * c;
	if (dis < 0) cout << "No decision\n";
	else if (dis == 0) cout << -b / (2 * a) << endl;
	else {
		double x1 = (-b - sqrt(dis)) / (2 * a);
		double x2 = (-b + sqrt(dis)) / (2 * a);
		cout << x1 << " " << x2 << endl;
	}	
}

/*
Написать функцию, которая принимает в качестве 
параметров вещественное число и количество знаков
после десятичной точки, которые должны остаться.
Задачей функции является округление вышеуказанного
вещественного числа с заданной точностью
*/
double roundingNumber(double d, int n) { // (5.4555559, 2) -> 5.46
	int temp = d * pow(10, n + 1);
	if (temp % 10 >= 5) {
		temp += 10;  		 
	}
	temp /= 10;// 
	return (double)temp / pow(10, n); // 5.46
}

/*
Написать шаблонные функции и протестировать их
в основной программе:
■ Нахождения максимального значения в одномерном
массиве;
■ Нахождения максимального значения в двумерном
массиве;
■ Нахождения максимального значения в трёхмерном
массиве.
*/
template <typename T>
T maximum(T arr[], int s){
	T max = arr[0];
	for (int i = 0; i < s; i++) {
		if (max < arr[i]) max = arr[i];
	}
	return max;
}
template <typename T>
T maximum(T arr[][5], int s, int k) {
	T max = arr[0][0];
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < k; j++) {
			if (max < arr[i][j]) max = arr[i][j];
		}
	}
	return max;
}
template <typename T>
T maximum(T arr[][5][4], int s, int k, int h) {
	T max = arr[0][0][0];
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < k; j++) {
			for (int l = 0; l < h; l++) {
				if (max < arr[i][j][l]) max = arr[i][j][l];
			}
		}
	}
	return max;
}

/*
Реализуйте перегруженные функции для
■ Нахождения максимального значения двух целых;
■ Нахождения максимального значения трёх целых.
*/
int max1(int a, int b) { return a > b ? a : b; }
int max1(int a, int b, int c){
	if (a > b && a > c) return a;
	else if (b > c) return b;
	else return c;
}


/*
Написать ф-ю, которая принимает координаты шахматной фигуры 
куда нужно сходить.
Ф-я должна возвращать true или false, если этот ход возможен
  0 1 2 3 4 5 6 7	- B
0|*|_|_|_|_|_|_|_|
1|_|*|_|_|_|_|_|*|
2|_|_|*|_|_|_|*|_|
3|_|_|_|*|_|*|_|_|
4|_|_|_|_|P|_|_|_|
5|_|_|_|*|_|*|_|_|
6|_|_|*|_|_|_|*|_|
7|_|*|_|_|_|_|_|*|

|
A
*/
//для пешки
const int centerA = 4, centerB = 4;
bool IsMovePawn(int a, int b) {
	return (centerB == b && centerA == a - 1) ? true : false;
}
//для слона
bool IsMoveElephant(int a, int b) {
	return (abs(centerA-a) == abs(centerB - b)) ? true : false;
}
