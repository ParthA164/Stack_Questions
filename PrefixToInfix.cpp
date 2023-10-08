#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

bool isOperator(char c){
	return (!isalpha(c) && !isdigit(c));
}

string PrefixToInfix(string s){
	stack<string> st;
	for(int i=s.length()-1;i>=0;i--){
		if(isalpha(s[i]) || isdigit(s[i])){
			string op(1,s[i]);
			st.push(op);
		}
		else if(isOperator(s[i]) && st.size()>=2){
			string a=st.top();
			st.pop();
			string b=st.top();
			st.pop();
			string c="("+a+s[i]+b+")";
			st.push(c);
		}
		else{
			cout<<"Invalid Expression"<<endl;
			return 0;
		}
		
	}
	if(st.size()==1){
		return st.top();
	}
	else{
		cout<<"Invalid Expression"<<endl;
		return 0;
	}
	
}

int main(){
	string s="*+a-bc/-de+-fgh";
	string ans;
	ans=PrefixToInfix(s);
	cout<<ans;
	return 0;
}
