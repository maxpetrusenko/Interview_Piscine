#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
typedef struct s_people
{
	char *name; 
	int time; //in minute
}t_people;

/*--------------------------------
  :) function you must implement
  --------------------------------*/
int isPossible(struct s_people **people, int nbTable, int totalTime);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_people **readGuestList();


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
