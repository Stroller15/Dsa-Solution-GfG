//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int> kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        vector<int>ans;
        sort(range.begin(),range.end());
        for (int qq=0;qq<q;qq++)
        {
            int k = queries[qq],till=0,check=0;
            for (int i=0;i<n;i++)
            {
                if (max(range[i][0]-1,till)+k<=range[i][1])
                {
                    ans.push_back(max(range[i][0]-1,till)+k);
                    check=1;
                    break;
                }
                k-=max(range[i][1],till)-max(range[i][0]-1,till);
                till = max(till,range[i][1]);
            }
            if (!check) ans.push_back(-1);
        }
        return ans;
    } 
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends