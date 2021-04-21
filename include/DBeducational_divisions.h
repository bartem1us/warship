// Copyright 2020 bartem1us <filkovghjynj@mail.ru>
#include <educational_divisions.h>
#include <vector>
#include <algorithm>
#include"Divisions.h"
#ifndef RK1_TIMP_DBEDUCATIONAL_DIVISIONS_H
#define RK1_TIMP_DBEDUCATIONAL_DIVISIONS_H

class DbEducationalDivisions:public Divisions2{
private:
    std::vector<EducationalDivisions> database;
public:
    void createDB(const std::string &name_, std::vector<EducationalDivisions> &data);

    void printDB(const std::string &name_);

    void deleteTarget(std::string &name_, std::string &name_Divisons);

    void deleteDB(const std::string &name_);

    void openDB(const std::string &name_);

    void renameBD(const std::string old_name, const std::string &new_name);

    void insertDB(EducationalDivisions &division_, const std::string &name_);

    void InsertCourse(const std::string &number_course, const std::string &field, const std::string &field_name,
                      std::string &name_, std::string &name_Division);

    void
    insertDB1(const std::string &field, const std::string &field_name, std::string &name_, std::string &name_Division);

    void print_target(std::string &name_, std::string &name_Divisons);



    int Calculationfunction(std::string &name_, std::string &name_DB);

    std::string &FindFIO(std::string &name_, std::string &name_DB);

    void SortName(std::string &name_);
    void SortStuff(std::string &name_);

    void SelectionStuff(std::string &name_, size_t number);

    void SelectionIncome(std::string &name_,size_t number);

};

#endif //RK1_TIMP_DBEDUCATIONAL_DIVISIONS_H
