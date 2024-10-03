class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
     int ans=0;
        unordered_map<int,int> um;
        for(int i=0;i<arr.size();i++){
            int rem=(arr[i]%k+k)%k;
            int t=(k-rem)%k;
            if(um.find(t)!=um.end() && um[t]>0){
                ans++;
                um[t]--;
            }
            else{
                um[rem]++;
            }
        }
        return arr.size()/2==ans?true:false;
        
    }
};