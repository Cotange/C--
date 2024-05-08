#include <iostream>
#include <vector>

using namespace std;

//Бинарный поиск

//Реализуйте функцию бинарного поиска в отсортированном по возрастанию массиве.
//Если объект есть в массиве, функция должна вернуть его индекс, иначе — вернуть -1.

int binary(const vector<int>& mas, int x) 
{
    int l = 0;
    int r = mas.size() - 1;
    while (l <= r) 
    {
        int m = l + (r - l) / 2;
        if (mas[m] == x)
            return m;
        if (mas[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    
    return -1;
}

int main() 
{
    vector<int> mas = {7, 11, 60, 89, 321};
    int x = 89;
    int result = binary(mas, x);
    if (result == -1)
        cout << "Элемент не найден";
    else
        cout << "Элемент найден под индексом массива " << result;
}
