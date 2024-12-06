class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int> um;
        for(auto x:banned){
            um[x]++;
        }
        int count=0,curr=0;
        for(int i=1;i<=n;i++){
           
            if(um.find(i)==um.end()){
                curr+=i;
                 if(curr>maxSum){
                return count;
            }
                count++;
            }
            
        }
        return count;
        
    }
};