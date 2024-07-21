class Solution {
public:

    vector<int> toposort(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n + 1);
        vector<int> indegree(n + 1);
        vector<int> order;
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                count++;
            }
        }
 
        while(!q.empty()) {
	        int u = q.front();
	        order.push_back(u);
	        q.pop();
	        
	        for(int &v : adj[u]) {
	            indegree[v]--;
	            
	            if(indegree[v] == 0) {
	                q.push(v);
                    count++;
	            }
	            
	        }
	    }

        if (count != n) 
            return {};

        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        
        
        vector<int> v1=toposort(mat1,k);
        vector<int> v2=toposort(mat2,k);
        vector<vector<int>> ans(k,vector<int>(k,0));
       if(v1.size()==0 || v2.size()==0){
        return {};
       }
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(v1[i]==v2[j]){
                    ans[i][j]=v1[i];
                }
            }
        }
        return ans;


    }
};