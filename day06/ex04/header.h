#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
#define WIDTH 8

#define M1	0x5555555555555555ULL
#define M2	0x3333333333333333ULL
#define M4	0x0f0f0f0f0f0f0f0fULL
#define M8	0x00ff00ff00ff00ffULL
#define M16	0x0000ffff0000ffffULL 
#define M32	0x00000000ffffffffULL 

#define ROW(pos) ((pos) / 8)
#define COL(pos) ((pos) % 8)

typedef enum	e_labels
{
	ROW, COL, K, DROW, DCOL
}				t_label;

/*--------------------------------
  :) function you must implement
  --------------------------------*/
int getInitialPos(uint64_t board);
double knightOut(uint64_t board, int n);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
void printBoard(uint64_t board);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
