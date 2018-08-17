/*
Not actual BODMas, parenthesis are necessary in input.

(a+(b*c))		abc*+

((a+b)*(z+x))	ab+zx+*

((a+t)*((b+(a+c))^(c+d)))	at+bac++cd+^*

*/


#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>


int bracket_call(std::string input, int position);

int main()
{
	std::string input[100];
	int freq, i, j, position;


	/*	Input process	*/
	scanf ("%d\n", &freq);

	for(i=0; i<freq; i++)
	{
		std::getline (std::cin, input[i]);
	}

	for(i=0; i<freq; i++)
	{
		position = 0;

		position = bracket_call(input[i], position);
		printf("\n");
	}

	return 0;
}


int bracket_call(std::string input, int position)
{
	char mem, both = 0;

	while(1)
	{
		if(input.size() == position)
			return position;
		else if(input.at(position) == '(')
		{
			position = bracket_call(input, position+1);
			both++;
		}
		else if(input.at(position) == ')')
			return position+1;
		else if(input.at(position) == '+' || input.at(position) == '-' || input.at(position) == '*' || input.at(position) == '/' || input.at(position) == '^')
		{
			mem = input.at(position);
			position++;
		}
		else
		{
			printf("%c", input.at(position));
			position++;
			both++;
		}

		if(both == 2)
			printf("%c", mem);
	}
}
