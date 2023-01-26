/*                                        V. Creating Expression1

                                          time limit per test1 second
                                          memory limit per test256 megabytes
                                          input standard input
                                          output standard output
                                          
Given two numbers N,X and an array A of N numbers. Determine if there is a way to put '+' or '-' signs between every two numbers in the array A
in order to make an expression that is equal to X.

Note: Solve this problem using recursion.

Input
First line contains two numbers N and X
(1≤N≤20,−109≤X≤109).

Second line contains N
 distinct numbers A1,A2,....AN
 (1≤Ai≤105)
.

Output
Print "YES" if you can put '+' or '-' signs between every two number to create an expression that is equal to X
 otherwise, print "NO".

Examples
inputCopy
5 5
1 2 3 4 5
outputCopy
YES
inputCopy
5 2
1 2 3 4 5
outputCopy
NO
Note
In the first example: 1 - 2 - 3 + 4 + 5 = 5

*/


#include<bits/stdc++.h>
using namespace std;

bool canEqual(vector<int> &vec, int n, int x, int target,int i)
{
    if(i==n)
    {
        if(target ==x)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    
    return canEqual(vec,n,x,target+vec[i],i+1) || canEqual(vec,n,x,target-vec[i],i+1);
    
}

int main()
{
    int n,x;
    cin>>n>>x;
    
    vector<int> vec(n);
    for(int i=0; i<n; i++)
    {
        cin>>vec[i];
    }
    
    if(canEqual(vec,n,x,vec[0],1))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
    
    return 0;
}


