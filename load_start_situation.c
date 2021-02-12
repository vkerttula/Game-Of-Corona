#include "header.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------*/
/*!
 @fn void load_start_situation(struct cell board[MAX_X][MAX_Y])
 @brief Read start_situation.txt file and makes board based on that file. Also randomize sick population to board.
 @param board gamedata
 @return -
 */
/*********************************************************************/
void load_start_situation(struct cell board[MAX_X][MAX_Y])
{
    int x, y;
    int numberArray[2550];

    FILE *filePointer;
    filePointer = fopen("start_situation.txt", "r");

        for(x=MIN; x<MAX_X-1; x++)
        {
            for(y=MIN; y<MAX_Y-1; y++)
            {
                fscanf(filePointer, "%1d", &board[x][y].current);

                if(board[x][y].current != 9) // if you are at land, you might get sick by 3% chance
                {
                    if(rand()%100 < 3) //randomize sickness for gametable 
                        {
                        board[x][y].sick = 1;
                        }
                }
            }
        }

    fclose(filePointer);
}