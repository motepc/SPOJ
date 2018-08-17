/*

Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Input:The first line contains an integer 'T' denoting the total number of test cases.
Each test case constitutes of two lines.
First line contains 'N', representing the number of elements in the set and the second line contains the elements of the set.

Output: Print YES if the given set can be partioned into two subsets such that the sum of elements in both subsets is equal, else print NO.


Constraints: 
1 <= T<= 100
1 <= N<= 100
0 <= arr[i]<= 1000


Example:

Input:
2
4
1 5 11 5
3
1 3 5 

Output:

YES
NO

*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include <bitset>


using namespace std;


int divide(int* seq, int target, int size, int* group, int* counter);


int main()
{
	int freq, t, i, size, target, seq[100], group[100], outsize;
	int* counter;


	scanf ("%d\n", &freq);

	for(t=0; t<freq; t++)
	{
		cin >> size;
		for(i=0; i<size; i++)
			cin >> seq[i];

		target = 0;
		for(i=0; i<size; i++)
			target = target + seq[i];

		if(target%2 == 1)
		{
			printf("NO\n");
			return 0;
		}

		target = target/2;
		outsize = 0;
		counter = &outsize;

		if(divide(&seq[0], target, size, &group[0], counter))
		{
			printf("YES\n");

			for(i=outsize-1; i>=0; i--)
				printf("%d ", group[i]);

			printf("\n");
		}
		else
			printf("NO\n");
	}

	return 0;
}

int divide(int* seq, int target, int size, int* group, int* counter)
{
	if(target < 0)
		return 0;

	if(target == *seq)
	{
		group[*counter] = *seq;
		*counter = *counter + 1;

		return 1;
	}

	if(size == 1)
		return 0;

	if(divide((seq+1), (target-*seq), (size-1), group, counter))
	{
		group[*counter] = *seq;
		*counter = *counter + 1;

		return 1;
	}

	if(divide((seq+1), target, (size-1), group, counter))
		return 1;

	return 0;
}
