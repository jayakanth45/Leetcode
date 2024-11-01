class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int count=0;
        for(int i=1;i<s.size();i++){
           if(s[i]==s[i-1]){
               count++;
               
           }
            else{
                count++;
                if(count==1){
                    ans+=s[i-1];
                }
                else if(count<3){
                    while(count--){
                        ans+=s[i-1];
                    }
                }
                else if(count>=3){
                    ans+=s[i-1];
                    ans+=s[i-1];
                }
                count=0;
                
             }
        }
       int k=s.size();
         count++;
                if(count==1){
                    ans+=s[k-1];
                }
                else if(count<3){
                    while(count--){
                        ans+=s[k-1];
                    }
                }
                else if(count>=3){
                    ans+=s[k-1];
                    ans+=s[k-1];
                }
        
        return ans;
        
    }
};