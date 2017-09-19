#ifndef _DYNAMIC_ARRAY_LIST_H_
#define _DYNAMIC_ARRAY_LIST_H_

#include "abstract_list.h"

template <typename T> class DynamicArrayList : public AbstractList<T> {
public:

	//constructor
	DynamicArrayList();

	//copy constructor
	DynamicArrayList(const DynamicArrayList &x);

	//destructor
	~DynamicArrayList();

	//operator
	DynamicArrayList &operator=(DynamicArrayList x);

	//checks if list is empty
	bool isEmpty();

	//returns the length of list
	std::size_t getLength();

	//insert an item at the list at given position
	void insert(std::size_t position, const T &item);

	//remove an item from a given position
	void remove(std::size_t position);

	//clear the list
	void clear();

	//return entry at given position
	T getEntry(std::size_t position);

	//set entry at given position
	void setEntry(std::size_t position, const T &newValue);
	
	//swap
	void swap(DynamicArrayList &x, DynamicArrayList &y);

private:

	T *data;
	std::size_t capacity;
	std::size_t size;

};

#include "dynamic_array_list.txx"

#endif // _DYNAMIC_ARRAY_LIST_H_
