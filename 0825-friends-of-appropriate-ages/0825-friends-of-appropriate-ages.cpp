class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());
        int ans=0;
        for(int i=1;i<ages.size();i++){
            int x=i;
            int y=i-1;
            while(y>=0){
           
                if(ages[x]==ages[y] && ages[y]>0.5*ages[x]+7){
                 
                    ans+=2;
                    
                }
               else if(ages[y]>0.5*ages[x]+7){
                   
                    ans+=1;
                  
                  
                }
                else{
                    break;
                }
                
                
                y--;
            }
            
            
            
        }
        return ans;
        
    }
};