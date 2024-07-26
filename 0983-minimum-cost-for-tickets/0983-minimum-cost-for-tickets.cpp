class Solution {
private:
    int solve(int n,vector<int> &days,vector<int> &cost,int index,vector<int> &dp)
{
    //base case
    if(index>=n) return 0;
        if(dp[index]!=-1){
            return dp[index];
        }

    //1 day pass
    int opt1=cost[0]+solve(n,days,cost,index+1,dp);

    int i;
    //7 day pass
    for(i=index;i<n && days[i]<days[index]+7;i++);

    int opt2=cost[1]+solve(n,days,cost,i,dp);

    //30 day pass 
    for(i=index;i<n && days[i]<days[index]+30;i++);

    int opt3=cost[2]+solve(n,days,cost,i,dp);

    return dp[index]=min(opt3,min(opt1,opt2));
}


public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
       
        int n=days.size();
         vector<int> dp(n+1,-1);
    return solve(n,days,cost,0,dp); 
    }
};