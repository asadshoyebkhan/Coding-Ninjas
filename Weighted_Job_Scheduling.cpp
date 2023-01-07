/*
Weighted Job Scheduling.

You are given N jobs where every job is represented as:
1. Start Time
2. Finish Time
3. Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.


Input Format:
The first line of input contains an integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 


Constraints:
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6


Output Format:
Output one integer, the maximum profit that can be achieved.


Sample Input 1
4
3 10 20
1 2 50
6 19 100
2 100 200


Sample Output 1
250

*/





// O(nlogn) approach


#include<bits/stdc++.h>
using namespace std;

struct Jobs{
    int start, end, profit;
};

bool compares(Jobs j1, Jobs j2)
{
    return j1.end < j2.end;
}

int binarySearch(Jobs jobs[], int index)
{
    int lo = 0, hi = index - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (jobs[mid].end <= jobs[index].start)
        {
            if (jobs[mid + 1].end <= jobs[index].start)
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;

    Jobs * arr = new Jobs[n];

    for(int i=0; i<n; i++)
    {
        int s,e,p;
        cin>>s>>e>>p;

        Jobs temp;
        temp.start = s;
        temp.end = e;
        temp.profit = p;

        arr[i] = temp;
    }

    sort(arr,arr+n, compares);

    int *dp = new int[n];
    dp[0] = arr[0].profit;


    for(int i=1; i<n; i++)
    {
        int including = arr[i].profit;
        int lNconflicting = -1;

        
        lNconflicting = binarySearch(arr, i);

      

        if (lNconflicting != -1) {
          including += dp[lNconflicting];
        }

        dp[i] = max(dp[i-1],including);
    }

    cout<<dp[n-1]<<endl;
    return 0;
}