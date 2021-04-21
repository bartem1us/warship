// Copyright 2020 bartem1us <filkovghjynj@mail.ru>
#include <iostream>
#include <string>
#ifndef DZ_DIVISIONS_H
#define DZ_DIVISIONS_H

class Divisions2 {
public:
    virtual void SortName(std::string &name_) = 0;
    virtual void SortStuff(std::string &name_)=0;
    virtual void SelectionStuff(std::string &name_, size_t number)=0;
    virtual void SelectionIncome(std::string &name_,size_t number)=0;
};

#endif //DZ_DIVISIONS_H
