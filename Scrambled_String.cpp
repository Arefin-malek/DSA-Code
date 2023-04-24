#include <bits/stdc++.h>
using namespace std;
#define ll long long
    unordered_map<string , bool > dp;
    bool solve(string a , string b)
    {
        if(a.compare(b) == 0) return true;
        if(a.length() <= 1) return false;

        int n = a.length();

        bool flag = false;

        string key = a;
        key.append(b);

        if(dp.find(key) != dp.end()) return dp[key];
        for(int i=1 ; i<=n-1; i++)
        {
            bool cond1 =  solve(a.substr(0,i) , b.substr(n-i,i)) && solve(a.substr(i,n-i) , b.substr(0,n-i));
            bool cond2 = solve(a.substr(0,i) , b.substr(0,i) ) && solve(a.substr(i,n-i) , b.substr(i , n-i));

            if( cond1 || cond2) {
                flag = true;
                break;
            }
        }
        return dp[key] = flag;
    }
    bool isScramble(string s1, string s2) {
        return solve(s1 , s2);
    }

    int main()
    {
        string a , b;
        cin>>a>>b;
        cout << isScramble(a , b) << endl;
    }