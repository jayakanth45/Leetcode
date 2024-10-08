class Solution {
public:
    int minSwaps(string s) {
        int swaps=0;
        int imbalanced=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                imbalanced++;
            }
            else if(s[i]=='['){
                imbalanced--;
            }
            if(imbalanced>0){
                swaps++;
                imbalanced-=2;
            }
        }
        return swaps;
        
    }
};