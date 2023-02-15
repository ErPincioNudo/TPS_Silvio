#include <iostream>
#include <ctime>
#include <cstdlib>
#include <memory>

int* invertArr(int arr[], int arrSize);
void printArr(int arr[], int arrSize);
void loadArr(int arr[], int arrSize);

int main()
{
	// array and constants
	const int arr0Size = 10;
	int arr0[arr0Size];

	// Welcome message
	std::cout << "Hello this program will create an array of 10 integers,\nload it with random nums from -50 to 50,\nand then heap allocate another array that'll have the elements inverted.\n";
	
	// Loading array
	loadArr(arr0, arr0Size);

	// Printing array
	printArr(arr0, arr0Size);

	// Assigning heap allocated inverted array to a unique ptr
	std::unique_ptr<int*> invArr = std::make_unique<int*>(invertArr(arr0,arr0Size));

	// Print inverted array
	printArr(*invArr, arr0Size);

	// Shutdown message
	std::cout << "\n\nThe program has finished executing and it'll now close once you press enter. ";

	std::cin.get();
}

int* invertArr(int arr[], int arrSize) // Return a heap allocated inverted array of the one taken as input !! REMEMBER TO DELETE THE ARRAY !!
{
	int* ptr = new int[arrSize]; // heap allocating array

	for (int i = 0; i < arrSize; i++) // inverting...
		ptr[arrSize - i - 1] = arr[i];

	return ptr;
}

void printArr(int arr[], int arrSize) // Prints an array taken as input
{
	std::cout << "\n\n";
	for (int i = 0; i < arrSize; i++)
		std::cout << "| " << arr[i] << " ";
}

void loadArr(int arr[], int arrSize) // Loads an array loaded with random integers from -50 to 50
{
	srand(time(NULL)); // Setting seed

	for (int i = 0; i < arrSize; i++)
		arr[i] = rand() % 101 - 50;
}
