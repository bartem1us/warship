#include "scientific_divisions.h"

ScientificDivisions::ScientificDivisions() = default;

ScientificDivisions::~ScientificDivisions() = default;

ScientificDivisions::ScientificDivisions(const std::string &name_, const std::string &manager_,
                                         const size_t graduate_students_,
                                         const size_t staff_, std::vector<project> &project_) : name(name_),
                                                                                                         manager(manager_),
                                                                                                         graduate_students(
                                                                                                                 graduate_students_),
                                                                                                         staff(staff_),
                                                                                                         projectSD(project_) {}


void ScientificDivisions::SetName(const std::string &name_) {
    name = name_;
}

void ScientificDivisions::SetManager(const std::string &manager_) {
    manager = manager_;
}

void ScientificDivisions::SetGraduate_students(const size_t graduate_students_) {
    graduate_students = graduate_students_;
}

void ScientificDivisions::SetStaff(const size_t staff_) {
    staff = staff_;
}

void ScientificDivisions::SetProject(const std::vector<struct project> &project_)
{
    projectSD=project_;
}

std::string& ScientificDivisions::GetName() {
    return name;
}

std::string& ScientificDivisions::GetManager() {
    return manager;
}

size_t ScientificDivisions::GetGraduate_students() {
    return graduate_students;

}
std::vector<struct project> ScientificDivisions::GetProject()
{
    return projectSD;
}

size_t ScientificDivisions::GetStaff() {
    return staff;
}


