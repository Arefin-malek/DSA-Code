#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int>Parent , rank;
    public:
        DisjointSet(int n){
            rank.resize(n+1, 0);
            Parent.resize(n+1);
            for(int i=0 ; i<=n ; i++){
                Parent[i]=i;
            }
        }
        int findUPar(int node){
            if(node == Parent[node]){
                return node;
            }
            return Parent[node] = findUPar(Parent[node]);
        }

        void unionByRank(int u , int v){
            int ulp_v= findUPar(v);
            int ulp_u = findUPar(u);
            if(ulp_u == ulp_v){
                return ;
                // u and v are alr in the same component
            }
            if(rank[ulp_u] < rank[ulp_v]){
                Parent[ulp_u] = ulp_v;
            }
            if(rank[ulp_u] > rank[ulp_v]){
                Parent[ulp_v] = ulp_u;
            }
            else{
                Parent[ulp_v] = ulp_v;
                rank[ulp_v]++;
            }
        }
};
int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"Same\n";
    }
    else cout << "NOT SAME\n";

    return 0;
}