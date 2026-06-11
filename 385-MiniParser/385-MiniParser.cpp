// Last updated: 6/11/2026, 11:33:29 AM
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    bool isdigit(char ch){
        if(ch == '-' || (ch>='0' && ch<='9')){
            return true;
        }
        return false;
    }

    NestedInteger deserialize(string s) {
        stack<NestedInteger> st;
        int n = s.size();
        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])){
                int e = i;
                while(e+1<n && isdigit(s[e+1])){
                    e++;
                }
                int num = stoi(s.substr(i, e-i+1));
                NestedInteger temp(num);
                if(!st.empty()){
                    NestedInteger temp(num);
                    st.top().add(num);
                }else{
                    NestedInteger temp(num);
                    return temp;
                }
                i = e;
            }else if(s[i] == '['){
                NestedInteger temp;
                st.push(temp);
            }else if(s[i] == ']'){
                NestedInteger top = st.top();
                st.pop();
                if(!st.empty()){
                    st.top().add(top);
                }else{
                    return top;
                }
            }
        }
        NestedInteger temp;
        return temp;
    }
};