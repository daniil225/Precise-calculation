#include "cosec.h"

#include <iostream>

cosec::cosec(float x, float y): Function(x, y) {}

float cosec::calc()
{
    float arg = Add();

    std::cout << arg << std::endl;
}