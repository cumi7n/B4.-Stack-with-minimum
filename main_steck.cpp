#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int m;
    cin >> m;

    stack<int> s1 , s2;

    while (m--)
    {
        string command;
        cin >> command;

        // Добавление элемента в массивы
        if (command == "push"){
            int k;
            cin >> k;

            s1.push(k);

            if(s2.empty() || k <= s2.top()){
                s2.push(k);
            }
            cout << "ok" << endl;

        }
    

        // Удаление элементов из массива 

        if (command == "pop"){
            if (s1.empty()){
                cout << "error"<< endl;

            }
            else {
                cout << s1.top() << endl;
                if (s1.top() == s2.top()){
                    s2.pop();
                }
                s1.pop();
            }
        }

        // Вывод последнего элемена списка 

        if (command == "back"){
            if (s1.empty()){
                cout << "error" << endl;
            }
            else{
                cout << s1.top() << endl;
            }
        }
        
        // Минимальное значение в стеке 

        if (command == "min"){
            if (s1.empty()){
                cout << "error" << endl;
            }
            else{
                cout << s2.top() << endl;
            }
        }

        // Каличество элементов || Размер стека 

        if (command == "size"){
            cout << s1.size() << endl;
        }

        // Удаление всего стека 

        if (command == "clear"){
            while (!s1.empty())
            {
                s1.pop();
            }
            while (!s2.empty())
            {
                s2.pop();
            }
            cout << "ok" << endl;
            
            
         }




        
    }
    return 0;
    
}