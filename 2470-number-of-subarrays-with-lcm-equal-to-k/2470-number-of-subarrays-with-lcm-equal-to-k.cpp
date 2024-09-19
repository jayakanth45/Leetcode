class Solution {
public:
    long long lcm(long long a, long long b)
    {
        return (a/__gcd(a,b))*b;
    }
    int subarrayLCM(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int ans=0;
        for(int x=0; x<n; x++)
        {
            int l=1;
            for(int y=x; y<n; y++)
            {
                l=lcm(l,nums[y]);
                if(l==k) ans++;
                else if(l>k) break;
            }
        }
        return ans;
    }
};