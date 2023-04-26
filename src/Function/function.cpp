#include "function.h"


Function::Function(float x, float y): arg_x(x), arg_y(y) {   }


bool Function::Compare()
{
    
}


std::pair<float,float> Function::GetArg()
{
    return std::make_pair(arg_x, arg_y);
}

void Function::SetArg(float x, float y)
{
    arg_x = x;
    arg_y = y;
}