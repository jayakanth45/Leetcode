class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int result = INT_MIN;
        int maxEle = arrays[0].back();
        int minEle = arrays[0].front();
        for(int i = 1 ; i< arrays.size();i++){
            int currMax = arrays[i].back();
            int currMin = arrays[i].front();
            result = max(result , max(abs(maxEle - currMin),abs(minEle - currMax)));
            maxEle = max(maxEle , currMax);
            minEle = min(minEle , currMin);
        }
        return result;
    }
};