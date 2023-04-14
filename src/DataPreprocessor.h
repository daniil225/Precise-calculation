#pragma once

#include "Base_struct.h"
#include <tuple>

class DataPreprocessor
{

    private:
        bool Validate(std::pair<Data, Data> &data);
        void Preparetion_data(std::pair<Data, Data> &data,std::pair<IndexRange, IndexRange> &Index);

public:
    DataPreprocessor(const DataPreprocessor&) = delete;
    DataPreprocessor(std::pair<Data, Data> &data, std::pair<IndexRange, IndexRange> &Index);

    DataPreprocessor& operator=(const DataPreprocessor&) = delete;

    ~DataPreprocessor();
    
};