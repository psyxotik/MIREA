#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>


int main() {
    // Напишите программу, которая считает количество гласных во введенной пользователем строке
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);
    int vowelCount = 0;
    for (char c : input) {
        // Проверяем, является ли символ гласной
        if (c == 'а' || c == 'е' || c == 'ё' || c == 'и' || c == 'о' || c == 'у' || c == 'ы' || c == 'э' || c == 'ю' || c == 'я' ||
            c == 'А' || c == 'Е' || c == 'Ё' || c == 'И' || c == 'О' || c == 'У' || c == 'Ы' || c == 'Э' || c == 'Ю' || c == 'Я') {
            vowelCount++;
        }
    }

    std::cout << "Количество гласных: " << vowelCount << std::endl;

    std::cout << "________________________________________________________________________________________________________________________\n" << std::endl;
    //Напишите программу, которая определяет, является ли введенное с клавиатуры слово палиндромом (читается одинаково в обе стороны): racecar, шалаш, комок, hannah.
    std::string input_0;
    std::cout << "Введите слово: ";
    std::getline(std::cin, input_0);

    // Удаляем пробелы и приводим к нижнему регистру
    std::string cleanedInput;
    for (char c : input_0) {
        if (c != ' ') {
            cleanedInput += tolower(c);
        }
    }

    // Проверяем, является ли слово палиндромом
    bool isPalindrome = true;
    int len = cleanedInput.length();
    for (int i = 0; i < len / 2; i++) {
        if (cleanedInput[i] != cleanedInput[len - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        std::cout << "Слово является палиндромом." << std::endl;
    }
    else {
        std::cout << "Слово не является палиндромом." << std::endl;
    }

    std::cout << "________________________________________________________________________________________________________________________\n" << std::endl;
    //Напишите программу, которая шифрует введенную строку шифром Цезаря.Сдвиг также вводится пользователем.
    std::string input_1;
    int shift;

    std::cout << "Введите строку для шифрования: ";
    std::getline(std::cin, input_1);

    std::cout << "Введите сдвиг: ";
    std::cin >> shift;

    std::string encrypted;
    for (char c : input_1) {
        if (c >= 'а' && c <= 'я') {
            c = (c - 'а' + shift) % 32 + 'а';
        }
        else if (c >= 'А' && c <= 'Я') {
            c = (c - 'А' + shift) % 32 + 'А';
        }
        encrypted += c;
    }

    std::cout << "Зашифрованная строка: " << encrypted << std::endl;

    std::cout << "________________________________________________________________________________________________________________________\n" << std::endl;
    //Предположите, что выведет программа ниже. Перепечатайте программу и узнайте правильный ответ.
    int number{ 5 };
    int& refnumber{ number };
    int& refnumbers{ number };
    int& renumber{ refnumbers };
    renumber = 90;
    number = 50;
    refnumber = 50;
    refnumbers = 91;
    if (refnumber > refnumbers) {
        std::cout << number << std::endl;
    }
    else if (number < refnumber) {
        std::cout << refnumber << std::endl;
    }
    else { std::cout << number << refnumber << refnumbers << renumber << std::endl; }

    std::cout << "________________________________________________________________________________________________________________________\n" << std::endl;
    //Напишите программу, которая выводит транспонированную матрицу 3x3.
    //Транспонированная матрица — это матрица, полученная из исходной путём замены строк на столбцы.

    int matrix[3][3];
    std::cout << "Введите элементы матрицы 3x3:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> matrix[i][j];
        }
    }

    // Выводим транспонированную матрицу
    std::cout << "Транспонированная матрица:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix[j][i] << " "; // Меняем местами индексы
        }
        std::cout << std::endl;
    }

    std::cout << "________________________________________________________________________________________________________________________\n" << std::endl;
    //Напишите программу, которая копирует многомерный массив в другой многомерный массив такого же размера.
    //Почему нельзя просто написать присвоение A = B ?
    int sourceMatrix[3][3];
    std::cout << "Введите элементы исходной матрицы 3x3:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> sourceMatrix[i][j];
        }
    }

    // Копируем исходный массив в новый массив
    int copiedMatrix[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            copiedMatrix[i][j] = sourceMatrix[i][j]; // Копируем элементы
        }
    }

    // Выводим скопированную матрицу
    std::cout << "Скопированная матрица:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << copiedMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "________________________________________________________________________________________________________________________\n" << std::endl;
    //Напишите программу, которая заполняет массив 4х4 единицами в шахматном порядке.
    int chessboard[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            // Заполняем единицами в шахматном порядке
            chessboard[i][j] = (i + j) % 2; // 1 для черных клеток, 0 для белых
        }
    }

    // Выводим массив
    std::cout << "Массив 4x4 в шахматном порядке:" << std::endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << chessboard[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "________________________________________________________________________________________________________________________\n" << std::endl;
    //Напишите программу, которая сортирует многомерный массив 3х3 по возрастанию.
    int matrix1[3][3];
    std::cout << "Введите элементы матрицы 3x3:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> matrix1[i][j];
        }
    }

    // Сортируем элементы матрицы по возрастанию
    int temp[9]; // Временный одномерный массив для хранения элементов
    int index = 0;

    // Копируем элементы матрицы в одномерный массив
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[index++] = matrix1[i][j];
        }
    }

    // Сортируем одномерный массив
    std::sort(temp, temp + 9);

    // Заполняем отсортированными элементами исходную матрицу
    index = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix1[i][j] = temp[index++];
        }
    }

    // Выводим отсортированную матрицу
    std::cout << "Отсортированная матрица:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix1[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;

}
