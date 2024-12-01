class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<double,int> um;
        for(auto x:arr){
            if(um.find(x*2)!=um.end() || (um.find(x/2)!=um.end() && x%2==0)){
                return true;
            }
            else{
                um[x]++;
            }
        }
        return false;
        
    }
};