// Last updated: 6/11/2026, 11:29:19 AM
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<int, int> um;

struct Custom_sort {
    bool operator()(const int &a, const int &b) {
        if (um.find(a) != um.end() && um.find(b) != um.end()) {
            return um[a] < um[b];
        } else if (um.find(a) != um.end()) {
            return true; // Prefer elements in `um`
        } else if (um.find(b) != um.end()) {
            return false; // `b` is in `um`, prefer it over `a`
        } else {
            return a < b; // Otherwise, compare by value
        }
    }
};

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        um.clear();
        for (int i = 0; i < arr2.size(); i++) {
            um[arr2[i]] = i; // Map values from `arr2` to their indices
        }
        Custom_sort customSort; // Create an instance of `Custom_sort`
        sort(arr1.begin(), arr1.end(), customSort); // Use the instance here
        return arr1;
    }
};
