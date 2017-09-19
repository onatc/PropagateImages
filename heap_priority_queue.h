#ifndef HEAP_PRIORITY_QUEUE_H
#define HEAP_PRIORITY_QUEUE_H

#include "abstract_priority_queue.h"
#include "dynamic_array_list.h"
#include <stdexcept>
template <typename T>
class HeapPriorityQueue : public AbstractPriorityQueue<T>
{
public:

	HeapPriorityQueue();

	// return true if the priority queue is empty
	bool isEmpty();

	// insert item into the queue
	void add(const T& item);

	// remove highest priority item from the queue
	void remove();

	// get the item with the highest priority from the queue
	T peek();

private:

	DynamicArrayList<T> lst;
};


#include "heap_priority_queue.txx"


#endif // _HEAP_PRIORITY_QUEUE_H_

