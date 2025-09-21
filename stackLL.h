class stackLL
{
private:
	class node
	{
	public:
		//put what you need in here

		int* data;
		node* next;


		node(int value){data = new int(value); next = nullptr;}
	};

	node * top;

public:

	stackLL()
	{
		top = nullptr;
	}

	//Take care of memory leaks...
	~stackLL()
	{
		while(top != nullptr){
			node* temp = top;

			top = top-> next;

			delete temp->data;

			delete temp;
		}
	}
// run time is O(1)
	//return true if empty, false if not
	bool empty()
	{
		return top == nullptr;
	}

	//add item to top of stack
	void push(int x)
	{
		node* newNode = new node(x);

		newNode-> next = top;
		top = newNode;

	}
// run time is O(1)
	//remove and return top item from stack
	int pop()
	{
		if(empty()){
			return -1;
		}

		node* temp = top;

		int value = *(top->data);

		top = top->next;

		delete temp;
		
		return value;

	}
// O(n)
	//add item x to stack, but insert it
	//right after the current ith item from the top
	//(and before the i+1 item).
	void insertAt(int x, int i)
	{
		if (i == 0) {
        push(x);
        return;
    }
    node* current = top;

    for (int count = 0; count < i - 1; count++) 
	{
        if (current == nullptr) return; 
		current = current-> next;
    }
    if (current == nullptr) return; 

    node* newNode = new node(x);

    newNode->next = current->next;
	
    current->next = newNode;


	}

};