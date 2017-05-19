template<class T>
class vector{
public:
	vector<T>(){
		head = 0;
		length= 0;	
		rear = head;
	};
	bool push_back(T val){
		if(this->length==0){
			head = new Node(val);
			rear = head;
		}
		Node *nNode = new Node(val);
		rear->next = nNode;
		rear = nNode;
		this->length++;
	};
	
	int size(){
		return this->length;
	};
private:
	struct Node{
		Node(T v){
			val = v;
			next=0;
		};
		T val;
		Node *next;
	};
	Node *head;
	Node *rear;
	int length;
};
