#include <iostream>
#include <string>
#include <stack>

using namespace std;

//Задача на использование адаптеров. На вход подаётся скобочная последовательность — строка, 
//которая состоит из скобок ()[]{}. Вам нужно определить, является ли она правильной. 
//В правильной скобочной последовательности каждой открывающей скобке соответствует закрывающая 
//и пары скобок корректно вложены друг в друга.

bool Right(const string& brackets) 
{
    stack<char> stack;

    for (const auto& bracket : brackets) 
    {
        if (bracket == '(' or bracket == '[' or bracket == '{') 
            stack.push(bracket);
        else {
            if (stack.empty()) 
                return false;
 
            char top = stack.top();
            stack.pop();

            if ((bracket == ')' and top != '(') or (bracket == ']' and top != '[') or (bracket == '}' and top != '{')) 
                return false;
        }
    }

    return stack.empty();
}

int main() {
    string example = "(){[]}{[()]}";
  
    cout << "Последовательность правильная? " << boolalpha << Right(example);
}