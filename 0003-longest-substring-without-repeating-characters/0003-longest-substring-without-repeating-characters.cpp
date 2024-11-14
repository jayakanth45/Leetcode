class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int max1=0,j=0;
        unordered_map<char,int> u;
        for(int i=0;i<s.size();i++){
            u[s[i]]++;
            while(u[s[i]]>1 && i>=j){
                u[s[j]]--;
                j++;
            }
            max1=max(max1,i-j+1);
        }
        return max1;
    }
};