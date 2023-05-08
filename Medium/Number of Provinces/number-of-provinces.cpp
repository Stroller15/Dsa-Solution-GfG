//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    void dfs(vector<int> adjLst[] , int visited[] , int i) {
        visited[i] = 1;
        
        for(auto x : adjLst[i]) {
            if(!visited[x]) {
                dfs(adjLst , visited , x);
            }
        }
    }
    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjLst[V];
        // change matrix in adjList
        
        for(int i = 0 ; i < V ; i++) {
            for(int j = 0 ; j < V ; j++){
                if(adj[i][j] == 1 && i != j)
                adjLst[i].push_back(j);
                // adjLst[j].push_back(i);
            }
        }
        
        int visited[V] = {0};
        int ans = 0;
        
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]) {
                ans++;
                dfs(adjLst , visited , i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends