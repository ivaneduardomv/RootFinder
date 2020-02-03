#include <stdio.h>
#include <stdlib.h>

#include "Root_Finder.h"

#define ARRAY_LENGTH 16

float error = 0.1;

float my_func(float x)
{
    //return x*x - 9.0;
    //return (x*x*x*x*x) - 3.0*(x*x) + 1.0;
    return (x*x*x*x) -5.0*(x*x) + 3.0;
}

int main()
{
    Root_Finder rf_arr[ARRAY_LENGTH];

    Init_Root_Finder((rf_arr+0), 0.0, -0.1, &my_func);
    Init_Root_Finder((rf_arr+1), 0.0, 0.1, &my_func);
    Init_Root_Finder((rf_arr+2), -1.0, -0.1, &my_func);
    Init_Root_Finder((rf_arr+3), 1.0, 0.1, &my_func);

    Init_Root_Finder((rf_arr+4), -2.0, -0.1, &my_func);
    Init_Root_Finder((rf_arr+5), 2.0, 0.1, &my_func);
    Init_Root_Finder((rf_arr+6), -3.0, -0.1, &my_func);
    Init_Root_Finder((rf_arr+7), 3.0, 0.1, &my_func);

    Init_Root_Finder((rf_arr+8), -4.0, -0.1, &my_func);
    Init_Root_Finder((rf_arr+9), 4.0, 0.1, &my_func);
    Init_Root_Finder((rf_arr+10), -5.0, -0.1, &my_func);
    Init_Root_Finder((rf_arr+11), 5.0, 0.1, &my_func);

    Init_Root_Finder((rf_arr+12), -6.0, -0.1, &my_func);
    Init_Root_Finder((rf_arr+13), 6.0, 0.1, &my_func);
    Init_Root_Finder((rf_arr+14), -7.0, -0.1, &my_func);
    Init_Root_Finder((rf_arr+15), 7.0, 0.1, &my_func);

    for(int i = 0; i < ARRAY_LENGTH; ++i) Display_Root_Finder((rf_arr+i));
    puts("");

    for(int k = 0; k < 10; ++k)
    {
        for(int i = 0; i < ARRAY_LENGTH; ++i) Update_Root_Finder_Position((rf_arr+i));
        for(int i = 0; i < ARRAY_LENGTH; ++i) Evaluate_Root_Finder_Error((rf_arr+i), &error);
        for(int i = 0; i < ARRAY_LENGTH; ++i) Update_Root_Finder_Speed((rf_arr+i));

        for(int i = 0; i < ARRAY_LENGTH; ++i) Display_Root_Finder((rf_arr+i));
        puts("");
    }

    //for(int i = 0; i < ARRAY_LENGTH; ++i) Display_Root_Finder((rf_arr+i));
    //puts("");
    return 0;
}
