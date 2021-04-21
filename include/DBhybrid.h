//
// Created by bartem1us on 20.04.2021.
//
#include "DBscientific_divisions.h"
#include "DBeducational_divisions.h"
#ifndef DZ_DBHYBRID_H
#define DZ_DBHYBRID_H

class Dbhybrid : public DbScientificDivisions,public DbEducationalDivisions
{

};
#endif //DZ_DBHYBRID_H
