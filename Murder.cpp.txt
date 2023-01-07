/* 

Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.


Input Format:
First line of input contains an integer T, representing number of test case.
For each test case, first line of input contains integer N, representing the number of stairs.
For each test case, second line of input contains N space separated integers, representing numbers written on the stairs.


Constraints
T<=10^5
1<=N<=10^5
All numbers will be between 0 and 10^9
Sum of N over all test cases doesn't exceed 5*10^5


Output Format
For each test case output one line giving the final sum for each test case.


Sample Input 1:
1
5
1 5 3 6 4
Sample Output 1:
15


Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).

*/


#include <bits/stdc++.h>
using namespace std;

long long merge(long long *arr, long long start, long long mid, long long end) {

  long long count = 0;
  long long size1 = mid - start + 1;
  long long size2 = end - mid;

  long long *arr1 = new long long[size1 + 1];
  long long *arr2 = new long long[size2 + 1];

  for (long long i = 0; i < size1; i++) {
    arr1[i] = arr[i + start];
  }
  arr1[size1] = INT_MAX;

  for (long long i = 0; i < size2; i++) {
    arr2[i] = arr[i + mid + 1];
  }
  arr2[size2] = INT_MAX;

  long long i = 0;
  long long j = 0;

  for (long long k = start; k <= end; k++) {
    if (arr1[i] < arr2[j]) {
      arr[k] = arr1[i];
      count += (end - mid - j) * arr1[i];
      i++;
    } else {
      arr[k] = arr2[j];
      j++;
    }
  }

  return count;
}

long long merge_sort(long long *arr, long long a, long long n) {
  if (a < n) 
  {

    long long temp = (a + n) / 2;
    long long x=merge_sort(arr, a, temp);
    long long y=merge_sort(arr, temp + 1, n);
    long long z=merge(arr, a, temp, n);

    return x+y+z;
  }
  return 0;
}

int main() {

  // write your code here
  long long t;
  cin >> t;

  while (t--) {
    long long n;
    cin >> n;

    long long *arr = new long long[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }

    cout<< merge_sort(arr, 0, n - 1)<<endl;
  }

  return 0;
}

