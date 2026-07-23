#include<bits/stdc++.h>
using namespace std;
struct hash_pair {
    size_t operator()(const pair<int,int>& p) const {
        return hash<long long>()(((long long)p.first << 32) | (unsigned int)p.second);
    }
};
int main(){
    unordered_set<pair<int,int>, hash_pair> s; // Vaild
    // unordered_set<pair<int, int>> st; // Invalid
    set<pair<int,int>> st1; // Valid
    return 0;
}