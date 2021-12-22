



#pragma once


#include<iostream>

template <typename data_type>
struct tree_node;

template <typename data_type>
class BootleggedBinaryTree;


template <typename data_type>
struct tree_node
{
	data_type data;
	tree_node<data_type>* left_node;
	tree_node<data_type>* right_node;

	tree_node() {};
	tree_node(const data_type& input_data);

};

template <typename data_type>
tree_node<data_type>::tree_node(const data_type& input_data)
{
	data = input_data;
	left_node = 0;
	right_node = 0;
}



template <typename data_type>
class BootleggedBinaryTree
{
public:
	
	BootleggedBinaryTree();
	~BootleggedBinaryTree();

	void insert(const data_type& input_data);
	void erase(const data_type& data);
	void find(const data_type& data);

	tree_node<data_type>* find_minimum(tree_node<data_type>* current_root);

	void in_order_traversal();

	void clear();

	tree_node<data_type>* get_tree_root();
	tree_node<data_type>* get_nodes_left_node(tree_node<data_type>* current_root);
	tree_node<data_type>* get_nodes_right_node(tree_node<data_type>* current_root);

private:

	void in_order(tree_node<data_type>* root);
	void post_order_delete(tree_node<data_type>* root);

	size_t size;
	tree_node<data_type>* root;

};

template <typename data_type>
BootleggedBinaryTree<data_type>::BootleggedBinaryTree()
{
	root = 0;
	size = 0;
}

template <typename data_type>
void BootleggedBinaryTree<data_type>::post_order_delete(tree_node<data_type>* root)
{
	if (root->left_node != 0)
	{
		post_order_delete(root->left_node);
	}
	if (root->right_node != 0)
	{
		post_order_delete(root->right_node);
	}

	delete root;
	root = 0;

	return;
}

template <typename data_type>
BootleggedBinaryTree<data_type>::~BootleggedBinaryTree()
{
	post_order_delete(this->root);
}

template <typename data_type>
void BootleggedBinaryTree<data_type>::insert(const data_type& input_data)
{
	if (root == 0)
	{
		root = new tree_node<data_type>(input_data);
	}
	else
	{
		tree_node<data_type>* current_node = root;

		while (current_node != 0)
		{
			if (input_data > current_node->data && current_node->right_node != 0)
			{
				current_node = current_node->right_node;
			}
			else if (input_data <= current_node->data && current_node->left_node != 0)
			{
				current_node = current_node->left_node;
			}
			else
			{
				break;
			}
		}

		tree_node<data_type>* new_node = new tree_node<data_type>(input_data);
		if (input_data > current_node->data)
		{
			current_node->right_node = new_node;
		}
		else
		{
			current_node->left_node = new_node;
		}
	}
}

template <typename data_type>
tree_node<data_type>* BootleggedBinaryTree<data_type>::find_minimum(tree_node<data_type>* current_root)
{
	tree_node<data_type>* current_node = current_root;

	while (current_node != 0 && current_node->left_node != 0)
	{
		current_node = current_node->left_node;
	}

	return current_node;
}


template <typename data_type>
void BootleggedBinaryTree<data_type>::erase(const data_type& data)
{
	tree_node<data_type>* current_node = root;
	tree_node<data_type>* previous_node = root;

	while (current_node != 0)
	{
		if (data > current_node->data && current_node->right_node != 0)
		{
			previous_node = current_node;
			current_node = current_node->right_node;
		}
		else if (data < current_node->data && current_node->left_node)
		{
			previous_node = current_node;
			current_node = current_node->left_node;
		}
		else
		{
			break;
		}

	}

	if (current_node->data != data)
	{
		return;
	}
	else
	{
		if (current_node->left_node == 0 && current_node->right_node == 0)
		{
			if (previous_node->left_node == current_node)
			{
				previous_node->left_node = 0;
			}
			else
			{
				previous_node->right_node = 0;
			}

			delete current_node;
			current_node = 0;
		}
		else if (current_node->left_node != 0 && current_node->right_node != 0)
		{
			tree_node<data_type>* successor_node = find_minimum(current_node->right_node);

			previous_node = current_node->right_node;

			while (previous_node->left_node != successor_node)
			{
				previous_node = previous_node->left_node;
			}

			previous_node->left_node = 0;

			current_node->data = successor_node->data;

			delete successor_node;
			successor_node = 0;
		}
		else
		{
			tree_node<data_type>* successor_node;

			if (current_node->left_node != 0)
			{
				successor_node = current_node->left_node;
			}
			else
			{
				successor_node = current_node->right_node;
			}

			if (previous_node->left_node == current_node)
			{
				previous_node->left_node = successor_node;
			}
			else
			{
				previous_node->right_node = successor_node;
			}

			delete current_node;
			current_node = successor_node;
		}
	}
}

template <typename data_type>
void  BootleggedBinaryTree<data_type>::find(const data_type& data)
{
	tree_node<data_type>* current_node = root;

	while (current_node != 0)
	{
		if (data > current_node->data && current_node->right_node != 0)
		{
			current_node = current_node->right_node;
		}
		else if (data < current_node->data && current_node->left_node)
		{
			current_node = current_node->left_node;
		}
		else
		{
			break;
		}
	}

	if (current_node->data == data)
	{
		std::cout << data << " is in the tree.\n";
		return;
	}
	else
	{
		std::cout << data << " is not in the tree.\n";
	}
}


template <typename data_type>
void BootleggedBinaryTree<data_type>::in_order(tree_node<data_type>* root)
{
	if (root != 0)
	{
		if (root->left_node != 0)
		{
			in_order(root->left_node);
		}
		std::cout << root->data << " ";
		if (root->right_node != 0)
		{
			in_order(root->right_node);
		}
	}
}


template <typename data_type>
void BootleggedBinaryTree<data_type>::in_order_traversal()
{
	in_order(root);
}

template <typename data_type>
void BootleggedBinaryTree<data_type>::clear()
{
	post_order_delete(root);
}


template <typename data_type>
tree_node<data_type>* BootleggedBinaryTree<data_type>::get_tree_root()
{
	return root;
}

template <typename data_type>
tree_node<data_type>* BootleggedBinaryTree<data_type>::get_nodes_left_node(tree_node<data_type>* current_root)
{
	return current_root->left_node;
}

template <typename data_type>
tree_node<data_type>* BootleggedBinaryTree<data_type>::get_nodes_right_node(tree_node<data_type>* current_root)
{
	return current_root->right_node;
}





