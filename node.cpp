#include "node.h"
#include <iostream>

node::~node()
{
	delete [] this->link_field;
}


/*Precondition: head_ptr is a head pointer of a linked 
list of items and these items can be compared with a < operator.
Postcondition: head_ptr points to the head of a linked list with
exactly the same entries, but the entries in this list are sorted from 
smallest to largest. The original linked list is nol longer available. 
*/
void sort_list(node*& head_ptr)
{
	node* largest;
	node* current;
	node* previous;
	
	current = head_ptr;
	while(current != NULL)
	{
		if(current < largest)
		{
			largest = current;
		}
		previous = current;
		list_remove(largest);
		list_insert(previous, largest);
		current = head_ptr->link();
	}
}

void list_remove(node *previous_ptr) 
{
        node *remove_ptr;

        remove_ptr = previous_ptr->link();
        previous_ptr->set_link(remove_ptr->link());
        delete remove_ptr;
}

void list_insert(node *previous_ptr, const node::value_type &entry)
{
        node *insert_ptr;

        insert_ptr = new node(entry, previous_ptr->link());
        previous_ptr->set_link(insert_ptr);
}