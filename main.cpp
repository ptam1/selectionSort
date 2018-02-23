#include <iostream>
#include "node.h"
using namespace std;




void sort_list(node*& head_ptr);



int main()
{
	node* tail = new node(6);
	node* six = new node(4, tail);
	node* five = new node(2, six);
	node* four = new node(7, five);
	node* three = new node(3, four);
	node* two = new node(1, three);
	node* one = new node(5, two);
	
	cout << "Testing sort_list function" << endl;
	print(one);
	sort_list(one);
	
	return 0;
}



/*Precondition: head_ptr is a head pointer of a linked 
list of items and these items can be compared with a < operator.
Postcondition: head_ptr points to the head of a linked list with
exactly the same entries, but the entries in this list are sorted from 
smallest to largest. The original linked list is nol longer available. 
*/
void sort_list(node*& head_ptr)
{
	node* largestNode = NULL;
	node* newList = NULL;
	node* largestPrevious = NULL;
	node* previous = NULL;
	int largest = 0;
	
	while( head_ptr != NULL)
	{
		
		previous = head_ptr;
		
		for(node* current = head_ptr; current != NULL; current->link())
		{
			if(largest < current->data())
			{
				largest = current->data();
				largestNode = current;
				largestPrevious = previous;
			}
		}
		
		if(largestNode == head_ptr)
		{
			list_head_remove(head_ptr);
		}
		else
		{
			largestPrevious->set_link(largestNode->link());
			delete largestNode;
		}
		
		list_head_insert(newList, largest);
	}
	
		head_ptr = newList;
		cout << "The Sorted List is: " << " ";
		for(node* i = head_ptr; i != NULL; i = i->link())
	{
		cout << i->data() << " " << " ";
	}   
}
