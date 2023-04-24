#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr , int i , int j)
{
    if(i>=j) return 0;
    int mn = INT_MAX;
    for(int k = i ; k<= j-1 ; k++)
    {
        int sum = arr[i-1] * arr[k] * arr[j] + solve(arr , i , k) + solve(arr, k+1 , j);
        mn = min(mn,sum);
    }

    return mn;
}
int main()
{
    vector<int>arr = {40,20,30,10,30};
    int n = arr.size();
    cout << solve(arr, 1 , n-1)<< endl;
    return 0;
}