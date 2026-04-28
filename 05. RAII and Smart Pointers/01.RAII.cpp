#include <iostream>
#include "raii_header.h"
#define _CRT_SECURE_NO_WARNINGS		// Disables MSVC's fopen warning

/*
	RAII is the foundational idiom of C++ resource management. The idea: bind the lifetime
	of a resource (memory, file handle, lock, socket, …) to the lifetime of an object.
	-> Acquisition happens in the constructor.
	-> Release happens in the destructor.
	-> The destructor is automatically called when the object goes out of scope, even if
	   an exception is thrown.
*/

class File{
	std::FILE* handle{nullptr};
public:
	explicit File(const char* filename, const char* mode) : handle{std::fopen(filename,mode)}{
		if(!handle){
			throw std::runtime_error{"Failed to open file"};
		}
	}
	// No copying but move is possible
	File(const File&) = delete;
	File& operator = (const File&) = delete;
	~File(){
		if(handle){
			std::fclose(handle);
		}
	}
	std::FILE* get() const noexcept{
		return handle;
	}
};

void basicRAII(){
	File f{"data.txt", "r"};	// Resource acquired
	// ... use f.get() ...
} // f destroyed here, file closed automatically – no leak, even on exception