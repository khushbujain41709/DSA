// Code chef contest
// https://www.codechef.com/START250C/problems/JUMPCOST
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
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        // vector<long long> dp(n, 0);
        ll ans = 0;
        long long sum = 0;
        for(int i = 2; i<=n; i++){
            // dp[i] = max(0LL, (long long)(dp[i]+prev + a[i]-i));
            // if(dp[i] != 0){
            //     prev = i;
            // }
            ll val = a[i-1] + sum + 1 - i;
            // dp[i] = max(0LL, prev + a[i]-i);
            ans = max(ans, val);
            // prev = max(prev, dp[i] + i);
            if(a[i-1] > 0) sum += a[i-1];
        }
        // for(int i = 0; i<n; i++){
        //     sum += dp[i];
        // }
        cout<<ans<<endl;
    }
}
// Jumping Cost
// You have an array A of N elements.
// You are currently at index 1 with a balance of 0, and you can perform the following jump operation as many times as you want:
// Choose to jump from index i to index j (i < j), and add:
// (Aj - j + i)
// to your balance.
// Find the maximum possible balance you can have at any point using these jump operations.

// Input Format
// The first line of input contains a single integer T, denoting the number of test cases.
// Each test case consists of multiple lines:
// The first line contains a single integer N.
// The second line contains N integers — A1, A2, ..., AN.

// Output Format
// For each test case, output the maximum balance possible on a new line.

// Constraints
// 1 ≤ T ≤ 100
// 2 ≤ N ≤ 100
// -100 ≤ Ai ≤ 100

// Sample Input
// 3
// 6
// 5 5 -1 5 -1 1
// 5
// 5 5 5 5 5
// 3
// -4 -1 -5

// Sample Output
// 7
// 16
// 0

// Explanation
// Test Case 1
// The optimal sequence of jumps is:
// 1 → 2 → 4
// The balance obtained is:
// Jump 1 → 2:
// A2 - 2 + 1 = 5 - 2 + 1 = 4
// Jump 2 → 4:
// A4 - 4 + 2 = 5 - 4 + 2 = 3
// Total balance:
// 4 + 3 = 7
// Therefore, the answer is 7.

// Test Case 2
// The maximum possible balance is:
// 16

// Test Case 3
// All possible jumps decrease the balance, so the optimal choice is to make no jumps at all.
// Therefore, the answer is:
// 0