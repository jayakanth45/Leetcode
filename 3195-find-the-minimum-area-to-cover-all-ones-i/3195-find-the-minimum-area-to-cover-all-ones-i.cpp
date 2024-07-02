class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
       
        int start1=1,end1=1;
        int flag1=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    if(!flag1){
                        start1=i+1;
                            flag1=1;
                    }
                    end1=i+1;
                    
                    break;
                }
            }
        }
        
        int start2=1,end2=1;
        int flag2=0;
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]==1){
                    if(!flag2){
                        start2=i+1;
                        flag2=1;
                    }
                    end2=i+1;
                    
                    break;
                }
            }
            
        }
        return (end1-start1+1)*(end2-start2+1);
        
    }
};