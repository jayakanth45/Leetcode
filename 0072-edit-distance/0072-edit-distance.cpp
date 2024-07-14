class Solution {
public:
    int n,m;
    int dfs(string &word1,string &word2,int i,int j,vector<vector<int>> &dp){
        if(j==m)return n-i;
        if(i==n)return m-j;

        if(dp[i][j]!=-1)return dp[i][j];

        if(word1[i]==word2[j])return dfs(word1,word2,i+1,j+1,dp);
        int ins= 1+dfs(word1,word2,i,j+1,dp);
        int del= 1+dfs(word1,word2,i+1,j,dp);
        int rep= 1+dfs(word1,word2,i+1,j+1,dp);
        return dp[i][j]=min({ins,del,rep});
    }
public:
    int minDistance(string word1, string word2) {
        n=word1.length();
        m=word2.length();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return dfs(word1,word2,0,0,dp);
    }
};