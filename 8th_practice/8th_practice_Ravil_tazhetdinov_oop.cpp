#include <iostream>
#include <string>
#include <Windows.h>


using namespace std;

class Rectangle_1 {
private:
    int a;
    int b;
public:
    Rectangle_1(const int& a1, const int& b1) : a(a1), b(b1) {}
    void area_rect() const {
        cout << "Площадь прямоугольника: " << a * b << " кв.см" << endl;
    }
};

class Rectangle_2 {
private:
    int a;
    int b;
public:
    Rectangle_2(const int& a1, const int& b1) : a(a1), b(b1) {}
    void area_rect() const {
        cout << "Площадь прямоугольника: " << a * b << " кв.см" << endl;
    }
    void setA(int a) {
        this->a = a;
    }
    void setB(int b) {
        this->b = b;
    }
    int getA() {
        return a;
    }
    int getB() {
        return b;
    }
};



// Абстрактный класс Utensil - интерфейс для всех предметов утвари
class Utensil {
public:
    virtual void use() = 0;  // Метод, описывающий использование предмета
    virtual ~Utensil() = default;
};

// Класс для кастрюли, наследуется от Utensil
class Pot : public Utensil {
public:
    void use() override {
        cout << "Используем кастрюлю для варки супа." << endl;
    }
};

// Класс для чайника, наследуется от Utensil
class Kettle : public Utensil {
public:
    void use() override {
        cout << "Используем чайник для кипячения воды для кофе." << endl;
    }
};

// Класс для ложки, наследуется от Utensil
class Spoon : public Utensil {
public:
    void use() override {
        cout << "Используем ложку для размешивания супа." << endl;
    }
};

// Класс для чашки, наследуется от Utensil
class Cup : public Utensil {
public:
    void use() override {
        cout << "Используем чашку для питья кофе." << endl;
    }
};

// Класс для процесса готовки супа
class SoupCooking {
private:
    Pot* pot;       // Кастрюля
    Spoon* spoon;   // Ложка

public:
    // Конструктор, принимающий кастрюлю и ложку
    SoupCooking(Pot* p, Spoon* s) : pot(p), spoon(s) {}

    void cook() {
        cout << "Готовим суп:" << endl;
        pot->use();      // Используем кастрюлю
        spoon->use();    // Используем ложку
        cout << "Суп готов!" << endl;
    }
};

// Класс для процесса готовки кофе
class CoffeeCooking {
private:
    Kettle* kettle;  // Чайник
    Cup* cup;        // Чашка

public:
    // Конструктор, принимающий чайник и чашку
    CoffeeCooking(Kettle* k, Cup* c) : kettle(k), cup(c) {}

    void cook() {
        cout << "Готовим кофе:" << endl;
        kettle->use();   // Используем чайник
        cup->use();      // Используем чашку
        cout << "Кофе готов!" << endl;
    }
};

// Функция для демонстрации готовки
void cookDish(SoupCooking& soupCooking) {
    soupCooking.cook();  // Готовим суп
}

void cookDish(CoffeeCooking& coffeeCooking) {
    coffeeCooking.cook();  // Готовим кофе
}

// Класс BankAccount - описание банковского счета
class BankAccount {
private:
    string accountNumber;  // Номер счета
    string owner;          // Владелец счета
    double balance;        // Баланс счета (инкапсулированный)

public:
    // Конструктор для создания счета
    BankAccount(string accNum, string own, double initialBalance)
        : accountNumber(accNum), owner(own), balance(initialBalance) {}

    // Метод для внесения денег на счет
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Внесено " << amount << " на счет. Текущий баланс: " << balance << endl;
        }
        else {
            cout << "Ошибка: сумма должна быть положительной." << endl;
        }
    }

    // Метод для снятия денег со счета
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Ошибка: недостаточно средств на счете." << endl;
        }
        else if (amount <= 0) {
            cout << "Ошибка: сумма снятия должна быть положительной." << endl;
        }
        else {
            balance -= amount;
            cout << "Снято " << amount << " со счета. Текущий баланс: " << balance << endl;
        }
    }

    // Метод для проверки баланса
    void checkBalance() const {
        cout << "Текущий баланс: " << balance << endl;
    }

    // Метод для отображения информации о счете
    void displayAccountInfo() const {
        cout << "Номер счета: " << accountNumber << endl;
        cout << "Владелец: " << owner << endl;
        cout << "Баланс: ";
        checkBalance();  // Вызываем проверку баланса
    }
};

// Абстрактный класс Transport - базовый класс для транспортных средств
class Transport {
public:
    // Чисто виртуальная функция для движения
    virtual void move() const = 0;

    // Чисто виртуальная функция для сигнала
    virtual void honk() const = 0;

    // Виртуальный деструктор
    virtual ~Transport() = default;
};

// Класс Car - конкретный транспорт, наследуется от Transport
class Car : public Transport {
public:
    void move() const override {
        cout << "Машина едет по дороге." << endl;
    }

    void honk() const override {
        cout << "Машина сигналит: Бип-бип!" << endl;
    }
};

// Класс Bicycle - конкретный транспорт, наследуется от Transport
class Bicycle : public Transport {
public:
    void move() const override {
        cout << "Велосипед едет по велосипедной дорожке." << endl;
    }

    void honk() const override {
        cout << "Велосипед сигналит: Звон-звон!" << endl;
    }
};

// Класс Train - конкретный транспорт, наследуется от Transport
class Train : public Transport {
public:
    void move() const override {
        cout << "Поезд мчится по рельсам." << endl;
    }

    void honk() const override {
        cout << "Поезд сигналит: Тууу-тууу!" << endl;
    }
};

// Функция для демонстрации работы транспорта
void demonstrateTransport(const Transport& transport) {
    transport.move();  // Вызываем движение
    transport.honk();  // Вызываем сигнал
}

void ex1() {
    //Постановка задачи.Напишите программу для вычисления площади прямоугольника, используя принцип инкапсуляции.
    cout << "Задание №1" << endl;
    int length, width;
    cout << "Введите длину прямоугольника: ";
    cin >> length;
    cout << "Введите ширину прямоугольника: ";
    cin >> width;
    Rectangle_1 a(length, width);
    a.area_rect();
    cout << endl << "________________________________________________________________________________________________________________________\n" << endl;
}

void ex2() {
    //Постановка задачи : Напишите программу для вычисления площади прямоугольника, используя принцип инкапсуляции и модификаторы доступа для сокрытия данных, сделав частными вариабельность длины и ширины.
    cout << "Задание №2" << endl;
    int length, width;
    cout << "Введите длину прямоугольника: ";
    cin >> length;
    cout << "Введите ширину прямоугольника: ";
    cin >> width;
    Rectangle_2 a(length, width);
    a.area_rect();
    cout << "\nВведите новую длину прямоугольника: ";
    cin >> length;
    a.setA(length);
    cout << "Введите новую ширину прямоугольника: ";
    cin >> width;
    a.setB(width);
    cout << "Новая длина прямоугольника: " << a.getA() << " см" << endl;
    cout << "Новая ширинa прямоугольника: " << a.getB() << " см" << endl;
    a.area_rect();
    cout << endl << "________________________________________________________________________________________________________________________\n" << endl;
}



void ex3_4() {
    //Постановка задачи. Реализуйте код интерфейса для варки , в т.ч. для варки супа и кофе. Прокомментируйте свой код построчно.
    //Постановка задачи.Реализуйте код для предметов утвари, в т.ч.для варки супа и кофе.Прокомментируйте свой код построчно.
    cout << "Задание №3_4" << endl;
    // Создаем объекты утвари
    Pot pot;          // Кастрюля для супа
    Spoon spoon;      // Ложка для супа
    Kettle kettle;    // Чайник для кофефф
    Cup cup;          // Чашка для кофе
    // Создаем объекты для готовки
    SoupCooking soupCooking(&pot, &spoon);  // Готовка супа
    CoffeeCooking coffeeCooking(&kettle, &cup);  // Готовка кофе
    // Готовим суп
    cookDish(soupCooking);
    // Готовим кофе
    cookDish(coffeeCooking);
    cout << endl << "________________________________________________________________________________________________________________________\n" << endl;
}

void ex5() {
    //.Каждый банковский счет имеет номер, владельца, баланс и операции, такие как внесение денег, снятие денег и проверка баланса.Чтобы защитить данные от несанкционированного доступа, информация о балансе должна быть скрыта(инкапсулирована).Доступ к этой информации возможен только через методы, которые проверяют корректность действий(например, невозможность снять сумму больше текущего баланса).
    cout << "Задание №5" << endl;
    // Создаем банковский счет
    BankAccount account("123456789", "Иван Иванов", 5000.0);
    // Печатаем информацию о счете
    account.displayAccountInfo();
    // Внесение денег
    account.deposit(1500.0);
    // Снятие денег
    account.withdraw(2000.0);
    // Попытка снять больше, чем доступно
    account.withdraw(5000.0);
    // Проверка баланса
    account.checkBalance();
    cout << endl << "________________________________________________________________________________________________________________________\n" << endl;
}

void ex6() {
    //.Каждый банковский счет имеет номер, владельца, баланс и операции, такие как внесение денег, снятие денег и проверка баланса.Чтобы защитить данные от несанкционированного доступа, информация о балансе должна быть скрыта(инкапсулирована).Доступ к этой информации возможен только через методы, которые проверяют корректность действий(например, невозможность снять сумму больше текущего баланса).
    cout << "Задание №6" << endl;
    // Создаем объекты разных видов транспорта
    Car car;
    Bicycle bicycle;
    Train train;
    // Демонстрируем работу транспорта
    cout << "Демонстрация работы автомобиля:" << endl;
    demonstrateTransport(car);
    cout << "\nДемонстрация работы велосипеда:" << endl;
    demonstrateTransport(bicycle);
    cout << "\nДемонстрация работы поезда:" << endl;
    demonstrateTransport(train);
    cout << endl << "________________________________________________________________________________________________________________________\n" << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ex1();
    ex2();
    ex3_4();
    ex5();
    ex6();
}

