#pragma once 

#include <math.h>
#include <tuple>


class Function
{
private:
    float arg_x;
    float arg_y;

public:

    Function(float x, float y);
    
    // всегда срвниваем числа  x и y 
    bool Compare();

    std::pair<float,float> GetArg();
    void SetArg(float x, float y);

    virtual float Add(float x, float y);
    virtual float calc(float arg);
    
    ~Function();
};