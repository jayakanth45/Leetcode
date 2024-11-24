class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int max1=0;
        for(int i=0;i<colors.size();i++){
            for(int j=i+1;j<colors.size();j++){
                if(colors[j]!=colors[i]){
                    max1=max(max1,j-i);
                }
            }
        }
        return max1;
        
    }
};