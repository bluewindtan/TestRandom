// TestRandom.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>

int CalcRandomValue(int nMin, int nMax)
{
	if (nMin > nMax)
	{
		return -1;
	}
	// start random
	//srand( (unsigned)time(NULL) );

	return (int)( (double)rand() / (double)RAND_MAX  * (nMax - nMin + 1) + nMin );
}

int CalcRandomArrayValue(int nCount, int arrProb[])
{
	if (0 == nCount)
	{
		return -1;
	}
	// calc the total value
	int nTotal = 0;
	for (int i=0; i<nCount; i++)
	{
		nTotal += arrProb[i];
	}

	// random
	int nRandom = CalcRandomValue(1, nTotal);

	// get the index at the array
	int nTemp = 0;
	for (int i=0; i<nCount; i++)
	{
		nTemp += arrProb[i];
		if (nRandom <= nTemp)
		{
			return i;
		}
	}

	return -1;
}

#define ARRAY_LENGTH 4

int _tmain(int argc, _TCHAR* argv[])
{
	int arrInt[ARRAY_LENGTH] = {10, 10, 10, 70};
	int arrResult[ARRAY_LENGTH] = {0};
	
	srand( (unsigned)time(NULL) );

	//////////////////////////////////////////////////////////////////////////
	for (int i=0; i<100; i++)
	{
		if (0 == (i % 10))
		{
			printf("\n");
		}
		int nIndex = CalcRandomValue(0, 4);
		printf("%d\t", nIndex);
	}
	printf("\n");
	system("pause");

	//////////////////////////////////////////////////////////////////////////
	for (int i=0; i<100; i++)
	{
		if (0 == (i % 10))
		{
			printf("\n");
		}
		int nIndex = CalcRandomArrayValue(ARRAY_LENGTH, arrInt);
		arrResult[nIndex]++;
		printf("%d\t", nIndex);
	}
	printf("\nthe result is :\n");
	for (int i=0; i<ARRAY_LENGTH; i++)
	{
		printf("\t%d", arrResult[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}

