#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    cout << "[TEST] Проверка математической логики (Вариант 19)...\n";
    
    // Подготовка входных данных
    ofstream inFile("in_data.txt");
    inFile << "1\n4\n7\n10\n5\n40\n300\n2\n-1\n2\n"; // Массив X
    inFile << "2\n45\n-1000\n24\n5\n6\n53\n2\n54\n35\n"; // Массив Y
    inFile.close();

    // Выполнение бинарника
    int exitCode = system("../usr/bin/array_calc < in_data.txt > out_data.txt");
    if (exitCode != 0) {
        cerr << "[FAIL] Программа завершилась с ошибкой!\n";
        return 1;
    }

    // Анализ результата
    ifstream outFile("out_data.txt");
    string buffer, resultText;
    while (getline(outFile, buffer)) {
        resultText += buffer + " ";
    }
    outFile.close();

    if (resultText.find("300, -1000") != string::npos) {
        cout << "[SUCCESS] Логика работает корректно. Искомые числа найдены.\n";
        return 0; // 0 означает успешное прохождение теста для CI/CD
    }
    
    cerr << "[FAIL] Ожидаемый результат не найден в выводе!\n";
    return 1;
}