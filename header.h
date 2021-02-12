/***************************************************************************
 *   Copyright (C) 2020 by Valtteri Kerttula                               *
 *   e1801116@edu.vamk.fi                                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************

 1.  NAME
     Game Of Life 

 2. Rules:
    Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    Any live cell with two or three live neighbours lives on to the next generation.
    Any live cell with more than three live neighbours dies, as if by overpopulation.
    Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

 3.  VERSIONS
       Original:
         1.0.0 / Kerttula

       Version history: 1.0.0 added comments

**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include <curses.h>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */

/* Global constants */
#define MAX_X 52 /**< Vertical gameboard size. */
#define MAX_Y 123 /**< Horizontally gameboard size. */
#define MIN 1 /**< Min value for loops. */

/* Global variables */

/* Global structures */
struct cell 
{
    int current; /**< Current board data. This date are used when printing current situation to screen. */
    int future; /**< Future board data. This data are used for calculation next year situation. */
    int sick; /**< Sick population data. This date are used for calculate future sick population. */
};

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
void print_current(struct cell board[MAX_X][MAX_Y]);
void count_neighbors(struct cell board[MAX_X][MAX_Y]);
void generate_year(struct cell board[MAX_X][MAX_Y]);
void enter_to_start(void);
void banner(void);
void load_start_situation(struct cell board[MAX_X][MAX_Y]);
