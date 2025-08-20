#include <iostream>
#include <vector>

using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int k)
{
  int n = a.size(), m = b.size();

  // array to store the merged sorted array
  vector<int> arr(n + m);
  int i = 0, j = 0, d = 0;
  while (i < n && j < m)
  {

    // if the element of a[] is smaller, insert
    // the element to the sorted array
    if (a[i] < b[j])
      arr[d++] = a[i++];

    // if the element of b[] is smaller, insert
    // the element to the sorted array
    else
      arr[d++] = b[j++];
  }

  // push the remaining elements of a[]
  while (i < n)
    arr[d++] = a[i++];

  // push the remaining elements of b[]
  while (j < m)
    arr[d++] = b[j++];

  return arr[k - 1];
}

int main()
{
  vector<int> a = {2, 3, 6, 7, 9};
  vector<int> b = {1, 4, 8, 10};
  int k = 5;
  cout << kthElement(a, b, k);
  return 0;
}