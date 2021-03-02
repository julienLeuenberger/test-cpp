#include "square.h"

double Square::get_side(){
    return side_length;
}
double Square::get_area(){
    return area;
}
void Square::set_size(double size)
{
    this->side_length=size;
    this->area=size*size;
}
