class Solution {
  private:
    bool dfs(int node, vector<vector<int>>& adj,
             vector<bool>& visited, int count, int n) {
        if (count == n) return true;

        for (int i : adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                if (dfs(i, adj, visited, count + 1, n))
                    return true;
                // Backtracking
                visited[i] = false;
            }
        }
        return false;
    }

  public:
    bool check(int n, int m, vector<vector<int>> edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            visited[i] = true;
            if (dfs(i, adj, visited, 1, n))
                return true;
        }
        return false;
    }
};