class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n+1);
        for(int i=0;i<edges.size();i++){
            vector<int>edge = edges[i];
            int src = edge[0];
            int dest = edge[1];
            double p = succProb[i];
            adj[src].push_back({dest,p});
            adj[dest].push_back({src,p});
        }
        vector<double>prob(n,0.0);
        priority_queue<pair<double,int>> pq;
        prob[start_node]=1.0;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            double currProb = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(node == end_node)
                return currProb;

            if(currProb < prob[node])
                continue;
            
            for(auto it : adj[node]) {
                int next = it.first;
                double edgeProb = it.second;
                double newProb = currProb * edgeProb;
                if(newProb > prob[next]) {
                    prob[next] = newProb;
                    pq.push({newProb, next});
                }
            }
            
        }
        return 0.0;

    }
};