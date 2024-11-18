class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> ans(n,0);
        int lyt=0;
     
        
         if(k>0){
            
            for(int i=0;i<code.size();i++){
                int p=k;
                int sum=0;
                int j=(i+1)%n;
                while(p--){
                    sum+=code[j];
                    //cout<<code[j]<<endl;
                    j=(j+1)%n;
                }
               ans[lyt++]=sum;
                
            }
           
        }
        else if(k<0){
             for(int i=0;i<code.size();i++){
                int p=-1*k;
                 cout<<p<<endl;
                int sum=0;
                 int j=(i-1)%n;
                 if(i==0){
                     j=n-1;
                 }
                
                while(p--){
                    sum+=code[j];
                    
                    j=(j==0)?n-1:(j-1)%n;
                    
                }
                ans[lyt++]=sum;
            }
            
        }
        return ans;
        
    }
};