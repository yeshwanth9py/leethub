// Last updated: 6/11/2026, 11:33:34 AM

unordered_map<int, int> ump;

struct Compare{
    bool operator()(int a, int b){
        return ump[a]<ump[b];
    }   
};

vector<int> anums;
vector<int> anss;
int dp[1001][1001];
int rec(int ind, int prev){
    if(ind == anums.size()){
        return 0;
    }
    if(dp[ind][prev]!=-1) return dp[ind][prev];
    int maxl = rec(ind+1, prev);
    if(anums[ind]%anums[prev] == 0){
        maxl = max(maxl, 1+rec(ind+1, ind));
    }
    return dp[ind][prev] = maxl;
}

void generate(int ind, int prev){
    if(ind == anums.size()){
        return;
    }
    int ci = -1;
    int maxl = rec(ind+1, prev);
    if(anums[ind]%anums[prev] == 0){
        maxl = max(maxl, 1+rec(ind+1, ind));
        if(maxl == 1+rec(ind+1, ind)){
            ci = ind;
        }
    }
    if(ci == -1){
        generate(ind+1, prev);
    }else{
        anss.push_back(anums[ind]);
        generate(ind+1, ind);
    }
}

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        ump.clear();
        for(int i=0; i<n; i++){
            ump[nums[i]] = i;
        }

        sort(nums.begin(), nums.end());
        anums = nums;
        memset(dp, -1, sizeof(dp));
        int maxs = 0;
        int fi = -1;
        for(int i=0; i<n; i++){
            maxs = max(maxs, 1+rec(i+1, i));
            if(1+rec(i+1, i) == maxs){
                fi = i;
            }
        }
        cout<<maxs<<endl;
        cout<<fi<<endl;
        anss.clear();
        anss.push_back(anums[fi]);
        generate(fi+1, fi);
        sort(anss.begin(), anss.end(), Compare());
        return anss;
    }
};