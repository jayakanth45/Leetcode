class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n) ;

        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]}) ;
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]}) ;
        }

        vector<double> dis(n, -1) ;
        dis[start_node] = 1 ; // Stores the highest probability of reaching a node.

        priority_queue<pair<double, int>> pq ; // Max-heap of { probability, node }.
        pq.push({ 1.0, start_node }) ;

        while(!pq.empty())
        {
            auto [currProb, currNode] = pq.top() ;
            pq.pop() ;

         // If the current probability is less than the stored one, skip it.
         // Because, it will only decrease further on multiplying with a probability
         // number lying within the range [0, 1].
            if (currProb < dis[currNode]) continue;

            for(auto nodePair : adj[currNode])
            {
                auto [node, prob] = nodePair ;
                double newProb = currProb * prob ;

                if(newProb > dis[node])
                {
                    dis[node] = newProb ;
                    pq.push({ newProb, node }) ;
                }
            }
        }

        return dis[end_node] == -1 ? 0 : dis[end_node] ;
    }
};