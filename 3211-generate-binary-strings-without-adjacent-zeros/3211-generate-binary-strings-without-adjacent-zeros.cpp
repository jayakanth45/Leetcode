class Solution {
public:
    void generatestrings(int n,vector<string> &ans,string temp,bool flag){
        if(n==0){
            ans.push_back(temp);
            return;
        }
        generatestrings(n-1,ans,temp+"1",1);
        if(flag){
            generatestrings(n-1,ans,temp+"0",0);
        }
 
        
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
   
        generatestrings(n,ans,"",1);
        return ans;
        
    }
};