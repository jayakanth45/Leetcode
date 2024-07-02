class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int count=0;
        unordered_map<int,int> um;
        for(auto x:arr){
            int rem=(x%k+k)%k;
            int p=(k-rem)%k;
            if(um.find(p)!=um.end() && um[p]>0){
                count++;
                um[p]--;
            }
            else
            
            
            um[rem]++;
            
        }
        if(count==arr.size()/2){
            return true;
            
        }
        return false;
        
    }
};