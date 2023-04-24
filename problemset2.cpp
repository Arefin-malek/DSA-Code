#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n , q , sum =0 ;
    cin>>n>>q;
    vector<int>v(n);
    vector<int>pre;
    for(int i=0 ; i<n; i++)
    {
        cin>>v[i];
        sum+= v[i];
        pre.push_back(sum);
    }
    while (q--)
    {
        ll l , r , k , tempans2=sum , temp;
        cin>>l>>r>>k;
        ll tempans = k * (r-l+1);
        if(l > 1)
         temp = pre[r-1]- pre[l-2];
        else  temp =pre[r-1];
        tempans2 -= temp;
        if((tempans2+tempans) % 2 == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
}
int main()
{
    int t;
    cin>>t;
    while(t--) solve();
}