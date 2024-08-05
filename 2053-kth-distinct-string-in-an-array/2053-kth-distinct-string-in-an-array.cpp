class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> um;
        for(auto x:arr){
            um[x]++;
        }
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(um[arr[i]]==1){
               
                count++;
            }
           
            if(count==k){
                return arr[i];
            }
        }
        return "";
        
    }
};