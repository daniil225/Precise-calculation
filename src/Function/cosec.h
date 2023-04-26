#pragma once 

#include "function.h"

// In this file realised method for precice calc trigonometric function
// cosec(x+y) = 1/sin(x+y)

class cosec : public Function
{

public:
    cosec(float x, float y);
    

    float calc();
    ~cosec();
};