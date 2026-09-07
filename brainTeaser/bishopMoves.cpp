// https://www.codechef.com/START250C/problems/BISHOPMV

// Bishop Moves
// You have a chessboard of size 8×8, where the cells are numbered (1,1), (1,2), …, (1,8), …, (8,1), …, (8,8).
// A bishop is a chess piece which travels along diagonals (between any 2 cells in the same diagonal in a single move). A diagonal can be of 2 types:
// - A set of cells (x,y) where x+y is constant.
// - A set of cells (x,y) where x−y is constant.
// For example, {(1,2),(2,3),(3,4),(4,5),(5,6),(6,7),(7,8)} form a diagonal.
// You are given 2 cells (X1,Y1) and (X2,Y2). Can a bishop starting in the first cell reach the second? If it can, what is the minimum number of moves?

// Input Format
// - The first line of input will contain a single integer T, denoting the number of test cases.
// - The first and only line of each test case contains 4 integers X1, Y1, X2 and Y2.

// Output Format
// For each test case, output on a new line the minimum moves needed or -1 if impossible.

// Constraints
// - 1 ≤ T ≤ 100
// - 1 ≤ X1, Y1, X2, Y2 ≤ 8
// - (X1,Y1) ≠ (X2,Y2)

// Sample Input
// 4
// 1 2 7 8
// 2 1 1 2
// 1 2 3 6
// 1 2 2 2

// Sample Output
// 1
// 1
// 2
// -1

// Explanation:
// Test Case 1: (1,2) and (7,8) are on the same diagonal, and hence can be reached in 1 move.

// Test Case 3: The bishop can first go like:
// (1,2) → (4,5) → (3,6)
// thus reaching in 2 steps.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pow(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = res*a;
        b = b>>1;
        a *= a;
    }
    return res;
}
ll gcd(ll a, ll b) {
    if(b > a) return gcd(b, a);
    if(b == 0) return a;
    return gcd(a % b, b);
}
int main(){
    int t;
    cin>>t;
    vector<int> khubu;
    unordered_map<int, int> mp;
    unordered_set<int> khushbu;
    while(t--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        // vector<int> a(n);
        // for(int i = 0; i<n; i++){
        //     cin>>a[i];
        // }
        int cnt = 0;
        if ((x1+y1 == x2+y2) || (x1-y1 == x2-y2)){
            cout<<1<<endl;
        }
        else if((x1+y1)%2 != (x2+y2)%2){
            cout<<-1<<endl;
        }
        else{
            cout<<2<<endl;
        }
    }
}