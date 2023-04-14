#include "DataPreprocessor.h"

#include <iostream>
#include <cmath>


DataPreprocessor::DataPreprocessor(std::pair<Data, Data> &data, std::pair<IndexRange, IndexRange> &Index) 
{  

    if(Validate(data))
    {
        Preparetion_data(data, Index);
    }
    else
    {
        std::cout << "Error Incorrect Data";
        exit(-1);
    }

}


bool DataPreprocessor::Validate(std::pair<Data, Data> &data)
{
    if(data.first.Min > data.first.Max) return false;
    if(data.second.Min > data.second.Max) return false;
    if(data.first.Step <= 0 || data.second.Step <= 0) return false;

    return true;
}


void DataPreprocessor::Preparetion_data(std::pair<Data, Data> &data, std::pair<IndexRange, IndexRange> &Index)
{

    Index.first.start = -1;
    Index.second.start = -1;
    Index.first.end = int(fabs(data.first.Max - data.first.Min)/data.first.Step);
    Index.second.end = int(fabs(data.second.Max - data.second.Min)/data.second.Step);

    if(Index.first.end > MaxRange || Index.second.end > MaxRange || Index.first.end*Index.second.end > MaxRange)
    {
        throw "Big range Overflow!";
        exit(-1);
    }
}

DataPreprocessor::~DataPreprocessor() {  }