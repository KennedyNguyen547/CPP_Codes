

#pragma once

#include <string>
#include <functional>
#include <iostream>

template <typename key_type, typename data_type>
struct key_value_pair;

template <typename key_type, typename data_type>
class BootleggedHashTable;


template <typename key_type, typename data_type>
std::ostream& operator<< (std::ostream& out_stream, const BootleggedHashTable<key_type, data_type>& the_table);


template <typename key_type, typename data_type>
struct key_value_pair
{
	key_value_pair();
	key_value_pair(const key_type& input_key_value, const data_type& input_data_value);

	key_type key_value;
	data_type data_value;


};

template <typename key_type, typename data_type>
key_value_pair<key_type, data_type>::key_value_pair()
{
	key_type key_value = key_type();
	data_type data_value = data_type();
}


template <typename key_type, typename data_type>
key_value_pair<key_type, data_type>::key_value_pair(const key_type& input_key_value, const data_type& input_data_value)
{
	key_value = input_key_value;
	data_value = input_data_value;
}

template <typename key_type, typename data_type>
bool operator==(const key_value_pair<key_type, data_type>& left_pair, const key_value_pair<key_type, data_type>& right_pair)
{
	return (left_pair.key_value == right_pair.key_value && left_pair.data_value == right_pair.data_value);
}

template <typename key_type, typename data_type>
bool operator!=(const key_value_pair<key_type, data_type>& left_pair, const key_value_pair<key_type, data_type>& right_pair)
{
	return !(left_pair.key_value == right_pair.key_value && left_pair.data_value == right_pair.data_value);
}

template <typename key_type, typename data_type>
class BootleggedHashTable
{
public:
	BootleggedHashTable();
	~BootleggedHashTable();

	void insert(const key_type& key_value, const data_type& data_value);
	void erase(const key_type& key_value, const data_type& data_value);
	void clear();

	size_t current_size() const;
	size_t current_cap_size() const;

	bool all_buckets_occupied() const;

	key_value_pair<key_type, data_type>* begin();




private:

	void resize();
	key_value_pair<key_type, data_type> *begin_pointer;
	size_t size;
	size_t cap_size;

	friend std::ostream& operator<< <> (std::ostream& out_stream, const BootleggedHashTable& the_table);

};

template <typename key_type, typename data_type>
BootleggedHashTable<key_type, data_type>::BootleggedHashTable()
{
	size = 0;
	cap_size = 16;

	begin_pointer = new key_value_pair<key_type, data_type>[cap_size];

	
	for (size_t i = 0; i < cap_size; i++)
	{
		begin_pointer[i] = key_value_pair<key_type, data_type>();
	}
	
}

template <typename key_type, typename data_type>
BootleggedHashTable<key_type, data_type>::~BootleggedHashTable()
{
	delete[] begin_pointer;
}


template <typename key_type, typename data_type>
void BootleggedHashTable<key_type, data_type>::insert(const key_type& key_value, const data_type& data_value)
{
	std::hash<key_type> hash_type;

	key_value_pair<key_type, data_type> blank_pair = key_value_pair<key_type, data_type>();

	size_t bucket_slot = hash_type(key_value) % cap_size;
	key_value_pair<key_type, data_type> new_pair = key_value_pair<key_type, data_type>(key_value, data_value);
	if (begin_pointer[bucket_slot] == blank_pair)
	{
		begin_pointer[bucket_slot] = new_pair;
		size++;
	}
	else
	{
		begin_pointer[bucket_slot] = new_pair;
	}

	if (all_buckets_occupied())
	{
		resize();
	}
	return;
}

template <typename key_type, typename data_type>
void BootleggedHashTable<key_type, data_type>::erase(const key_type& key_value, const data_type& data_value)
{
	std::hash<key_type> hash_type;

	size_t bucket_slot = hash_type(key_value) % cap_size;
	if (begin_pointer[bucket_slot].data_value == data_value)
	{
		begin_pointer[bucket_slot] = 0;
		size--;
	}
	return;
}

template <typename key_type, typename data_type>
void BootleggedHashTable<key_type, data_type>::clear()
{
	for (size_t i = 0; i < cap_size; i++)
	{
		begin_pointer[i] = 0;
	}
}

template <typename key_type, typename data_type>
size_t BootleggedHashTable<key_type, data_type>::current_size() const
{
	return size;
}

template <typename key_type, typename data_type>
size_t BootleggedHashTable<key_type, data_type>::current_cap_size() const
{
	return cap_size;
}


template <typename key_type, typename data_type>
void BootleggedHashTable<key_type, data_type>::resize()
{
	size_t old_cap_size = cap_size;
	cap_size *= 2;

	key_value_pair<key_type, data_type>  blank_pair = key_value_pair<key_type, data_type>();

	key_value_pair<key_type, data_type>* new_begin_pointer = new key_value_pair<key_type, data_type>[cap_size];

	for (size_t i = 0; i < cap_size; i++)
	{
		new_begin_pointer[i] = key_value_pair<key_type, data_type>();
	}

	std::hash<key_type> hash_type;

	for (size_t i = 0; i < size; i++)
	{
		if (begin_pointer[i] != blank_pair)
		{

			size_t bucket_slot = hash_type(begin_pointer[i].key_value) % cap_size;
			new_begin_pointer[bucket_slot] = begin_pointer[i];
		}
	}

	delete[] begin_pointer;

	begin_pointer = new_begin_pointer;

}


template<typename key_type, typename data_type>
bool BootleggedHashTable<key_type, data_type>::all_buckets_occupied() const
{
	bool all_buckets_occupied = true;
	key_value_pair<key_type, data_type> blank_pair = key_value_pair<key_type, data_type>();

	for (size_t i = 0; i < cap_size; i++)
	{
		if (begin_pointer[i] == blank_pair)
		{
			all_buckets_occupied = false;
		}
	}
	return all_buckets_occupied;
}

template <typename key_type, typename data_type>
key_value_pair<key_type, data_type>* BootleggedHashTable<key_type, data_type>::begin()
{
	return begin_pointer;
}

template <typename key_type, typename data_type>
std::ostream& operator<< (std::ostream& out_stream, const BootleggedHashTable<key_type, data_type>& the_table)
{
	key_value_pair<key_type, data_type> blank_pair = key_value_pair<key_type, data_type>();

	key_value_pair<key_type, data_type>* begin_pointer = the_table.begin_pointer;

	for (size_t i = 0; i < the_table.current_cap_size(); i++)
	{
		if (begin_pointer[i] != blank_pair)
		{
			std::cout << "key: " << begin_pointer[i].key_value << "\n" << "stored in bucket slot " << i << "\n" <<
				"value: " << begin_pointer[i].data_value << "\n\n";
		}
	}
	return out_stream;
}





