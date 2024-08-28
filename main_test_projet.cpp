#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int k;
    cin >> k;

    stack<int> s1, s2;

    while (k--) {
        string s;
        cin >> s;

        if (s == "push") {
            int value;  // Изменено: Переименовал переменную k в value, чтобы избежать конфликта с внешней переменной k
            cin >> value;

            s1.push(value);

            // Добавляем элемент в s2 только если он меньше или равен текущему минимуму
            if (s2.empty() || value <= s2.top()) {
                s2.push(value);
            }

            // Исправлено: Теперь выводится "ok" после успешного добавления элемента
            cout << "ok" << endl;
        } 
        else if (s == "pop") {
            if (!s1.empty()) {
                if (s1.top() == s2.top()) {
                    s2.pop();
                }
                s1.pop();
                cout << "ok" << endl;  // Исправлено: Добавлено "ok" после успешного удаления элемента
            } else {
                cout << "error" << endl;  // Исправлено: Вывод "error" если стек пустой
            }
        } 
        else if (s == "min") {
            if (!s2.empty()) {
                cout << s2.top() << endl;  // Исправлено: Вывод минимального элемента
            } else {
                cout << "error" << endl;  // Исправлено: Вывод "error" если стек пустой
            }
        } 
        else if (s == "back") {
            if (!s1.empty()) {
                cout << s1.top() << endl;  // Исправлено: Вывод последнего элемента стека
            } else {
                cout << "error" << endl;  // Исправлено: Вывод "error" если стек пустой
            }
        } 
        else if (s == "size") {
            cout << s1.size() << endl;  // Исправлено: Всегда вывод размер стека
        } 
        else if (s == "clear") {
            while (!s1.empty()) {
                s1.pop();
            }
            while (!s2.empty()) {
                s2.pop();
            }
            cout << "ok" << endl;  // Исправлено: Вывод "ok" после успешной очистки стеков
        }
    }

    return 0;
}
