class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long sum=0;
        for(auto x:gifts){
            sum+=x;
            pq.push(x);
        }
        long long ans=0;
        while(k--){
            int a=pq.top();
            int h=a-floor(sqrt(a));
            ans+=h;
            pq.pop();
            pq.push(floor(sqrt(a)));
        }
        return abs(ans-sum);
    }
};