#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! my structures
  --------------------------------*/

typedef struct	s_data
{
	int			n_combs;
	int			n_gts;
	int			dist;
}				t_data;

/*--------------------------------
  !! required structure
  --------------------------------*/


/*--------------------------------
  :) function you must implement
  --------------------------------*/
double probaDistance(int dist, int *locations, int n);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
