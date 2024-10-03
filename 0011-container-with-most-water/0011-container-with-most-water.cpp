class Solution {

public:
    int maxArea(vector<int>& input) {
        int start=0;
        int end=input.size()-1;
        int ans;
        int max1=INT_MIN;
        while(start<end){
                ans=min(input[start],input[end])*(end-start);
                if(max1 < ans){
                    max1=ans;
                }
                if(input[start] < input[end]){
                    start++;
                }else if(input[start] > input[end]){
                    end--;
                }else{
                    start++;
                    end--;
                }
        }
        return max1;
    }
};