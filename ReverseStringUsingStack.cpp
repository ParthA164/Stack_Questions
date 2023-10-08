#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

void ReverseStringUsingStack(string & s){
	stack<int> st;
	for(int i=0;i<s.length();i++){
		st.push(s[i]);
	}
	int k=0;
	while(!st.empty()){
		s[k]=st.top();
		st.pop();
		k++;
	}
	
	
}

int main(){
	string s="Computer Programming";
	ReverseStringUsingStack(s);
	cout<<s;
	return 0;
}
