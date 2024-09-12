class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        unordered_map<int,vector<int>> um;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0)
                um[i].push_back(j);
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    if(um.find(i)!=um.end()){
                        cnt=count(um[i].begin(),um[i].end(),j);
                        if(cnt>0){
                            int start=0;
                            while(start<=n-1){
                                matrix[i][start]=0;
                                start++;
                            }
                            int start1=0;
                            while(start1<=m-1){
                                matrix[start1][j]=0;
                                start1++;
                                
                            }
                            
                            
                            
                            
                        }
                    }
                }
            }
        }
        
        
    }
};