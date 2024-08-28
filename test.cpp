#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int m; // количество команд
    cin >> m;

    stack<int> s1, s2;

    while (m--) {
        string command;
        cin >> command;

        if (command == "push") {
            int n;
            cin >> n;
            s1.push(n);
            if (s2.empty() || n <= s2.top()) {
                s2.push(n);
            }
            cout << "ok" << endl;
        } else if (command == "pop") {
            if (s1.empty()) {
                cout << "error" << endl;
            } else {
                if (s1.top() == s2.top()) {
                    s2.pop();
                }
                cout << s1.top() << endl;
                s1.pop();
            }
        } else if (command == "back") {
            if (s1.empty()) {
                cout << "error" << endl;
            } else {
                cout << s1.top() << endl;
            }
        } else if (command == "min") {
            if (s2.empty()) {
                cout << "error" << endl;
            } else {
                cout << s2.top() << endl;
            }
        } else if (command == "size") {
            cout << s1.size() << endl;
        } else if (command == "clear") {
            while (!s1.empty()) s1.pop();
            while (!s2.empty()) s2.pop();
            cout << "ok" << endl;
        }
    }

    return 0;
}
