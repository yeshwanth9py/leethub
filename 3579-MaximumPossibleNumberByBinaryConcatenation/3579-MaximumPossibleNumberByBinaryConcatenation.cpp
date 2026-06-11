// Last updated: 6/11/2026, 11:17:47 AM
#include <bits/stdc++.h> // not recommended for production but okay for CP
using namespace std;

class Solution {
public:
    int n;
    int maxans = -100000;
    vector<int> vis;
    vector<int> arr;

    // Function to generate permutations and update maxans
    void perms(int ind, vector<int>& temp){  // Pass temp by reference to avoid copying
        if(ind == n){
            maxans = max(maxans, this->maxgoodans(temp));
            return;
        }

        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                temp.push_back(arr[i]);
                vis[i] = 1;
                perms(ind+1, temp);
                vis[i] = 0;
                temp.pop_back();  // Backtrack
            }
        }
    }

    // Function to calculate the "goodness" of a permutation
    int maxgoodans(vector<int>& nums){  // Pass nums by reference
        int mask = 0;

        for(int i=0; i<nums.size(); i++){
            mask = mask << (int)(log2(nums[i]) + 1);
            mask = mask | nums[i];
            // cout << mask << endl;  // Debug output
        }

        return mask;
    }

    // Main function to find the maximum "good number"
    int maxGoodNumber(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        vis.resize(n+1, 0);
        vector<int> temp;
        this->perms(0, temp);  // Start the permutation generation
        return maxans;  // Return the maximum good number
    }
};
