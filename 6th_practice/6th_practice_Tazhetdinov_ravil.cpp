#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <Windows.h>

// Класс для рисования квадрата
class Square {
public:
    Square(float x, float y, float size) {
        // Инициализация прямоугольника как квадрата


    }

    // Метод для рисования квадрата на окне
    void draw() {

    }
};


// Класс для рисования круга
class Circle {
public:
    Circle(float x, float y, float radius) {
        // Инициализация круга

    }

    // Метод для рисования круга на окне
    void draw() {

    }
};


class LegalAct {
protected:
    std::string name;  // Название НПА
    int level;         // Уровень НПА в иерархии

public:
    LegalAct(const std::string& name, int level) : name(name), level(level) {}

    // Виртуальный метод для отображения информации о НПА
    virtual void display() const {
        std::cout << "Уровень " << level << ": " << name << std::endl;
    }

    // Виртуальный деструктор
    virtual ~LegalAct() = default;
};

// Класс для Конституции РФ
class Constitution : public LegalAct {
public:
    Constitution() : LegalAct("Конституция РФ", 1) {}
};

// Класс для федеральных законов
class FederalLaw : public LegalAct {
public:
    FederalLaw(const std::string& name) : LegalAct(name, 2) {}
};

// Класс для указов Президента
class PresidentialDecree : public LegalAct {
public:
    PresidentialDecree(const std::string& name) : LegalAct(name, 3) {}
};

// Класс для постановлений Правительства
class GovernmentDecree : public LegalAct {
public:
    GovernmentDecree(const std::string& name) : LegalAct(name, 4) {}
};

// Класс для подзаконных актов
class SubordinateAct : public LegalAct {
public:
    SubordinateAct(const std::string& name) : LegalAct(name, 5) {}
};


class Revolution {
protected:
    std::string name; // Название революции

public:
    Revolution(const std::string& name) : name(name) {}

    // Виртуальный метод для отображения общего описания революции
    virtual void displayDescription() const {
        std::cout << "Революция: " << name << std::endl;
    }

    // Виртуальный метод для отображения лозунгов
    virtual void displaySlogans() const = 0;

    // Виртуальный метод для описания событий
    virtual void displayKeyEvents() const = 0;

    // Виртуальный деструктор
    virtual ~Revolution() = default;
};

// Класс для Великой французской революции
class FrenchRevolution : public Revolution {
public:
    FrenchRevolution() : Revolution("Великая французская революция") {}

    void displayDescription() const override {
        std::cout << "Описание: революция, начавшаяся во Франции в 1789 году, "
            "направленная на свержение монархии и установление республики."
            << std::endl;
    }

    void displaySlogans() const override {
        std::cout << "Лозунги: Свобода! Равенство! Братство!" << std::endl;
    }

    void displayKeyEvents() const override {
        std::cout << "Ключевые события:\n"
            << "- Казнь короля Людовика XVI и королевы Марии Антуанетты\n"
            << "- Созыв Учредительного собрания\n"
            << "- Гибель революционеров: Робеспьер, Марат, Дантон\n"
            << "- Приход к власти Наполеона Бонапарта\n";
    }
};

// Класс для Великой Октябрьской социалистической революции
class OctoberRevolution : public Revolution {
public:
    OctoberRevolution() : Revolution("Великая Октябрьская социалистическая революция") {}

    void displayDescription() const override {
        std::cout << "Описание: революция, произошедшая в России в 1917 году, "
            "с целью свержения Временного правительства и установления Советской власти."
            << std::endl;
    }

    void displaySlogans() const override {
        std::cout << "Лозунги:«Долой войну!», «Долой самодержавие!», «Хлеба!», «Вся власть — Советам»" << std::endl;
    }

    void displayKeyEvents() const override {
        std::cout << "Ключевые события:\n"
            << "- Казнь царя Николая II и семьи\n"
            << "- Созыв Учредительного собрания\n"
            << "- Гибель революционеров: Свердлов, Урицкий, Дзержинский\n"
            << "- Приход к власти Ленина\n";
    }
};

// Базовый класс Transport
class Transport {
protected:
    std::string name;    // Название транспортного средства
    int maxSpeed;        // Максимальная скорость

public:
    // Конструктор базового класса
    Transport(const std::string& name, int maxSpeed)
        : name(name), maxSpeed(maxSpeed) {}

    // Метод для отображения общей информации
    virtual void displayInfo() const {
        std::cout << "Транспортное средство: " << name << "\n";
        std::cout << "Максимальная скорость: " << maxSpeed << " км/ч\n";
    }

    // Виртуальный деструктор
    virtual ~Transport() = default;
};

// Класс Car (наследуется от Transport)
class Car : public Transport {
private:
    int doors; // Количество дверей

public:
    // Конструктор для автомобиля
    Car(const std::string& name, int maxSpeed, int doors)
        : Transport(name, maxSpeed), doors(doors) {}

    // Переопределение метода displayInfo
    void displayInfo() const override {
        Transport::displayInfo();
        std::cout << "Количество дверей: " << doors << "\n";
    }
};

// Класс Bicycle (наследуется от Transport)
class Bicycle : public Transport {
private:
    bool hasGears; // Наличие передач

public:
    // Конструктор для велосипеда
    Bicycle(const std::string& name, int maxSpeed, bool hasGears)
        : Transport(name, maxSpeed), hasGears(hasGears) {}

    // Переопределение метода displayInfo
    void displayInfo() const override {
        Transport::displayInfo();
        std::cout << "Наличие передач: " << (hasGears ? "Да" : "Нет") << "\n";
    }
};


class Encryptor {
private:
    std::string cryptoKey; // Криптографический ключ

public:
    // Конструктор принимает криптографический ключ
    Encryptor(const std::string& key) : cryptoKey(key) {}

    // Метод для шифрования текста
    std::string encrypt(const std::string& plainText) {
        std::string encryptedText = plainText;
        for (size_t i = 0; i < plainText.size(); ++i) {
            encryptedText[i] = plainText[i] ^ cryptoKey[i % cryptoKey.size()];
        }
        return encryptedText;
    }

    // Метод для дешифрования текста
    std::string decrypt(const std::string& encryptedText) {
        std::string decryptedText = encryptedText;
        for (size_t i = 0; i < encryptedText.size(); ++i) {
            decryptedText[i] = encryptedText[i] ^ cryptoKey[i % cryptoKey.size()];
        }
        return decryptedText;
    }
};

// Функция для отображения информации о революциях
void displayRevolutions(const std::vector<std::shared_ptr<Revolution>>& revolutions) {
    for (const auto& revolution : revolutions) {
        revolution->displayDescription();
        revolution->displaySlogans();
        revolution->displayKeyEvents();
        std::cout << "---------------------------------\n";
    }
}

// Функция для вывода иерархии
void displayHierarchy(const std::vector<std::shared_ptr<LegalAct>>& acts) {
    std::cout << "Иерархия нормативно-правовых актов:" << std::endl;
    for (const auto& act : acts) {
        act->display();
    }
}


// Функция для рисования логотипа
void drawLogo() {
    // Создаем квадрат
    Square square(100, 100, 100);
    square.draw();

    // Создаем круг
    Circle circle(150, 150, 50);
    circle.draw();
}

template <typename T>
T findMax(const T& a, const T& b) {
    return (a > b) ? a : b; // Возвращаем большее из двух значений
}



void ex_1() {
    std::cout << "Задание №1 \nПредположим, что нам нужно нарисовать на форме логотип, который состоит из квадрата и круга.\
Предположим, что у нас уже есть классы рисования квадрата и круга. Как нарисовать логотип?" << std::endl;
    drawLogo();

    std::cout << "----------------------------------------------" << std::endl;
}

void ex_2() {
    std::cout << "Задание №2 \n  реализуйте принципы наследования и полиморфизма для иерархии нормативно-правовых актов (далее НПА) федерального уровня в РФ (см. рис.1), \
выведите в консоль схему иерархии нормативно-правовых актов и дайте письменные пояснения к коду. Затем проверьте корректность работы кода на трех разных с т.зр. иерархии НПА РФ по своему выбору." << std::endl;
    auto constitution = std::make_shared<Constitution>();
    auto federalLaw = std::make_shared<FederalLaw>("Федеральный закон о бюджете");
    auto presidentialDecree = std::make_shared<PresidentialDecree>("Указ Президента о праздниках");
    auto governmentDecree = std::make_shared<GovernmentDecree>("Постановление Правительства о мерах безопасности");
    auto subordinateAct = std::make_shared<SubordinateAct>("Инструкция Министерства внутренних дел");

    // Собираем все акты в список
    std::vector<std::shared_ptr<LegalAct>> acts = {
        constitution, federalLaw, presidentialDecree, governmentDecree, subordinateAct
    };

    // Отображаем иерархию
    displayHierarchy(acts);
    std::cout << "----------------------------------------------" << std::endl;
}

void ex_3() {
    auto frenchRevolution = std::make_shared<FrenchRevolution>();
    auto octoberRevolution = std::make_shared<OctoberRevolution>();

    // Список революций
    std::vector<std::shared_ptr<Revolution>> revolutions = {
        frenchRevolution, octoberRevolution };

    // Отображаем информацию о революциях
    displayRevolutions(revolutions);
    
}
void ex_4() {
    // С числами (int)
    int num1 = 42, num2 = 87;
    std::cout << "Максимум среди " << num1 << " и " << num2 << ": " << findMax(num1, num2) << std::endl;

    // С числами с плавающей запятой (double)
    double d1 = 3.14, d2 = 2.71;
    std::cout << "Максимум среди " << d1 << " и " << d2 << ": " << findMax(d1, d2) << std::endl;

    // Со строками (std::string)
    std::string str1 = "Apple", str2 = "Banana";
    std::cout << "Максимум среди \"" << str1 << "\" и \"" << str2 << "\": " << findMax(str1, str2) << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}

void ex_5() {
    // Создаем объекты разных транспортных средств
    Car car("Легковой автомобиль", 180, 4);
    Bicycle bicycle("Горный велосипед", 45, true);

    // Отображаем информацию о транспортных средствах
    std::cout << "Информация о транспортных средствах:\n\n";

    std::cout << "1. Автомобиль:\n";
    car.displayInfo();
    std::cout << "\n";

    std::cout << "2. Велосипед:\n";
    bicycle.displayInfo();
    std::cout << "\n";
    std::cout << "----------------------------------------------" << std::endl;
}

void ex_6() {
    std::string key = "mySecretKey";

    // Создаем объект класса Encryptor с заданным ключом
    Encryptor encryptor(key);

    // Исходный текст для шифрования
    std::string originalText = "Hello, World!";
    std::cout << "Исходный текст: " << originalText << std::endl;

    // Шифруем текст
    std::string encryptedText = encryptor.encrypt(originalText);
    std::cout << "Зашифрованный текст: " << encryptedText << std::endl;

    // Расшифровываем текст
    std::string decryptedText = encryptor.decrypt(encryptedText);
    std::cout << "Расшифрованный текст: " << decryptedText << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}

// Основная функция программы
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ex_1();
    ex_2();
    ex_3();
    ex_4();
    ex_5();
    ex_6();
    return 0;
}