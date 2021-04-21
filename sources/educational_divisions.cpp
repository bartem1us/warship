// Copyright 2020 bartem1us <filkovghjynj@mail.ru>
#include "educational_divisions.h"

EducationalDivisions::EducationalDivisions() = default;

EducationalDivisions::~EducationalDivisions() = default;

EducationalDivisions::EducationalDivisions(const std::string &name_, const std::string &manager_,
                                           const size_t graduate_students_, const size_t staff_,
                                           std::map<size_t, course_info> &course_) : name(name_),
                                                                                     manager(manager_),
                                                                                     graduate_students(graduate_students_),
                                                                                     staff(staff_), course(course_) {}

void EducationalDivisions::SetName(const std::string &name_) {
    name = name_;
}

void EducationalDivisions::SetManager(const std::string &manager_) {
    manager = manager_;
}

void EducationalDivisions::SetGraduate_students(const size_t graduate_students_) {
    graduate_students = graduate_students_;
}

void EducationalDivisions::SetStaff(const size_t staff_) {
    staff = staff_;
}

void EducationalDivisions::SetCourse(std::map<size_t, course_info> &course_) {
    course = course_;
}
void EducationalDivisions::SetCourseTutionFee(size_t tuiton_fee_,size_t number_course) {
    course[number_course-1].tuition_fee=tuiton_fee_;
}
void EducationalDivisions::SetCourseStudentsNumber(size_t stude,size_t number_course) {
    course[number_course-1].students=stude;
}

std::string& EducationalDivisions::GetName() {
    return name;
}

std::string& EducationalDivisions::GetManager() {
    return manager;
}

size_t EducationalDivisions::GetGraduate_students() {
    return graduate_students;

}


size_t EducationalDivisions::GetStaff() {
    return staff;
}
std::map<size_t, course_info>& EducationalDivisions::GetCourse()
{
    return course;
}






