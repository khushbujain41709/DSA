// Leetcode 881
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int n = people.size();
    int boats = 0;
    int i = 0;
    int j = n-1;
    while(i <= j){
        if(people[i] + people[j] > limit){
            j--;
            boats++;
        }
        else{ 
        // people[i] + people[j] <= limit
        // both i++ and j-- as only two people at the same time can travel
            i++;
            j--;
            boats++;
        }
    }
    return boats;
}
int main(){
    
    return 0;
}