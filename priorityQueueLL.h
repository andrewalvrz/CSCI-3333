template <class T>
class priorityQueueLL
{
private:
	class node
	{
	public:
		//put what you need here..

		T data;

		node* next;

		node(T val) : data(val), next(nullptr){};
	};

	node* head = nullptr;

	//add what you wish here

public:

	priorityQueueLL()
	{}

	~priorityQueueLL()
	{
		while(head){
			node* temp = head;

			head = head-> next;

			delete temp;

		}

	}
	// run time  is O(1)
	//return true if empty, false if not
	bool empty()
	{
		return head == nullptr;

	}


	// run time is O(n)
	//add item
	void insert(T x)
	{
	
		node* newNode = new node(x);

        if (head == nullptr || x < head->data)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            node* curr = head;

            while (curr->next != nullptr && curr->next->data <= x)
            {
                curr = curr->next;
            }

            newNode->next = curr->next;
            curr->next = newNode;
        }


	}
	// run time is O(1)
	//remove and return smallest item
	T extractMin()
	{
		if(empty()){

			std::cout << "queue is empty";
		}

		node* temp = head;

		T extrmin = head-> data;

		head = head -> next;

		delete temp;

		return extrmin;

	}

};