// Last updated: 6/11/2026, 11:35:30 AM
class Solution {
public:
    int compareVersion(string v1, string v2) {
        istringstream iss(v1);
        string temp;

        vector<int> arr1;
        while(getline(iss, temp, '.')){
            arr1.push_back(stoi(temp));
        }

        istringstream iss2(v2);

        vector<int> arr2;
        while(getline(iss2, temp, '.')){
            arr2.push_back(stoi(temp));
        }

        // for(int el: arr2){
        //     cout<<el<<" ";
        // }
        int n, m;
        n = arr1.size();
        m = arr2.size();

        int i=0;
        int j=0;

        while(i<n && j<m){
            if(arr1[i] == arr2[j]){
                i++;
                j++;
            }else if(arr1[i]>arr2[j]){
                return 1;
            }else{
                return -1;
            }
        }

        while(i<n){
            if(arr1[i] == 0){
                i++;
            }else if(arr1[i]>0){
                return 1;
            }else{
                return -1;
            }
        }

        while(j<m){
            if(arr2[j] == 0){
                j++;
            }else if(arr2[j]>0){
                return -1;
            }else{
                return 1;
            }
        }


        return 0;
    }
};