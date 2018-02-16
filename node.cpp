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
	while()
	{
		if()
	}
}