class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives=0,tens=0;
        for(int i=0;i<bills.size();i++){
          if(bills[i]==5){
              fives++;
          }
            else if(bills[i]==10){
                if(fives==0){
                    return false;
                }
                fives--;
                tens++;
            }
            else{
                if(!(fives>=3) && !(tens>=1 && fives>=1)){
                    return false;
                }
                else{
                    if(tens>=1 && fives>=1){
                        tens--;
                        fives--;
                    }
                    else{
                        fives-=3;
                    }
                }
            }
        }
        return true;
    }
};