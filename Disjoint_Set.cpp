#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int>Parent , rank , size;
    public:
        DisjointSet(int n){
            rank.resize(n+1, 0);
            size.resize(n+1, 1);
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
        void unionBySize(int u , int v){
            int ulp_v= findUPar(v);
            int ulp_u = findUPar(u);
            if(ulp_u == ulp_v){
                return ;
                // u and v are alr in the same component
            }
            if(size[ulp_u] <size[ulp_v]){
                Parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                 Parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};
int main(){
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"Same\n";
    }
    else cout << "NOT SAME\n";

    return 0;
}