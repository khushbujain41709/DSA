// Leetcode 3739
#include<bits/stdc++.h>
using namespace std;
// The intended solution is:
// Step 1: Convert to +1/-1: let arr[i] = 1 if nums[i] == target else -1.
// Step 2: Build prefix sums: pref[0]=0, pref[k] = pref[k - 1] + arr[k - 1] for k=1..n
// Step 3: Count pairs (i < j) with pref[j] > pref[i] (these correspond to subarrays where target is majority).  So now the whole problem becomes: Count subarrays whose sum is positive.
// Step 4: Use coordinate compression on all pref values and a Fenwick tree / ordered map: iterate k from 0..n, query how many previous pref are < current, add to ans, then update. Coordinate-compress all prefix values. 
// Traverse the prefix array once.
// Maintain previous prefix frequencies in a Fenwick Tree (BIT).
// For each pref[j], query how many previous prefixes are strictly smaller.
// This gives O(n log n) which passes the constraints.
// If target never appears return 0.
class Fenwick{
    public:
    int n;
    vector<int> BIT;
    Fenwick(int n){
        this->n = n;
        BIT = vector<int>(n+1, 0);
    }
    void update(int idx, int val){
        while(idx <= n){
            BIT[idx] += val;
            idx += idx & (-idx);
        }
    }
    long long query(int idx){
        long long sum = 0;
        while(idx > 0){ // not equal to 0 as
        // 0 & 0 = 0, So idx -= 0; idx remains 0, and the loop never terminates, causing an infinite loop.
            sum += BIT[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
};
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> arr(n,0);
        bool flag = false;
        for(int i = 0; i<n; i++){
            if(nums[i] == target){
                flag = true;
                arr[i] = 1;
            }
            else arr[i] = -1;
        }
        if(flag == false) return 0; 
        vector<int> pref(n+1, 0);
        for(int i = 1; i<=n; i++){
            pref[i] = pref[i-1] + arr[i-1];
        }
        long long ans = 0;

        vector<int> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        Fenwick BIT(vals.size());

        for(int i = 0; i<=n; i++){
            int rank = lower_bound(vals.begin(), vals.end() , pref[i]) - vals.begin() + 1;
            ans += BIT.query(rank-1);
            BIT.update(rank, 1);
        }
        return ans;
    }
};
int main(){
    
    return 0;
}
// Fenwick Trees(BIT) always use 1-based indexing.
// Every Fenwick implementation uses idx += idx & (-idx); and idx-=idx&(-idx);

// Remove duplicates - vals.erase(unique(vals.begin(),vals.end()),vals.end()).
// bit.update(rank,1); - Meaning - "I've now seen this prefix sum once."

/*
Approach (O(n log n))

Observation:
A subarray has target as the majority element if

count(target) > count(other elements)

Convert the array:
- target      → +1
- non-target  → -1

Now for any subarray,

sum = (#target) - (#others)

A subarray is valid iff

sum > 0

------------------------------------------------------------

Step 1: Build Prefix Sum

pref[0] = 0

pref[i] = pref[i-1] + (nums[i-1] == target ? 1 : -1)

For example,

nums   = [1,2,2,3]
target = 2

Converted array

[-1, +1, +1, -1]

Prefix sums

pref = [0, -1, 0, 1, 0]

------------------------------------------------------------

Step 2: Convert subarray condition

For subarray (l...r),

sum = pref[r+1] - pref[l]

Need

pref[r+1] - pref[l] > 0

which becomes

pref[r+1] > pref[l]

So the problem reduces to:

Count pairs (i < j) such that

pref[i] < pref[j]

------------------------------------------------------------

Step 3: Coordinate Compression

Prefix sums may be negative.

Fenwick Tree requires indices starting from 1.

Collect all prefix sums

[0, -1, 0, 1, 0]

Sort & remove duplicates

[-1, 0, 1]

Assign ranks

-1 → 1
 0 → 2
 1 → 3

Compressed prefix sequence

0  -> 2
-1 -> 1
0  -> 2
1  -> 3
0  -> 2

------------------------------------------------------------

Step 4: Fenwick Tree

Fenwick stores frequency of prefix sums seen so far.

For every prefix sum:

1. Find its compressed rank.
2. Query how many previous ranks are strictly smaller.
3. Add this count to answer.
4. Insert current rank into Fenwick Tree.

Since we need

pref[i] < pref[j]

we use

query(rank - 1)

instead of

query(rank)

------------------------------------------------------------

Dry Run

Prefix sums

[0, -1, 0, 1, 0]

Compressed ranks

[2, 1, 2, 3, 2]

Initially BIT is empty.

Prefix = 0 (rank 2)
Query(1) = 0
Answer = 0
Insert rank 2

--------------------------------

Prefix = -1 (rank 1)
Query(0) = 0
Answer = 0
Insert rank 1

--------------------------------

Prefix = 0 (rank 2)
Query(1) = 1
Answer = 1
Insert rank 2

--------------------------------

Prefix = 1 (rank 3)
Query(2) = 3
Answer = 4
Insert rank 3

--------------------------------

Prefix = 0 (rank 2)
Query(1) = 1
Answer = 5
Insert rank 2

Final Answer = 5

------------------------------------------------------------

Complexity

Building prefix sum      : O(n)
Coordinate compression   : O(n log n)
Fenwick queries/updates  : O(n log n)

Overall Time : O(n log n)
Space        : O(n)
*/