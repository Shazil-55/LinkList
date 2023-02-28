#pragma once
#include "Stack.h"

#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T info;
	Node<T>* next;
	Node()
	{
		info = 0;
		next = nullptr;
	}
	Node(T value)
	{
		info = value;
		next = nullptr;
	}

};

template <typename T>
class LSLL
{
	Node<T>* head; // jo pehle object(node) ko point karay ga
public:

	LSLL()
	{
		head = nullptr;
	}
	void insertAtHead(T val) // yani head pe ek new node bana do 
	{
		Node<T>* p = new Node<T>(val); //ek pointer bnaiya jo ke ek parametrized node ko point kar raha jo ke abhi bnaiya hai 
		p->next = head;
		head = p;
	}
	void insertAtTale(T val)
	{
		Node<T>* p2 = head;
		Node<T>* p = new Node<T>(val);
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
			p->next = nullptr;
		}
	}

	void insertAfter(T key, T val)
	{
		if (!head)return;
		Node<T>* p = head;
		Node<T>* after = head->next;
		while (after != nullptr)
		{
			if (p->info == key)
			{
				Node<T>* x = new Node<T>(val);
				p->next = x;
				x->next = after;

			}
			p = p->next;
			after = after->next;
		}


	}
	void insertBefore(T key, T val)
	{
		if (!head)return;
		if (head->info == key)
		{
			insertAtHead(val);
			return;
		}
		Node<T>* prev = head;
		Node<T>* p = head->next;
		while (p != nullptr)
		{
			if (p->info == key)
			{
				Node<T>* x = new Node<T>(val);
				x->next = p;
				prev->next = x;
			}
			prev = prev->next;
			p = p->next;
		}

	}
	// REMOVES
	void remove(T key)
	{
		if (!head)return;
		Node<T>* p = head->next;
		Node<T>* prev = head;
		if (head->info == key)
		{
			Node<T>* x = head->next;
			delete head;
			head = x;
			return;
		}
		while (p != nullptr)
		{
			if (p->info == key)
			{
				prev->next = p->next;
				delete p;
				return;
			}
			prev = p;
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
			Node<T>* p = head->next;
			delete head;
			head = p;
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
			Node<T>* p = head->next;
			Node<T>* prev = head;
			while (p != nullptr)
			{
				if (p->next == nullptr)
				{

					delete p;
					p = nullptr;
					prev->next = nullptr;
					break;
				}
				prev = prev->next;
				p = p->next;
			}
		}

	}

	void removeAfter(T key)
	{
		if (!head || head->next == nullptr)return;
		Node <T>* after = head->next;
		Node <T>* p = head;
		while (p->next != nullptr)
		{
			if (p->info == key && after == nullptr)return;
			if (p->info == key && after->next == nullptr)
			{
				removeAtTale();
				return;
			}
			if (p->info == key && after->next != nullptr)
			{
				Node <T>* temp = p->next;
				p->next = after->next;
				after = after->next;
				delete temp;
			}
			if (after != nullptr)
			{
				p = p->next;
				after = after->next;
			}
		}
	}
	void removeBefore(T key)
	{
		if (!head)return;
		Node <T>* p = head->next->next;
		Node <T>* before = head;
		if (before->next->info == key)removeAtHead();
		while (p->next != nullptr)
		{
			int count = 0;

			if (p->info == key)
			{
				Node <T>* temp = before->next;
				before->next = p;
				p = p->next;
				delete temp;
				count++;
			}
			if (count == 0)
			{
				p = p->next;
				before = before->next;
			}
		}
	}
	void display()
	{
		Node <T>* p = head;

		while (p != nullptr)
		{
			cout << " " << p->info;
			p = p->next;
		}
		
	}

	// Tasks 
	LSLL<T> doUnion(LSLL<T>& list);   // task 1
	bool isEqual(LSLL<T>& list);		// task 2
	LSLL<T> createClone();	// task 3
	void delAlternate(); // task 4
	void splitList(LSLL<T> list_A, LSLL<T> list_B); // task 5
	void removeDuplicates();							//6
	LSLL<T> mergeSortedLists(LSLL<T> list);				//7
	void reversePrint2();								//8
	void reverse2(Node<T>*);								//8
	void reversePrint();								//8
	void reverseList();									//9
	void swap(int first_value, int second_value);		//11
	bool findMajorityColor(LSLL<T> list_A, int nodes);	//15
	bool isJoining(LSLL<T>& list);						//16
	void Join_them(LSLL<T>& list);						//16
	void rearrange();									//18
	int middle_node();									//19
	void find_pairs(int x);								//21
	void rearrange_condition();							//22
	void remove_greater();								//23

	void reverse_recursive()
	{
		Node<T>* p = head, *p2 = head;
		rl2(p, p);
		p2->next = nullptr;
	}
	void rl2(Node<T>* ptr , Node<T>* prev)
	{
		if (ptr == nullptr)
		{
			head = prev;
			return;
		}
		rl2(ptr->next, ptr);
		ptr->next = prev;
		prev = nullptr;
	}

};



// taks 1

template< typename T>
LSLL<T> LSLL<T> :: doUnion(LSLL<T>& list)
{
	LSLL<T> temp;
	Node <T>* p = head;
	while (p != nullptr)
	{
		temp.insertAtTale(p->info);
		p = p->next;

	}
	//p = head;
	Node <T>* p2 = list.head;
	while (p2 != nullptr)
	{
		p = head;
		int count = 0;
		while (p != nullptr)
		{
			if (p2->info == p->info)
			{
				count++;
				break;
			}

			p = p->next;
		}
		if (count == 0)
		{
			temp.insertAtTale(p2->info);
		}
		p2 = p2->next;
	}

	return temp;

}

// equal  task 2

template< typename T>
bool LSLL<T> :: isEqual(LSLL<T>& list)
{
	Node <T>* p = this->head;
	Node <T>* p2 = list.head;
	int nodes1 = 0, nodes2 = 0;
	while (p != nullptr)
	{
		nodes1++;
		p = p->next;
	}
	while (p2 != nullptr)
	{
		nodes2++;
		p2 = p2->next;
	}
	if (nodes1 != nodes2)return false;

	//p = head;
	p2 = list.head;
	while (p2 != nullptr)
	{
		p = head;
		int count = 0;
		while (p != nullptr)
		{
			if (p2->info == p->info)
			{
				count++;
				break;
			}

			p = p->next;
		}
		if (count == 0)
		{
			return false;
		}
		p2 = p2->next;
	}

	return true;

}


// clone task 3


template< typename T>
LSLL<T> LSLL<T> ::createClone()
{
	LSLL<T> temp;
	Node <T>* p = head;
	while (p != nullptr)
	{
		temp.insertAtTale(p->info);
		p = p->next;

	}
	
	return temp;

}


// task 4
template< typename T>
void LSLL<T> ::delAlternate()
{
	int mod = 2; // q k p humara seedha 2nd node ko point kar raha 
	Node<T>* prev = head;
	Node<T>* p = head->next;
	Node<T>* p2 = head->next->next;
	while (p->next != nullptr) // p-> next isliye ke agalay humara p2 bhi para hai to error aa sakta tha
	{
		int count = 0;
		if (mod % 2 == 0)
		{
			delete p;
			p = p2;// p ko agay point kara diya 
			prev->next = p;  // previous ko p par
			p2 = p2->next; // p2 ko apnay hi agay 
			count++;
		}
		if (count > 0)mod++;  // yeh isliye kiya ke agar delete ho jaiye to dubara se neche waala kam na karay q ke uper karwa chukay hai hum point 
		else
		{
			mod++;
			prev = p;
			p = p->next;
			p2 = p->next; // p ke agay
		}
	}
}

// task 5

template< typename T>
void LSLL<T> ::splitList(LSLL<T> list_1, LSLL<T> list_2)
{
	Node<T>* p = head;
	int nodes = 0;
	while (p != nullptr)
	{
		nodes++;
		p = p->next;
	}
	
	int nodes_1, nodes_2;
	if (nodes % 2 == 0)
	{
		nodes_1 = nodes / 2;
		nodes_2 = nodes - nodes_1;
	}
	else
	{
		nodes_1 = nodes / 2 + 1;
		nodes_2 = nodes - nodes_1;
	}
	Node<T>* p1 = head;
	Node<T>* p2;
	for (int i = 0; i < nodes_1; i++)
	{
		list_1.insertAtTale(p1->info);
		p1 = p1->next;
	}
	//p2 = p1;
	for (int i = 0; i < nodes_2; i++)
	{
		list_2.insertAtTale(p1->info);
		p1 = p1->next;
	}


}

// task 6
template< typename T>
void LSLL<T> ::removeDuplicates()
{
	Node<T>* p = head;
	Node<T>* p2 ;
	Node<T>* prev;
	int nodes = 0;
	while (p != nullptr)
	{
		p2 = p->next;
		prev = p;
		while (p2 != nullptr)
		{
			if (p->info == p2->info)
			{
				prev->next = p2->next;
				delete p;
			}
			if (prev->next == nullptr)break;
			prev = prev->next;	
			p2 = prev->next;
		
		}
		p = p->next;
	}


}

// task 7
template< typename T>
LSLL<T> LSLL<T> ::mergeSortedLists(LSLL<T> list)
{
	LSLL<T> temp;
	Node<T>* p = head;
	Node<T>* p2 = list.head;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	if (p->info < p2->info)
	{
		p2 = list.head;
		p = head;
		while (p != nullptr)
		{
			temp.insertAtTale(p->info);
			p = p->next;
		}
		p = p2;
		while (p2 != nullptr)
		{
			temp.insertAtTale(p2->info);
			p2 = p2->next;
		}
	}
	
	else
	{
		p = head;
		while (p != nullptr && p2 != nullptr)
		{
			if (p->info < p2->info)
			{
				temp.insertAtTale(p->info);
				p = p->next;
			}
			else if (p->info > p2->info)
			{
				temp.insertAtTale(p2->info);
				p2 = p2->next;
			}
			else
			{
				temp.insertAtTale(p->info);
				p = p->next;
			}
			temp.display();
			cout << endl;
		}
		if (p2 != nullptr)
		{
			while (p2 != nullptr)
			{
				temp.insertAtTale(p2->info);
				p2 = p2->next;
			}
		}
		if (p!= nullptr)
		{
			while (p != nullptr)
			{
				temp.insertAtTale(p->info);
				p = p->next;
			}
		}
	}
	return temp;
}


// task 8

template< typename T>
void LSLL<T> ::reversePrint()
{
	int nodes = 0;
	Node<T>* p = head;
	while (p != nullptr)
	{
		nodes++;
		p = p->next;
	}
	int* ptr = new int[nodes];
	p = head;
	int i = 0;
	while (p != nullptr)
	{
		ptr[i] = p->info;
		i ++ ;
		p = p->next;
	}
	for (int j = nodes - 1; j >= 0; j--)
	{
		cout << ptr[j] << " ";
	}
	delete ptr;
}

template< typename T>
void LSLL<T> ::reversePrint2()
{
	int nodes = 0;
	Node<T>* p = head;
	reverse2(p);
}
template< typename T>
void LSLL<T> ::reverse2(Node<T>*ptr)
{
	if (ptr == nullptr)return;
	reverse2(ptr->next);
	cout << ptr->info;

}

// task 9
template< typename T>
void LSLL<T> ::reverseList()
{
	int nodes = 0;
	Node<T>* p = head;
	while (p != nullptr)
	{
		nodes++;
		p = p->next;
	}
	p = head;
	Node<T>** ptr = new Node<T> * [nodes]; // address store karanay ke liye 
	int i = 0;
	ptr[i] = head; // pehli node ka adrress
	i++;
	while (p->next != nullptr)
	{
		ptr[i] = p->next; // sab nodes ka adrress
		p = p->next;
		i++;
	}
	head = ptr[nodes - 1]; // akhri node ka adress head mein 
	for (int j = nodes - 2; j >= 0; j--)
	{
		p->next = ptr[j]; // last ka adress (p->next)mein second last ka dress and second last mein third last ka and so on 
		p = p->next;
	}
	p->next = nullptr;

	delete[]ptr; // delete the memory

}


// task 11
template< typename T>
void LSLL<T> ::swap(int first_value, int second_value)
{
	Node<T>* first_prev ;
	Node<T>* first;
	Node<T>* first_next;
	if (first_value == 1)
	{
		
		 first_prev = head;
		 first = head;
		 first_next = first->next;
	}
	else
	{
		 first_prev = head;
		 first = head->next;
		 first_next = first->next;
	}
	Node<T>* second_prev = head;
	Node<T>* second = head->next;
	Node<T>* second_next = second->next;
	
	for (int i = 1; i < first_value-1 && first_next != nullptr; i++)
	{
		 first_prev = first_prev ->next;
		 first = first->next;
		 first_next = first_next->next;
	}

	for (int i = 1; i < second_value-1 && second_next != nullptr; i++)
	{
		second_prev = second_prev->next;
		second = second->next;
		second_next = second_next->next;
	}
	

		first_prev->next = second;
		second->next = first_next;
		second_prev->next = first;
		first->next = second_next;

	
}


// task 15
template< typename T>
bool LSLL<T> ::findMajorityColor(LSLL<T> list_A , int n )
{
	Node<T>* p = head;
	Stack<T> s1, s2;
	for (int i = 0; i < n; i++)
	{
		if (p->info == 1)
		{
			if (s2.isEmpty()) 
			{
				s1.push(1);
			}
			else
			{
				s2.pop();
			}
		}
		else if (p->info == 0)
		{
			if (s1.isEmpty())
			{
				s2.push(0);
			}
			else
			{
				s1.pop();
			}
		}
		p = p->next;
	}

	if (!s1.isEmpty()) {
		return true;
	}
	else if (!s2.isEmpty())
	{
		return false;
	}
	else {
		return false;
	}

}

//16 - 17
template< typename T>
void LSLL<T> ::Join_them(LSLL<T>& list)
{
	Node<T>* p = head;
	Node<T>* p2 = list.head;
	
	for (int i = 0; i < 3; i++)
	{
		p = p->next;
	}
	while (p2->next != nullptr)
	{
		p2 = p2->next;
	}
	p2->next = p;
}

template< typename T>
bool LSLL<T> ::isJoining(LSLL<T> & list)
{
	Node<T>* p = head;
	Node<T>* p2 = list.head;
	int nodes1=0, nodes2=0;

	while (p != nullptr)
	{
		nodes1++;
		p = p->next;
	}
	while (p2 != nullptr)
	{
		nodes2++;
		p2 = p2->next;
	}

	p = head;
	p2 = list.head;

	Node<T>** ptr1 = new Node<T>*[nodes1];
	Node<T>** ptr2 = new Node<T>*[nodes2];
	int i = 0, j = 0;

	ptr1[i] = head; // pehli node ka adrress
	i++;
	while (p->next != nullptr)
	{
		ptr1[i] = p->next; // sab nodes ka adrress
		p = p->next;
		i++;
	}
	ptr2[j] = list.head; // pehli node ka adrress
	j++;
	while (p2->next != nullptr)
	{
		ptr2[j] = p2->next; // sab nodes ka adrress
		p2 = p2->next;
		j++;
	}
	
	for (int l= 0; l < nodes1; l++)
	{
		for (int k = 0; k < nodes2; k++)
		{
			if (ptr1[l] == ptr2[k])
			{
				cout << endl << "the value at joining point is  : " << ptr1[l]->info << endl; // task -17
				return true;
			}
		}
	}

	return false;

}


// task -18
template <typename T>
void LSLL<T> ::rearrange()
{
	Node<T>* p = head;
	int nodes = 0, j = 1, k = 0;
	while (p != nullptr)
	{
		nodes++;
		p = p->next;
	}
	p = head;
	
	Node<T>** ptr = new Node<T>*[nodes];
	
	ptr[0] = head; // pehli node ka adrress
	for ( int a =1 ; a<nodes ; a++)
	{
		ptr[a] = p->next; // sab nodes ka adrress
		p = p->next;	
	}
	p = head; k = nodes;

	for (int i = 0; i < nodes-1; i++)
	{
		if (i % 2 == 0)
		{
			p->next = ptr[k-1];
			k--;
		}
		else
		{
			p->next = ptr[j];
			j++;
		}
		p = p->next;
	}
	p->next = nullptr;


}


// task 19
template <typename T>
int LSLL<T> ::middle_node()
{
	Node<T>* p = head;
	Node<T>* p2 = head;
	while (p2->next != nullptr  && p2->next->next !=nullptr)
	{
		p = p->next;
		p2 = p2->next->next;
	}
	return p->info;
}


//task -21
template< typename T>
void LSLL<T> ::find_pairs(int x)
{
	Node<T>* p = head;
	Node<T>* p2 = head->next;
	Node<T>* prev=head ;

		while (p2 != nullptr)
		{
			if (p->info + p2->info == x)
			{
				cout << "( " << p->info << " , " << p2->info << " )" << endl;
				p = p->next;
				continue;
			}
			else if (p->info + prev->info == x)
			{
				cout << "( " << p->info << " , " << prev->info << " )" << endl;
				p = p->next;
				continue;
			}
			prev = p2;
			p2 = p2->next;
		}
		
}


// task-22
template< typename T>
void LSLL<T> ::rearrange_condition()
{
	Node<T>* p = head;
	Node<T>* p1 = p->next;
	//Node<T>* p2 = head->next->next;
	int i = 0;
	while (p1 != nullptr)
	{
		T x = p->info;
		T y = p1->info;
		if (i % 2 == 0)
		{
			if (x < y) 
			{

			}
			else
			{
				T temp = p->info;
				p->info = p1->info;
				p1->info = temp;
			}
		}
		else
		{
			if (x > y)
			{

			}
			else
			{
				T temp = p->info;
				p->info = p1->info;
				p1->info = temp;
			}

		}
		p = p->next;
		i++;
		if (p1 != nullptr)p1 = p->next;

	}


}


// task -23
template< typename T>
void LSLL<T> ::remove_greater()
{
	Node<T>* prev = head;
	Node<T>* p = head;
	Node<T>* p1 = head->next;


	while (p1!= nullptr)
	{
		if (p->info < p1->info)
		{
			T temp = p->info;
			p = p->next;
			p1 = p->next;
			remove(temp);
			continue;
		}
		p = p->next;
		p1 = p->next;
	}
	p->next = nullptr;

}
