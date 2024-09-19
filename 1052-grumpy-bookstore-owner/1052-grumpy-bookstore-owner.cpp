class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int i=0;
        int j=0;
        int sum=0,max1=INT_MIN,start=0,end=0,sum1=0;
        while(i<grumpy.size()){
            sum+=grumpy[i];
            if(grumpy[i]==1)
            sum1+=customers[i];
            if(i-j+1==minutes){
                if(sum!=0){
                    if(sum1>max1){
                        start=j;
                        end=i;
                        max1=sum1;
                    }
                }
                sum-=grumpy[j];
                if(grumpy[j]==1)
                sum1-=customers[j];
                j++;
            }
            i++;
            
        }
        int ans=0;
        for(int i=0;i<grumpy.size();i++){
            if(grumpy[i]==0 || ( i>=start && i<=end))
                ans+=customers[i];
        }
        return ans;
        
    }
};