class Solution {
public:
    string getSmallestString(string s) {
        
        
        for(int i=1;i<s.size();i++){
            if(int(s[i]-48)%2==int(s[i-1]-48)%2 && int(s[i]-48)<int(s[i-1]-48)){
                swap(s[i],s[i-1]);
                break;
            }
            
        }
        return s;
    }
};