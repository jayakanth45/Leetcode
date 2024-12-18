class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n=prices.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()>prices[i]){
                st.pop();
            }
            int k=prices[i];
            if(!st.empty()){
                prices[i]=prices[i]-st.top();
            }
            st.push(k);
        }
        return prices;
        
    }
};