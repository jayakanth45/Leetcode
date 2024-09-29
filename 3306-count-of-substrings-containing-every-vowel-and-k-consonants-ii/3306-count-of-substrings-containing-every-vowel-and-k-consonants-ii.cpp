class Solution {
public:
    long long fun(string word, int k){
        map<char,int> mp;
        map<char,int> mp1;
        
        int i=0;
        int j=0;
        
        int n = word.size();
        int cnt1=0;
        long long ans=0;
        while(j<n){
            mp[word[j]]++;
            
           if(word[j]=='a' || word[j]=='e' || word[j]=='i' || word[j]=='o' || word[j]=='u'){
               mp1[word[j]]++;
           }
            else cnt1++;
            
            while(mp1.size()==5 && cnt1>k){
                if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u'){
                    mp1[word[i]]--;
                    if(mp1[word[i]]==0) mp1.erase(word[i]);
                }
                else{
                    cnt1--;
                }
                mp[word[i]]--;
                if(mp[word[i]]==0) mp.erase(word[i]);
                i++;
            }
            ans+=(j-i+1);
            j++;
            
        }
        return ans;
    }
    
    long long countOfSubstrings(string word, int k) {
        return fun(word,k)-fun(word,k-1);
    }
};