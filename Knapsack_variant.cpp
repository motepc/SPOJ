/*

Puzzle Problem

Take input array of integers. Then also an integer N as an input.
Find a subset of numbers from array such that difference between summation of all numbers from subset and N should be minimum.

Author - Pravin Mote
12th Dec 2015
*/



#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>


int group(int *input, int N, int size, int *subset, int *ptr);

int main()
{
	int size, i, N, sum = 0, position = 0;
	int * ptr;

	printf("\n\n  Give size of array - ");
	std::cin >> size;

	int input[size], subset[size];
	printf("\n  Input %d numbers (separated by space) - ", size);

	for(i=0; i<size; i++)
	{
		std::cin >> input[i];
		subset[i] = 0;
	}

	printf("\n  Input target - ");
	std::cin >> N;

	ptr = &position;

	sum = group(&input[0], N, size, &subset[0], ptr);

	i = 0;
	printf("\n\n  ");printf("\n\nReached in last *ptr = %d\n", *ptr);

	while(i < *ptr)
	{
		printf("%d  ", subset[i]);

		i++;
	}

	printf("=  %d", sum);


	printf("\n\n");
	return 0;
}


int group(int *input, int N, int size, int *subset, int *ptr)
{
	int temp1, temp2, current, position;
	position = *ptr;

	if(size == 1)
	{
		current = *input;
		if((N-current)*(N-current) > N*N)
			return 0;
		else
		{
			subset[*ptr] = current;
			*ptr = *ptr + 1;
			return current;
		}
	}

	current = *input++;
	temp1 = current + group(input, N-current, size-1, subset, ptr);
	temp2 = group(input, N, size-1, subset, ptr);

	if((N-temp1)*(N-temp1) > (N-temp2)*(N-temp2))
	{
		*ptr = position;
		return temp2;
	}
	else
	{
		subset[*ptr] = current;
		*ptr = *ptr + 1;
		return temp1;
	}
}
