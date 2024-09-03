class Solution {
public:
    int getLucky(string s, int k) {
        int sum=0;
        for(auto x:s){
            int p=int(x)-96;
            if(p>9){
                sum+=p%10;
                sum+=p/10;
               
            }
            else{
                sum+=p;
            }
        }
        k--;
        while(k>0){
            int temp=sum;
            sum=0;
            while(temp>0){
                sum+=temp%10;
                temp/=10;
            }
            k--;
        }
        return sum;
        
    }
};