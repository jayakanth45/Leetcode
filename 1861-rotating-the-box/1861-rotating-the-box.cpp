class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();
        int flag=0,find=0;
        vector<vector<char>> ans(n,vector<char>(m,'.'));
        int k=m-1;
        for(int i=0;i<box.size();i++){
            for(int j=0;j<box[i].size();j++){
                ans[j][k]=box[i][j];
            }
            k--;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(ans[j][i]=='#'){
                   flag=1;
                   find=0;
                   int p=j;
                   p++;
                   while(flag && p<n){
                       if(p<n && ans[p][i]=='*'){
                           flag=0;
                       }
                       else if(ans[p][i]=='.'){
                           flag=0;
                           find=1;
                           ans[p][i]='#';
                       }
                       else{
                           p++;
                       }
                   }
                   if(find){
                       
                       ans[j][i]='.';
                   }
                   else{
                       //cout<<j<<i;
                       ans[j][i]='#';
                   }
               }
            }
        }
        
        
        
        
        
        
        return ans;
    }
};