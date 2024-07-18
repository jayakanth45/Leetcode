class Solution {
    public int maxArea(int[] height) {
        int start=0;
        int end=height.length-1;
        int max_water=Integer.MIN_VALUE;
        int ans=0;
        while(start<end){
            ans=Math.min(height[start],height[end])*(end-start);
            max_water=Math.max(max_water,ans);
            if(height[start]<height[end]){
                start++;
            }
            else if(height[start]>height[end]){
                end--;
            }
            else{
                start++;
                end--;
            }
            
        }
        return max_water;
        
    }
}