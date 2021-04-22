//
// Created by bartem1us on 20.04.2021.
//
#include "DBscientific_divisions.h"
#include "DBeducational_divisions.h"
#ifndef DZ_DBHYBRID_H
#define DZ_DBHYBRID_H

class Dbhybrid : public DbScientificDivisions,public DbEducationalDivisions : public Divisions2
{
    void SortName(std::string &name_);

    void SelectionStuff(std::string &name_, size_t number);

    void SelectionIncome(std::string &name_,size_t number);
};
#endif //DZ_DBHYBRID_H
