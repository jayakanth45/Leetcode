class Solution {
    public String longestPalindrome(String s) {
        String ans="";
         int p=s.length();
        int start,end,arambam=0,antham=Integer.MIN_VALUE;
        for(int i=0;i<p;i++){
            start=i;
            end=i;
            while(start>=0 && end<p && s.charAt(start)==s.charAt(end)){
                if(end-start+1>antham){
                    antham=end-start+1;
                    ans=s.substring(start,end+1);
                    
                }
                start--;
                end++;
            }
            
            start=i;
            end=i+1;
            while(start>=0 && end<p && s.charAt(start)==s.charAt(end)){
                if(end-start+1>antham){
                   antham=end-start+1;
                   ans=s.substring(start,end+1);
                }
                start--;
                end++;
            }
            
            
        }
        return ans;
        
    }
}