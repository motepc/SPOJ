/*

Given a sequence of 2*k characters, please print every second character from the first half of the sequence. Start printing with the first character.

Input
In the first line of input your are given the positive integer t (1<=t<=100) - the number of test cases.
In the each of the next t lines, you are given a sequence of 2*k (1<=k<=100) characters.

Output
For each of the test cases please please print every second character from the first half of a given sequence (the first character should appear).

Example

Input:
	4
	your 
	progress 
	is 
	noticeable

Output:
	y
	po
	i
	ntc

*/







/*

Printf of string and its size can be done as

	printf("\n  String print\n  %s \n  String size is %d\n", in.c_str(), in.size());


oldstring.push_back(newstring)  -   It appends new string at the end of old string

To clear string -		name.clear();
To append 1 digit from int to string -		name.append((char*)(&int), 0, 1);
To replace 1 digit of string by int -		name.replace(location, size,(char*)(&int));
*/



#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>

int main()
{
	std::string input[100];
	int freq, i, j;

	scanf ("%d\n", &freq);

	for(i=0; i<freq; i++)
	{
		std::getline (std::cin, input[i]);
	}

	for(i=0; i<freq; i++)
	{
		j = 0;
		printf("\n");

		while(j < (input[i].size())/2)
		{
			printf("%c", input[i].at(j));
			j = j+2;
		}
	}

	return 0;
}
