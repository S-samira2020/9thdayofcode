#include<iostream>
using namespace std;

int count_rotation(int arr[], int low, int high)
{
    if(high < low)
    {
        return 0;
    }
    if(high == low)
    {
        return arr[0];
    }
 int mid = (low+high)/2;
 if(mid < high && arr[mid+1] < arr[mid])
 {
     return (mid+1);
 }
 if(mid > low && arr[mid] < arr[mid-1])
 {
     return mid;
 }
 if(arr[high] > arr[mid])
 {
     return count_rotation(arr,low, mid-1);
 }
  return count_rotation(arr, mid+1, high);
}
int main()
{
    int sz;
    cin >> sz;
    int arr[100];
    for(int ind = 0; ind < sz ; ind++)
    {
        cin >> arr[ind];
    }
    int result = count_rotation(arr, 0, sz-1);
    cout << result << endl;
    return 0;

}
