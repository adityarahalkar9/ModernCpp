#include "basic_header.h"
import <iostream>;
import <array>;
import <algorithm>;

/*
	The std::array class template is a modern alternative to c-style arrays that provides
	safe, efficient and predictable behaviour while maintaining compatibility with standard 
	algorithms.
	-> std::array<T, N> is fixed size. N is known at compile time.
	-> Safer than C-style arrays. Provides bounds checked access with .at().
	-> Stack allocation - No dynamic memory allication
	-> STL Compatible
	-> Support iterators: Can be used with ranged based loops and STL iterators.
*/
// Function to demonstrate basic usage of arrays
void basicUsage(){
	// Declaring and inititalising std::array
	std::array<int, 5> arr1{1,2,3,4,5};

	// Zero initialised array
	std::array<int, 5> arr2{};

	// Accessing elements
	std::cout << "arr1[2]: " << arr1[2] << std::endl;			// Fast Access(unsafe)
	std::cout << "arr1.at(2): " << arr1.at(2) << std::endl;		// Safe Access

	// Accessing first and last elements
	std::cout << "First element: " << arr1.front() << std::endl;
	std::cout << "Last element: " << arr1.back() << std::endl;
	std::cout << std::endl;
}


// Function to modify array
void modifyArray(){
	std::array<int, 5> arr{};
	arr.fill(42);				// Fill all elements of array with 42
	for(int i : arr){
		std::cout << i << " ";
	}
	std::cout << std::endl;
}


/*
	An iterator is like a smart pointer�declared via Container::iterator
	that lets you:
	=> Start at arr.begin()
	=> Move forward with ++it
	=> Read or modify elements using *it
	=> Stop at arr.end()

	Why use an iterator instead of indexes?
	=> Generic traversal: Works uniformly with arrays, lists, vectors, sets, etc.
	=> Cleaner code: No index tracking or bounds calculation.
	=> Composability: Compatible with STL algorithms (std::sort, std::find, etc.) that work on iterator ranges.
	=> Access control: Iterator categories (random-access, bidirectional, input/output) define operations you can use.
*/
void iterateArray(){
	std::array<int, 5> arr{10,20,30,40,50};
	std::cout << "Iterating using ranged based loop" << std::endl;
	for(int i : arr){
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::cout << "Iterating using iterator" << std::endl;
	for(std::array<int, 5>::iterator it = arr.begin(); it != arr.end(); ++it){
		std::cout << *it << " ";
	}
}


// Functions to demonstrate swapping
void swapArray(){
	std::array<int, 3> arr1{1,2,3};
	std::array<int, 3> arr2{4,5,6};
	arr1.swap(arr2);	// Swap contents of arr1 and arr2
	std::cout << "arr1 after swap " << std::endl;
	for(int i : arr1){
		std::cout << i << " ";	// arr1 now has {4,5,6}
	}
}


// Using algorithms on std::array
void useAlgorithms(){
	std::array<int, 5> arr = {5,1,4,2,3};

	// Sorting array using std::sort
	std::sort(arr.begin(), arr.end());
	std::cout << "Sorted array is" << std::endl;
	for(int i : arr){
		std::cout << i << " ";
	}
	std::cout << std::endl;

	// Finding an element in sorted array using std::find
	std::array<int, 5>::iterator it = std::find(arr.begin(), arr.end(), 3);
	if(it != arr.end()){
		std::cout << "Found at index: " << (it - arr.begin()) << std::endl;
	}
}


int stlArray(){
	// basicUsage();
	// modifyArray();
	// iterateArray();
	// swapArray();
	// useAlgorithms();

	return 0;
}


/*
	When to use std::array
	=> When array size is fixed and known at compile time
	=> When performance matters(no heap allocation like std::vector)
	=> When you need safe indexing with .at() (Bounds checking access)
	=> When working with algorithms,STL etc

	When not to use std::array
	=> If you need dynamic resizing, use std::vector
	=> If size is unknown at compile time, use std::vector or std::unique_ptr<T[]>
	=> If you need heap allocation, prefer std::vector
*/