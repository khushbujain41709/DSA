#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
// No repetitions allowed with backtracking
// f(str, i) generates permutation of string from i to n-1.
void permutations1(string &s, int i){ // passing with reference is important
    if(i == s.size() - 1){
        cout<<s<<endl;
        return;
    }
    for(int idx = i; idx < s.size(); idx++){
        swap(s[idx], s[i]);
        permutations1(s, i+1);
        swap(s[idx], s[i]); // This is the backtracking step - If we will skip this step then repeated strings will be generated.
    }
}
// Repetitions allowed with backtracking
void permutations2(string &s, int i){ // passing with reference is important
    if(i == s.size() - 1){
        cout<<s<<endl;
        return;
    }
    unordered_set<int> set;
    for(int idx = i; idx < s.size(); idx++){
        if(set.count(s[idx])){ // pruning repeating calls
            continue;
        }
        set.insert(s[idx]);
        swap(s[idx], s[i]);
        permutations2(s, i+1);
        swap(s[idx], s[i]); // This is the backtracking step - If we will skip this step then repeated strings will be generated.
    }
}
int main(){
    string s = "aba";
    permutations2(s, 0);
    return 0;
}