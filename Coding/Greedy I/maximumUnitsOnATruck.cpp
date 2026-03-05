// Leetcode 1710
#include<bits/stdc++.h>
using namespace std;
// This custom comparator is always written above public class in leetcode
bool customComparator(vector<int>& a, vector<int>& b){
    return a[1] > b[1]; // agar a ka profit jyada hai b se toh a pehle b se
}
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    int m = boxTypes.size();
    // Sort using the custom comparison function
    sort(boxTypes.begin(), boxTypes.end(), customComparator);
    int ans = 0;
    for(int i = 0; i<m; i++){
        if(truckSize >= boxTypes[i][0]){
            ans += boxTypes[i][0] * boxTypes[i][1];
            truckSize -= boxTypes[i][0];
        }
        else{
            ans += truckSize * boxTypes[i][1]; // remaining truckSize * units per box
            truckSize = 0;
        }
        if(truckSize == 0){
            return ans;
        }
    }
    return ans;
}
int main(){
    
    return 0;
}