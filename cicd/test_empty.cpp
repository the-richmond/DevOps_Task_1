#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    cout << "[TEST] Проверка работы с пустым результатом...\n";
    
    ofstream inFile("in_data.txt");
    for(int i=1; i<=10; i++) inFile << i << "\n";
    for(int i=100; i<=109; i++) inFile << i << "\n";
    inFile.close();

    system("../usr/bin/array_calc < in_data.txt > out_data.txt");

    ifstream outFile("out_data.txt");
    string buffer, resultText;
    while (getline(outFile, buffer)) resultText += buffer;
    outFile.close();

    if (resultText.find("Массив Z пуст") != string::npos) {
        cout << "[SUCCESS] Пустой массив корректно идентифицирован.\n";
        return 0;
    }
    
    cerr << "[FAIL] Ошибка обработки пустого массива Z!\n";
    return 1;
}