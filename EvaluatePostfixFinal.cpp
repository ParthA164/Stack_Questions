#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

bool isOperator(char c){
	return(!isdigit(c) && !isalpha(c));
}

int evaluate(char c, int a ,int b){
	if(c=='+'){
		return b+a;
	}
	else if(c=='-'){
		return b-a;
	}
	else if(c=='*'){
		return b*a;
	}
	else if(c=='/'){
		if(a==0){
			cout<<"Division by zero! Not allowed";
			return 0;
		}
		else {
			return b/a;
		}
	}
	else if(c=='%'){
			if(a==0){
			cout<<"Division by zero! Not allowed";
			return 0;
		}
		else {
			return b%a;
		}
	}
	else if(c=='^'){
		return pow(b,a);
	}
}

int EvaluatePostfix(string s){
	stack<int> st;
	for(int i=0;i<s.length();i++){
		if(isdigit(s[i])){
			st.push(s[i]-'0');
		}
		else if(isOperator(s[i]) && st.size()>=2){
			int a=st.top();
			st.pop();
			int b=st.top();
			st.pop();
			int ans=evaluate(s[i],a,b);
			st.push(ans);
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
		cout<<"Invalid Expression"<<endl;
		return 0;
	}
}

int main(){
 	string s="284+*6-";
	int answer;
	answer=EvaluatePostfix(s);
    cout<<answer;
}
