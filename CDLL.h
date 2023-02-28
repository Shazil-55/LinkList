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
class CDLL
{
	DNode<T>* head; // jo pehle object ko point karay ga
public:

	CDLL()
	{
		head = nullptr;
	}
	~CDLL()
	{
		DNode<T>* p = head;
		DNode<T>* nextNode = p;
		do
		{
			nextNode = p->next;
			delete p;
			p = nextNode;
		}while (p != head);
	}
	void insertAtHead(T val)
	{
		DNode<T>* p = new DNode<T>(val);
		if (!head)
		{
			head = p;
			head->next = p;
			head->prev = p;
			return;
		}
		p->next = head;
		p->prev = head->prev;
		head->prev = p;
		p->prev->next = p;
		head = p;

	}


	void insertAtTale(T val)
	{
	
		DNode<T>* p_node = new DNode<T>(val);
		if (head == nullptr)
		{
			insertAtHead(val);
		}
		else
		{
			DNode<T>* p = head;
			DNode<T>* p2 = head->next;
		    do
			{
				p2 = p2->next;
				p = p->next;

			} while (p2!= head);

			p->next = p_node;
			p_node->prev = p;
			p_node->next = head;
			head->prev = p_node;
		}
	}

	void insertAfter(T key, T val)
	{
		if (!head)return;
		DNode<T>* p = head;
		DNode<T>* after = head->next;
		do
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
		} while (after != head);


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
		do
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
		} while (p != head);

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
		do
		{
			if (p->info == key)
			{
				p->prev->next = p->next;
				p->next->prev = p->prev;
				delete p;
				return;
			}
			p = p->next;
		} while (p != head);
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
			DNode<T>* x2 = head->prev;
			delete head;
			head = x;
			x->prev = x2;
			x->prev->next = x;
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
			DNode<T>* p = head->prev;
			DNode<T>* p2 = p->prev;
			p2->next = p->next;
			delete p;
			head->prev = p2;
			p = nullptr;
		}

	}

	void removeAfter(T key)
	{
		if (!head || head->next == nullptr)return;
		DNode <T>* after = head->next;
		DNode <T>* p = head;
		do
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
		} while (p->next != head);
	}
	void removeBefore(T key)
	{
		if (!head)return;
		DNode <T>* p = head->next->next;
		if (p->prev->info == key)removeAtHead();
		do
		{
			if (p->info == key)
			{
				DNode <T>* temp = p->prev;
				p->prev->prev->next = p;
				p->prev = p->prev->prev;
				delete temp;
			}
			p = p->next;
		} while (p != head);
	}

	void display()
	{
		DNode <T>* p = head;

		do
		{
			cout << " " << p->info;
			p = p->next;

		} while (p != head);
	}


};

