class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
      vector<int> ans;
        map<int,int> mp;
        for(auto x:nums){
            mp[x]++;
        }
       map<int,vector<int>> temp;
        for(auto x:mp){
            temp[x.second].push_back(x.first);
        }
        for(auto x:temp){
            vector<int> temp1;
            for(int i=0;i<x.second.size();i++){
                temp1.push_back(x.second[i]);
            }
            for(int k=temp1.size()-1;k>=0;k--){
                while(mp[temp1[k]]--){
                    ans.push_back(temp1[k]);
                }
            }
        }
        return ans;
        
        
    }
};