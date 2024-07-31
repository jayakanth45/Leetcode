class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
         int n=(int)books.size();
       vector<int>dp(n+1,-1);
       function<int(int)>f=[&](int i)->int{
        if(i==n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int res=INT_MAX;
        int maxm=0;
        int sum=0;
         for(int j=i;j<n;j++)
         {
            if((sum+books[j][0])>shelfWidth)
            break;
            sum+=books[j][0];
            maxm=max(maxm,books[j][1]);
            res=min(res,maxm+f(j+1));
         }

         return dp[i]=res;
       };   

       int ans=f(0);
       return ans;
    }
};