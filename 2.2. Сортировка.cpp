#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Составить программу, которая на основе заданного списка формирует два других, 
//помещая в первый из них положительные, а во второй — отрицательные элементы исходного списка, 
//сортируя их по возрастанию при заполнении.

int main()
{
    vector<int> data = {10, -8, -9, 11, -3, 17};

    vector<int> positive;
    vector<int> negative;

    for (const auto& element : data) 
    {
        if (element >= 0) 
            positive.push_back(element);
        else
            negative.push_back(element);
    }

    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end());
}
