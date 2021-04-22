// Copyright 2020 bartem1us <filkovghjynj@mail.ru>
#include <scientific_divisions.h>
#include "Divisions.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <filesystem>
#ifndef RK1_TIMP_DBSCIENTIFIC_DIVISIONS_H
#define RK1_TIMP_DBSCIENTIFIC_DIVISIONS_H

class DbScientificDivisions:public Divisions2{
private:
    std::map<std::string,std::vector<ScientificDivisions>> databaseSD;
public:
    void createDB(const std::string &name_, std::map<std::string,std::vector<ScientificDivisions>> &data);

    void printDB(const std::string &name_);

    void deleteTarget(std::string &name_, std::string &name_Divisons);

    void deleteDB(const std::string &name_);

    void openDB(const std::string &name_);

    void renameBD(const std::string old_name, const std::string &new_name);

    void insertDB(ScientificDivisions &division_, const std::string &name_);

    void InsertCourse(const std::string &Field_change, const std::string &new_field,
                 std::string &name_, std::string &name_Division);

    void
    insertField(const std::string &field, const std::string &field_name, std::string &name_, std::string &name_Division);

    void print_target(std::string &name_, std::string &name_Divisons);

    void SortStuff(std::string &name_);

    int Calculationfunction(std::string &name_, std::string &name_DB);

    std::string &FindFIO(std::string &name_, std::string &name_DB);

    void SortName(std::string &name_);

    void SelectionStuff(std::string &name_, size_t number);

    void SelectionIncome(std::string &name_,size_t number);
};

#endif //RK1_TIMP_DBSCIENTIFIC_DIVISIONS_H
