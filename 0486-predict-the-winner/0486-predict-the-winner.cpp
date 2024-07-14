class Solution {
public:
    bool giveans(vector<int> nums,int idx,int idx1,int n,int count,int p,int score1,int score2){
       if (idx > idx1) {
        return score1 >= score2;
    }
        
        
        
        if(p){
            return giveans(nums,idx+1,idx1,n,count+1,0,score1+nums[idx],score2) || giveans(nums,idx,idx1-1,n,count+1,0,score1+nums[idx1],score2);
            
        }
      return giveans(nums,idx+1,idx1,n,count+1,1,score1,score2+nums[idx])  && giveans(nums,idx,idx1-1,n,count+1,1,score1,score2+nums[idx1]);
        
        
        
        
        
    }
    bool predictTheWinner(vector<int>& nums) {
        return giveans(nums,0,nums.size()-1,nums.size(),0,1,0,0);
        
    }
};