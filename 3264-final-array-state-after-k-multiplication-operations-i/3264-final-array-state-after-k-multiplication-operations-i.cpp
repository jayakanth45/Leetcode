class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       for(int i=0;i<nums.size();i++){
           pq.push({nums[i],i});
       }
        int p,q;
        while(k--){
            p=pq.top().first;
            q=pq.top().second;
            pq.pop();
            nums[q]=p*multiplier;
            pq.push({nums[q],q});
        }
        return nums;
    }
};