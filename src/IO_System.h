#pragma once

#include "Base_struct.h"


#include<string>
#include<vector>
#include<fstream>
#include<tuple>

class IO_System
{
private:
    std::string in;   
    std::string out;
    std::ifstream input; // Descriptor file std::string in; 
    std::ofstream output; // Descreptor file std::string out;
    //Data about Range
    std::pair<Data,Data> Range; // Rabge for function
    std::pair<int,int> Index; // first = end range for x;   second = end range for y 

    bool OneMoreStep(float Min, float Max, float Step, int N); // is one more step needed
    void Load_data(); // Load data from file and validate that. Uses validate class
    
public:

    IO_System(const IO_System&) = delete;  // Ban copy constructor
    IO_System(std::string input, std::string out);
    IO_System& operator=(const IO_System&) = delete;


    void SetFunction(); // Set the function for which we will build a table
    void BuildTable(); // Build a table for the selected function


    void GetIndex();
    void GetRange();
    

};