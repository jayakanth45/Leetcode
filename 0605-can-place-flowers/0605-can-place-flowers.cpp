class Solution {
public:
    bool canPlaceFlowers(vector<int>& bed, int n) {
        int count=0;
        if(n==0){
            return true;
        }
        if(bed.size()==1){
            return bed[0]==0?true:false;
        }
        
        if(bed[0]==0 && bed[1]==0){
            bed[0]=1;
            count=1;
        }
        for(int i=1;i<bed.size()-1;i++){
            if(bed[i]==0 && bed[i-1]==0 && bed[i+1]==0){
                count++;
                bed[i]=1;
            }
        }
        int k=bed.size();
        if(bed[k-1]==0 && bed[k-2]==0){
            count++;
        }
        return count>=n?true:false;
    }
};