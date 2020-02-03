#include "Root_Finder.h"

void Init_Root_Finder(Root_Finder *rf, float x_init, float travel_speed_init, float (*eval_func)(float))
{
    rf->x = x_init;
    rf->eval_func = eval_func;
    rf->y = eval_func(rf->x);
    rf->y_prev = rf->y;
    rf->travel_speed = travel_speed_init;
    rf->is_active = 1;
    rf->id = id_count++;
}

void Display_Root_Finder(Root_Finder *rf)
{
    printf("Root Finder #%i -> x = %.3f, y = %.3f, travel speed = %.3f, is active = %i\r\n",
            rf->id,
            rf->x,
            rf->y,
            rf->travel_speed,
            rf->is_active
            );
}

void Update_Root_Finder_Position(Root_Finder *rf)
{
    if(rf->is_active)
    {
        rf->x += rf->travel_speed;
        rf->y_prev = rf->y;
        rf->y = rf->eval_func(rf->x);
    }
}

void Update_Root_Finder_Speed(Root_Finder *rf)
{
    if(ABS(rf->y) < ABS(rf->y_prev)) return;
    rf->travel_speed *= -1.0;
}

void Evaluate_Root_Finder_Error(Root_Finder *rf, float *error)
{
    if(ABS(rf->y) <= *error) rf->is_active = 0;
}
