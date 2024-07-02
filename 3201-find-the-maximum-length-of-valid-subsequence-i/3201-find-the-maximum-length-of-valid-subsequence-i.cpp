class Solution {
public:
    int maximumLength(vector<int>& a) {
         int ans=1;
        int cnt=a[0]%2;
        int n=a.size();
        vector<int>occ(2,0);
        occ[a[0]%2]++;
        for (int i=1;i<n;i++){
            if (a[i]%2!=cnt){
                ans++;
                cnt=1-cnt;
            }
            occ[a[i]%2]++;
        }
        return max({occ[0],ans,occ[1]});
    }
};