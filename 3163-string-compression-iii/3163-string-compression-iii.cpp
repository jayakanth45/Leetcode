class Solution {
public:
    string compressedString(string s) {
        string ans="";
        int count=0;
       
        for(int i=0;i<s.size();i++){
            if(i>0 && s[i-1]==s[i]){
                count++;
                    if(count+1>9){
                         ans+=to_string(count);
                ans+=s[i-1];
                count=0;
                    }
                }
            else if(i>0 && s[i]!=s[i-1]){
                ans+=to_string(count+1);
                ans+=s[i-1];
                count=0;
            }
           
        }
         ans+=to_string(count+1);
                ans+=s[s.size()-1];
                count=0;
        return ans;
        
    }
};