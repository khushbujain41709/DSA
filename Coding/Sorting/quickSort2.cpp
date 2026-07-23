// Time complexity = O(n logn) at average case
// Space complexity = O(log n) so it is an in-place sorting
#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int>& v, int starting_index , int ending_index){
    int n = v.size();
    int pivot = v[ending_index];
    int i = starting_index - 1;
    for(int j = starting_index; j<ending_index; j++){
        if(pivot > v[j]){ // bade element ko ignore krke aage jao
            i++;
            swap(v[i], v[j]); 
        }
    }
    swap(v[ending_index], v[i+1]);
    return i+1;
}
void quickSort(vector<int>& v, int starting_index , int ending_index){
    if(starting_index >= ending_index) return;
    int pivot_index = partition(v,starting_index,ending_index);
    quickSort(v,starting_index,pivot_index -1);
    quickSort(v,pivot_index + 1 , ending_index);
}
int main(){
    vector<int> v = {5,1,8,2,7,6,3,4,-8};
    int n = v.size();
    quickSort(v,0,n-1);
    for(int i = 0;i<n;i++){
        cout<<v[i] <<" ";
    }
    return 0;
} 