class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int ans=(skills[0]>skills[1]) ? 0 : 1;
        int count=1;
        for(int i=2;i<skills.size();i++){
            if(count==k) return ans;
            if(skills[ans]<skills[i]){
                ans=i;
                count=1;
            }
            else count++;
        }
        return ans;
    }
};