#include<iostream>
using namespace std;
template <typename T>
class Node{
	public:
	Node<T>* next;
	T data;
	
		Node(T data){
			this->data=data;
			next=NULL;
		}
};
template <typename T>
class Stack {
    Node<T>* head;
    int size;
public:
    Stack() {
        head = NULL;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return head == NULL;
    }
    void push(T element) {
        Node<T>* newNode = new Node <T>(element);
        newNode->next = head;
        head = newNode;
        size++;
    }
    T pop() {
        if (isEmpty()) {
             cout << "Stack Empty!" << endl;
            return -1;
        }
        T ans = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
    T top() {
        if (isEmpty()) {
             cout << "Stack Empty!" << endl;
            return -1;
        }
        return head->data;
    }
};
int main(){
	Stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);
	cout<<s.top()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.getSize()<<endl;
	cout<<s.isEmpty()<<endl;
	return 0;
}
