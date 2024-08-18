class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s;
        s.insert(1);
        
        long long ugly = 1;
        for (int i = 1; i < n; i++) {
            ugly = *s.begin(); 
            s.erase(s.begin()); 

            
            s.insert(ugly * 2);
            s.insert(ugly * 3);
            s.insert(ugly * 5);
        }

        return *s.begin();
    }
};