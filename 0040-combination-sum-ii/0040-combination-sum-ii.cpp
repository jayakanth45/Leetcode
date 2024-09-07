class Solution {
public:
    void combination(vector<vector<int>> &ans,vector<int> &temp,int idx,int target,vector<int> &arr){
        
            if(target==0)
            {
                ans.push_back(temp);
                    return;
            }
        
        
        for(int i=idx;i<arr.size();i++){
            if(i!=idx && arr[i]==arr[i-1])
                continue;
            if(arr[i]>target)
                break;
            temp.push_back(arr[i]);
            combination(ans,temp,i+1,target-arr[i],arr);
            temp.pop_back();
        }
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        combination(ans,temp,0,target,candidates);
        return ans;
    }
};