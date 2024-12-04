#include <iostream>
#include <string>
#include <Windows.h>
#include <limits>
using namespace std;

// Класс для обработки заказа
class Accept_order {
protected:
    int number_grams; // Поле в защищенной области
public:
    Accept_order(const int& qua) : number_grams(qua) {} // Конструктор
};

// Класс для создания торта
class Сreate_cake {
private:
    string color; // Цвет торта
    string taste; // Вкус торта
public:
    // Конструктор с параметрами
    Сreate_cake(const int& qua, const string& col, const string& tas)
        : color(col), taste(tas) {}

    // Методы для доступа к данным
    string getColor() const { return color; }
    string getTaste() const { return taste; }
};

// Класс для упаковки торта
class Сake_packer : public Сreate_cake, public Accept_order { // Наследуем от обоих классов
public:
    // Конструктор класса Сake_packer, который вызывает конструкторы базовых классов
    Сake_packer(const int& qua, const string& col, const string& tas)
        : Сreate_cake(qua, col, tas), Accept_order(qua) {}

    // Метод для упаковки торта
    void pack() {
        cout << "Упакованный торт:\n"
            << "Граммовка: " << number_grams << " грамм\n"
            << "Цвет: " << getColor() << "\n"
            << "Вкус: " << getTaste() << endl;
    }
};

// Базовый класс для мебели
class Мебель {
protected:
    double price;  // Цена мебели
public:
    Мебель(double p) : price(p) {} // Конструктор для инициализации цены

    virtual void displayInfo() const {
        cout << "Цена мебели: " << price << " руб." << endl;
    }
};

// Класс для стола
class Стол {
private:
    string material;  // Материал стола
public:
    Стол(const string& m) : material(m) {}

    void displayTableInfo() const {
        cout << "Материал стола: " << material << endl;
    }
};

// Класс для тумбочки
class Тумбочка {
private:
    int numDrawers;  // Количество ящиков в тумбочке
public:
    Тумбочка(int drawers) : numDrawers(drawers) {}

    void displayDrawerInfo() const {
        cout << "Количество ящиков: " << numDrawers << endl;
    }
};

// Класс для шкафа
class Шкаф {
private:
    int numShelves;  // Количество полок в шкафу
public:
    Шкаф(int shelves) : numShelves(shelves) {}

    void displayShelfInfo() const {
        cout << "Количество полок в шкафу: " << numShelves << endl;
    }
};

// Класс для стула
class Стул {
private:
    bool hasArmrests;  // Наличие подлокотников
public:
    Стул(bool armrests) : hasArmrests(armrests) {}

    void displayChairInfo() const {
        cout << "Наличие подлокотников: " << (hasArmrests ? "Да" : "Нет") << endl;
    }
};

// Класс для объединения всех типов мебели
class Мебель_собираемая : public Мебель, public Стол, public Тумбочка, public Шкаф, public Стул {
public:
    // Конструктор, который инициализирует все классы
    Мебель_собираемая(double p, const string& tableMaterial, int drawers, int shelves, bool armrests)
        : Мебель(p), Стол(tableMaterial), Тумбочка(drawers), Шкаф(shelves), Стул(armrests) {}

    // Метод для отображения полной информации о мебели
    void displayFullInfo() const {
        Мебель::displayInfo();
        displayTableInfo();
        displayDrawerInfo();
        displayShelfInfo();
        displayChairInfo();
    }
};

// Основной класс Мебель_2
class Мебель_2 {
protected:
    string manufacturer;  // Производитель
    double price;         // Цена
    string material;      // Материал

public:
    // Конструктор
    Мебель_2(const string& man, double p, const string& mat)
        : manufacturer(man), price(p), material(mat) {}

    // Геттеры
    string getManufacturer() const { return manufacturer; }
    double getPrice() const { return price; }
    string getMaterial() const { return material; }

    // Метод, который будет переопределен в производных классах
    virtual void displayManufacturer() const {
        cout << "Производитель: " << manufacturer << endl;
    }

    // Виртуальный метод для отображения общей информации
    virtual void displayInfo() const {
        displayManufacturer();
        cout << "Цена: " << price << " руб." << endl;
        cout << "Материал: " << material << endl;
    }
};

// Класс Шкаф_2, наследуемый от Мебель_2
class Шкаф_2 : public Мебель_2 {
private:
    double width;   // Ширина
    double depth;   // Глубина
    double height;  // Высота

public:
    // Конструкторы с разными параметрами
    Шкаф_2(const string& man, double p, const string& mat, double w, double d, double h)
        : Мебель_2(man, p, mat), width(w), depth(d), height(h) {}

    // Переопределение метода displayManufacturer
    void displayManufacturer() const override {
        cout << "Производитель шкафа: " << manufacturer << endl;
    }

    // Метод для отображения информации о шкафе
    void displayInfo() const override {
        Мебель_2::displayInfo();
        cout << "Ширина: " << width << " см" << endl;
        cout << "Глубина: " << depth << " см" << endl;
        cout << "Высота: " << height << " см" << endl;
    }
};

// Класс Стол_2, наследуемый от Мебель_2
class Стол_2 : public Мебель_2 {
private:
    int numDrawers;        // Количество ящиков
    double workSurfaceArea; // Площадь рабочей поверхности

public:
    // Конструкторы с разными параметрами
    Стол_2(const string& man, double p, const string& mat, int drawers, double area)
        : Мебель_2(man, p, mat), numDrawers(drawers), workSurfaceArea(area) {}

    // Переопределение метода displayManufacturer
    void displayManufacturer() const override {
        cout << "Производитель стола: " << manufacturer << endl;
    }

    // Метод для отображения информации о столе
    void displayInfo() const override {
        Мебель_2::displayInfo();
        cout << "Количество ящиков: " << numDrawers << endl;
        cout << "Площадь рабочей поверхности: " << workSurfaceArea << " кв.см" << endl;
    }
};

// Класс Стул_2, наследуемый от Мебель_2
class Стул_2 : public Мебель_2 {
private:
    double backrestHeight; // Высота спинки

public:
    // Конструкторы с разными параметрами
    Стул_2(const string& man, double p, const string& mat, double backHeight)
        : Мебель_2(man, p, mat), backrestHeight(backHeight) {}

    // Переопределение метода displayManufacturer
    void displayManufacturer() const override {
        cout << "Производитель стула: " << manufacturer << endl;
    }

    // Метод для отображения информации о стуле
    void displayInfo() const override {
        Мебель_2::displayInfo();
        cout << "Высота спинки: " << backrestHeight << " см" << endl;
    }
};

// Класс для вывода информации о мебели
class WriterInfo_2 {
public:
    // Метод для отображения информации о любом типе мебели
    static void write(const Мебель_2& furniture) {
        furniture.displayInfo();
        cout << "---------------------------------" << endl;
    }
};

// Функция для ввода положительных чисел
double getPositiveDoubleInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < 0) {
            cin.clear(); // Очищаем флаг ошибки ввода
            cin.ignore(1000, '\n'); // Игнорируем остаток ввода
            cout << "Ошибка! Введите положительное число." << endl;
        }
        else {
            break;
        }
    }
    return value;
}

// Функция для ввода положительных целых чисел
int getPositiveIntInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < 0) {
            cin.clear(); // Очищаем флаг ошибки ввода
            cin.ignore(1000, '\n'); // Игнорируем остаток ввода
            cout << "Ошибка! Введите положительное число." << endl;
        }
        else {
            break;
        }
    }
    return value;
}




void ex1() {
    /*Упаковщик торта
    1.Создать торт
    2.украсить торт
    3.упаковать торт
    */
    cout << "Задание №1" << endl;
    int number_grams; // Количество грамм
    string color; // Цвет торта
    string taste; // Вкус торта
    cout << "Введите количество грамм: ";
    cin >> number_grams;
    cout << "Введите цвет торта: ";
    cin >> color;
    cout << "Введите вкус торта: ";
    cin >> taste;
    cout << endl;
    // Создаем упаковщика и передаем параметры для торта
    Сake_packer packer(number_grams, color, taste);
    // Упаковываем торт
    packer.pack();
    cout << endl << "________________________________________________________________________________________________________________________\n" << endl;
}

void ex2() {
    cout << "Задание №2" << endl;
    double price; // Цена
    string material; // Цвет торта
    int Number_boxes; // Количество ящиков
    int Number_shelves_closet;// Количество ящиков
    string armrests;// Наличие подлокотников
    cout << "Введите цену: ";
    cin >> price;
    if (price > 0) {
        cout << "Введите материал: ";
        cin >> material;
        cout << "Введите количество ящиков: ";
        cin >> Number_boxes;
        if (Number_boxes > 0) {
            cout << "Введите количество полок в шкафу: ";
            cin >> Number_shelves_closet;
            if (Number_boxes > 0) {
                cout << "Наличие подлокотников \"да или нет\": ";
                cin >> armrests;
                cout << endl;
                // Создаем мебель с конкретными характеристиками
                if ((armrests == "да") or (armrests == "Да")) {
                    Мебель_собираемая myFurniture(price, material, Number_boxes, Number_shelves_closet, true);
                    myFurniture.displayFullInfo();
                }
                else if ((armrests == "нет") or (armrests == "Нет")) {
                    Мебель_собираемая myFurniture(price, material, Number_boxes, Number_shelves_closet, false);
                    myFurniture.displayFullInfo();
                }
                else {
                    cout << "Введены некоректные данные";
                }
            }
            else {
                cout << "Введите количество полок в шкафу: ";
            }
        }
        else {
            cout << "Введены некоректные данные";
        }
    }
    else {
        cout << "Введены некоректные данные";
    }
    cout << endl << "________________________________________________________________________________________________________________________\n" << endl;
}
void ex3() {
    cout << "Задание №3" << endl;
    string manufacturer, material;

    // Ввод данных
    cout << "Введите производителя мебели: ";
    getline(cin, manufacturer); // Ввод строки с названием производителя

    cout << "Введите материал мебели: ";
    getline(cin, material); // Ввод материала мебели

    double price = getPositiveDoubleInput("Введите цену мебели: ");
    double width = getPositiveDoubleInput("Введите ширину шкафа: ");
    double depth = getPositiveDoubleInput("Введите глубину шкафа: ");
    double height = getPositiveDoubleInput("Введите высоту шкафа: ");

    // Создаем объекты мебели
    Шкаф_2 cabinet(manufacturer, price, material, width, depth, height);

    // Создаем другие объекты мебели
    int numDrawers = getPositiveIntInput("Введите количество ящиков стола: ");
    double workSurfaceArea = getPositiveDoubleInput("Введите площадь рабочей поверхности стола (кв.см): ");
    Стол_2 table(manufacturer, price, material, numDrawers, workSurfaceArea);

    double backrestHeight = getPositiveDoubleInput("Введите высоту спинки стула (см): ");
    Стул_2 chair(manufacturer, price, material, backrestHeight);

    // Используем WriterInfo для отображения информации о мебели
    WriterInfo_2::write(cabinet);
    WriterInfo_2::write(table);
    WriterInfo_2::write(chair);
    cout << endl << "________________________________________________________________________________________________________________________\n" << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ex1();
    ex2();
    ex3();
}

