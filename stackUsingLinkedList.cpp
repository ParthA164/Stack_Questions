#include<iostream>
using namespace std;
template <typename T>
class Node{
	public:
	T data;
	Node<T>*next;
	Node(T data){
		this->data=data;
		next=NULL;
	}
};
template <typename T>
class stack{
	Node<T>* head;
	int size;
	public:
		stack(){
			head=NULL;
			size=0;
		}
		void push(int data){
			Node<T>* newNode=new Node<T>(data);
			newNode->next=head;
			head=newNode;
			size++;
		}
		bool isEmpty(){
			return head==NULL;
		}
		int getSize(){
			return size;
		}
		
		T pop(){
			if(isEmpty()){
				cout<<"stack is Empty"<<endl;
				return 0;
			}
			int ans=head->data;
			Node<T>* temp=head;
			head=head->next;
			delete temp;
			size--;
			return ans;
		}
		T top(){
				if(isEmpty()){
				cout<<"stack is Empty"<<endl;
				return 0;
			}
			return head->data;
		}
		void Display(){
			Node<T>* temp=head;
			while(temp!=NULL){
				cout<<temp->data<<endl;
				temp=temp->next;
			}
		}
		
		
};

int main(){
	stack<int> st;
	for(int i=10;i<=100;i+=10){
		st.push(i);
	}
	st.Display();
	cout<<endl;
	cout<<st.getSize()<<endl;
	st.pop();
	st.pop();
	cout<<st.top()<<endl;
	cout<<st.getSize()<<endl;
	cout<<st.isEmpty()<<endl;
	
	return 0;
}

