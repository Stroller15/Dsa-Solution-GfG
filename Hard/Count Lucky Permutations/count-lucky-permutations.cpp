//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long dp[1<<15][15];
    bool g[15][15];
    long long rec(vector<int> &a,int left,int pre)
    {
        if(pre!=-1 && dp[left][pre]!=-1) return dp[left][pre];
        if(left==0) return 1LL;
        long long s=0;
        for(int i=0;i<a.size();i++)
        {
            if(left&(1<<i) && (pre==-1 || g[pre][a[i]])) 
            {
                s+=rec(a,left-(1<<i),a[i]);
            }
        }
        return dp[left][pre]=s;
        
    }
    long long int luckyPermutations(int N, int M, vector<int> arr,
                                    vector<vector<int>> graph) {
        memset(dp,-1LL,sizeof dp);
        memset(g,0,sizeof g);
        for(auto &i:arr) --i;
        for(auto i:graph)   g[i[0]-1][i[1]-1]=1,g[i[1]-1][i[0]-1]=1;
        return rec(arr,(1<<N)-1,-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<int> arr(N);
        vector<vector<int>> graph(M, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> graph[i][j];
            }
        }
        Solution obj;
        cout << obj.luckyPermutations(N, M, arr, graph) << endl;
    }
}

// } Driver Code Ends