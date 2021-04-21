// Copyright 2020 bartem1us <filkovghjynj@mail.ru>
#include <iostream>
#include <string>
#include <filesystem>
#include <map>

#ifndef RK1_COUNT_H
#define RK1_COUNT_H
struct course_info {
    size_t students;
    double tuition_fee;
};

class EducationalDivisions {
    std::string name;
    std::string manager;
    size_t graduate_students;
    size_t staff;
    std::map<size_t, course_info> course;

public:
    EducationalDivisions();

    EducationalDivisions(const std::string &name_, const std::string &manager_,
                         const size_t graduate_students_, const size_t staff_,std::map<size_t,course_info> &course_);

    ~EducationalDivisions();

    void SetName(const std::string &name_);

    void SetManager(const std::string &manager_);

    void SetGraduate_students(const size_t graduate_students_);

    void SetStaff(const size_t staff_);

    void SetCourse(std::map<size_t, course_info> &course_);

    void SetCourseStudentsNumber(size_t stude,size_t number_course);
void SetCourseTutionFee(size_t stude,size_t number_course);
    std::string &GetName();

    std::string& GetManager();

    size_t GetGraduate_students();

    size_t GetStaff();

    std::map<size_t, course_info> & GetCourse();


};

#endif //RK1_COUNT_H
