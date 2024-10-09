class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        for(auto x:s){
            if(x==')' && !st.empty() && st.top()=='('){
                st.pop();
                
            }
            else{
                st.push(x);
            }
        }
        return st.size();
        
    }
};