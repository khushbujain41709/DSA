#include<iostream>
#include<vector>
using namespace std;
// If we combine both optimizations - path compression with union by size/rank - we will reach nearly constant time queries. It turns out, that the final amortized time complexity is O(alpha(n)) , where alpha(n)  is the inverse Ackermann function, which grows very slowly. 
// TC of both functions is O(log*n) - DSU with union by size/rank, but without path compression works in O(logn) time per query.
/*
5 8
Enter operation(Union/Find): Union
1 2
Enter operation(Union/Find): Union   
2 3
Enter operation(Union/Find): Union
1 4
Enter operation(Union/Find): Find 
1
1
Enter operation(Union/Find): Find
2
1
Enter operation(Union/Find): Find
3
1
Enter operation(Union/Find): Find
5
5
Enter operation(Union/Find): Find
4
1
0 1 1 1 1 5
0 3 0 0 0 0
*/
int find(vector<int>& parent, int x){
    // This method returns which group/cluster x belongs to.
    if(parent[x] == x) return x; // base case
    return parent[x] = find(parent, parent[x]); // recursive call
}
void unionDSU(vector<int>& parent, vector<int>& rank, int a, int b){
    int x = find(parent, a);
    int y = find(parent, b);
    if(rank[x] >= rank[y]){
        parent[y] = x;
        rank[x]++;
    }
    else{
        parent[x] = y;
        rank[y]++;
    }
}
int main(){
    int nodes, queries;
    cin>>nodes>>queries;
    vector<int> parent(nodes+1,0); // 1 based indexing
    for(int i = 0; i<=nodes; i++){
        parent[i] = i;
    }
    vector<int> rank(nodes+1,0); // Initial rank 0
    while(queries--){
        string s;
        cout<<"Enter operation(Union/Find): ";
        cin>>s;
        if(s == "Union"){
            int x,y;
            cin>>x>>y;
            unionDSU(parent,rank,x,y);
        }
        else if(s == "Find"){
            int x;
            cin>>x;
            cout<<find(parent,x)<<endl;
        }
    }
    for(int i = 0; i<=nodes; i++){
        cout<<parent[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i<=nodes; i++){
        cout<<rank[i]<<" ";
    }
    cout<<endl;
    return 0;
}