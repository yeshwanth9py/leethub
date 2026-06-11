// Last updated: 6/11/2026, 11:19:19 AM
class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        int ct1 = 0;
        if(s1.size()>(nums1.size())/2){
            ct1 += (s1.size()-(nums1.size()/2));
        }
        
        
        int ct2 = 0;
        if(s2.size()>(nums2.size())/2){
            ct2 += (s2.size()-(nums2.size()/2));
        }
        // cout<<ct2<<endl;

        vector<int> temp;
        if(ct1>0){
            // cout<<"elems of s1 present in s2 :"<<" ";
            for(auto el: s1){
                if(s2.count(el)>0){
                   cout<<el<<" ";
                    temp.push_back(el);
                    ct1--;
                }
               
                if(ct1 == 0){
                    break;
                }
            }
        }
        for(int el: temp){
            s1.erase(el);
        }
        // cout<<ct1<<endl;
        temp.clear();
        if(ct2>0){
            for(auto el: s2){
                if(s1.count(el)>0){
                    temp.push_back(el);
                     ct2--;
                }
               
                if(ct2 == 0){
                    break;
                }
            }
        }

        for(int el: temp){
            s2.erase(el);
        }

        set<int> ans;
        for(int el: s1){
            ans.insert(el);
        }

        for(int el: s2){
            ans.insert(el);
        }

        return ans.size()-ct1-ct2;
    }
};