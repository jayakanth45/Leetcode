class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp(arr);
        sort(temp.begin(),temp.end());
        unordered_map<int,int> um;
        int k=1;
        for(int i=0;i<temp.size();i++){
            if(um.find(temp[i])!=um.end()){
                continue;
            }
            else{
                um[temp[i]]=k;
                k++;
            }
        }
        for(int i=0;i<arr.size();i++){
            temp[i]=um[arr[i]];
        }
        return temp;
        
        
    }
};