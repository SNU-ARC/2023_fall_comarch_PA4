/*
 * cachelab.c - Cache Lab helper functions
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cachelab.h"
#include <time.h>

int arrCount[TYPECOUNT];
int verbosity; /* print trace if set */
int cachePolicy; // 0 : lru, 1 : fifo

void initCount()
{
	for(int i = 0; i < TYPECOUNT; i++)
	{
		arrCount[i] = 0;
	}
}

void Verbose(TYPE t)
{
	arrCount[t]++;
		
	if(verbosity)
	{
		switch(t)
		{
			case 	L1_Miss:
				printf("L1 Miss ");
				break;
			case	L1_Hit:
				printf("L1 Hit ");
				break;
			case	L1_Eviction:
				printf("L1 Eviction ");
				break;
			case 	L2_Miss:
				printf("L2 Miss ");
				break;
			case	L2_Hit:
				printf("L2 Hit ");
				break;
			case	L2_Eviction:
				printf("L2 Eviction ");
				break;
			case	L2_Write:
				printf("L2 Write ");
				break;
			case	Mem_Write:
				printf("Mem Write ");
				break;
			default:
				break;
		}
	}
	
}

/* 
 * printSummary - Summarize the cache simulation statistics. Student cache simulators
 *                must call this function in order to be properly autograded. 
 */
void printSummary()
{
    FILE* output_fp = fopen("./csim_results", "w");
    assert(output_fp);
      
    for(int i = 0; i < TYPECOUNT; i++)
    {
    	fprintf(output_fp, "%d ", arrCount[i]);
    }
    fprintf(output_fp, "\n");
	fclose(output_fp);
}


