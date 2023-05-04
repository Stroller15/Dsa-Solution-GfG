//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool detectCycle(vector<int> adj[], vector<int> &vis, int src) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        
        // source and parent
        q.push({src, -1});
        
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            
            for(auto adjecentNode : adj[node]) {
                if(!vis[adjecentNode]) {
                    vis[adjecentNode] = 1;
                    q.push({adjecentNode, node});
                }
                // In this case if adjecentNode is visited and that is not there parent then it
                // will be a cycle
                else if(adjecentNode != parent) {
                    return true;
                }
            }
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V+1, 0);
        // we are doing it for components
        for(int i = 0 ; i < V ; i++) {
            if(!vis[i]) {
                if(detectCycle(adj, vis, i))
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends