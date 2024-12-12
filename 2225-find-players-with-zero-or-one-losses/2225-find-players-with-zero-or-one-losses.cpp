class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp,um;
        for(int i=0;i<matches.size();i++){
            mp[matches[i][0]]++;
            um[matches[i][1]]++;
        }
        vector<vector<int>> ans(2);
        for(auto x:mp){
            if(um.find(x.first)==um.end()){
                ans[0].push_back(x.first);
            }
        }
        for(auto x:um){
            if(x.second==1){
                ans[1].push_back(x.first);
            }
        }
        return ans;
    }
};