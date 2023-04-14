#pragma once

// Include method for adding 2 numbers


// realize method Compare and Adding 
// Operating Range significant 4 fugures
class PrMath
{

    float x;
    float y;

public:
    PrMath(float x, float y);
    PrMath();
    void SetParametrs(float x, float y);

    float Add();
    bool Compare();

    ~PrMath();
};