template<typename Q>
class queueLL
{
private:
	//put what you need here...

	struct Node{

		Q data;
		Node* next;

		Node(const Q& x): data(x), next(nullptr){};
	};

	Node* front;

	Node* back;

public:
	queueLL() : front(nullptr), back(nullptr){};

	~queueLL()
	{
		while(front != nullptr){

			Node* temp = front;

			front = front->next;

			delete temp;

		}
		back = nullptr;

	}
// run time ios O(1)
	//add item to back of queue
	void enqueue(const Q& x)
	{
		Node* newNode = new Node(x);

		if(empty()){
			front = back = newNode;
		}
		else{
			back-> next = newNode;
			back = newNode;

		}




	}
// run time is O(1)
	//remove and return first item from queue
	Q dequeue()
	{
		if(empty()){
			std::cout << "stack is empty"<< std:: endl;
		}

		Node* temp = front;

		Q value = front->data;

		front = front->next;

		delete temp;

		

		if(front == nullptr){

			back == nullptr;
		}

		return value;


	}
// run time is O(1)
	//return true if empty, false otherwise.
	bool empty()
	{
		return front == nullptr;
		

	}

	//For the final part of the test program, template this class
	//and add a decimate method.

	 void decimate(){
		int count = 1;
    Node* curr = front;
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (count % 10 == 0) {
            Node* toDelete = curr;
            if (prev) {
                prev->next = curr->next;
            } else {
                front = curr->next;
            }
            if (curr == back) {
                back = prev;
            }
            curr = curr->next;
            delete toDelete;
        } else {
            prev = curr;
            curr = curr->next;
        }
        count++;
    }
	
	 }


};