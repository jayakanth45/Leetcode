class Solution {
public:
    bool rotateString(string s, string goal) {
        
    if(s.size()!=goal.size())
        return false;
        int n=s.size();
        if(s==goal){
            return true;
        }
        while(n--){
             s+=s[0];
             s.erase(s.begin());
            if(s==goal){
                return true;
            }
        }
     return false;   
    }
};