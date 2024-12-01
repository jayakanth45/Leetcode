class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0;
        int cows=0;
        unordered_map<char,int> um;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
            else
            um[secret[i]]++;
        }
        for(int i=0;i<guess.size();i++){
            if(um.find(guess[i])!=um.end() && um[guess[i]]>0 && secret[i]!=guess[i]){
                    cows++;
                    um[guess[i]]--;
            }
        }
        string ans="";
        ans+=to_string(bulls)+'A'+to_string(cows)+"B";
        return ans;
    }
};