#ifndef NODE_H
#define NODE_H

#include <cstdlib> //Provides size_t and NULL

using namespace std;

class node
{
public:
	//Typedef
	typedef int value_type;
	
	//Constructor
	node( 
	const value_type &init_data = value_type(),
	node *init_link = NULL
	)
	{
		data_field = init_data;
		link_field = init_link;
	}
	
	//Destructor
	~node();
	
	//Member functions to set the data and link fields
	void set_data(const value_type &new_data) {data_field = new_data;}
	void set_link(node *new_link) {link_field = new_link;}
	
	//Constant member function to retrieve thecurrent data
	value_type data() const {return data_field;}
	
	//Different versions of member functions to retrieve the current link
	const node *link() const {return link_field;}
	node *link() {return link_field;}
	
private:
void sort_list(node*& head_ptr);
};

#endif