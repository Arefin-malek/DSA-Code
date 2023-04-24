#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// ALWAYS PASS YOUR DP VECTOR WITH REFF & LIKE THIS
//vector<vector<int>>dp{101 ,vector<int>(10001 , -1)} LIKE THIS 
// INSTEAD OF THIS THIS IT MIGHT GIVE ERROR vector<vector<int>>dp(101 ,vector<int>(10001 , -1))
    int solve(int e , int f, vector<vector<int>>&dp)
    {
        if(e == 1 ) return dp[e][f] = f;
        else if(f==0 || f==1 ) return dp[e][f] =  f;
        else if(dp[e][f] != -1) return dp[e][f];
        else
        {        
            int mn = INT_MAX;
            int low = 1, high = f;
            int ans=INT32_MAX;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                int left = solve(e - 1, mid - 1,dp);
                int right = solve(e , f - mid,dp);
                int temp = 1 + max(left,right);
                ans = min(ans,temp);
                if(left<right) low=mid+1;
                else  high=mid-1;
            }
             dp[e][f] = ans;
        }
        return dp[e][f];
    }
    int superEggDrop(int k, int n) {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL); 
      vector<vector<int>>dp{101 ,vector<int>(10001 , -1)};
      return solve(k,n,dp);   
    }
};