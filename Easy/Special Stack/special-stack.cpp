//{ Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}
// } Driver Code Ends


// With extra space taking a supportive stack

// stack<int> ss;

// void push(stack<int>& s, int a){
// 	// Your code goes here
// 	s.push(a);
	
// 	//check for suportive stack
// 	if(ss.size() == 0 || a <= ss.top()) {
// 	    ss.push(a);
// 	}
// }

// bool isFull(stack<int>& s,int n){
// 	// Your code goes here
// 	if(s.size() == n) {
// 	    return true;
// 	}
// 	else {
// 	    return false;
// 	}
// }

// bool isEmpty(stack<int>& s){
// 	// Your code goes here
//     return s.empty();
// }

// int pop(stack<int>& s){
// 	// Your code goes here
// 	int poppedElement;
	
// 	if(!s.empty()) {
// 	    poppedElement = s.top();
// 	    s.pop();
// 	}
	
	
// 	//check on suportive stack
// 	if(ss.top() == poppedElement) {
// 	    ss.pop();
// 	}
	
// 	return poppedElement;
// }

// int getMin(stack<int>& s){
// 	// Your code goes here
// 	return ss.top();
// }

//---------------------------------------------------------------------------

int minElement;

void push(stack<int>& s, int a){
	// Your code goes here
	if(s.empty()) {
	    s.push(a);
	    minElement = a;
	} else {
	    if(a > minElement) {
	        s.push(a);
	    } else if(a <= minElement) {
	        s.push(2*a - minElement);
	        minElement = a;
	    }
	}
	
	
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	return (s.size() == n);

}

bool isEmpty(stack<int>& s){
	// Your code goes here
	return s.empty();
    
}

int pop(stack<int>& s){
	// Your code goes here
	if(s.empty()) {
	    return -1;
	} else {
	    if(s.top() > minElement) {
	        int poppedElement = s.top();
	        s.pop();
	    } else if(s.top() <= minElement) {
	        minElement = 2 * minElement - 1;
	        s.pop();
	        return minElement;
	    }
	}

}

int getMin(stack<int>& s){
	// Your code goes here
	if(s.empty()) {
	    return -1;
	}else {
	    return minElement;
	}
}





