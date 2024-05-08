#include <iostream>
#include <vector>

using namespace std;

//Вам надо написать функцию аналогичную Print, которая умеет печатать в поток std::cout элементы переданного контейнера через указанную строку-разделитель. 
//Первый аргумент функции — контейнер. Гарантируется, что по этому контейнеру можно проитерироваться с помощью стандартного цикла range-based for, 
//и что элементы контейнера можно напечатать в поток std::cout с помощью стандартного оператора <<. 
//Второй аргумент функции — строка-разделитель, которую надо печатать между элементами. 
//В конце необходимо напечатать перевод строки \n.

template <typename Container, typename Delimiter>
void Print(const Container& container, const Delimiter& delimiter) 
{
    for (const auto& element : container) 
    {
        cout << element << delimiter;
    }
    cout << '\n';
}

int main() { 
    vector<int> data = {1, 2, 3}; 
    Print(data, ", ");
} 
