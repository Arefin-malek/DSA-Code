// #include<bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int n ;
//     cin>>n;

//     vector<int>v(2*n);
//     unordered_map<int,int>mp;
//     for(int i=0 ; i<2*n; i++)
//     {
//         cin>>v[i];
//         mp[v[i]]++;
//     }

//     for(auto i : mp)
//     {
//         if(i.second>2) 
//         {
//             cout <<"No"<<endl;
//             return ;
//         }
//     }
//     cout <<"Yes"<<endl;
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--) solve();
// }
from collections import Counter

def solve():
    n = int(input())
    v = list(map(int, input().split()))

    mp = Counter(v)
    for i in mp:
        if mp[i] > 2:
            print("No")
            return
a
    print("Yes")

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
