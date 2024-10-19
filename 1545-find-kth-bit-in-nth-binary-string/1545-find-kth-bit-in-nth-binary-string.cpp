class Solution {
public:
    string giveans(string s){
        string temp="";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                temp+='1';
            }
            else{
                temp+='0';
            }
        }
        return temp;
        
    }
    char findKthBit(int n, int k) {
        string str="0";
        string rev="0";
        while(n--){
            str+="1"+giveans(str);
            
            
        }
        return str[k-1];
        
    }
};