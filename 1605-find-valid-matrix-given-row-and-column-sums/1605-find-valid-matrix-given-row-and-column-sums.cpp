class Solution {
public:
    
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int nr=rowSum.size();
        int nc=colSum.size();
        vector<vector<int>> ans(nr, vector<int>(nc, 0));
        int i=0,j=0;
        while(true)
        {
            ans[i][j]=min(rowSum[i],colSum[j]);
                rowSum[i]-=ans[i][j];
                colSum[j]-=ans[i][j];

            if(i==nr-1 && j==nc-1)
            break;
            if(j==nc-1)
            {
                i=(i+1)%nr;
            }
                j=(j+1)%nc;
        }
        return ans;
        
    }
};