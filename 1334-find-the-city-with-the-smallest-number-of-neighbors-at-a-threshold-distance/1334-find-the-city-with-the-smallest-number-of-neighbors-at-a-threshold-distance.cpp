class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> ans(n,vector<int>(n,distanceThreshold+1));
        for(int i=0;i<edges.size();i++){
            ans[edges[i][0]][edges[i][1]]=edges[i][2];
            ans[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j){
                        continue;
                    }
                    else if(ans[i][k]+ans[k][j]<=distanceThreshold){
                        ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
                    }
                }
            }
        }
        int city=0,prev=0;
        for(int i=0;i<n;i++){
            if(ans[0][i]<=distanceThreshold){
                prev++;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            count=0;
            for(int j=0;j<n;j++){
                if(ans[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(prev==count){
                city=max(city,i);
            }
            else if(count<prev){
                city=i;
                prev=count;
            }
        }
        return city;
    }
};