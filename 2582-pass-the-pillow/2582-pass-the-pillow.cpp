class Solution {
public:
    int passThePillow(int n, int time) {
      int k=1;
        int flag=0;
        while(time--){
     
             if(flag)
                k--;
            else
                k++;
            if(k==n){
                flag=1;
            }
            if(k==1){
                flag=0;
            }
        }
        return k;
        
    }
};