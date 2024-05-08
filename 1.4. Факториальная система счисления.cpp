#include <iostream>
#include <vector>

using namespace std;

//Факториальная система счисления

//Число N, записанное в факториальной системе счисления,
//означает, что N = a1 · 1! + a2 · 2! + a3 · 3! + ... + an-1 · (n-1)! + an · n!
//Напишите функцию, которая принимает натуральное число и печатает на экран его
//представление в факториальной системе счисления. Разряды отделяйте друг от друга точками.

vector<int> factorial(int n) 
{
    vector<int> result;
    int factorial = 1;
    while (n > 0) 
    {
        result.push_back(n % (factorial + 1));
        n /= (factorial + 1);
        factorial++;
    }
    return result;
}

void printfactorial(int n) 
{
    vector<int> print = factorial(n);
    for (int i = print.size() - 1; i >= 0; i--) 
    {
        cout << print[i];
        if (i != 0)
            cout << ".";
    }
}

int main() {
    int num = 6;
    cout << "Представление числа " << num << " в факториальной системе счисления: ";
    printfactorial(num);
}
