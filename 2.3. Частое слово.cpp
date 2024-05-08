#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream> 

using namespace std;

//Дан текст. Выведите слово, которое в этом тексте встречается чаще всего. 
//Если таких слов несколько, выведите то, которое меньше в лексикографическом порядке.

int main() 
{
  string text = "Meow Gav Hru Meow";

  map<string, int> count;

  string word;
  istringstream iss(text);
  while (iss >> word) 
  {
    count[word]++;
  }

  auto mostword = max_element(count.begin(), count.end(), [](const auto& a, const auto& b) 
  {
    return a.second < b.second or (a.second == b.second and a.first > b.first);
  });

  cout << "Наиболее часто встречающееся слово: " << mostword->first << '\n';
}
