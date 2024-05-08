#include <atomic>
#include <mutex>
#include <vector>

using namespace std;

//Реализовать свой потокобезопасный контейнер
//Контейнер, который можно использовать в нескольких потоках без дополнительных блокировок

template <typename T>
class ConcurrentVector 
{
private:
    atomic<bool> locked;
    mutex m;
    vector<T> data;

public:
    ConcurrentVector() : locked(false) {}

    void push_back(const T& value) 
    {
        lock_guard<mutex> lock(m);
        data.push_back(value);
    }

    T& operator[](size_t index) 
    {
        while (locked.load()) {}
        return data[index];
    }

    size_t size() 
    {
        while (locked.load()) {}
        return data.size();
    }

    void lock() 
    {
        locked.store(true);
    }

    void unlock() 
    {
        locked.store(false);
    }
};