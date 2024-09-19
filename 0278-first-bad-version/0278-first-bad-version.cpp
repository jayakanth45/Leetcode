// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1;
        int h=n;
        int mid=0;
        if(n==1)
            return isBadVersion(n)?1:0;
        int ans=0;
        while(l<=h){
            mid=h+(l-h)/2;
            if(isBadVersion(mid)){
                ans=mid;
                h=mid-1;
            }
            else 
                l=mid+1;
        }
        return ans;
    }
};