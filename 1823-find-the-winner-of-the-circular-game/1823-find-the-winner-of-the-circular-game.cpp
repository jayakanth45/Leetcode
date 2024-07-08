class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=i+1;
        }
        int pos=0;
        while(ans.size()>1){
            pos=pos+k-1;
            pos%=ans.size();
            ans.erase(ans.begin()+pos);
        }
        return ans[0];
        
    }
};