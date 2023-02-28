#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct DNode
{
	T info;
	DNode<T>* next;
	DNode<T>* prev;

	DNode()
	{
		info = 0;
		next = nullptr;
	}
	DNode(T value)
	{
		info = value;
		next = prev = nullptr;
	}

};

template <typename T>
class LDLL
{
	DNode<T>* head; // jo pehle object ko point karay ga
public:

	LDLL()
	{
		head = nullptr;
	}
	~LDLL()
	{
		DNode<T>* p = head;
		DNode<T>* nextNode = p;
		while (p != nullptr)
		{
			nextNode = p->next;
			delete p;
			p = nextNode;
		}
	}
	void insertAtHead(T val)
	{
		DNode<T>* p = new DNode<T>(val);
		if (!head)
		{
			head = p;
			return;
		}
		p->next = head;
		head->prev = p;
		head = p;



	}
	void insertAtTale(T val)
	{
		DNode<T>* p2 = head;
		DNode<T>* p = new DNode<T>(val);
		if (head == nullptr)
		{
			insertAtHead(val);
		}
		else
		{
			while (p2->next != nullptr)
			{
				p2 = p2->next;
			}
			p2->next = p;
			p->prev = p2;
			p->next = nullptr;
		}
	}

	void insertAfter(T key, T val)
	{
		if (!head)return;
		DNode<T>* p = head;
		DNode<T>* after = head->next;
		while (after != nullptr)
		{
			if (p->info == key)
			{
				DNode<T>* x = new DNode<T>(val);
				p->next = x;
				x->prev = p;
				x->next = after;
				after->prev = x;

			}
			p = p->next;
			after = after->next;
		}
		// ahri case pe nhi chal raha


	}
	void insertBefore(T key, T val)
	{
		if (!head)return;
		if (head->info == key)
		{
			insertAtHead(val);
			return;
		}
		DNode<T>* p = head->next;
		while (p != nullptr)
		{
			if (p->info == key)
			{
				DNode<T>* x = new DNode<T>(val);
				x->next = p;
				p->prev->next = x;
				x->prev = p->prev;
				p->prev = x;
			}
			p = p->next;
		}

	}
	// REMOVES
	void remove(T key)
	{
		if (!head)return;
		DNode<T>* p = head->next;
		if (head->info == key)
		{
			removeAtHead();
		}
		while (p != nullptr)
		{
			if (p->info == key)
			{
				p->prev->next = p->next;
				p->next->prev = p->prev;
				delete p;
				return;
			}
			p = p->next;
		}
	}
	void removeAtHead()
	{
		if (!head)return;
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			DNode<T>* x = head->next;
			delete head;
			head = x;
			return;
		}
	}
	void removeAtTale()
	{
		if (!head)return;
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			DNode<T>* p = head->next;
			while (p->next != nullptr)
			{
				p = p->next;
			}

			p->prev->next = nullptr;
			delete p;
			p = nullptr;
		}

	}

	void removeAfter(T key)
	{
		if (!head || head->next == nullptr)return;
		DNode <T>* after = head->next;
		DNode <T>* p = head;
		while (p->next != nullptr)
		{
			if (p->info == key && after->next == nullptr)
			{
				removeAtTale();
				return;
			}
			if (p->info == key && after->next != nullptr)
			{
				DNode <T>* temp = p->next;
				p->next = after->next;
				after->next->prev = p;
				after = after->next;
				delete temp;
			}
			if (after != nullptr)
			{
				p = p->next;
				after = p->next;
			}
		}
	}
	void removeBefore(T key)
	{
		if (!head)return;
		DNode <T>* p = head->next->next;
		if (p->prev->info == key)removeAtHead();
		while (p->next != nullptr)
		{
			if (p->info == key)
			{
				DNode <T>* temp = p->prev;
				p->prev->prev->next = p;
				p->prev = p->prev->prev;
				delete temp;
			}
			p = p->next;
		}
	}

	void display()
	{
		DNode <T>* p = head;

		while (p != nullptr)
		{
			cout << " " << p->info;
			p = p->next;
		}
	}


	void reverseList(); // 10
	void find_pairs(int x); // 20

};


template< typename T>
void LDLL<T> ::reverseList()
{
	int nodes = 0;
	DNode<T>* p = head;
	while (p != nullptr)
	{
		nodes++;
		p = p->next;
	}
	p = head;
	DNode<T>** ptr = new DNode<T> *[nodes]; // address store karanay ke liye 
	int i = 0, k=0;
	ptr[i] = head; // pehli node ka adrress
	i++;
	while (p->next != nullptr)
	{
		ptr[i] = p->next; // sab nodes ka adrress
		//ptr_prev[k] = p->prev;
		p = p->next;
		i++; k++;
	}
	head = ptr[nodes - 1]; // akhri node ka adress head mein 
	head->prev = nullptr;
	for (int j = nodes - 2; j >= 0; j--)
	{
		p->next = ptr[j]; // last ka adress (p->next) second last ka dress mein and second last mein third last ka and so on 
		p = p->next;
		p->prev = ptr[j + 1];
	}
	p->next = nullptr;

	delete[]ptr; // delete the memory
}



template< typename T>
void LDLL<T> ::find_pairs(int x)
{
	DNode<T>* p = head;
	DNode<T>* p2 = head->next;

	while (p->next != nullptr)
	{
		while (p2 != nullptr)
		{
			if (p->info + p2->info == x)
			{
				cout << "( " << p->info << " , " << p2->info << " )"<<endl;
			}
			p2 = p2->next;
		}
		p = p->next;
		p2 = p->next;
	}



}