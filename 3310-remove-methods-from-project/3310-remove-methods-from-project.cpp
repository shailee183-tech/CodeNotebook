class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);

        for(auto &e : invocations){
            graph[e[0]].push_back(e[1]);
        }

        vector<bool> vis(n,false);
        queue<int> q;
        q.push(k);
        vis[k] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v : graph[u]){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        vector<int> ans;
        for(int u=0;u<n;u++){
            if(vis[u]) continue;

            for(int v: graph[u]){
                if(vis[v]){
                    vector<int> all(n);
                    iota(all.begin(),all.end(),0);
                    return all;
                }
            }
            ans.push_back(u);
        }
        return ans;
    }
};