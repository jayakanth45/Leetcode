class Solution {
public:
    int longestMountain(vector<int>& arr) {    
        if(arr.size()<3){
            return 0;
        }
        int n=arr.size();
        bool flag=0;
        bool flag1=0;
        int j;
        int max1=0;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1] && !flag && !flag1){
                j=i-1;
                flag=1;
            }
            else if(arr[i]<arr[i-1] && flag){
                max1=max(i-j+1,max1);
                flag1=1;
            }
            else if(arr[i]>arr[i-1] && flag && flag1){
                i--;
                flag=0;
                flag1=0;
            }
            else if(arr[i]==arr[i-1]){
                flag=0;
                flag1=0;
            }
          
            
            
        }
        return max1;
    }
};