#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required
  --------------------------------*/
# define CS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 !?:;,.$&<>()+*-_="

struct s_node {
	char c;
	struct s_node *prev;
	struct s_node *next;
};

struct s_dblst {
	struct s_node	*head;
};

struct s_node	*nodenew(char c);
struct s_dblst	*dblstnew(void);
void			dblstsnoc(struct s_dblst *dblst, char c);
char			dblstgetn(struct s_dblst *dblst, int n);

/*--------------------------------
  :) function you must implement
  --------------------------------*/
char *precious(int *text, int size);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
