#include <iostream>
#include "LSLL.h"
using namespace std;

int main()
{
	LSLL<int> list1;
	list1.insertAtHead(50);
	list1.insertAtHead(40);
	list1.insertAtHead(3);
	list1.insertAtHead(2);
	list1.insertAtHead(1);


	 //list1.reversePrint2();
	 list1.reverse_recursive();
	 cout << endl;
	list1.display();
}