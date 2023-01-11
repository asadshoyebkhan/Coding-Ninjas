/*
Given an array of length ‘N’, where each element denotes the position of a stall. Now you have ‘N’ stalls and an integer ‘K’ which denotes the number of cows that are aggressive. To prevent the cows from hurting each other, you need to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. Return the largest minimum distance.
Input format :
The first line contains a single integer ‘T’ denoting the number of test cases.

The first line of each test case contains two integers ‘N’ and ‘K’ denoting the number of elements in the array/list and the number of aggressive cows.

The second line contains ‘N’ single space-separated integers denoting the elements of the array.
Output format :
For each test case, print the majority element in a separate line.
Note :
You do not need to print anything; it has already been taken care of.
Constraints :
1 <= T <= 5
2 <= N <= 20000
2 <= C <= N
0 <= ARR[i] <= 10 ^ 9

Where ‘T’ is the number of test cases, 'N' is the length of the given array and, ARR[i] denotes the i-th element in the array.

Time Limit: 1 sec.
Sample Input 1 :
2
3 2
1 2 3
5 2
4 2 1 3 6
Sample Output 1 :
2
5
Explanation to Sample Input 1 :
In the first test case, the largest minimum distance will be 2 when 2 cows are placed at positions {1, 3}.

In the second test case, the largest minimum distance will be 5 when 2 cows are placed at positions {1, 6}.
Sample Input 2 :
2
6 4
0 3 4 7 10 9
6 3
0 4 3 7 10 9
Sample Output 2 :
3
4
Explanation to Sample Input 2 :
In the first test case, the largest minimum distance will be 3 when 4 cows are placed at positions {0, 3, 7, 10}.

In the second test case, the largest minimum distance will be 4 when 3 cows are placed at positions {0, 4, 10}.
*/


// Fuction of aggressive Cows

#include<bits/stdc++.h>
bool can_place_k_cows(vector<int> &stalls, int distance, int k)
{
    int n = stalls.size();
    int count =0;

    int j=0;
    for(int i=1; i<n; i++)
    {
      if (stalls[i] - stalls[j] >= distance) 
      {
        count++;
        if (count == k - 1) 
        {
          return true;
        }
        j=i;
      }


    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) 
{
  //    Write your code here.
  int n = stalls.size();
  sort(stalls.begin(), stalls.end());


  int start = 0;
  int end = stalls[n - 1];


  int max_distance = INT_MIN;

  while (start <= end) 
  {
    int mid = (start + end) / 2;

    if (can_place_k_cows(stalls, mid, k) )
    {
      max_distance = max(max_distance, mid);
      if(start == mid)
      {
          start = mid+1;
      }
      else
        start = mid;
    }

    
    else 
    {
      end = mid - 1;
    }

  }

  return max_distance;
}
