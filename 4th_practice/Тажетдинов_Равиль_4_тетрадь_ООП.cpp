#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <typeinfo>
#include <string>
#include <windows.h>
using namespace std;

double rad_deg(double radians) {
	return radians * (180.0 / M_PI);
}

double logg(double a, double b) {
	return log(a) / log(b);
}

void ex1() {
	/*Найдите решение уравнения при следующих начальных данных :
	x = 45900 y = 34.590
		log_x⁡〖((cos⁡(2y) * sin⁡(x / 10000)) / x ^ (tan⁡(y)))〗
		В каком типе данных компилятор вывел ответ ? Почему ?*/
	cout << "Задание №1" << endl;
	cout << "Начальные данные: x = 45900 y = 34.590" << endl;
	int x = 45900;
	double y = 34.590;
	double equation = logg((cos(rad_deg(2 * y)) * sin(rad_deg(x / 10000))) / (pow(x, tan(y))), x);
	cout << "Ответ: " << equation << "\nТип данных: " << typeid(equation).name() << " Пояснение:\nТип данных double находится на втором месте по приоритету, а тип int на последнем\n1.long double\n2.double\n3.float4.unsigned long long\n5.long long\n6.unsigned long\n7.long\n8.unsigned int\n9.int " << endl;
	cout << "________________________________________________________________________________________________________________________\n" << endl;
}

void ex2() {

	cout << "Задание №2" << endl;
	unsigned y;
	cout << "Введите число для переменной y: ";
	cin >> y;
	int v = 0 - y;
	cout << "1. 0 - y = " << 0 - y << ". Тип данных: " << typeid(0 - y).name() << endl << "2. int v = 0 - y" << endl << "   v = " << v << ". Тип данных: " << typeid(v).name() << endl << "Объяснение:\nВ первом случае происходит переполнения по модулю (выход за границы), а во втором случае это происходит из-за неявного переоброзования данных" << endl;
	cout << "________________________________________________________________________________________________________________________\n" << endl;
}

void ex3() {
	//Напишите программу, которая заполняет матрицу 5х5 0 - ми и 1 - ми в шахматном порядке, в цикле for - each.
	cout << "Задание №3" << endl;
	int a[5][5]{ 0 };
	bool chek = true;
	for (auto& rows : a) {
		for (auto& elem : rows) {
			if (chek) {
				elem = 1;
				chek = false;
				cout << elem;
			}
			else {
				chek = true;
				cout << elem;
			}
		}
		cout << endl;
	}

	cout << "________________________________________________________________________________________________________________________\n" << endl;
}

void ex4() {

	cout << "Задание №4" << endl;
	string name_array[5] = { "Равиля", "Глеба", "Артура", "Насти", "Сергея" };
	string favorite_colors[5];
	for (int i = 0; i < 5; ++i) {
		cout << "Какой любимый цвет у " << name_array[i] << "? ";
		cin >> favorite_colors[i];
	}
	for (int i = 0; i < 5; ++i) {
		cout << favorite_colors[i] << " " << '\t';
	}
	cout << '\n';
	for (int i = 0; i < 5; ++i) {
		cout << "любимый цвет " <<  name_array[i]<< ": " << favorite_colors[i] << endl;
	}
	cout << "________________________________________________________________________________________________________________________\n" << endl;
}



void ex5() {
	//Проанализируйте программу и предположите, что она выведет.Перепечатайте, скомпилируйте и проверьте свой ответ.
	cout << "Задание №5" << endl;
	cout << "каждое число в массиве A сложится с самим собой." << endl;
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "начальный массив: ";
	for (int i = 0; i < 10; i++) {
		
		cout << a[i] << '\t';
	}
	cout << endl;
	cout << "итоговый массив: ";
	int* ptr;
	for (int i = 0; i < 10; i++) {
		ptr = &a[i];
		cout << a[i] + *ptr << '\t';
	}
	cout << endl << "________________________________________________________________________________________________________________________\n" << endl;
}

void ex6() {
	//Напишите программу, которая увеличивает каждый элемент массива на 1 с использованием указателей.
	cout << "Задание №6" << endl;
	int length;
	cout << "Введите длину массива: ";
	cin >> length;
	int* array = new int[length];
	int* pointer = &array[0];
	for (int i = 0; i < length; i++) {
		int j = i + 1;
		cout << "Введите №" << j << " значение: ";
		cin >> *(pointer + i);
	}
	cout << "Начальный массив:" << endl;
	for (int i = 0; i < length; i++) {
		cout << *(pointer + i) << ' ';
	}
	cout << endl;
	for (int i = 0; i < length; i++) {

		*(pointer + i) += 1;
	}
	cout << "Увеличинный массив на еденицу:" << endl;
	for (int i = 0; i < length; i++) {
		cout << *(pointer + i) << ' ';
	}
	cout << endl << "________________________________________________________________________________________________________________________\n" << endl;
}

void ex7() {
	//Напишите программу, которая вычисляет сумму элементов массива, используя указатели.
	cout << "Задание №7" << endl;
	int length;
	int sum = 0;
	cout << "Введите длину массива: ";
	cin >> length;
	int* array = new int[length];
	int* pointer = &array[0];
	for (int i = 0; i < length; i++) {
		int j = i + 1;
		cout << "Введите №" << j << " значение: ";
		cin >> *(pointer + i);
	}
	cout << "Начальный массив:" << endl;
	for (int i = 0; i < length; i++) {
		cout << *(pointer + i) << ' ';
		sum += *(pointer + i);
	}
	cout << "\nСумма элементов массива = " << sum << endl;
	cout << endl << "________________________________________________________________________________________________________________________\n" << endl;
}


int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ex1();
	ex2();
	ex3();
	ex4();
	ex5();
	ex6();
	ex7();
}