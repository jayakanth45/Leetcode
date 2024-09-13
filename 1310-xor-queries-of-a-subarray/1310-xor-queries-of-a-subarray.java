class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = arr.length;
        int []prexor = new int[n];
        prexor[0] = arr[0];
        for(int i=1;i<n;i++){
            prexor[i] = arr[i] ^ prexor[i-1];
        }
        int ans[] = new int[queries.length];
        for(int i = 0;i<queries.length;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            ans[i] = l==0 ? prexor[r]:prexor[l-1] ^ prexor[r];
        }
        return ans;
    }
}