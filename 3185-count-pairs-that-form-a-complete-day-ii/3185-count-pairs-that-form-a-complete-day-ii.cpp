class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long count= 0;
        unordered_map<int,int> um;
    
    
    for (int i=0;i<hours.size();i++) {
        int rem = hours[i] % 24;
        
        int count1 = (24 - rem) % 24;
        count+= um[count1];
    um[rem]++;
    }
    
    return count;
        
        
    }
};