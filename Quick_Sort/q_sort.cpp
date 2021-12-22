




#include <iostream>

#include <vector>

#include <algorithm>

#include <random>

#include <iterator>

#include <array>

template <typename data_type>
void q_sort(data_type some_array[], const int& size, const int& left, const int& right);

template <typename data_type>
int partition(data_type some_array[], const int& size , const int& left, const int & right);



int main()
{
	
	int size;


	std::random_device rand_dev;
	std::mt19937 range(rand_dev());
	std::uniform_int_distribution<int> distribution(-100000, 100000);

	std::cout << "pick an array size : ";
	std::cin >> size;

	int * some_array = new int[size];


	for (int i = 0; i < size; i++)
	{
		some_array[i] = distribution(range);
	}


	for (int i = 0; i < size; i++)
	{
		std::cout << some_array[i] << " ";
	}
	std::cout << "\n";

	q_sort(some_array, size, 0, size-1);

	for (int i = 0; i < size; i++)
	{
		std::cout << some_array[i] << " ";
	}

	std::cout << "\n";
	std::cout << std::is_sorted(some_array, some_array + (size - 1));

	delete[] some_array;



	return 0;




}



template <typename data_type>
void q_sort(data_type some_array[], const int& size, const int& left, const int& right)
{
	if (left < right)
	{
		int index_q = partition(some_array, size, left, right);
		q_sort(some_array, size, left, index_q - 1);
		q_sort(some_array, size, index_q + 1, right);
	}

}


template <typename data_type>
int partition(data_type some_array[], const int& size, const int& left, const int & right)
{

	data_type pivot = some_array[right];
	int index_i = left - 1;

	for (int index_j = left; index_j < right; index_j++)
	{
		if (some_array[index_j] <= pivot)
		{
			index_i++;
			std::swap(some_array[index_i], some_array[index_j]);
		}
	}
	std::swap(some_array[index_i + 1], some_array[right]);
	return index_i + 1;
}



























