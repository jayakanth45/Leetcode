class Solution {
public:
    vector<int> getRow(int n) {
         n=n+1;
        long long res=1;
      vector<int> temp;
      temp.push_back(1);
        for(int i=1;i<n;i++){
            res=res*(n-i);
            res/=(i);
            temp.push_back(res);
        }
        return temp;
    
        
    }
};