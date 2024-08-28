#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int k;
    cin >> k;

    stack<int> s1, s2;

    while (k--) {
        string command;
        cin >> command;

        // Добавление элементов     
        if (command == "push") {
            int val;
            cin >> val;

            s1.push(val);

            // Добавляем элемент в s2 только если он меньше или равен текущему минимуму
            if (s2.empty() || val <= s2.top()) {
                s2.push(val);
            }

            // Исправлено: теперь всегда выводим "ok" после успешного добавления элемента
            cout << "ok" << endl;
        } 

        // Удаление
        else if (command == "pop") {
            if (!s1.empty()) {
                // Исправлено: теперь правильно удаляется элемент из s2, если он равен верхнему элементу s1
                if (s1.top() == s2.top()) {
                    s2.pop();
                }
                s1.pop();
                cout << "ok" << endl;  // Исправлено: выводим "ok" после успешного удаления элемента
            } else {
                cout << "error" << endl;  // Исправлено: выводим "error", если стек пустой
            }
        }

        // Минимальное значение
        else if (command == "min") {
            if (!s2.empty()) {
                cout << s2.top() << endl;
            } else {
                cout << "error" << endl;
            }
        }

        // Последний элемент без удаления
        else if (command == "back") {
            if (!s1.empty()) {
                cout << s1.top() << endl;
            } else {
                cout << "error" << endl;
            }
        }

        // Размер стека
        else if (command == "size") {
            cout << s1.size() << endl;  // Исправлено: всегда выводим размер стека
        }

        // Очистка стека
        else if (command == "clear") {
            while (!s1.empty()) {
                s1.pop();
            }
            while (!s2.empty()) {
                s2.pop();
            }
            cout << "ok" << endl;  // Исправлено: добавлен endl для корректного форматирования
        }
    }

    return 0;
}
