class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b' && st.empty()){
                st.push('b');
            }
            else if(s[i]=='b'){
                st.push('b');
            }
            else if(s[i]=='a' && !st.empty() && st.top()=='b'){
                count++;
                st.pop();
            }
        }
        return count;
        
    }
};