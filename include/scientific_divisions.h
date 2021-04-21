// Copyright 2020 bartem1us <filkovghjynj@mail.ru>
#include <string>
#include <iostream>
#include<map>
#include<vector>
#ifndef RK1_TIMP_SCIENTIFIC_DIVISIONS_H
#define RK1_TIMP_SCIENTIFIC_DIVISIONS_H
struct project
{
    std::string name;
    size_t cost;
};
class ScientificDivisions {
    std::string name;
    std::string manager;
    size_t graduate_students;
    size_t staff;
    std::vector<struct project> projectSD;
public:
    ScientificDivisions();

    ~ScientificDivisions();

    ScientificDivisions(const std::string &name_, const std::string &manager_,
                                             const size_t graduate_students_,
                                             const size_t staff_, std::vector<project> &project_);
    std::string &GetName();

    std::string& GetManager();

    size_t GetGraduate_students();

    size_t GetStaff();

    std::vector<struct project> GetProject();

    void SetName(const std::string &name_);

    void SetManager(const std::string &manager_);

    void SetGraduate_students(const size_t graduate_students_);

    void SetStaff(const size_t staff_);

    void SetProject(const std::vector<struct project> &project_);


};

#endif //RK1_TIMP_SCIENTIFIC_DIVISIONS_H
