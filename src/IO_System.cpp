#include "IO_System.h"
#include "DataPreprocessor.h"
#include <iostream>
#include <cmath>

/*  Private section */



bool IO_System::OneMoreStep(float Min, float Max, float Step, int N)
{
    bool res = true;
    float f = Min + N*Step;
    float Tmp = fabs(fabs(f) - fabs(Max));
    float isStep = (fabs(Max)-fabs(Tmp))/fabs(Max);

    if(std::isnan(isStep))
    {
        res = false;
    }
    else
    {
        if(isStep <= 1 && isStep >= 0.999990)
        {
            res = false;
        }
    }

    return res;
}



void IO_System::Load_data()
{
    input >> Range.first.Min >> Range.first.Max >> Range.first.Step >> Range.second.Min >> Range.second.Max >> Range.second.Step;
    // Validate data
    // Calc Index Range for X and Y
    DataPreprocessor(Range, Index);
}



/* Public section  */
IO_System::IO_System(std::string in, std::string out)
{
    output.open(out); // Open the file for print Table
    input.open(in); // Open for Load Data

    if(!input.is_open())
    {
        std::cout << "Error open file: " << in << std::endl;
        std::cout << "Programe Terminate." << std::endl;
        input.close();
        output.close();
    }

    
    Load_data(); // Load data and validate
}


void IO_System::GetIndex()
{
    std::cout << "X = [ " << 0 << "; " << Index.first << "]" << std::endl;
    std::cout << "Y = [ " << 0 << "; " << Index.second << "]" << std::endl; 
}
void IO_System::GetRange()
{
    std::cout << "MinX = " << Range.first.Min << "  MaxX = " << Range.first.Max << "  StepX = " << Range.first.Step << std::endl;
    std::cout << "MinY = " << Range.second.Min << "  MaxY = " << Range.second.Max << "  StepY = " << Range.second.Step << std::endl;
}