// http://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
// ITMO course in edu pages - step 1 - practice
#include<iostream>
#include<vector>
using namespace std;
int find(vector<int>& parent, int x){
    if(parent[x] == x) return x;
    else return parent[x] = find(parent, parent[x]);
}
void unionDSU(vector<int>& parent, vector<int>& rank,vector<int>& minimal,vector<int>& maximal, vector<int>& size, int a, int b){
    int x = find(parent,a);
    int y = find(parent,b);
    if( x == y) return ; // both a and b are in same set - like union 1 2 - union 2 3 - union 1 3
    if(rank[x] >= rank[y]){
        parent[y] = x;
        rank[x] ++;
        size[x] += size[y];
        minimal[x] = min(minimal[x], minimal[y]);
        maximal[x] = max(maximal[x], maximal[y]);
    }
    else if(rank[x] < rank[y]){
        parent[x] = y;
        rank[y] ++;
        size[y] += size[x];
        minimal[y] = min(minimal[x], minimal[y]);
        maximal[y] = max(maximal[x], maximal[y]);
    }
}
int main(){
    int nodes, queries;
    cin>>nodes>>queries;
    vector<int> parent(nodes+1,0); // 1 based indexing
    vector<int> minimal(nodes+1,0);
    vector<int> maximal(nodes+1,0);
    vector<int> size(nodes+1,1); // starting size is 1
    for(int i = 0; i<=nodes; i++){
        parent[i] = i;
        minimal[i] = i;
        maximal[i] = i;
    }
    vector<int> rank(nodes+1,0); // Initial rank 0
    while(queries--){
        string s;
        cin>>s;
        if(s == "union"){
            int x,y;
            cin>>x>>y;
            unionDSU(parent,rank,minimal, maximal, size, x, y);
        }
        else if(s == "get"){
            int x;
            cin>>x;
            x = find(parent, x);
            cout<<minimal[x]<<" "<<maximal[x]<<" "<<size[x]<<endl;
        }
    }
    return 0;
}