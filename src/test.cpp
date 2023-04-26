#include<iostream>
#include<sstream>
#include<string>
#include<stdio.h>

int main()
{
    float x = -1.454459;   //*.***e+*
    float y = 1.454454;
    std::string res_x;
    std::string res_y;
    std::stringstream ss;
    ss.setf(std::ios::scientific);
    ss.setf(std::ios::showpos);
    ss.precision(3);

    ss << x << " " << y;

    ss >> res_x >> res_y;

    std::cout << (res_x == res_y) << std::endl; 


}