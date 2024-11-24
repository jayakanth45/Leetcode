class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max1=-1;
        vector<int> ans(arr.size(),-1);
        for(int i=arr.size()-1;i>=0;i--){
            ans[i]=max1;
            max1=max(max1,arr[i]);
           
        }
        return ans;
    }
};