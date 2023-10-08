#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

string ReverseString(string s){
	stack<char> st;
	int i=0;
	while(s[i]!='\0'){
		st.push(s[i]);
		i++;
	}
	int j=0;
	while(!st.empty()){
		s[j]=st.top();
		st.pop();
		j++;
	}
	return s;
}

int prec(char c){
	if(c=='^'){
		return 3;
	}
	else if(c=='*' || c=='/' || c=='%'){
		return 2;
	}
	else if(c=='+' || c=='-'){
		return 1;
	}
	else{
		return -1;
	}
}
bool isOperator(char c){
	return (!isalpha(c) && !isdigit(c));
}

string InfixToPostfix(string s) {
    string res;
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i]) || isdigit(s[i])) {
            res += s[i];
        }
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(') {
                st.pop();
            }
        }
        else {
            if (isOperator(s[i])) {
                while (!st.empty() && prec(st.top()) >= prec(s[i])) {
                    res += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}


string InfixToPrefix(string s){
	s=ReverseString(s);
	for(int i=0;i<s.length();i++){
		if(s[i]=='('){
			s[i]=')';
		}
		else if(s[i]==')'){
			s[i]='(';
		}
	}
     string prefix=InfixToPostfix(s);
     prefix=ReverseString(prefix);
     return prefix;
}

int main(){
	string s="(A+B^C)*D+E^5";
	string ans;
	ans=InfixToPrefix(s);
	cout<<ans;
	return 0;
}
