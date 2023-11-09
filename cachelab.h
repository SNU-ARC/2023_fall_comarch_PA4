/* 
 * cachelab.h - Prototypes for Cache Lab helper functions
 */

#ifndef CACHELAB_TOOLS_H
#define CACHELAB_TOOLS_H

#define MAX_TRANS_FUNCS 100

typedef struct trans_func{
  void (*func_ptr)(int M,int N,int[N][M],int[M][N]);
  char* description;
  char correct;
  unsigned int num_hits;
  unsigned int num_misses;
  unsigned int num_evictions;
} trans_func_t;

typedef enum Type
{
	L1_Hit = 0,
	L1_Miss,
	L1_Eviction,
	L2_Hit,
	L2_Miss,
	L2_Eviction,
	L2_Write,
	Mem_Write,
	
	TYPECOUNT	
} TYPE;

extern int arrCount[TYPECOUNT];
extern int verbosity; /* print trace if set */
extern int cachePolicy; // 0 : lru, 1 : fifo
/* 
 * printSummary - This function provides a standard way for your cache
 * simulator * to display its final hit and miss statistics
 */ 
void printSummary(); /* number of evictions */

void initCount();

void Verbose(TYPE t);

#endif /* CACHELAB_TOOLS_H */
