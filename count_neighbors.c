#include "header.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------*/
/*!
 @fn void count_neighbors(struct cell board[MAX_X][MAX_Y])
 @brief Counts neighbors and sick population from board and make new situation to future board.
 @param board gameboard data
 @return -
 */
/*********************************************************************/
void count_neighbors(struct cell board[MAX_X][MAX_Y])
{
    int i, j, x, y, neighbors = 0, sick_neighbors = 0;

    /* checks every cell one by one */
    for(x=MIN; x<MAX_X-1; x++)
    {
        for(y=MIN; y<MAX_Y-1; y++)
        {
            /* currently cell neighbors */
            for(i=-1; i<=1; i++)
            {
                for(j=-1; j<=1; j++)
                {
                    if(board[i][j].current >= 0 || board[i][j].current <= 9) //check healty neighbors
                    {
                        neighbors += board[x+i][y+j].current;
                    }                 
                    else if(board[i][j].sick == 1) //check sick neighbors
                    {
                        sick_neighbors += board[x+i][y+j].sick;
                    }       
                }

            } 
         
        /* decrease current cell valua from total value */
        neighbors -= board[x][y].current;


        /* Healthy population logic */
        if      ((board[x][y].current == 1) && (neighbors < 2)) board[x][y].future = 0;
        else if ((board[x][y].current == 1) && (neighbors > 3)) board[x][y].future = 0;
        else if ((board[x][y].current == 0) && (neighbors == 3)) board[x][y].future = 1;
        else    board[x][y].future = board[x][y].current;

        /* Sick population logic */
        if ((board[x][y].future == 1) && (rand()%100 < 1)) //1% to get sick without contact
            board[x][y].sick = 1;

        else if ((board[x][y].current == 1) && (sick_neighbors > 0)) //getting sick after being close of sick population
            board[x][y].sick = 1;

        else if (board[x][y].sick == 1) 
        {
            if(rand()%100 < 3)      //3% chance to die
                board[x][y].sick = 0;
            if(rand()%100 < 9)      //9% chance to survive 
                board[x][y].future = 1;
        }

        neighbors = 0;
        sick_neighbors = 0;
        }
    }
}