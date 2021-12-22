






#include <iostream>
#include <vector>

#include <algorithm>




/*
below are functions for indexing

*/
 int parent_index(const unsigned int & index);

int left_index(const unsigned int & index);


 int right_index(const unsigned int & index);


 /*
 below function gives the array the max heap property starting at index i
 */

void max_heapify(int some_array[], const int& size, const int & index);


/*
below function turns the array into a maximum heap array
*/

void build_max_heap(int some_array[], const int& size);


// sorts using the above functions
void heap_sort(int some_array[], const int& size);




void min_heapify(int some_array[], const int& size, const int& index);




int main()
{
	int some_array[] = { 27,17,3,16,13,10,1,5,7,12,4,8,9,0};
	//int size = 14;


	//heap_sort(some_array, 14);

	//max_heapify(some_array, 14, 2);
	/*
	std::cout << std::is_heap(some_array, some_array+13);

	std::cout << std::endl;
	build_max_heap(some_array, 13);

	std::cout << std::endl;
	std::cout << std::is_heap(some_array, some_array + 13);
	std::cout << std::endl;
	//min_heapify(some_array, 14, 0);

	*/

	//min_heapify(some_array, 14, 2);




	for (int i = 0; i < 14; i++)
	{
		std::cout << some_array[i] << " ";

	}
	std::cout << "\n";


	return 0;

}










int parent_index(const unsigned int & index)
{
	return (index >> 1) - 1;

}

 int left_index(const unsigned int & index)
{
	return (index << 1) +1;
}


int right_index(const unsigned int & index)
{
	return (index << 1) +2  ;
}




void max_heapify(int some_array[], const int& size , const int & index)
{
	int left = left_index(index);
	int right = right_index(index);

	int index_of_largest = index;

	/*
	std::cout << " index : " << index << std::endl
		<< "left index : " << left << std::endl
		<< " right index : " << right << std::endl 
		<< " index of largest: " << index_of_largest <<  std::endl;
		*/

	if (left < size && some_array[left] > some_array[index])
	{
		index_of_largest = left;
	}
	else
	{
		index_of_largest = index;
	}

	if (right < size && some_array[right] > some_array[index_of_largest])
	{
		index_of_largest = right;
	}

	if (index_of_largest != index )
	{
		std::swap(some_array[index], some_array[index_of_largest]);
		max_heapify(some_array, size, index_of_largest);
	}
	return;

}

void build_max_heap(int some_array[], const int& size)
{
	for (int i = (size >> 1); i > 1; i--)
	{
		max_heapify(some_array, size, i);
	}
}


void heap_sort(int some_array[], const int& size)
{
	int heap_size = size - 1;
	build_max_heap(some_array, size -1);


	for (int i = size -1; i >0; i--)
	{

		std::swap(some_array[0], some_array[i]);
		heap_size--;
		max_heapify(some_array, heap_size, 0);
	}


	return;

}

void min_heapify(int some_array[], const int& size, const int& index)
{
	int left = left_index(index);
	int right = right_index(index);

	int index_of_smallest = index;

	if (left < size && some_array[left] < some_array[index])
	{
		index_of_smallest = left;
	}
	else
	{
		index_of_smallest = index;
	}


	if (right < size && some_array[right] < some_array[index_of_smallest])
	{
		index_of_smallest = right;
	}

	if (index_of_smallest != index)
	{
		std::swap(some_array[index], some_array[index_of_smallest]);
		min_heapify(some_array, size, index_of_smallest);
	}


	return;
}




/*
for (int i = 0; i < size; i++)
{
std::cout << some_array[i] << " ";

}

std::cout << "\n";
*/



























