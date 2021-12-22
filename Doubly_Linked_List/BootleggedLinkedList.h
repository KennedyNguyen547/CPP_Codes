

#pragma once

#include<iostream>

template <typename data_type>
struct node;

template <typename data_type>
class BootleggedLinkedList;

template <typename data_type>
std::ostream& operator<< (std::ostream& out_stream, const BootleggedLinkedList<data_type>& the_list);


template <typename data_type>
struct node
{
	data_type data;
	node<data_type>* previous_node;
	node<data_type>* next_node;
	node();
	node(const data_type& input_data);
};

template <typename data_type>
node<data_type>::node()
{
	previous_node = 0;
	next_node = 0;
}


template <typename data_type>
node<data_type>::node(const data_type& input_data)
{
	data = input_data;
	previous_node = 0;
	next_node = 0;
}

template <typename data_type>
class BootleggedLinkedList
{
public:

	BootleggedLinkedList();
	~BootleggedLinkedList();

	data_type front() const;
	data_type back() const;

	void push_front(const data_type& data);
	void push_back(const data_type& data);
	void pust_at(const size_t& pos, const data_type& data);

	void pop_front();
	void pop_back();
	void erase_at(const size_t& pos);
	void clear();

	size_t getSize() const;
	bool empty() const;

	node<data_type>* begin() const;
	node<data_type>* end() const;

private:

	node<data_type>* front_node;
	node<data_type>* back_node;
	node<data_type>* dummy_node;

	size_t size;


};

template <typename data_type>
BootleggedLinkedList<data_type>::BootleggedLinkedList()
{
	node<data_type>* dummy_node = new node<data_type>;

	front_node = 0;
	back_node = 0;
	size = 0;


}


template <typename data_type>
BootleggedLinkedList<data_type>::~BootleggedLinkedList()
{
	node<data_type>* current_node = front_node;
	node<data_type>* next_node;

	while (current_node != 0)
	{
		// in this approach, store the pointer to next
		next_node = current_node->next_node;
		// delete current pointer
		delete current_node;
		// assign current node pointer to the next
		current_node = next_node;
	}
	delete dummy_node;
}

template <typename data_type>
data_type BootleggedLinkedList<data_type>::front() const
{
	if (front_node != 0)
	return front_node->data;
}

template <typename data_type>
data_type BootleggedLinkedList<data_type>::back() const
{
	if (back_node != 0)
		return back_node->data;
}

template <typename data_type>
void BootleggedLinkedList<data_type>::push_front(const data_type& data)
{
	if (front_node == dummy_node)
	{
		node<data_type> *new_node = new node<data_type>(data);
		front_node = new_node;
		back_node = new_node;
	}
	else
	{
		node<data_type> *new_node = new node<data_type>(data);
		new_node->next_node = front_node;
		front_node->previous_node = new_node;
		front_node = new_node;
	}
	size++;
	return;
}

template <typename data_type>
void BootleggedLinkedList<data_type>::push_back(const data_type& data)
{
	if (back_node == 0)
	{
		node<data_type> *new_node = new node<data_type>(data);
		front_node = new_node;
		back_node = new_node;
		size++;
		return;
	}
	else
	{
		node<data_type> *new_node = new node<data_type>(data);
		new_node->previous_node = back_node;
		back_node->next_node = new_node;
		back_node = new_node;
		size++;
		return;
	}

}

template <typename data_type>
void BootleggedLinkedList<data_type>::pust_at(const size_t& pos, const data_type& data)
{
	if (pos > size)
	{
		return;
	}

	else
	{
		node<data_type>* current_node = front_node;

		for (int i = 1; current_node != 0 && i < pos; i++)
		{
			current_node = current_node->next_node;
		}
		node<data_type> *new_node = new node<data_type>(data);
		new_node->next_node = current_node->next_node;
		current_node->next_node = new_node;
		new_node->previous_node = current_node;
		if (current_node == back_node)
		{
			back_node = new_node;
		}
		size++;
	}
	return;

}

template <typename data_type>
void BootleggedLinkedList<data_type>::pop_front()
{
	if (front_node == 0)
		return;
	else
	{
		node<data_type> *next_node = front_node->next_node;
		front_node->next_node->previous_node = 0;
		delete front_node;
		front_node = next_node;
		size--;
	}
	return;
}

template <typename data_type>
void BootleggedLinkedList<data_type>::pop_back()
{
	if (back_node == 0)
		return;
	else
	{
		node<data_type> *prev_node = back_node->previous_node;
		prev_node->next_node = 0;
		delete back_node;
		back_node = prev_node;
		size--;
	}
	return;
}

template <typename data_type>
void BootleggedLinkedList<data_type>::erase_at(const size_t& pos)
{
	if (pos > size)
		return;
	else
	{
		node<data_type> *current_node = front_node;

		for (int i = 0; current_node != 0 && i < pos; i++)
		{
			current_node = current_node->next_node;
		}

		current_node->previous_node->next_node = current_node->next_node;
		current_node->next_node->previous_node = current_node->previous_node;

		if (current_node == front_node)
		{
			front_node = current_node->next_node;
		}
		if (current_node == back_node)
		{
			back_node = current_node->previous_node;
		}
		delete current_node;
		size--;
	}
	return;
}

template <typename data_type>
void BootleggedLinkedList<data_type>::clear()
{
	node<data_type> *current_node = front_node;
	node<data_type> *next_node;
	if (current_node != 0)
	{
		for (; current_node != 0; size--)
		{
			next_node = current_node->next_node;
			delete current_node;
			current_node = next_node;
		}
		front_node = 0;
		back_node = 0;
	}
	else
	{
		return;
	}
	return;
}


template <typename data_type>
size_t BootleggedLinkedList<data_type>::getSize() const
{
	return size;
}



template <typename data_type>
bool BootleggedLinkedList<data_type>::empty() const
{
	if (front_node == 0 && back_node == 0)
		return true;
	else
		return false;
}

template <typename data_type>
node<data_type>* BootleggedLinkedList<data_type>::begin() const
{
	if (front_node != 0)
		return front_node;
}

template <typename data_type>
node<data_type>* BootleggedLinkedList<data_type>::end() const
{
	if (back_node != 0)
		return back_node;
}


template <typename data_type>
std::ostream& operator<< (std::ostream& out_stream, const BootleggedLinkedList<data_type>& the_list)
{
	if (the_list.empty())
	{
	}
	else
	{
		for (node<data_type> *current_node = the_list.begin(); current_node != 0;)
		{
			std::cout << current_node->data << " ";
			current_node = current_node->next_node;
		}
	}
	return out_stream;
}




