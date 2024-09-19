class Solution {
public:
    string longestPalindrome(string s) {
        int siz=s.size();
        int arambam=0;
        int antham=1;
        int start,end=0;
        for(int i=0;i<siz;i++){
            start=i-1;
            end=i;
            while(start>=0 && end<siz && s[start]==s[end]){
                if(end-start+1>antham){
                    arambam=start;
                    antham=end-start+1;
                }
                start--;
                end++;
            }
             start=i-1;
            end=i+1;
            while(start>=0 && end<siz && s[start]==s[end]){
                if(end-start+1>antham){
                    arambam=start;
                    antham=end-start+1;
                }
                start--;
                end++;
            }
            
        }
        return s.substr(arambam,antham);
        
        
    }
};