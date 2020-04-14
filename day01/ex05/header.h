#ifndef HEADER_H
# define HEADER_H

# define MAX_CAPACITY	1000

/*--------------------------------
  !! required structure
  --------------------------------*/

/*--------------------------------
  :) function you must implement
  --------------------------------*/

// Tank

struct s_elem {
    int energy;
    struct s_elem *next;
};

struct s_stack {
    struct s_elem *elem;
    int sum;
};

struct s_tank {
    struct s_stack **stacks;
    int n;
};

struct s_tank *initTank(void);

void tankPush(struct s_tank *tank, int energy);

int tankPop(struct s_tank *tank);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/


/*--------------------------------
  &  your own other function
  --------------------------------*/

struct s_elem	*elemnew(int energy);
struct s_stack	*initStack(void);
int				isEmpty(struct s_stack *stack);
int				pop(struct s_stack *stack);
void			push(struct s_stack *stack, int energy);
int				peek(struct s_stack *stack);
int				tankIsEmpty(struct s_tank *tank);

#endif
