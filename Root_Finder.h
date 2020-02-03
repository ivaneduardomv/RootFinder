#ifndef ROOT_FINDER_H
#define ROOT_FINDER_H

#include <stdio.h>

#define ABS(x) (x>0?x:-x)

static int id_count = 0;
typedef struct Root_finder_tag
{
    float x;
    float y;
    float y_prev;
    float travel_speed;
    float (*eval_func)(float);
    int is_active; // 0 = false, 1 = true
    int id;
}Root_Finder;

void Init_Root_Finder(Root_Finder *rf, float x_init, float travel_speed_init, float (*eval_func)(float));
void Display_Root_Finder(Root_Finder *rf);
void Update_Root_Finder_Position(Root_Finder *rf);
void Update_Root_Finder_Speed(Root_Finder *rf);
void Evaluate_Root_Finder_Error(Root_Finder *rf, float *error);

#endif // ROOT_FINDER_H
