#include <iostream>
#include <unordered_set>

using namespace std;

//Счастливые числа

//Определим последовательность натуральных чисел рекурсивно: следующее число
//равно сумме квадратов цифр текущего числа. Если последовательность придёт к 1, то
//начальное число последовательности называется счастливым.
//Напишите функцию, проверяющую, является ли переданное ей натуральное число счастливым.

int sumsq(int n) 
{
    int sum = 0;
    while (n > 0) 
    {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

bool happy(int n, unordered_set<int>& ex) 
{
    if (n == 1)
        return true;
    if (ex.count(n))
        return false;
    ex.insert(n);
    int next = sumsq(n);
    return happy(next, ex);
}

int main() 
{
    int num = 19;
    unordered_set<int> ex;
    if (happy(num, ex))
        cout << "Число " << num << " - счастливое.";
    else
        cout << "Число " << num << " - не счастливое.";
}
