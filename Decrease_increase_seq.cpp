/*

You are given S - a sequence of n integers S = s1, s2, ..., sn.
Please, compute if it is possible to split S into two parts: s1, s2, ..., si and si+1, si+2, ..., sn (1 <= i < n)
in such a way that the first part is strictly decreasing while the second is strictly increasing one.


Input data specification
In the first line you are given an integer 2<=n<=100 and in the following line n integers 
-100 <= si <= 100.


Output data specification
One word Yes or No.


Example 1
Input:
5 
-1 2 -1 1 -1 

Output:
No


Example 2
Input:
6 
3 1 -2 -2 -1 3 

Output:
Yes


Example 3
Input:
6 
2 2 1 0 1 2
 
Output:
No

*/




#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>



int main()
{
	int i, ns, s[100], half = 0;


	scanf ("%d\n", &ns);

	for(i=0; i<ns; i++)
	{
		std::cin >> s[i];
	}


	i = 1;

	while(s[i-1] > s[i])
	{
		i++;
		if(i == ns)
		{
			printf("Yes");
			return 0;
		}
	}

	half = 1;
	i++;

	while(s[i-1] < s[i])
	{
		i++;
		if(i == ns)
		{
			printf("Yes");
			return 0;
		}
	}

	printf("No");

	return 0;
}
