class Solution {
public:
    bool isCircularSentence(string s) {
        
        //bool flag=0;
        char ch;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
              
                continue;
            }
             if(i>0 && s[i-1]==' '){
                  cout<<i;
                if(s[i]!=ch){
                    
                    return false;
                }
            }
            else if(i<n-1 && s[i+1]==' '){
                
                ch=s[i];
            }
            
            
        }
       
        
        
        if(s[n-1]!=s[0]){
            return false;
        }
        return true;
        
    }
};