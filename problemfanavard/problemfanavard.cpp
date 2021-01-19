// problemfanavard.cpp : Defines the entry point for the console application.

#include "stdafx.h"

#include <iostream>
using namespace std;

int main() {

	//n is number of objects , m is number of boxes , k is size of boxes

	int n, m, k, sumsize = 0, sum1 = 0, sum2 = 0, sum3 = 0, sumobj = 0;

	int i, j, p = 0, b, Counter; //These are the loop counters used in the program
	int result;
	cout << "Enter number of objects, number of boxes and size of boxes";
	cin >> n >> m >> k;

	int *objects = new int[n + 1];
	int *numbox = new int[m + 1];
	sumsize = k*m;

	cout << "Enter size of objects Respectively";

	for (Counter = 1; Counter <= n; Counter++)
	{
		cin >> objects[Counter];
	}


	for (i = n; i > 0; i--)
	{
		if (sum1 + objects[i] <= sumsize)
		{
			sum1 += objects[i];  //Collect objects until they are <= to the total capacity of the boxes

		}
		else
		{
			i++;
			j = i;
			break;
		}
	}
	if (i == 0)
	{
		i++;
		j = i;
	}
	while (i <= n)
	{
		sumobj = 0;
		while (sumobj + objects[i] <= k && i <= n)
		{
			sumobj += objects[i];  //Collect objects until they are <= to the total capacity one of the box
			i++;
		}

		numbox[p] = sumobj;
		p++;
		if (p == m&& i <= n) //If objects did not end
		{
			p = 0;
			sum2 = 0;
			for (b = n; b >= i; b--)
			{
				sum2 += objects[b];  //sum of remaining objects
			}
			sum3 = 0;
			while (sum3<sum2)
			{
				sum3 += objects[j];
				j++;
			}
		}
	}
	i--;
	if (i == n)
	{
		result = n - (j - 1);
		cout << "number of objects is: " << result << "   ";
	}
	return 0;
}