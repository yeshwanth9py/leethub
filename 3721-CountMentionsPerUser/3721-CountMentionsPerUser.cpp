// Last updated: 6/11/2026, 11:16:38 AM
struct Cmp{
    bool operator()(vector<string> &a, vector<string> &b){
        if(a[1] != b[1]){
            return stoi(a[1])<stoi(b[1]);
        }
        return a[0]>b[0];
    }
};

class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), Cmp());
        
        vector<int> ment(n, 0);
        int all = 0;
        set<int> allon;
        for(int i=0; i<n; i++){
            allon.insert(i);
        }

        deque<pair<int, int>> st;

        for(auto eve: events){
            // cout<<eve[1]<<": ";
            // for(auto e: st){
            //     cout<<e.first<<" "<<e.second<<", ";
            // }
            while(!st.empty() && st.back().first<=stoi(eve[1])){
                auto [telexp, tel] = st.back(); st.pop_back();
                // cout<<tel<<" ";
                allon.insert(tel);
            }
            // cout<<endl;
            if(eve[0] == "MESSAGE"){
                if(eve[2] == "ALL"){
                    all++;
                }else if(eve[2] == "HERE"){
                    for(int el: allon){
                        ment[el]++;
                    }
                }else{
                    vector<int> curev;
                    istringstream iss(eve[2]);
                    string token;
                    while(iss>>token){
                        curev.push_back(stoi(token.substr(2)));
                    }
                    for(auto el: curev){
                        ment[el]++;
                    }
                }
            }else{
                int cur = stoi(eve[2]);
                allon.erase(cur);
                st.push_front({stoi(eve[1])+60, cur});
            }
        }

        for(int &el: ment){
            el = el+all;
        }
       
        return ment;

    }
};