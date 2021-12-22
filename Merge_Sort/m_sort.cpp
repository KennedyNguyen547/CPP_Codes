





#include <iostream>





template <typename num_type>
void merge(num_type some_array[], const unsigned int index_begin, const unsigned int mid_index, const unsigned int index_end);

template <typename num_type>
void merge_sort(num_type some_array[], const unsigned int index_begin, const unsigned int index_end);




int main()
{

	const int array_size = 10;

	int some_array[array_size] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	merge_sort(some_array, 0, 9);


	for (int i = 0; i < array_size; i++)
	{
		std::cout << some_array[i] << " ";

	}



	system("PAUSE");



	return 0;
}


template <typename num_type>
void merge_sort(num_type some_array[], const unsigned int index_begin, const unsigned int index_end)
{
	if (index_begin < index_end)
	{
		unsigned int mid_index = (index_begin + index_end) / 2;

		merge_sort(some_array, index_begin, mid_index);

		merge_sort(some_array, mid_index + 1, index_end);

		merge(some_array, index_begin, mid_index, index_end);
	}



}







template <typename num_type>
void merge(num_type some_array[], const unsigned int index_begin, const unsigned int mid_index, const unsigned int index_end)
{
	const unsigned int left_size = mid_index - index_begin + 1;

	const unsigned int right_size = index_end - mid_index;

	num_type* left_side = new num_type[left_size];

	num_type* right_side = new num_type[right_size];

	for (unsigned int i = 0; i < left_size; i++)
	{
		left_side[i] = some_array[index_begin + i];
	}
	for (unsigned int j = 0; j < right_size; j++)
	{
		right_side[j] = some_array[mid_index + j + 1];
	}


	for (unsigned int k = index_begin, i = 0, j = 0; k <= index_end; k++)
	{
		if ((left_side[i] <= right_side[j] && i < left_size) || (i < left_size && j >= right_size))
		{
			some_array[k] = left_side[i];
			i++;
		}
		else
		{
			some_array[k] = right_side[j];
			j++;
		}

	}

	delete[] left_side;
	delete[] right_side;

}




