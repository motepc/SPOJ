/*

Input is a seq of max 100 integers.
Order(order=n) is this seq is calculated using recursive diff of seq.

Then polynimial of order n		P(n) = a(D).n^D+a(D-1).n^(D-1)+...+a1.n+a0		gives system of linear equation,
								P(1) = a(D)    +a(D-1)        +...+a1  +a0 = seq(0)
								P(2) = a(D).2^D+a(D-1).2^(D-1)+...+a1.2+a0 = seq(1)
	This system of linear eqution is converted to matrix
								[coeff][a] = [seq]
*/



#include<iostream>
#include<cstdio>
#include<cmath>


using namespace std;


int main()
{
	int freq, t, i, j, k;
	int insize, outsize, order;
	long double matrix[100][100], input[100], diff[100], factor;

	scanf ("%d\n", &freq);

	for(t=0; t<freq; t++)
	{
		cin >> insize >> outsize;

		for(i=0; i<insize; i++)
		{
			cin >> input[i];
		}

		for(i=0; i<insize; i++)
		{
			diff[i] = input[i];
		}

		//		Calculate order of polynomial by finding recursive differences
		order = 0; j = 0;
		while(order < (insize-1))
		{
			for(i=0; i<(insize-order-1); i++)
			{
				if(diff[i] != diff[i+1])
					break;

				if(i == (insize-order-2))
					j = 1;
			}

			if(j == 1)
				break;

			for(i=0; i<(insize-order-1); i++)
				diff[i] = diff[i+1] - diff[i];

			order++;
		}

		//		Create coeff matrix of order+1
		order++;
		for(i=0; i<order; i++)
		{
			for(j=(order-1); j>=0; j--)
			{
				matrix[i][j] = pow((long double)(i+1),(order-1-j));
			}
		}

		//		Create upper matrix by row transformation of augmented matrix
		for(i=0; i<order; i++)
		{
			for(j=i+1; j<order; j++)
			{
				factor = matrix[j][order-1-i]/matrix[i][order-1-i];

				for(k=0; k<order; k++)
				{
					matrix[j][k] = matrix[j][k] - factor*matrix[i][k];
				}

				input[j] = input[j] - factor*input[i];
			}
		}

		//		Multiply upper triangular matrix with variable matrix [Coeff][a] = [input]
		for(i=0; i<order; i++)
		{
			diff[i] = 0;
			for(j=0; j<i; j++)
				diff[i] = diff[i] + matrix[order-1-i][j]*diff[j];

			diff[i] = (input[order-1-i] - diff[i])/matrix[order-1-i][i];
		}

		//		Calculate subsequent outputs
		order--;
		for(i=(insize+1); i<(insize+outsize+1); i++)
		{
			factor = 0;
			for(j=order; j>=0; j--)
				factor = factor + diff[order-j]*pow(i,j);

			printf("%lld", ((long long)(factor + 0.5)));
			if(i != (insize+outsize))
				printf(" ");
		}
		cout << "\n";
	}

	return 0;
}
