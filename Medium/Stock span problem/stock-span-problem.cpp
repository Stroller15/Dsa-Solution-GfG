//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Tc - O(N^2)
// class Solution
// {
//     public:
//     //Function to calculate the span of stockâ€™s price for all n days.
//     vector <int> calculateSpan(int arr[], int n)
//     {
//       vector<int> ans;
//       for(int i = 0 ; i < n ; i++) {
//           int cnt = 0;
//           for(int j = i ; j >= 0 ; j--) {
//               if(arr[j] <= arr[i]) {
//                   cnt++;
//               }
//               else {
//                   break;
//               }
//           }
//           ans.push_back(cnt);
//       }
       
//       return ans;
//     }
// };


#include <vector>
#include <stack>

class Solution {
public:
    vector<int> calculateSpan(int arr[], int n) {
        vector<int> ans(n);
        stack<int> st;
        
        // Push the index of the first element
        st.push(0);
        ans[0] = 1; // The span of the first day is always 1.

        for (int i = 1; i < n; i++) {
            // Pop elements from the stack while they are smaller than the current price.
            while (!st.empty() && arr[i] >= arr[st.top()]) {
                st.pop();
            }

            // If the stack is empty, all previous prices are smaller, so the span is i + 1.
            // Otherwise, the span is the difference between the current day and the day at the top of the stack.
            ans[i] = st.empty() ? (i + 1) : (i - st.top());
            
            // Push the current day's index onto the stack.
            st.push(i);
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
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends