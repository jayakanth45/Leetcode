const int N = 1e6+10;
int dp[N]; 
int m[N];
class Solution {
public:
    int smallestDistancePair(vector<int>& arr1, int k) {
        memset(dp, 0, sizeof(dp));
        memset(m, 0, sizeof(m));

        for(auto e : arr1) m[e]++;

        vector<int> arr; 
        for(int i=0; i<N; i++) 
            if(m[i] != 0) arr.push_back(i); 
        // for(auto e : arr) cout << e << " ";
        
        for(int i=0; i<arr.size(); i++){
            auto v = arr[i], f = m[v];
            dp[0] += ((f * (f-1)) / 2);

            
            for(int j=i+1; j<arr.size(); j++){
                auto v2 = arr[j], f2 = m[v2];
                dp[abs(v2-v)] += f * f2;
            }
        }

        // for(int i=0; i<10; i++) cout << dp[i] << " ";
        int total = 0;
        for(int i=0; i<N; i++){
            total += dp[i];
            if(total >= k) return i;
        }


        return -1;
    }
};