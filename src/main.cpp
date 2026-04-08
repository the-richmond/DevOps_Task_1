#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Метод проверки ввода (чтение строки + конвертация)
int getValidInteger(const string& promptText) {
    string rawInput;
    while (true) {
        cout << promptText;
        getline(cin, rawInput);

        // Проверка на пустой ввод (если просто нажали Enter или ввели пробелы)
        if (rawInput.empty() || rawInput.find_first_not_of(" \t\r\n") == string::npos) {
            cout << "[!] Ошибка: Пустой ввод. Пожалуйста, введите целое число.\n";
            continue;
        }
        
        try {
            size_t pos;
            int parsedNumber = stoi(rawInput, &pos);
            // Убеждаемся, что строка полностью состоит из цифр (нет мусора вроде "123abc")
            if (pos == rawInput.length()) {
                return parsedNumber;
            }
        } catch (const invalid_argument&) {
            // Ошибка конвертации (ввели буквы)
        } catch (const out_of_range&) {
            cout << "[!] Ошибка: Введенное число выходит за допустимые пределы.\n";
            continue;
        }
        cout << "[!] Ошибка: Некорректный ввод. Пожалуйста, введите целое число.\n";
    }
}

// Функция заполнения вектора
void fillVector(vector<int>& vec, const string& name, int count) {
    cout << "\n--- Заполнение массива " << name << " (" << count << " элементов) ---\n";
    for (int i = 0; i < count; ++i) {
        vec.push_back(getValidInteger("Ввод " + name + "[" + to_string(i) + "]: "));
    }
}

// Функция печати вектора
void displayVector(const vector<int>& vec, const string& name) {
    cout << name << " = { ";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i < vec.size() - 1 ? ", " : "");
    }
    cout << " }\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "***************************************************\n";
    cout << "* Лабораторная работа 1. Обработка массивов       *\n";
    cout << "***************************************************\n";

    const int ELEMENTS_COUNT = 10;
    vector<int> arrayX;
    vector<int> arrayY;
    vector<int> arrayZ;

    // Ввод данных
    fillVector(arrayX, "X", ELEMENTS_COUNT);
    fillVector(arrayY, "Y", ELEMENTS_COUNT);

    // Использование стандартных алгоритмов C++ для поиска экстремумов
    int minValX = *min_element(arrayX.begin(), arrayX.end());
    int maxValY = *max_element(arrayY.begin(), arrayY.end());

    cout << "\n=> Минимальное значение в X: " << minValX << "\n";
    cout << "=> Максимальное значение в Y: " << maxValY << "\n\n";

    // Сборка массива Z по условию варианта
    for (int currentX : arrayX) {
        if (currentX > maxValY) arrayZ.push_back(currentX);
    }
    for (int currentY : arrayY) {
        if (currentY < minValX) arrayZ.push_back(currentY);
    }

    // Вывод результатов
    cout << "--- ИТОГОВЫЕ ДАННЫЕ ---\n";
    displayVector(arrayX, "Массив X");
    displayVector(arrayY, "Массив Y");
    
    if (arrayZ.empty()) {
        cout << "Массив Z пуст (нет элементов, удовлетворяющих условиям).\n";
    } else {
        displayVector(arrayZ, "Результирующий массив Z");
    }

    return 0;
}