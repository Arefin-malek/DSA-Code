#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod=1e3+3;
int dp[151][151][2];
int solve(string A, int i, int j, int IsTrue){

    if(i>j) return 0;

    if(i==j) {

        if(IsTrue) return A[i]=='T';

        else return A[i]=='F';

    }

    if(dp[i][j][IsTrue]!=-1) return dp[i][j][IsTrue];

    int count=0;

    for(int k=i+1; k<=j-1; k+=2){

        int LT = solve(A, i, k-1, 1);

        int LF = solve(A, i, k-1, 0);

        int RT = solve(A, k+1, j, 1);

        int RF = solve(A, k+1, j, 0);

        if(A[k]=='^') {

            if(IsTrue) count += (LT*RF + LF*RT)%mod;

            else count += (LT*RT + LF*RF)%mod;

        }

        else if(A[k]=='&') {

            if(IsTrue) count += (LT*RT)%mod;

            else count += (LT*RF + LF*RF + LF*RT)%mod;

        }

        else if(A[k]=='|') {

            if(IsTrue) count += (LT*RF + LT*RT + LF*RT)%mod;

            else count += (LF*RF)%mod;

        }

    }

    return dp[i][j][IsTrue]=count%mod;

}


int main() {
    string A = "F|T^T&F";
    memset(dp, -1, sizeof(dp));
    cout << solve(A, 0, A.size()-1, 1) << endl;
}

