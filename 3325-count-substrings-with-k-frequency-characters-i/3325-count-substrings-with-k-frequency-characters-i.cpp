class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int count=0;
        unordered_map<char,int> um,temp;
        int j=0;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            um[s[i]]++;
          
            while(um[s[i]]>=k){
                count+=n-i;
                um[s[j]]--;
                j++;
            }
            
        }
        return count;
        
        
    }
};