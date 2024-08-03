class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> um;
        for(int i=0;i<target.size();i++){
            um[target[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(um.find(arr[i])==um.end() || um[arr[i]]==0){
                return false;
            }
            else{
                um[arr[i]]--;
            }
        }
        return true;
        
        
    }
};