#include <iostream>
#include <cmath>
using namespace std;

string check_age(int age){
    if (age % 100 >= 11 && age % 100 <= 19) {
        return " лет";
    } else {
        switch (age % 10) {
            case 1:
                return " год";
            case 2:
            case 3:
            case 4:
                return " года";
            default:
                return " лет";
        }
    }
}


int main(){
    //Задание 1
    setlocale(LC_ALL,"RU");
    int number;
    cout << "Введите число: ";
    cin >> number;
    cout << "Введенное чилсо " << number << endl;
    //Задание 2
    string name;
    int age, weight, hight;
    cout << "Ввыедите ваше имя: ";
    cin >> name;
    cout << "Введите ваш возраст: ";
    cin >> age;
    cout << "Введите ваш вес: ";
    cin >> weight;
    cout << "Введите ваш рост: ";
    cin >> hight;
    cout << "Имя: " << name << "; " << "Возраст: " << age << check_age(age) <<"; " << "вес: " << weight << "кг; " << "рост: " << hight << "см" << endl;
    // задание 3
    cout << "Размеры типов данных в байтах:" << endl;
    cout << "int: " << sizeof(int) << " байт" << endl;
    cout << "float: " << sizeof(float) << " байт" << endl;
    cout << "double: " << sizeof(double) << " байт" << endl;
    cout << "char: " << sizeof(char) << " байт" << endl;
    // задание 4
    int sum, year;
    double percent;
    cout << "Введите сумму вклада: ";
    cin >> sum;
    cout << "Введите процентную ставку в %: ";
    cin >> percent;
    cout << "Введите срок вклада: ";
    cin >> year;
    cout << "Начисленные проценты: " << sum * pow((1 + percent/100.0),  year) - sum << endl;
    // задание 5
    int v_year;
    cout << "Введите год: ";
    cin >> v_year;

    bool is_v = false;
    if (v_year % 4 == 0){
        if (v_year % 100 == 0){
            if (v_year % 400 == 0) is_v = true;
        }
        else is_v = true;
    }
    if (is_v) cout << v_year << " - високосный год." << endl;
    else cout << v_year << " - не високосный год." << endl;
}
