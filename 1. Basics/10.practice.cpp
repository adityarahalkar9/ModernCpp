#include "iostream"
import <iostream>;
import <array>;

void arrayPractice(){
	int arr[10]{};
	for(int i = 0; i < std::size(arr); ++i){
		std::cout << arr[i] << " ";
	}
}