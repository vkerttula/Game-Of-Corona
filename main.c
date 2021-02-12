#include "header.h"

/*********************************************************************
*    MAIN PROGRAM                                                    */
/*!    \mainpage Game Of Life by VK 
        \section Introduction
        \date 04/2020
        \bug Testing bug tag.
        \warning Testing warning tag.
        \copyright GNU Public License.
*/
/**********************************************************************/
int main(void)
{
    int i, j, speed = 500000, years;
    long int end_of_years = 5;
    srand(time(NULL));

    struct cell board[MAX_X][MAX_Y] = {0, 0};

        initscr();

        start_color();
        init_pair(1, COLOR_BLACK, COLOR_GREEN);
        init_pair(2, COLOR_BLACK, COLOR_WHITE);
        init_pair(3, COLOR_WHITE, COLOR_CYAN);
        init_pair(4, COLOR_WHITE, COLOR_RED);
        init_pair(5, COLOR_RED, COLOR_WHITE);
        init_pair(6, COLOR_CYAN, COLOR_WHITE);
        init_pair(7, COLOR_BLUE, COLOR_WHITE);
        init_pair(8, COLOR_GREEN, COLOR_GREEN);
        init_pair(9, COLOR_BLUE, COLOR_BLUE);
        init_pair(10, COLOR_RED, COLOR_GREEN);
        bkgd(COLOR_PAIR(2));

        load_start_situation(board);

        banner();

        /* mainmenu */
        attron(COLOR_PAIR(2));
        move(12, 10);
        printw("Speed in microseconds: "); 
        move(12, 115);
        printw("Years: ");

        print_current(board);

        move(12, 33);
        scanw("%d", &speed);

        move(12, 122);
        scanw("%d", &end_of_years); 
        end_of_years++;     /* add +1, because first year are already printed */

        refresh();

        curs_set(0);

        enter_to_start();

        for(years=0; years < end_of_years; years++)
        {
            print_current(board); /* prints current situation */

            count_neighbors(board); /* calculate current neighbors to future board */

            generate_year(board); /* chance future board to current board */

            refresh();
            usleep(speed);
        }
        
        getch();
        endwin();

    return 0;

}
/* end of main */

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------*/
/*!
 @fn void enter_to_start(void)
 @brief User have to press some key to start a game.
 @param -
 @return -
*/
/*********************************************************************/
void enter_to_start(void)
{
    move(11, 62);
    attron(A_BLINK);
    attron(COLOR_PAIR(4));
    addstr("Press Enter to start!");
    attron(COLOR_PAIR(2));
    attroff(A_BOLD);
    attrset(A_NORMAL);
    scanw("");
    move(11, 62);
    clrtoeol(); /* deletes one line of text */
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------*/
/*!
 @fn void banner(void)
 @brief Prints banner.
 @param -
 @return -
*/
/*********************************************************************/
void banner(void)
{
    attron(COLOR_PAIR(5));
    move(1, 48);
    addstr("   ********     ****        ***   ***    *********\n");
    move(2, 48);
    addstr(" **            **   **     ** ** ** **   ***       \n");
    move(3, 48);
    addstr("***      ***  *********   **    *   **  ********  \n");
    move(4, 48);
    addstr(" ***      ** **       ** **         **  **         \n");
    move(5, 48);
    addstr("   ******* * **       ** **         ** *********  \n");
    attron(COLOR_PAIR(6));
    move(6, 48);
    addstr("                        OF                           \n");
    attron(COLOR_PAIR(7));
    move(8, 48);
    addstr("                   C O R O N A                       \n");
    attron(COLOR_PAIR(2));
}