// When we use - while(low<=high) then algorithm ends without finding the target
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v = {1,2,4,6,8,9,12,18,21,24,30};
    int target = 15;
    // Linear search - O(n) time complexity
    for(int i = 0;i<v.size();i++){
        if(v[i] > target){
            cout<<"Predecessor is : "<<v[i-1]<<endl;
            cout<<"Successor is : "<<v[i]<<endl;
            break;
        }
    }
    // Binary Search - O(logn) time complexity
    //              low
    //               ↓
    // 1 2 4 6 8 9 12 18 21
    //             ↑
    //           high
    // high = last smaller element
    // low = first greater element
    int low = 0;
    int high = v.size()-1;
    bool flag = false;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(v[mid] == target){  // in case element is found.
            cout<<"Predecessor is : "<<v[mid-1]<<endl;
            flag = true;
            break;
        }
        else if(v[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    if(flag == false){
        cout<<"Predecessor is : "<<v[high]<<endl;
        cout<<"Successor is : "<<v[low]<<endl;
    }
    return 0;
}