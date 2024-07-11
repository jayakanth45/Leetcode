class Solution {
public:
    string reverseParentheses(string s) {
     stack<int> st;

       for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push(i);
        }
        else if(s[i]==')'){
            int k = st.top();
            st.pop();
            reverse(s.begin()+k+1,s.begin()+i);
        }
       }
       string result;
        for (char c : s) {
            if (c != '(' && c != ')') {
                result += c;
            }
        }

    return result; 
        
    }
};