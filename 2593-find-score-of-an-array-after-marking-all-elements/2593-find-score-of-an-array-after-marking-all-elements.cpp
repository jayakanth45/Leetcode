class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score=0;
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int n=nums.size();
        unordered_map<int,int> um;
        for(auto x:mp){
                int k=0;
                while(k<x.second.size()){
                    if(um.find(x.second[k])!=um.end()){
                        
                    }
                    else{
                        score+=x.first;
                        um[x.second[k]]++;
                        if(x.second[k]>0){
                            um[x.second[k]-1]++;
                        }
                        if(x.second[k]<n-1){
                            um[x.second[k]+1]++;
                        }
                    }
                    k++;
                }
            
            
        }
        return score;
        
    }
};