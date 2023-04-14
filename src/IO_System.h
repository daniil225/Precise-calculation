#pragma once

#include "Base_struct.h"


#include<string>
#include<vector>
#include<fstream>
#include<tuple>
#include <iostream>

class IO_System
{
private:

    // Help information for precice build table
    int SizeX;
    int SizeY;
    std::vector<float> WorkRangeX;
    std::vector<float> WorkRangeY;
    OneMoreStep OneMoreStepX;
    OneMoreStep OneMoreStepY;

    std::string in;   
    std::string out;
    std::ifstream input; // Descriptor file std::string in; 
    std::ofstream output; // Descreptor file std::string out;
    //Data about Range
    std::pair<Data,Data> Range; // Rabge for function
    std::pair<IndexRange,IndexRange> IndexRanges; // first = end range for x;   second = end range for y 


    // Method for build table
    void CalcWorkRange(const char Axis);
    void BuildPageTable();

    void PrintDel();

    bool isOneMoreStep(float Min, float Max, float Step, int N); // is one more step needed
    void Load_data(); // Load data from file and validate that. Uses validate class
    
public:

     
    IO_System(const IO_System&) = delete;  // Ban copy constructor
    IO_System(std::string input, std::string out, int SizeX = 7, int SizeY = 10);
    IO_System& operator=(const IO_System&) = delete;

    void CalcWorkRanhe(const char Axis);
    float TestFunction(float x, float y); // Set the function for which we will build a table
    void BuildTable(); // Build a table for the selected function


    void GetIndex();
    void GetRange();


    void PrintWorkRange()
    {
        std::cout << "[ ";
        for(int i = 0; i < WorkRangeY.size(); i++)
        {
            std::cout << WorkRangeY[i] << ", ";
        }
        std::cout << "]\n";
    }
    

};