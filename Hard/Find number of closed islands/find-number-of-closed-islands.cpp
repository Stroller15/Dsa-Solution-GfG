//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    bool isValid(vector<vector<int>>& matrix, int N, int M, int i, int j) {
        if(i >= 0 && i < N-1 && j >= 0 && j < M-1 && matrix[i][j] == 1) {
            return true;
        }
        return false;
    }
    void dfs(vector<vector<int>>& matrix, int N, int M, int i, int j) {
        matrix[i][j] = 0;
        
        int arrX[4] = {1, 0, -1, 0};
        int arrY[4] = {0, 1, 0, -1};
        
        for(int k = 0 ; k < 4 ; k++) {
            int nArrX = i + arrX[k];
            int nArrY = j + arrY[k];
            
            if((isValid(matrix, N, M , nArrX, nArrY)) == true)
            dfs(matrix, N, M , nArrX, nArrY);
        }
    }
    public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < M ; j++) {
                // This loop we are using for boundary 
                // and making all value 0
                if(i * j == 0 || i == N-1 || j == M-1) {
                    if(matrix[i][j] == 1) {
                        dfs(matrix, N, M, i, j);
                    }
                }
            }
        }
        
        int numOfClosedIsland = 0;
        
        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < M ; j++) {
                // This loop we are using for counting no of
                // island coz remaing are only valid island
                    if(matrix[i][j] == 1) {
                        numOfClosedIsland++;
                        dfs(matrix, N, M, i, j);
                    }
            }
        }
        return numOfClosedIsland;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends