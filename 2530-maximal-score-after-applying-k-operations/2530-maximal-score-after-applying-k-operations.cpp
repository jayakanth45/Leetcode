class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(k>0){
            double a=pq.top();
            ans+=pq.top();
            pq.pop();
            cout<<ceil(a/3);
            pq.push(ceil(a/3));
            k--;
            
        }
        return ans;
        
    }
};