class Solution {
public:
    
    string s;
    int n=0;
    int dp[101][101];
    int solve(int l, int r)
    {
       if(l>=r || l>=n ) return 0;
       if(dp[l][r]!=-1) return dp[l][r];
       int ans= 101;
       for(int i=l+1; i<=r; i++)
       {
           if(s[i]==s[l])
           {
               ans= min(ans, solve(l,i-1)+ solve(i, r));
           }
       }
       ans= min(ans, 1+solve(l+1,r));
       return dp[l][r]=ans;
    }
    int strangePrinter(string s1) {
        s=s1;
        n=s.size();
        memset(dp,-1,sizeof(dp));
        return 1+solve(0,n-1);
    }
};