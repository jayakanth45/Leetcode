class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        int rem=0;
        int k=0;
        while(numBottles>0){
            ans+=(numBottles+rem)/numExchange;
            k=rem;
            rem=(numBottles+rem)%numExchange;
            numBottles=(numBottles+k)/numExchange;
           
        }
        return ans;
        
    }
};