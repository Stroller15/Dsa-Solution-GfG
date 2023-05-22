//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Using DFS
// Time Complexity - O(V+E) 
// Space Complexity - O(V)
// class Solution {
//   private:
//     bool dfs(vector<int> &visited, vector<int> &dfsVisited, vector<int> adj[], int src) {
//         visited[src] = true;
//         dfsVisited[src] = true;
        
//         for(auto node: adj[src]) {
//             if(!visited[node]) {
//                 if(dfs(visited, dfsVisited, adj, node))
//                     return true;
//             }
            
//             else if(visited[node] && dfsVisited[node]) {
//                 return true;
//             }
//         }
        
//         dfsVisited[src] = false;
//         return false;
//     }
    
//   public:
//     bool isCyclic(int V, vector<int> adj[]) {
//         vector<int> visited(V, false), dfsVisited(V, false);
        
//         for(int i = 0 ; i < V ; i++) {
//             if(!visited[i]) {
//                 if(dfs(visited, dfsVisited, adj, i))
//                     return true;
//             }
//         }
//         return false;
//     }
// };

// This code uses Depth First Search (DFS) to detect a cycle in a directed graph. 
// It marks each visited node as visited and also marks nodes that have been 
// visited in the current traversal. If a node is visited again and is marked as 
// visited in the current traversal, then a cycle is detected.


// *********************************************************

// Time Complexity - O(V + E)
// Space Complexity - O(V)
// Topo Sort(Kahn's algo) which only apply on Directed Acyclic Graph() + BFS

class Solution {
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        int indegree[V] = {0};
        
        for(int i = 0 ; i < V ; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        int cnt = 0;
        
        // Checking for 0 indegree node
        for(int i = 0 ; i < V ; i++) {
            if(indegree[i] == 0)
            q.push(i);
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
    
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        // If count is equal to vertex then there is no cycle
        return cnt == V ? false : true;
    }
};

// **************************************************************








//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends