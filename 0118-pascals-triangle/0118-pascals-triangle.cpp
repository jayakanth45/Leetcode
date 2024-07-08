class Solution {
public:
  vector<int> sumup(int n){
        int res=1;
      vector<int> temp;
         temp.push_back(1);
        for(int i=1;i<n;i++){
            res=res*(n-i);
            
            res/=i;
            temp.push_back(res);
        }
        return temp;
    }
    void giveans(vector<vector<int>> &ans,int n){
       for(int i=1;i<=n;i++){
           ans.push_back(sumup(i));
       }
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        giveans(ans,numRows);
        return ans;
        
    }
};