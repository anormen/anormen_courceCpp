#ifndef PART_H
#define PART_H

#include<iostream>

#include <string>

enum class enum_part{ OIL, TYRES, LAMP };


class part {

private:
    std::string partName;
    const std::string name_part[4] = { "Oil", "Tyres", "Lamp", "  xx "} ;

public:
    void printPartName( enum_part part );
};



#endif PART_H