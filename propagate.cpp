#include "heap_priority_queue.h"
#include <cmath>
#include <cstdlib>
#include <iostream>

#include "image.h"

struct pos
{
	int x;
	int y;
	int speed;
};


bool operator <(const pos& x, const pos& y) {
	return x.speed < y.speed;
}

bool operator >(const pos& x, const pos& y) {
	return x.speed > y.speed;
}

/*
*  Purpose for program
*  This program find a black pixel in the input image and propagates as long
*  as the given time period.
*
*
*  Programmer: Onat Calik
*  Date: November 18, 2016
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/
int main(int argc, char *argv[])
{
	if (argc != 3) {
		std::cout << "Missing Argument" << std::endl;
		return EXIT_FAILURE;

		try
		{
			HeapPriorityQueue<pos> list;
			Image<Pixel> initial = readFromFile(argv[1]);
			Image<Pixel> speed = readFromFile(argv[2]);
			Image<Pixel> output = initial;
			unsigned int T = std::atoi(argv[4]);
			pos first;

			for (int i = 0; i < initial.width(); i++)
			{
				for (int j = 0; j < initial.height(); j++)
				{
					if (initial(i, j).red == 0)
					{
						first.x = i;
						first.y = j;
						break;
					}
				}
			}
			int i = 1;

			while (i <= T)
			{
				if (initial(first.x + i, first.y).red == 255 && (first.x + i) <= initial.width())
				{
					pos temp;
					temp.x = first.x + i;
					temp.y = first.y;
					temp.speed = speed(first.x + i, first.y).red;

					list.add(temp);

				}

				if (initial(first.x - i, first.y).red == 255 && (first.x - i) >= 0)
				{
					pos temp;
					temp.x = first.x - i;
					temp.y = first.y;
					temp.speed = speed(first.x - i, first.y).red;


					list.add(temp);

				}

				if (initial(first.x, first.y + i).red == 255 && (first.y + i) <= initial.height())
				{
					pos temp;
					temp.x = first.x;
					temp.y = first.y + i;
					temp.speed = speed(first.x, first.y + i).red;


					list.add(temp);

				}

				if (initial(first.x, first.y - i).red == 255 && (first.y - i) >= 0)
				{
					pos temp;
					temp.x = first.x;
					temp.y = first.y - i;
					temp.speed = speed(first.x, first.y - i).red;


					list.add(temp);

				}

				while (!list.isEmpty())
				{
					initial(list.peek().x, list.peek().y).red = 0;
					initial(list.peek().x, list.peek().y).green = 0;
					initial(list.peek().x, list.peek().y).blue = 0;
					list.remove();
					output = initial;
				}

				i++;

			}

			output = initial;

			writeToFile(output, argv[3]);
		}

		catch (std::exception &ex) {
			std::cerr << ex.what() << std::endl;
			return EXIT_FAILURE;
		}

		return EXIT_SUCCESS;
	}
}