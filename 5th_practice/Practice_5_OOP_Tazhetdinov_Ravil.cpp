#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class rectangle {
private:
    int a, b;
public:
    void set_sides(int a_, int b_) {
        a = a_;
        b = b_;
    }
    int find_diagonal() {
        return sqrt(a * a + b * b);
    }

    string info() {
        return to_string(a) + ", " + to_string(b);
    }
};

class summa {
private:
    int x, y;
    int Sum() {
        return x + y;
    }
public:
    void set_variables(int a, int b) {
        x = a;
        y = b;
    }

    string printf() {
        return "Сумма чисел " + to_string(x) + ", " + to_string(y) + " равна " + to_string(Sum());
    }
};




class TicTacToe {
public:
    const size_t N;  // размер игрового поля
    const size_t K;  // сколько фишек нужно поставить в ряд, чтобы выиграть

private:
    // 0 - пусто, 1 - фишка первого игрока (крестик), 2 - фишка второго игрока (нолик)
    vector<vector<int>> Table;

    // номер текущего игрока (1 или 2)
    int currentPlayer;

public:
    TicTacToe(size_t n, size_t k) : N(n), K(k), currentPlayer(1) {
        Table.resize(N, vector<int>(N, 0));
        for (size_t i = 0; i != N; ++i) {
            Table[i].reserve(N);
        }
    }

    int operator()(size_t i, size_t j) const {
        return Table[i][j];
    }

    int GetCurrentPlayer() const {
        return currentPlayer;
    }

    bool Set(size_t i, size_t j) {  // возвращает true, если ход завершился выигрышем
        Table[i][j] = currentPlayer;
        currentPlayer = currentPlayer % 2 + 1;
        bool wins = CheckRow(i, j) || CheckColumn(i, j) || CheckDiagonal1(i, j) || CheckDiagonal2(i, j);
        return wins;
    }

private:
    bool CheckRow(size_t i, size_t j) const {
        size_t d1 = 0;
        while (d1 <= j && Table[i][j - d1] == Table[i][j]) {
            ++d1;
        }

        size_t d2 = 0;
        while (j + d2 < N && Table[i][j + d2] == Table[i][j]) {
            ++d2;
        }

        return d1 + d2 - 1 >= K;
    }

    bool CheckColumn(size_t i, size_t j) const {
        size_t d1 = 0;
        while (d1 <= i && Table[i - d1][j] == Table[i][j]) {
            ++d1;
        }

        size_t d2 = 0;
        while (i + d2 < N && Table[i + d2][j] == Table[i][j]) {
            ++d2;
        }

        return d1 + d2 > K;
    }

    bool CheckDiagonal1(size_t i, size_t j) const {
        size_t d1 = 0;
        while (i >= d1 && j >= d1 && Table[i - d1][j - d1] == Table[i][j]) {
            ++d1;
        }

        size_t d2 = 0;
        while (i + d2 < N && j + d2 < N && Table[i + d2][j + d2] == Table[i][j]) {
            ++d2;
        }

        return d1 + d2 - 1 >= K;
    }

    bool CheckDiagonal2(size_t i, size_t j) const {
        size_t d1 = 0;
        while (i >= d1 && j + d1 < N && Table[i - d1][j + d1] == Table[i][j]) {
            ++d1;
        }

        size_t d2 = 0;
        while (i + d2 < N && j >= d2 && Table[i + d2][j - d2] == Table[i][j]) {
            ++d2;
        }

        return d1 + d2 - 1 >= K;
    }
};

ostream& operator << (ostream& out, TicTacToe& field) {
    for (size_t i = 0; i != field.N; ++i) {
        for (size_t j = 0; j != field.N; ++j) {
            switch (field(i, j)) {
            case 0:
                out << '.';
                break;
            case 1:
                out << 'X';
                break;
            case 2:
                out << 'O';
            }
        }
        cout << "\n";
    }
    return out;
}

class Animal {
public:
    virtual void make_sound() = 0;
};


class Cat:Animal{
public:
    void make_sound() {
        cout << "Мяу" << endl;
    }
};

class Human {
    virtual void move() = 0;
};

class Man : Human {
private:
    string vector = "вправо";
public:
    void move() {
        cout << "Мужчина движется " + vector << endl;
    }
};

class Shape {
    virtual int get_area() = 0;
};

class Rectangle_1 : Shape {
private:
    int a, b;
public:

    int get_area() {
        return a * b;
    }

    void set_sides(int a_, int b_) {
        a = a_;
        b = b_;
    }
};


class Employee {
protected:
    string fullName;
    string passportData;
    string position;
    double salary;
    string address;
    string phoneNumbers;
    string maritalStatus;

public:
    void printFullInfo() const {
        cout << "ФИО: " << fullName << "\n"
            << "Паспортные данные: " << passportData << "\n"
            << "Должность: " << position << "\n"
            << "Оклад: " << salary << "\n"
            << "Адрес: " << address << "\n"
            << "Телефоны: " << phoneNumbers << "\n"
            << "Семейное положение: " << maritalStatus << "\n";
    }

public:
    Employee(const string& name, const string& passport, const string& pos,
        double sal, const string& addr, const string& phones, const string& status)
        : fullName(name), passportData(passport), position(pos), salary(sal),
        address(addr), phoneNumbers(phones), maritalStatus(status) {}
    string ret_fullName() {
        return fullName;
    }
    string ret_passportData() {
        return passportData;
    }
    string ret_address() {
        return address;
    }
    string ret_position() {
        return position;
    }
    string ret_maritalStatus() {
        return maritalStatus;
    }
    string ret_phoneNumbers() {
        return phoneNumbers;
    }

};

class ITDepartment {
protected:
    string fullName;
    string position;
public:
    ITDepartment(const string& name, const string& pos)
        : fullName(name), position(pos)
    {}

    void displayInfo() {
        cout << "ФИО: " << fullName << "\n"
            << "Должность: " << position << "\n";
    }
};

class FirstDepartment {
protected:
    string fullName;
    string address;
    string maritalStatus;
    string phoneNumbers;
    string passportData;
public:
    FirstDepartment(const string& name, const string& addr, const string& as, const string& phoneN, const string& passport)
        : fullName(name), address(addr), maritalStatus(as), phoneNumbers(phoneN), passportData(passport)
    {}

    void displayInfo() {
        cout << "ФИО: " << fullName << "\n"
            << "Паспортные данные: " << passportData << "\n"
            << "Адрес: " << address << "\n"
            << "Телефоны: " << phoneNumbers << "\n"
            << "Семейное положение: " << maritalStatus << "\n";
    }
};


class Integer {
public:
    Integer(int number)
    {
        value = number;
        cout << "Вызван конструктор" << endl;
    }
    void print() const {
        cout << "Значение: " << value << endl;
    }

    Integer(const Integer& other) {
        value = other.value;
        cout << "Вызов конструктора копирщика" << endl;
    }

private:
    int value;
};


class Students {
public:
    // Конструктор
    Students(const string& firstName, const string& lastName)
        : firstName(firstName), lastName(lastName) {}

    // Метод для добавления оценки
    void addGrade(int grade) {
        grades.push_back(grade);
    }

    // Метод для вывода данных студента
    void display() const {
        cout << "Студент: " << firstName << " " << lastName << endl;
        cout << "Оценки: ";
        for (int grade : grades) {
            cout << grade << " ";
        }
        cout << endl;
    }

    // Деструктор
    ~Students() {
        save();
    }

private:
    string firstName;          // Имя
    string lastName;           // Фамилия
    vector<int> grades;        // Оценки

    // Метод для сохранения данных в файл
    void save() const {
        ofstream outFile("students.txt", ios::app); // Открытие файла в режиме добавления
        if (outFile.is_open()) {
            outFile << firstName << " " << lastName << " ";
            for (int grade : grades) {
                outFile << grade << " ";
            }
            outFile << endl;
            outFile.close();
        }
        else {
            cerr << "Ошибка: Невозможно открыть файл для сохранения!" << endl;
        }
    }
};




class Counter {
public:
    // Конструктор
    Counter(const string& name) : name(name) {
        ++objectCount; // Увеличиваем статический счетчик при создании объекта
        cout << "Объект \"" << name << "\" создан. Всего объектов: " << objectCount << endl;
    }

    // Деструктор
    ~Counter() {
        --objectCount; // Уменьшаем статический счетчик при уничтожении объекта
        cout << "Объект \"" << name << "\" уничтожен. Всего объектов: " << objectCount << endl;
    }

    // Метод для получения текущего значения счетчика
    static int getObjectCount() {
        return objectCount;
    }

private:
    string name;                  // Уникальное имя объекта
    static int objectCount;       // Статическая переменная для подсчета объектов
};

// Определение статической переменной вне класса
int Counter::objectCount = 0;



void ex1() {
    /*Задаются два положительных целых числа, т.е.длина и ширина прмоугольника.Задача состоит в том, чтобы найти длину диагонали фигуры.
        Пользователь должен вводить длину и ширину прямоугольника.Программа должна выводить на консоль длину диагонали*/
    
    rectangle rectangle_1;
    rectangle_1.set_sides(3, 4);
    cout << "Диагональ четырёхугольника со сторонами " << rectangle_1.info() << " равна: " << rectangle_1.find_diagonal() << endl;

    cout << endl << "________________________________________________________________________________________________________________________\n" << endl;
}

void ex2() {
    /* Постановка задачи : есть две переменных x и y, и есть функция Sum, которая складывает два числа.Обозначение «cout << » можно рассматривать как вариант функции printf.Создали класс Сумма(Summa) с помощью ключевого слова класс(class).Класс — это просто шаблон.
        Чтобы получить экземпляр класса используйте «Summa s; ».Функция Sum не требует указания параметров, она берет эти параметры из свойств класса.Ключевое слово public означает, что свойства и методы класса доступны вне класса.*/
    summa s;
    s.set_variables(3, 9);
    cout << s.printf();

    cout << endl << "________________________________________________________________________________________________________________________\n" << endl;
}

void ex3() {
    /*«Крестики - нолики».Постановка задачи : один студент решил написать класс для своей реализации игры «крестики - нолики».Игра ведётся на квадратном поле размера N×NN×N двумя игроками.Игроки должны составить KK крестиков или ноликов в ряд(по горизонтали, по вертикали или по диагонали).
        Класс должен уметь создавать квадратное поле заданных размеров, выполнять очередной ход в пустую клетку, а также проверять, не наступил ли выигрыш.Кроме того, должен быть оператор << , который печатает поле.
        Студент пока не реализовал проверку выигрыша по диагоналям.А ещё его программа почему - то «падает» при попытке напечатать поле.Помогите ему исправить и сдать программу.Вот код студента :*/
    size_t n, m;
    std::cin >> n >> m;
    TicTacToe game(n, m);
    size_t x, y;
    while (std::cin >> x >> y) {
        int curPlayer = game.GetCurrentPlayer();
        if (game.Set(x, y)) {
            std::cout << "Player #" << curPlayer << " wins!\n";
        }
    }
    std::cout << game;

    cout << endl << "________________________________________________________________________________________________________________________\n" << endl;
}

void ex4() {
    /*Постановка задачи.Придумайте 3 абстрактных класса, определите для каждого из них один из методов как чистый виртуальный и напишите код с примерами классов и объектов классов, входящих в абстрактный.Сделайте вывод на консоль.*/
    Cat murzik;
    murzik.make_sound();
    Man anatoly;
    anatoly.move();
    Rectangle_1 rect;
    rect.set_sides(3, 4);
    cout << rect.get_area();
    cout << "";

    cout << endl << "________________________________________________________________________________________________________________________\n" << endl;
}

void ex5() {
    /*Постановка задачи. Кадровой службе необходимо решить вопрос с доступом к определённым данным сотрудников для разных департаментов организации. У кадровой службы полный доступ ко всем данным сотрудника: ФИО, паспортные данные, должность оклад,  адрес, телефоны, семейное положение и т.д. ИТ службе нужны данные о ФИО и должности. Первый отдел (секретность) должен иметь доступ к ФИО, адресу, семейном положению, адресу, телефонам и паспортным данным.
Напишите программный код для этих служб предприятия используя известные Вам модификаторы доступа.
*/
    Employee it_1("Дмитрий Захаров Ренатович", "9876 543210", "IT Specialist", 60000,
        "Москва, ул. Каховская, д. 14", "+7 988 351 43 21", "не женат");
    ITDepartment Zaharov_it(it_1.ret_fullName(), it_1.ret_position());
    FirstDepartment Zaharov(it_1.ret_fullName(), it_1.ret_address(), it_1.ret_maritalStatus(), it_1.ret_phoneNumbers(), it_1.ret_passportData());
    it_1.printFullInfo();
    cout << endl;
    Zaharov_it.displayInfo();
    cout << endl;
    Zaharov.displayInfo();

    cout << endl << "________________________________________________________________________________________________________________________\n" << endl;
}

void ex6() {
    //Постановка задачи : Есть класс Integer, который представляет число :
    //Добавьте в него конструктор копирования.В функции main создайте один объект Integer и скопируйте его в другой.
    // Создаем первый объект
    Integer a(10);
    a.print();

    // Копируем первый объект во второй
    Integer b = a;
    b.print();

    cout << endl << "________________________________________________________________________________________________________________________\n" << endl;
}

void ex7() {
    //Постановка задачи.Есть класс учеников.Реализуйте для него функционал, который будет принимать имя и фамилию ученика, и сохранять эти значения в соответствующих переменных класса.Кроме того, после завершения работы с программой, все данные должны сохраняться, записываться в текстовый файл.Оценки каждого студента находятся в отдельной строке, имя и фамилии должны разделяться пробелами.После имени и фамилии ученика ставится еще один пробел, а затем перечисляются все его оценки.
    //Нужно также сохранять все оценки после того, как работа со студентом закончена.Для этого создайте деструктор класса Students, который будет вызывать метод save() перед уничтожением объекта.
    Students student1("Максим", "Комаров");
    student1.addGrade(85);
    student1.addGrade(90);
    student1.addGrade(78);

    student1.display();

    // Создаем еще одного студента
    Students student2("Яна", "Темерланова");
    student2.addGrade(92);
    student2.addGrade(88);

    student2.display();

    cout << endl << "________________________________________________________________________________________________________________________\n" << endl;
}

void ex8_9() {
    cout << "Иницилизируем объект счётчик:  " << Counter::getObjectCount() << endl;

    // Создаем объекты
    Counter obj1("Объект1");
    Counter obj2("Объект2");

    cout << "счётчик объекта: " << Counter::getObjectCount() << endl;

    {
        // Создаем объект в отдельной области видимости
        Counter obj3("Объект3");
        cout << "счётчик объекта: " << Counter::getObjectCount() << endl;
    } // obj3 уничтожается здесь

    cout << "счётчик объекта после уничтожения obj3: " << Counter::getObjectCount() << endl;

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
    ex6();
    ex7();
    ex8_9();
}

