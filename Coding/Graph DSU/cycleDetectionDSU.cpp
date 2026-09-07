// If topological sort does not have all vertices then graph has a cycle.
// Topological sorting only exists for directed acyclic graph.
// For undirected graph: we can use, BFS, DFS or DSU.
// Here, we will use DSU: We will read each edge and on the vertices of the edge, we apply union operation.
// While doing union operation, if x and y has ame parent then there exists a cycle as there was a path from x to y and now the new edge is another path from x to y.
/*
10 10
0 1
0 2
0 3
3 4
5 6
4 5
3 6
Cycle exists in the graph
6 7
7 8
7 9
*/
// TC = O(e*log(V))
#include<iostream>
#include<vector>
using namespace std;
int find(vector<int>& parent, int x){
    // This method returns which group/cluster x belongs to.
    if(parent[x] == x) return x; // base case
    return parent[x] = find(parent, parent[x]); // recursive call
}
bool unionDSU(vector<int>& parent, vector<int>& rank, int a, int b){
    int x = find(parent, a);
    int y = find(parent, b);
    if(x == y) return true; // cycle exists
    if(rank[x] >= rank[y]){
        parent[y] = x;
        rank[x]++;
    }
    else{
        parent[x] = y;
        rank[y]++;
    }
    return false;
}
int main(){
    int nodes, queries;
    cin>>nodes>>queries;
    vector<int> parent(nodes+1,0); // 1 based indexing
    for(int i = 0; i<=nodes; i++){
        parent[i] = i;
    }
    vector<int> rank(nodes+1,0); // Initial rank 0
    bool flag = false;
    while(queries--){
        int x,y;
        cin>>x>>y;
        bool ans = unionDSU(parent,rank,x,y);
        if(ans){
            flag = true;
            cout<<"Cycle exists in the graph"<<endl;
        }
    }
    if(!flag) cout<<"Cycle does not exists in the graph"<<endl;
    return 0;
}