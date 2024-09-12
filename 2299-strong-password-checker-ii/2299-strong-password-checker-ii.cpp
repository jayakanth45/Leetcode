class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int count=0;
        bool flag1=0,flag2=0,flag3=0,flag4=0;
        if(password.size()<8){
            return false;
        }
        for(int i=0;i<password.size();i++){
            char x=password[i];
            if(i!=password.size()-1 && password[i]==password[i+1]){
                return false;
            }
           else if(isalpha(x) && islower(x) && !flag1){
                count++;
                flag1=1;
            }
            else if(isalpha(x) && isupper(x) && !flag2){
                count++;
                flag2=1;
            }
            else if(isdigit(x) && !flag3){
                count++;
                flag3=1;
            }
            else if(!isalpha(x) && !isdigit(x)){
                if(!flag4){
                count++;
                    flag4=1;
                }
                
                
            }
        }
        
        if(count==4){
            return true;
        }
        return false;
        
    }
};