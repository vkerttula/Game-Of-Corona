#include "header.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------*/
/*!
 @fn void generate_year(struct cell board[MAX_X][MAX_Y])
 @brief Changes future board situation to current board.
 @param board gameboard data
 @return -
 */
/*********************************************************************/
void generate_year(struct cell board[MAX_X][MAX_Y])
{
    int i, j;

    /* chance future to current */
    for(i=MIN; i<MAX_X-1; i++)
    {
        for(j=MIN; j<MAX_Y-1; j++)
        {
            board[i][j].current = board[i][j].future;
        }
    }
}