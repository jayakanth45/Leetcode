class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        unordered_map<int,int> um;
        for(auto x:spaces){
            um[x]=1;
        }
        for(int i=0;i<s.size();i++){
            if(um.find(i)!=um.end()){
                ans+=' ';
            }
            ans+=s[i];
        }
        return ans;
    }
};