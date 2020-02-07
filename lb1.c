//////////////////////////////////////////////////
/////     shamsulhaq alamyar                 /////
/////     S.ID 200412179                     /////
/////     Lab Assignment#1                   /////     
//////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "please enter one argument only");
		exit(EXIT_FAILURE);
	}
	else if (argc <= 0)
	{
		fprintf(stderr, " please enter positive numbers only");
		exit(EXIT_FAILURE);
	}

	unsigned int u_NumOfBits = atoi(argv[1]);     // user input number
	unsigned int Run_Avg = 0;                     //for the currnet running average of bits
	double rCount = 0;                            // count how many runs are in the given number
	double rTotal = 0;                            // total number of runs in given number
	double dAverage = 0;                          // the average runs in number

	//iterate  throgh all numbers in bit range
	for (int count = 1; count < (1 << u_NumOfBits) + 1; count++)
	{
		// iterate through bits in number
		for (int i = 0; i < u_NumOfBits; i++)
		{
			if (count & 1 << i && Run_Avg == 0)
			{
				Run_Avg = 1;
				rCount++;
			}
			else if (!(count & 1 << i) && Run_Avg == 1)
				Run_Avg = 0;
		}

		// calculate the running average
		rTotal += rCount;
		dAverage = rTotal / count;

		//  do a reset for next number
		Run_Avg = 0;
		rCount = 0;
	}
	printf("\n%.2f\n", dAverage);
	exit(EXIT_SUCCESS);
}