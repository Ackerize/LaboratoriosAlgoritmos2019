#include <bits/stdc++.h>
#include <iostream>


using namespace std;

void swap(int* a, int* b)
{
  int t = *a;
  *a = *b;
  *b = t;
}


int partition (int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] < pivot)
    {
    i++;
    swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
  int pi = partition(arr, low, high);
  quickSort(arr, low, pi - 1);
  quickSort(arr, pi + 1, high);
  }
}

int MultiploMax(int a){
  if(a%2 == 0)  
    return a+2;
  return a+1;
}

int main()
{
  int casos, n;
  cin >> casos;
  for(int i = 0; i < casos; i++){
    cin >> n;
    int arr[n];
    for(int j = 0; j < n; j++){
      cin >> arr[j];
    }
    quickSort(arr, 0, n - 1);
    cout << MultiploMax(arr[n-1]) << endl;
  }
  
  return 0;
}