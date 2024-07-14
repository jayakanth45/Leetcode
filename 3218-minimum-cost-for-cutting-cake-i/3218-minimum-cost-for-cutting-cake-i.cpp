class Solution {
public:
    int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
       int hb=1,vb=1,ans=0;
        
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        
        int i=h.size()-1,j=v.size()-1;

        while(i>=0 and j>=0){
            if(v[j]>=h[i]){
                ans+=v[j]*hb;
                vb++;
                j--;
            }
            else{
                ans+=h[i]*vb;
                hb++;
                i--;
            }
        }
        while(i>=0){
            ans+=h[i]*vb;
            hb++;
            i--;
        }
        while(j>=0){
            ans+=v[j]*hb;
            vb++;
            j--;
        }

        return ans;
 
    }
};