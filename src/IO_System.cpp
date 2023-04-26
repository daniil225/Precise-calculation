#include "IO_System.h"
#include "DataPreprocessor.h"
#include <iostream>
#include <cmath>
#include <sstream>

/*  Private section */


float IO_System::Add(float Min, float Step, int M)
{
    return 0.0;
}

bool IO_System::Compair(float x, float y)
{
    std::string str_x;
    std::string str_y;
    std::stringstream ss;
    // Settings for print 
    ss.setf(std::ios::scientific);
    ss.setf(std::ios::showpos);
    ss.precision(3);

    // Convert float -> string 
    ss << x << " " << y;
    ss >> str_x >> str_y;
    // Compair
    return str_x == str_y;
}


bool IO_System::isOneMoreStep(float Min, float Max, float Step, int N)
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


void IO_System::CalcWorkRange(const char Axis)
{
    if(Axis == 'X')
    {
        WorkRangeX.clear();
        int index = 0;
        int i = IndexRanges.first.start;
        for(; i < IndexRanges.first.end; i++)
        {
            // Check onto x(i) != x(i+1)
            if(index < SizeX)
            {
                WorkRangeX.push_back(Range.first.Min + Range.first.Step*(i+1));
                index++;
            }
            else
            {
                break;
            }
        }

        if(OneMoreStepX.isNeed && index < SizeX)
        {
            WorkRangeX.push_back(Range.first.Max);
            OneMoreStepX.isCheck = true;
            IndexRanges.first.start = IndexRanges.first.end;
        }
        else
        {
            IndexRanges.first.start = i;
        }
    }
    else if(Axis == 'Y')
    {
        float curY;
        WorkRangeY.clear();
        int index = 0;
        int i = IndexRanges.second.start;
        for(; i < IndexRanges.second.end; i++)
        {
            if(index < SizeY)
            {
                curY = Range.second.Min + Range.second.Step*(i+1);
                if(!Compair(curY, Y_prev)) 
                {
                    WorkRangeY.push_back(curY);
                    index++;
                    Y_prev = curY;
                }
            }
            else
            {
                break;
            }
        }
        
        if(!Compair(curY, Range.second.Max))
        {
            if(OneMoreStepY.isNeed && index < SizeY)
            {
                WorkRangeY.push_back(Range.second.Max);
                IndexRanges.second.start = IndexRanges.second.end;
                OneMoreStepY.isCheck = true;
            }
        }
        else
        {
            std::cout << "roehf";
            OneMoreStepY.isCheck = true;
        }

        IndexRanges.second.start = i;
    }
}

void IO_System::PrintDel()
{
    std::string del = "--------------";
    output << std::endl;

    for(int i = 0; i <= WorkRangeX.size(); i++)
    {
        output << del;
    }

    output << std::endl;

}

void IO_System::BuildPageTable()
{

    // Setings for format output
    output.setf(std::ios::scientific);
    output.setf(std::ios::showpos);
    output.precision(3);
    PrintDel();
    output << "|    y/x     |";
    for(int i = 0; i < WorkRangeX.size(); i++)
    {
        output << "| " << WorkRangeX[i] << " |";
    }

    PrintDel();


    for(int i = 0; i < WorkRangeY.size(); i++)
    {
        output << "| " << WorkRangeY[i] << " |";
        for(int j = 0; j < WorkRangeX.size(); j++)
        {
            float res = TestFunction(WorkRangeX[j], WorkRangeY[i]);
            if(isinff(res)) output << "|  Infinity  |";
            else output << "| " << res << " |";
        }
        PrintDel();
    }

    output << "\n\n\n";

    

}

void IO_System::Load_data()
{
    input >> Range.first.Min >> Range.first.Max >> Range.first.Step >> Range.second.Min >> Range.second.Max >> Range.second.Step;
    // Validate data
    // Calc Index Range for X and Y
    DataPreprocessor(Range, IndexRanges);
}



/* Public section  */
IO_System::IO_System(std::string in, std::string out, int SizeX, int SizeY):SizeX(SizeX), SizeY(SizeY)
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

    // Check size of the built table
    if(SizeX <= 0 || SizeY <= 0)
    {
        std::cout << "Error Size of table\n";
        exit(-1);
    }
    
    Load_data(); // Load data and validate

    OneMoreStepX.isNeed = isOneMoreStep(Range.first.Min, Range.first.Max, Range.first.Step, IndexRanges.first.end);
    OneMoreStepY.isNeed = isOneMoreStep(Range.second.Min, Range.second.Max, Range.second.Step, IndexRanges.second.end);
    OneMoreStepX.isCheck = false;
    OneMoreStepY.isCheck = false;

    // set value for build table
    X_prev = Range.first.Min;
    Y_prev = Range.second.Min;
}

float IO_System::TestFunction(float x, float y)
{   
    //return tanf((x+y)/float(180.0)*M_PI);
    return 1/sinf((x+y)/float(180.0)*M_PI);
    //return 1/cosf((x+y)/float(180.0)*M_PI);
}


 void IO_System::BuildTable()
 {
 
    while(IndexRanges.second.start != IndexRanges.second.end)
    {
        CalcWorkRange('Y');
        IndexRanges.first.start = -1;
        OneMoreStepX.isCheck = false;
        while(IndexRanges.first.start != IndexRanges.first.end)
        {
            CalcWorkRange('X');
            BuildPageTable();
        }

        if(OneMoreStepX.isNeed && !OneMoreStepX.isCheck)
        {
            WorkRangeX.clear();
            WorkRangeX.push_back(Range.first.Max);
            BuildPageTable();
        }
    }

    if(OneMoreStepY.isNeed && !OneMoreStepY.isCheck)
    {
        WorkRangeY.clear();
        WorkRangeY.push_back(Range.second.Max);
        
        IndexRanges.first.start = -1;
        OneMoreStepX.isCheck = false;
        while(IndexRanges.first.start != IndexRanges.first.end)
        {
            CalcWorkRange('X');
            BuildPageTable();
        }

        if(OneMoreStepX.isNeed && !OneMoreStepX.isCheck)
        {
            WorkRangeX.clear();
            WorkRangeX.push_back(Range.first.Max);
            BuildPageTable();
        }
    }



 }


void IO_System::GetIndex()
{
    std::cout << "X = [ " << IndexRanges.first.start << "; " << IndexRanges.first.end << "]" << std::endl;
    std::cout << "Y = [ " << IndexRanges.second.start << "; " << IndexRanges.second.end << "]" << std::endl; 
}
void IO_System::GetRange()
{
    std::cout << "MinX = " << Range.first.Min << "  MaxX = " << Range.first.Max << "  StepX = " << Range.first.Step << std::endl;
    std::cout << "MinY = " << Range.second.Min << "  MaxY = " << Range.second.Max << "  StepY = " << Range.second.Step << std::endl;
}