class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,ans1=0;
        int buy=prices[0];
        int cp=0;
        int ele=0;
        for(int i=1;i<prices.size();i++){
            if(i==prices.size()-1){
                ans1+=max(prices[i]-buy,cp);
            }
            else if(prices[i]<buy || prices[i]<ele){
                ans1+=ans;
                buy=prices[i];
                cout<<buy<<" ";
                ans=0;
                ele=0;
                cp=0;
            }
            else if(prices[i]-buy>cp){
                ele=prices[i];
                ans=prices[i]-buy;
                cp=prices[i]-buy;
            }
            
        }
        
        return ans1;
        
    }
};