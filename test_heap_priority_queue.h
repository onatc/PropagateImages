#include <cxxtest/TestSuite.h>

#include "heap_priority_queue.h"

#include <stdexcept>
template class HeapPriorityQueue<int>;

class HeapTests : public CxxTest::TestSuite
{
public:

	void testAdd1(void)
	{
		HeapPriorityQueue<int> a;

		a.add(1);

		TS_ASSERT_EQUALS(a.peek(), 1);
	}

	void testAdd2(void)
	{
		HeapPriorityQueue<int> a;

		a.add(5);
		a.add(4);
		a.add(8);
		a.add(3);
		a.add(25);
		a.add(12);
		a.add(1);
		a.add(4);

		TS_ASSERT_EQUALS(a.peek(), 25);
	}
	void testAdd3(void)
	{
		HeapPriorityQueue<int> a;

		a.add(5);
		a.add(4);
		a.add(3);
		a.add(2);

		TS_ASSERT_EQUALS(a.peek(), 5);
	}

	void testIsEmpty1(void)
	{
		HeapPriorityQueue<int> a;

		TS_ASSERT(a.isEmpty());
	}

	void testIsEmpty2(void)
	{
		HeapPriorityQueue<int> a;

		a.add(5);

		TS_ASSERT(!a.isEmpty());
	}


	void testIsEmpty3(void)
	{
		HeapPriorityQueue<int> a;

		a.add(5);
		a.add(3);
		a.remove();
		a.remove();

		TS_ASSERT(a.isEmpty());
	}

	void testPeek1(void)
	{
		HeapPriorityQueue<int> a;

		a.add(5);
		a.add(3);
		a.remove();

		TS_ASSERT_EQUALS(a.peek(), 3);
	}

   void testPeek2(void)
   {
	   HeapPriorityQueue<int> a;

	   a.add(5);
	   a.add(3);
	   a.add(36);
	   a.remove();
	   a.add(2);
	   a.add(4);
	   a.remove();

	   TS_ASSERT_EQUALS(a.peek(), 4);
   }



   void testRemove1(void)
   {

	   HeapPriorityQueue<int> a;

	   a.add(5);
	   a.add(3);
	   a.add(36);
	   a.add(2);
	   a.remove();
	   a.add(2);
	   a.add(4);
	   a.remove();
	   a.add(24);
	   a.add(1);
	   a.remove();

	   TS_ASSERT_EQUALS(a.peek(), 4);
   }

   void testRemove2(void)
   {

	   HeapPriorityQueue<int> a;

	   a.add(5);
	   a.add(2);
	   a.add(3);
	   a.add(1);
	   a.remove();
	   a.remove();


	   TS_ASSERT_EQUALS(a.peek(), 2);
   }

};
