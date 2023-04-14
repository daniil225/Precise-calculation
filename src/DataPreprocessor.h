#pragma once

#include "Base_struct.h"
#include <tuple>

class DataPreprocessor
{

    private:
        bool Validate(std::pair<Data, Data> &data);
        void Preparetion_data(std::pair<Data, Data> &data, std::pair<int, int> &Index);

public:
    DataPreprocessor(const DataPreprocessor&) = delete;
    DataPreprocessor(std::pair<Data, Data> &data, std::pair<int, int> &Index);

    DataPreprocessor& operator=(const DataPreprocessor&) = delete;

    ~DataPreprocessor();
    
};