#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    cout << "[TEST] Проверка защиты от некорректного ввода...\n";
    
    ofstream inFile("in_data.txt");
    inFile << "\n\nbad_string\n123x\n"; 
    for(int i=0; i<20; i++) inFile << i << "\n";
    inFile.close();

    system("../usr/bin/array_calc < in_data.txt > out_data.txt");

    ifstream outFile("out_data.txt");
    string buffer, resultText;
    while (getline(outFile, buffer)) resultText += buffer;
    outFile.close();

    bool hasEmptyError = resultText.find("Пустой ввод") != string::npos;
    bool hasTypeError = resultText.find("Некорректный ввод") != string::npos;

    if (hasEmptyError && hasTypeError) {
        cout << "[SUCCESS] Защита от дурака отработала штатно.\n";
        return 0;
    }
    
    cerr << "[FAIL] Исключения не были пойманы!\n";
    return 1;
}