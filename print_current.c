#include "header.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------*/
/*!
 @fn void print_current(struct cell board[MAX_X][MAX_Y])
 @brief Prints current land, population and sick population.
 @param board gameboard data
 @return -
 */
/*********************************************************************/
void print_current(struct cell board[MAX_X][MAX_Y])
{
    int i, j;

    for(i=MIN; i<MAX_X-1; i++)
    {
        for(j=MIN; j<MAX_Y-1; j++)
        {
            move(12+i, 9+j);

            if(board[i][j].current == 9) //Draw sea = blue
            {
                attron(COLOR_PAIR(9));
                printw(" ");
                attron(COLOR_PAIR(2));
            }
            else if(board[i][j].sick == 1) //Draw sick population
            {
                attron(COLOR_PAIR(10));
                printw("*");
                attron(COLOR_PAIR(2));
            }
            else if((board[i][j].current == 1) && (board[i][j].sick != 1)) //Draw population if not sick
            {
                attron(COLOR_PAIR(1));
                printw("*");
                attron(COLOR_PAIR(2));
            }
            else    //Draw land = green
            {
                attron(COLOR_PAIR(8));
                printw(" ");
                attroff(COLOR_PAIR(2));
            }
        }
    }
}