


#include <iostream>


void insertionSort(int some_array[], int size);

void show_array(int some_array[], int size);

int main()
{
	const int array_size = 15;

	int another_array[array_size] = { 1, 12, 3, 4, 51, 6, 7, 18, 9, 10, 11, 23, 13, 32, 15 };

	insertionSort(another_array, array_size);

	show_array(another_array, array_size);

	system("PAUSE");
	return 0;
}

void show_array(int some_array[], int size)
{
	
	for (int i = 0; i < size; i++)
	{
		std::cout << some_array[i] << " ";
	}
	std::cout << "\n";
}



void insertionSort(int some_array[], int size)
{
	//std::cout << size << "\n";
	for (int i = 0; i < size; i++)
	{
		int current_element = some_array[i];
		int j = i - 1;
		while (j >= 0 && some_array[j] < current_element)
		{
			some_array[j + 1] = some_array[j];
			j--;
		}
		some_array[j + 1] = current_element;
		show_array(some_array, size);
		std::cout << "\n";
	}

}

