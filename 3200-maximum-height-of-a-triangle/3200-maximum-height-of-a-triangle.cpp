class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int r1=red;
        int b1=blue;
      int count1=1;
        bool flag=0;
        int ans1=0;
      while(true){
          if(flag==0){
              if(red-count1<0){
                  ans1=count1-1;
                  break;
              }
              else{
                  red-=count1;
              }
              flag=1;
          }
          else{
              if(blue-count1<0){
                  ans1=count1-1;
                  break;
              }
              else{
                  blue-=count1;
              }
              flag=0;
          }
          count1++;
      }
        int count2=1,ans2=0,k=0;
         red=r1,blue=b1;
        flag=0;
        while(true){
          if(flag==0){
              if(blue-count2<0){
                  ans2=count2-1;
                  break;
              }
              else{
                  blue-=count2;
              }
              cout<<blue;
              flag=1;
             
          }
           else{
        
              if(red-count2<0){
                  ans2=count2-1;
                  break;
              }
              else{
                  red-=count2;
              }
              flag=0;
          }
          count2++;
            k++;
      }
        return max(ans1,ans2);
        
        
        
    }
};