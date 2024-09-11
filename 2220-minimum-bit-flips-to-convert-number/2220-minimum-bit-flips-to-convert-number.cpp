class Solution {
public:
    int minBitFlips(int start, int goal) {
        string strt="";
        while(start>0){
            strt=to_string(start%2)+strt;
            start/=2;
        }
        string goa="";
        while(goal>0){
            goa=to_string(goal%2)+goa;
            goal/=2;
            
        }
       while (strt.size() < goa.size()) strt = '0' + strt;
    while (goa.size() < strt.size()) goa = '0' + goa;

    int ans = 0;
    // Compare the two binary strings
    for (int i = 0; i < strt.size(); i++) {
        if (strt[i] != goa[i]) {
            ans++;
        }
    }
        return ans;
        
    }
};