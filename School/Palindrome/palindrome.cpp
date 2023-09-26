//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
	public:
		string is_palindrome(int n)
		{
		    // Code here.
		    string numToString = to_string(n);
		    int start = 0 , end = numToString.size() -1;
		    
		    while(start < end) {
		        if(numToString[start] != numToString[end]) {
		            return "No";
		        }
		        start++; end--;
		        
		    }
		    return "Yes";
		    
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends