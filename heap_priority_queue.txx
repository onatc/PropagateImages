#include "heap_priority_queue.h"

#include <stdexcept>

/*
*  Purpose for program
*  This is a 1 indexed heap priority queue.
*
*
*  Programmer: Onat Calik
*  Date: November 18, 2016
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/
template <typename T>
HeapPriorityQueue<T>::HeapPriorityQueue() {}

template <typename T>
bool HeapPriorityQueue<T>::isEmpty()
{

	return (lst.getLength() == 0 || lst.getLength() == 1);
}

template <typename T>
void HeapPriorityQueue<T>::add(const T& item)
{
	if (lst.isEmpty())
	{
		lst.insert(0, item);
	}

	int num = lst.getLength();

	for (; num > 1 && item > lst.getEntry(num / 2); num = num / 2)
	{
		if (num >= lst.getLength())
		{
			lst.insert(num, lst.getEntry(num / 2));
		}
		else
		{
			lst.setEntry(num, lst.getEntry(num / 2));
		}

	}

	if (num >= lst.getLength())
	{
		lst.insert(num, item);
	}
	else
	{
		lst.setEntry(num, item);
	}

}

template <typename T>
void HeapPriorityQueue<T>::remove()
{
	long length = lst.getLength();
	if (length == 0 || length == 1)
	{
		throw std::logic_error("Heap is empty");
	}

	T temp = lst.getEntry(length - 1);
	lst.setEntry(1, temp);
	int i = 1;
	int j = 2;
	while (j <= length - 1)
	{
		if (j < length - 1 && lst.getEntry(j) < lst.getEntry(j + 1))
		{
			j++;
		}
		if (lst.getEntry(i) < lst.getEntry(j))
		{
			T temp = lst.getEntry(i);
			lst.setEntry(i, lst.getEntry(j));
			lst.setEntry(j, temp);
		}
		i = j;
		j = j * 2;
	}

	lst.remove(lst.getLength() - 1);
	
}

template <typename T>
T HeapPriorityQueue<T>::peek()
{
	if (lst.getLength() <= 1)
	{
		throw std::logic_error("Heap is empty");
	}
	return lst.getEntry(1);
}



