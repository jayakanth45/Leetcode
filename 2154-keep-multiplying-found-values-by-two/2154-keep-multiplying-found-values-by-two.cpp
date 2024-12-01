class Solution {
public:
    int findFinalValue(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        for(auto x:nums){
            um[x]++;
        }
        int ans=k;
        while(um.find(k)!=um.end()){
            k=ans*2;
            ans*=2;
            
        }
        return ans;
        
    }
};