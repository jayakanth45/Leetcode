class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> um;
        for(auto x:allowed){
            um[x]=1;
        }
        bool flag=0;
        int ans=0;
        for(auto k:words){
            flag=0;
            string str=k;
            for(auto y:k){
                if(um.find(y)==um.end()){
                    flag=1;
                    break;
                }
            }
            if(!flag){
                ans++;
            }
            
        }
        return ans;
        
    }
};