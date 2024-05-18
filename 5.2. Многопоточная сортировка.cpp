#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void merge_sort(vector<int>& arr, int start, int end) 
{
    if (start >= end) 
        return;
    
    int mid = (start + end) / 2;
    
    thread left_thread(merge_sort, ref(arr), start, mid);
    thread right_thread(merge_sort, ref(arr), mid + 1, end);
    
    left_thread.join();
    right_thread.join();
    
    vector<int> temp(end - start + 1);
    int i = start, j = mid + 1, k = 0;
    
    while (i <= mid && j <= end) 
    {
        if (arr[i] <= arr[j]) 
        {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    
    while (i <= mid) 
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    
    while (j <= end) 
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    
    for (int i = start; i <= end; i++) 
    {
        arr[i] = temp[i - start];
    }
}

int main() 
{
    vector<int> arr = {5, 4, 3, 2, 1};
    
    merge_sort(arr, 0, arr.size() - 1);
    
    for (int num : arr)
    {
        cout << num << " ";
    }
}