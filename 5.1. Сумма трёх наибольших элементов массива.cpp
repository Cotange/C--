#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

using namespace std;

//Используя многопоточное программирование, 
//найти сумму 3 самых больших элементов массива, 
//заполненного случайными числами.

int sum3(vector<int>& mas) 
{
  sort(mas.begin(), mas.end(), greater<int>());
  return mas[0] + mas[1] + mas[2];
}

int main() 
{
  vector<int> mas(25);
  for (int i = 0; i < mas.size(); i++) 
  {
    mas[i] = rand() % 1000;
  }

  thread t(sum3, ref(mas));

  t.join();

  cout << "Сумма трёх наибольших элементов массива " << sum3(mas);
}