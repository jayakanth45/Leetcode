class Solution {
public:
    string reverseParentheses(string s) {
       stack<char> st;
        string temp="",ans="";
        bool flag=0;
        for(int i=0;i<s.size();i++){
          if(s[i]=='('){
              flag=1;
              st.push('(');
          }
            else if(s[i]==')'){
                while(st.top()!='(' && !st.empty()){
                    temp=temp+st.top();
                    st.pop();
                }
                
                
                    st.pop();
                if(st.empty()){
                    ans+=temp;
                    flag=0;
                }
                if(flag){
                for(int k=0;k<temp.size();k++){
                    st.push(temp[k]);
                }
                }
                
                temp="";
            }
           
            else if(flag){
                st.push(s[i]);
            }
            else if(st.empty()){
                ans+=s[i];
            }
        }
        return ans;
        
    }
};