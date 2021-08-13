#include<iostream>
#include<climits>
using namespace std;
int max_crossing_sum(int arr[], int low, int mid, int high)
{
      int leftsum = INT_MIN;
      int sum = 0;
      for (int i = mid; i >= low; i--)
      {
        sum += arr[i];
        if (sum > leftsum)
          {
              leftsum = sum;
          }
      }
      sum = 0;
      int rightsum = INT_MIN;
      for (int j = mid + 1; j <= high; j++)
      {
        sum += arr[j];
        if (sum > rightsum)
          {
              rightsum = sum;
          }
      }
      return (leftsum + rightsum);
}

int max_subarr_sum (int A[], int low, int high)
{
   if (low == high)
      return A[low];
  else
     {
      int mid = (low + high)/2;
      int left_sum = max_subarr_sum (A, low, mid);
      int right_sum = max_subarr_sum (A, mid+1, high);
      int crossing_sum = max_crossing_sum(A, low, mid, high);

      return (left_sum, right_sum, crossing_sum);
     }
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

    cout <<  max_subarr_sum(arr, 0, sz-1) ;
    return 0;
}


