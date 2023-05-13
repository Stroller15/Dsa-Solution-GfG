//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*WE CAN DO TOPO SORT WITH TWO WAYS {1- dfs} AND {2- bfs(kanh'S algO)}*/

// BFS
// Time Complexity - O(V+E) + O(V)
// Space Complexity - O(V) + O(V)

// class Solution
// {
// 	public:
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    int indegree[V] = {0};
// 	    vector<int> topo;
// 	    // Finding indegree of every element
// 	    for(int i = 0 ; i < V ; i++) {
// 	        for(auto it : adj[i]) {
// 	            indegree[it]++;
// 	        }
// 	    }
	    
// 	    queue<int> q;
//         // pushing all nodes with indegree 0 because it will confirm that 
//         // it always be first before any node
// 	    for(int i = 0 ; i < V ; i++) {
// 	        if(indegree[i] == 0) 
// 	            q.push(i);
// 	    }
	    
// 	    while(!q.empty()) {
// 	        int node = q.front();
// 	        topo.push_back(node);
// 	        q.pop();
	        
// 	        for(auto it : adj[node]) {
// 	            indegree[it]--;
// 	            if(indegree[it] == 0)
// 	                q.push(it);
// 	        }
// 	    }
// 	    return topo;
// 	}
// };

/********************************** DFS WAY   ******************************************************/
class Solution
{
    private:
    void dfs(vector<int> adj[], stack<int> &topoSort, vector<int> &vis, int src) {
        vis[src] = 1;
        
        for(auto adjNode : adj[src]) {
            if(!vis[adjNode]) {
                dfs(adj, topoSort, vis, adjNode);
            }
        }
        
        topoSort.push(src);
    }
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> topoSort;
	    vector<int> ans;
	    vector<int> vis(V, 0);
	    
	    for(int i = 0 ; i < V ; i++) {
	        if(!vis[i]) {
	            dfs(adj, topoSort, vis, i);
	        }
	    }
	    
	    while(!topoSort.empty()) {
	        ans.push_back(topoSort.top());
	        topoSort.pop();
	    }
	    
	    return ans;
	}
};


//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends