template<typename T>

class Node {
public:
	T data;
	Node<T> *next;
	Node(T data){
		this->data = data;
		next=NULL;
	}
};


template<typename T>
class Stack {
	Node<T> * head;
	int size; // No of elements present in stack
public:
	Stack(){
		head=NULL;
		size=0;
	}

	int getsize(){
		return size;
	}

	bool empty(){
		return head==NULL;
	}
	void push(T x){
		Node<T> * newNode= new Node<T> (x);
		newNode->next = head;//inserting new node at the starting 
		head=newNode;
		size++;
	}

	T pop(){
		if(empty()){
			return 0;
		}
		T ans = head->data;
		Node<T> * temp = head;
		head = head ->next;
		delete temp;
		size--;
		return ans;
	}

	T top(){
		if(empty()){
			return 0;
		}
		return head->data;
	}
};
