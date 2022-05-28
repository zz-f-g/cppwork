#include <conio.h>
#include "cmd_console_tools.h"
#include <iostream>
using namespace std;
#define CLR_CYLINDERS COLOR_HYELLOW
#define y_pedestal 15
#define height_cylinder 12
#define width_half_pedestal 11
#define width_interval 32

/* draw or erase a plate
- input:
    int x, y: coordinates
    int act: 1 for draw, 0 for erase
    int size: width = 2 * size + 1, color = size
    int state: 1 for plate on the cylinder, 0 for not, 0 by default
*/
void draw_plate(int x, int y, int act, int size, int state = 0)
{
    if (act)
    {
        cct_showch(x - size, y, ' ', size, 7, 2 * size + 1);
        cct_setcolor();
    }
    else
    {
        if (state)
        {
            cct_showch(x - size, y, ' ', 0, 7, size);
            cct_showch(x, y, ' ', CLR_CYLINDERS, 7, 1);
            cct_showch(x + 1, y, ' ', 0, 7, size);
        }
        else
            cct_showch(x - size, y, ' ', 0, 7, 2 * size + 1);
        cct_setcolor();
    }
}

/* functions for menu7 & menu8
move_plate_bystep
move_plate
*/

void move_plate_bystep(int x, int y, char direction, int size, int state = 0)
{
    draw_plate(x, y, 0, size, state);
    switch (direction)
    {
        case 'u':
            draw_plate(x, --y, 1, size, state);
            break;
        case 'd':
            draw_plate(x, ++y, 1, size, state);
            break;
        case 'l':
            draw_plate(--x, y, 1, size, state);
            break;
        case 'r':
            draw_plate(++x, y, 1, size, state);
            break;
    }
}

int main()
{
    draw_plate(15, 4, 1, 5);
    getchar();
    move_plate_bystep(15, 4, 'l', 5);
    getchar();
    return 0;
}