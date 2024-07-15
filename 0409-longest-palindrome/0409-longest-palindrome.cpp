class Solution {
public:
    int longestPalindrome(string s) {
        int count=0;
        unordered_map<char,int> um;
        for(int i=0;i<s.size();i++){
            um[s[i]]++;
        }
        int ans=0;
        for(auto x:um){
           int n=x.second;
            if(n % 2 == 0){
                ans = ans + n;
            }
            else if(n % 2 != 0){
                if(count==0){
                    ans = ans+(n);
                    count++;
                }
                else
                {
                    ans = ans + (n-1);
                }     
            }
        }
        return ans;
    }
};