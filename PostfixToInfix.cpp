#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

bool isOperator(char c){
	return (!isdigit(c) && !isalpha(c));
}

string PostfixToInfix(string s){
    stack<string> st;
    string res;
	for(int i=0;i<s.length();i++){
		if(isdigit(s[i]) || isalpha(s[i])){
			string op(1,s[i]);
			st.push(op);
		}
		else if(st.size()>=2 && isOperator(s[i])){
			string a=st.top();
			st.pop();
			string b=st.top();
	        st.pop();
			string c="("+b+s[i]+a+")";
			st.push(c);	
		}
		else{
			cout<<"Invalid Expression";
			return 0;
		}
	}
	if(st.size()==1){
		return st.top();
	}
	else{
		cout<<"Invalid Expression";
		return 0;
	}
}

int main(){
	string s="abc-+de-fg-h+/*";
	string ans;
	ans=PostfixToInfix(s);
	cout<<ans;
	return 0;
}
