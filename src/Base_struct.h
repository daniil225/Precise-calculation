#pragma once 


/* format in file:  startX endX stepX startX endX stepX */
/* Base struct  */
struct Data
{
    float Min;
    float Max;
    float Step;
};

struct IndexRange
{
    int start;
    int end;
};

struct OneMoreStep
{
    bool isNeed;
    bool isCheck;
};

// Max size of range
const int MaxRange = 2.25e+8;