#include "educational_divisions.h"
#include "Divisions.h"
#include "DBeducational_divisions.h"
#include "Intruction.h"
#include <map>
#include "dop_function.h"

int main() {
    help();
    std::string command;
    //DBHybrid dbHybrid;
    DbEducationalDivisions dbEducationalDivisions;
    DbScientificDivisions dbScientificDivisions;
    std::string name_directory;
    std::string name_;
    std::string manager_;
    size_t graduate_students_;
    size_t staff_;
    size_t students_;
    std::string name_project;
    size_t cost_project;
    double tuition_fee_;


    while (command != "quit") {
        std::cout << "Enter what command you want to do" << std::endl;
        std::cout << "You can write only:" << std::endl;
        std::cout << "Education Division or Scientific Division or Hybrid Division" << std::endl;
        std::getline(std::cin, command, '\n');
        if (command == "Education Division") {
            while (command != "quit") {
                std::cout << "Enter what command you want to do" << std::endl;
                std::getline(std::cin, command, '\n');
                if (command == "CreateDB") {
                    std::cout << "Enter name of your directory for Education Division" << std::endl;
                    std::getline(std::cin, name_directory, '\n');
                    std::cout << "Enter name of your Education Division" << std::endl;
                    std::getline(std::cin, name_, '\n');
                    std::cout << "Enter manager name of your Education Division" << std::endl;
                    std::getline(std::cin, manager_, '\n');
                    std::cout << "Enter number of graduated students your Education Division" << std::endl;
                    std::cin >> graduate_students_;
                    std::cout << "Enter number of staff your Education Division" << std::endl;
                    std::cin >> staff_;
                    std::cout << "Enter number of students your Education Division for 1 course" << std::endl;
                    std::cin >> students_;
                    std::cout << "Enter tuition fee for 1 student for 1 course :" << std::endl;
                    std::cin >> tuition_fee_;
                    EducationalDivisions new_education_divisions;
                    new_education_divisions.SetName(name_);
                    new_education_divisions.SetManager(manager_);
                    new_education_divisions.SetStaff(staff_);
                    new_education_divisions.SetGraduate_students(graduate_students_);
                    std::map<size_t, course_info> course_new;
                    course_info courseInfo;
                    courseInfo.tuition_fee = tuition_fee_;
                    courseInfo.students = students_;
                    course_new[0] = courseInfo;
                    std::cout << "Enter number of students your Education Division for 2 course" << std::endl;
                    std::cin >> students_;
                    std::cout << "Enter tuition fee for 1 student for 2 course :" << std::endl;
                    std::cin >> tuition_fee_;
                    courseInfo.tuition_fee = tuition_fee_;
                    courseInfo.students = students_;
                    course_new[1] = courseInfo;
                    std::cout << "Enter number of students your Education Division for 3 course" << std::endl;
                    std::cin >> students_;
                    std::cout << "Enter tuition fee for 1 student for 3 course :" << std::endl;
                    std::cin >> tuition_fee_;
                    courseInfo.tuition_fee = tuition_fee_;
                    courseInfo.students = students_;
                    course_new[2] = courseInfo;
                    std::cout << "Enter number of students your Education Division for 4 course" << std::endl;
                    std::cin >> students_;
                    std::cout << "Enter tuition fee for 1 student for 4 course :" << std::endl;
                    std::cin >> tuition_fee_;
                    courseInfo.tuition_fee = tuition_fee_;
                    courseInfo.students = students_;
                    course_new[3] = courseInfo;
                    std::cout << "Enter number of students your Education Division for 5 course" << std::endl;
                    std::cin >> students_;
                    std::cout << "Enter tuition fee for 1 student for 5 course :" << std::endl;
                    std::cin >> tuition_fee_;
                    courseInfo.tuition_fee = tuition_fee_;
                    courseInfo.students = students_;
                    course_new[4] = courseInfo;
                    std::cout << "Enter number of students your Education Division for 6 course" << std::endl;
                    std::cin >> students_;
                    std::cout << "Enter tuition fee for 1 student for 6 course :" << std::endl;
                    std::cin >> tuition_fee_;
                    courseInfo.tuition_fee = tuition_fee_;
                    courseInfo.students = students_;
                    course_new[5] = courseInfo;
                    new_education_divisions.SetCourse(course_new);
                    std::vector<EducationalDivisions> vecED;
                    std::map<std::string, std::vector<EducationalDivisions>> mapED;
                    vecED.push_back(new_education_divisions);
                    mapED[name_directory] = vecED;
                    dbEducationalDivisions.createDB(name_directory, mapED);
                } else if (command == "printDB") {
                    std::cout << "Enter name of directory which you want to print" << std::endl;
                    std::cin >> name_directory;
                    dbEducationalDivisions.printDB(name_directory);

                } else if (command == "print target") {
                    std::cout << "Enter name of directory you want to print " << std::endl;
                    std::cin >> name_directory;
                    std::cout << "Enter name of education division you want to print" << std::endl;
                    std::cin >> name_;
                    dbEducationalDivisions.print_target(name_directory, name_);
                } else if (command == "delete DB") {
                    std::cout << "Enter name of directory you want to delete" << std::endl;
                    std::cin >> name_directory;
                    dbEducationalDivisions.deleteDB(name_directory);
                } else if (command == "delete target") {
                    std::cout << "Enter name of directory you want to delete " << std::endl;
                    std::cin >> name_directory;
                    std::cout << "Enter name of education division you want to delete" << std::endl;
                    std::cin >> name_;
                    dbEducationalDivisions.deleteTarget(name_directory, name_);
                } else if (command == "rename DB") {
                    std::cout << "Enter name of directory you want to rename" << std::endl;
                    std::cin >> name_;
                    std::cout << "Enter new name of directory" << std::endl;
                    std::string new_name;
                    std::cin >> new_name;
                    dbEducationalDivisions.renameBD(name_directory, new_name);
                } else if (command == "Calculating") {
                    std::cout << "Enter name of directory you want calculate income" << std::endl;
                    std::cin >> name_directory;
                    std::cout << "Enter name of education division you want calculate income" << std::endl;
                    std::cin >> name_;
                    std::cout << "Income for 1 person is :"
                              << dbEducationalDivisions.Calculationfunction(name_directory, name_) << std::endl;

                } else if (command == "Insert DB") {
                    std::cout << "Enter name of your directory for Education Division" << std::endl;
                    std::cin >> name_directory;
                    std::cout << "Enter name of your Education Division" << std::endl;
                    std::cin >> name_;
                    std::cout << "Enter manager name of your Education Division" << std::endl;
                    std::cin >> manager_;
                    std::cout << "Enter number of graduated students your Education Division" << std::endl;
                    std::cin >> graduate_students_;
                    std::cout << "Enter number of staff your Education Division" << std::endl;
                    std::cin >> staff_;
                    std::cout << "Enter number of students your Education Division for 1 course" << std::endl;
                    std::cin >> students_;
                    std::cout << "Enter tuition fee for 1 student for 1 course :" << std::endl;
                    std::cin >> tuition_fee_;
                    EducationalDivisions new_education_divisions;
                    new_education_divisions.SetName(name_);
                    new_education_divisions.SetManager(manager_);
                    new_education_divisions.SetStaff(staff_);
                    new_education_divisions.SetGraduate_students(graduate_students_);
                    std::map<size_t, course_info> course_new;
                    course_info courseInfo;
                    courseInfo.tuition_fee = tuition_fee_;
                    courseInfo.students = students_;
                    course_new[0] = courseInfo;
                    std::cout << "Enter number of students your Education Division for 2 course" << std::endl;
                    std::cin >> students_;
                    std::cout << "Enter tuition fee for 1 student for 2 course :" << std::endl;
                    std::cin >> tuition_fee_;
                    courseInfo.tuition_fee = tuition_fee_;
                    courseInfo.students = students_;
                    course_new[1] = courseInfo;
                    std::cout << "Enter number of students your Education Division for 3 course" << std::endl;
                    std::cin >> students_;
                    std::cout << "Enter tuition fee for 1 student for 3 course :" << std::endl;
                    std::cin >> tuition_fee_;
                    courseInfo.tuition_fee = tuition_fee_;
                    courseInfo.students = students_;
                    course_new[2] = courseInfo;
                    std::cout << "Enter number of students your Education Division for 4 course" << std::endl;
                    std::cin >> students_;
                    std::cout << "Enter tuition fee for 1 student for 4 course :" << std::endl;
                    std::cin >> tuition_fee_;
                    courseInfo.tuition_fee = tuition_fee_;
                    courseInfo.students = students_;
                    course_new[3] = courseInfo;
                    std::cout << "Enter number of students your Education Division for 5 course" << std::endl;
                    std::cin >> students_;
                    std::cout << "Enter tuition fee for 1 student for 5 course :" << std::endl;
                    std::cin >> tuition_fee_;
                    courseInfo.tuition_fee = tuition_fee_;
                    courseInfo.students = students_;
                    course_new[4] = courseInfo;
                    std::cout << "Enter number of students your Education Division for 6 course" << std::endl;
                    std::cin >> students_;
                    std::cout << "Enter tuition fee for 1 student for 6 course :" << std::endl;
                    std::cin >> tuition_fee_;
                    courseInfo.tuition_fee = tuition_fee_;
                    courseInfo.students = students_;
                    course_new[5] = courseInfo;
                    new_education_divisions.SetCourse(course_new);
                    dbEducationalDivisions.insertDB(new_education_divisions, name_directory);
                } else if (command == "Insert Course") {
                    std::cout << "Enter name of directory you want insert" << std::endl;
                    std::cin >> name_directory;
                    std::cout << "Enter name of education division you want insert" << std::endl;
                    std::cin >> name_;
                    std::cout << "Enter number of course you want to change" << std::endl;
                    std::string number;
                    std::cin >> number;
                    std::cout << "Enter what field you want to change (only: Tution Fee or Number Students)"
                              << std::endl;
                    std::string field;
                    std::getline(std::cin, field, '\n');
                    std::cout << "Enter new value of field that you want to change" << std::endl;
                    std::string new_field;
                    std::getline(std::cin, new_field, '\n');
                    dbEducationalDivisions.InsertCourse(number, field, new_field, name_directory, name_);
                } else if (command == "Insert target") {
                    std::cout << "Enter name of directory you want insert" << std::endl;
                    std::cin >> name_directory;
                    std::cout << "Enter name of education division you want insert" << std::endl;
                    std::cin >> name_;
                    std::cout << "Enter field you want to change" << std::endl;
                    std::cout << "Only : Manager , Graduated Student , Staff";
                    std::string field;
                    std::getline(std::cin, field, '\n');
                    std::cout << "Enter new value for field" << std::endl;
                    std::string value;
                    std::cin >> value;
                    dbEducationalDivisions.insert_target(field, value, name_directory, name_);
                } else if (command == "Find FIO") {
                    std::cout << "Enter name of directory you want find" << std::endl;
                    std::getline(std::cin, name_directory, '\n');
                    std::cout << "Enter FIO for searching" << std::endl;
                    std::string FIO;
                    std::getline(std::cin, FIO, '\n');
                    dbEducationalDivisions.FindFIO(name_directory, FIO);

                } else if (command == "Sort by Name") {
                    std::cout << "Enter name of directory you want sort" << std::endl;
                    std::cin >> name_directory;
                    dbEducationalDivisions.SortName(name_directory);
                } else if (command == "Sort by Staff") {
                    std::cout << "Enter name of directory you want sort" << std::endl;
                    std::cin >> name_directory;
                    dbEducationalDivisions.SortName(name_directory);
                } else if (command == "Selection Staff") {
                    std::cout << "Enter name of directory you want select" << std::endl;
                    std::cin >> name_directory;
                    size_t number;
                    std::cout << "Enter number staff>staff_sort";
                    std::cin >> number;
                    dbEducationalDivisions.SelectionStuff(name_directory, number);

                } else if (command == "Selection Income") {
                    std::cout << "Enter name of directory you want select" << std::endl;
                    std::cin >> name_directory;
                    size_t number;
                    std::cout << "Enter number income for 1 staff > n ";
                    std::cin >> number;
                    dbEducationalDivisions.SelectionIncome(name_directory, number);

                } else if (command == "Open") {
                    std::cout << "Enter name of directory you want select" << std::endl;
                    std::cin >> name_directory;
                    dbEducationalDivisions.openDB(name_directory);
                } else if (command != "Open" && command != "Selection Income" && command != "Sort by Staff" &&
                           command != "Selection Staff" && command != "Sort by Name" && command != "Find FIO" &&
                           command != "Insert target" && command != "Insert Course" && command != "Insert DB" &&
                           command != "Calculating" && command != "rename DB" && command != "CreateDB" &&
                           command != "printDB" && command != "print target" && command != "delete target" &&
                           command != "delete DB") {
                    std::cout << "Follow the rules" << std::endl;
                    help();

                }
            }
        } else if (command == "Scientific Division") {

            while (command != "quit") {
                std::cout << "Enter what command you want to do" << std::endl;
                std::getline(std::cin, command, '\n');
                if (command == "CreateDB") {
                    std::cout << "Enter name of your directory for Scientific Division" << std::endl;
                    std::getline(std::cin, name_directory, '\n');
                    std::cout << "Enter name of your Scientific Division" << std::endl;
                    std::getline(std::cin, name_, '\n');
                    std::cout << "Enter manager name of your Scientific Division" << std::endl;
                    std::getline(std::cin, manager_, '\n');
                    std::cout << "Enter number of graduated students your Scientific Division" << std::endl;
                    std::cin >> graduate_students_;
                    std::cout << "Enter number of staff your Scientific Division" << std::endl;
                    std::cin >> staff_;
                    ScientificDivisions new_scientific_divisions;
                    new_scientific_divisions.SetName(name_);
                    new_scientific_divisions.SetManager(manager_);
                    new_scientific_divisions.SetStaff(staff_);
                    new_scientific_divisions.SetGraduate_students(graduate_students_);
                    std::vector<project> project_new;
                    project projectInfo;
                    std::cout << "Enter number of your projects" << std::endl;
                    size_t number;
                    std::cin >> number;
                    for (size_t i = 0; i < number; ++i) {
                        std::cout << "Enter name for you " << i + 1 << " project" << std::endl;
                        std::cin>>name_project;
                        std::cout << "Enter cost for you " << i + 1 << " project" << std::endl;
                        std::cin >> cost_project;
                        projectInfo.name = name_project;
                        projectInfo.cost = cost_project;
                        project_new.push_back(projectInfo);
                    }

                    new_scientific_divisions.SetProject(project_new);

                    std::map<std::string, std::vector<ScientificDivisions>> mapSD;
                    std::vector<ScientificDivisions> vecSD;
                    vecSD.push_back(new_scientific_divisions);
                    mapSD[name_directory] = vecSD;
                    dbScientificDivisions.createDB(name_directory, mapSD);
                } else if (command == "printDB") {
                    std::cout << "Enter name of directory which you want to print" << std::endl;
                    std::cin >> name_directory;
                    dbScientificDivisions.printDB(name_directory);

                } else if (command == "print target") {
                    std::cout << "Enter name of directory you want to print " << std::endl;
                    std::cin >> name_directory;
                    std::cout << "Enter name of Scientific Division you want to print" << std::endl;
                    std::cin >> name_;
                    dbScientificDivisions.print_target(name_directory, name_);
                } else if (command == "delete DB") {
                    std::cout << "Enter name of directory you want to delete" << std::endl;
                    std::cin >> name_directory;
                    dbScientificDivisions.deleteDB(name_directory);
                } else if (command == "delete target") {
                    std::cout << "Enter name of directory you want to delete " << std::endl;
                    std::cin >> name_directory;
                    std::cout << "Enter name of Scientific Division you want to delete" << std::endl;
                    std::cin >> name_;
                    dbScientificDivisions.deleteTarget(name_directory, name_);
                } else if (command == "rename DB") {
                    std::cout << "Enter name of directory you want to rename" << std::endl;
                    std::cin >> name_;
                    std::cout << "Enter new name of directory" << std::endl;
                    std::string new_name;
                    std::cin >> new_name;
                    dbScientificDivisions.renameBD(name_directory, new_name);
                } else if (command == "Calculating") {
                    std::cout << "Enter name of directory you want calculate income" << std::endl;
                    std::cin >> name_directory;
                    std::cout << "Enter name of Scientific Division you want calculate income" << std::endl;
                    std::cin >> name_;
                    std::cout << "Income for 1 person is :"
                              << dbScientificDivisions.Calculationfunction(name_directory, name_) << std::endl;

                } else if (command == "Insert DB") {
                    std::cout << "Enter name of your directory for Scientific Division" << std::endl;
                    std::cin >> name_directory;
                    std::cout << "Enter name of your Scientific Division" << std::endl;
                    std::cin >> name_;
                    std::cout << "Enter name of your directory for Scientific Division" << std::endl;
                    std::getline(std::cin, name_directory, '\n');
                    std::cout << "Enter name of your Scientific Division" << std::endl;
                    std::getline(std::cin, name_, '\n');
                    std::cout << "Enter manager name of your Scientific Division" << std::endl;
                    std::getline(std::cin, manager_, '\n');
                    std::cout << "Enter number of graduated students your Scientific Division" << std::endl;
                    std::cin >> graduate_students_;
                    std::cout << "Enter number of staff your Scientific Division" << std::endl;
                    std::cin >> staff_;
                    ScientificDivisions new_scientific_divisions;
                    new_scientific_divisions.SetName(name_);
                    new_scientific_divisions.SetManager(manager_);
                    new_scientific_divisions.SetStaff(staff_);
                    new_scientific_divisions.SetGraduate_students(graduate_students_);
                    std::vector<project> project_new;
                    project projectInfo;
                    std::cout << "Enter number of your projects" << std::endl;
                    size_t number;
                    std::cin >> number;
                    for (size_t i = 0; i < number; ++i) {
                        std::cout << "Enter name for you " << i + 1 << " project" << std::endl;
                        std::getline(std::cin, name_project, '\n');
                        std::cout << "Enter cost for you " << i + 1 << " project" << std::endl;
                        std::cin >> cost_project;
                        projectInfo.name = name_project;
                        projectInfo.cost = cost_project;
                        project_new.push_back(projectInfo);
                    }
                    new_scientific_divisions.SetProject(project_new);
                    dbScientificDivisions.insertDB(new_scientific_divisions, name_directory);
                } else if (command == "Insert Project") {
                    std::cout << "Enter name of directory you want insert" << std::endl;
                    std::cin >> name_directory;
                    std::cout << "Enter name of Scientific Division you want insert" << std::endl;
                    std::cin >> name_;
                    std::cout << "Enter number of course you want to change" << std::endl;
                    std::string number;
                    std::cin >> number;
                    std::cout << "Enter what field you want to change (only: Name or Cost)"
                              << std::endl;
                    std::string field;
                    std::getline(std::cin, field, '\n');
                    std::cout << "Enter new value of field that you want to change" << std::endl;
                    std::string new_field;
                    std::getline(std::cin, new_field, '\n');
                    dbScientificDivisions.InsertCourse(field, new_field, name_directory, name_);
                } else if (command == "Insert target") {
                    std::cout << "Enter name of directory you want insert" << std::endl;
                    std::cin >> name_directory;
                    std::cout << "Enter name of Scientific Division you want insert" << std::endl;
                    std::cin >> name_;
                    std::cout << "Enter field you want to change" << std::endl;
                    std::cout << "Only : Manager , Graduated Student , Staff";
                    std::string field;
                    std::getline(std::cin, field, '\n');
                    std::cout << "Enter new value for field" << std::endl;
                    std::string value;
                    std::cin >> value;
                    dbScientificDivisions.insertField(field, value, name_directory, name_);
                } else if (command == "Find FIO") {
                    std::cout << "Enter name of directory you want find" << std::endl;
                    std::getline(std::cin, name_directory, '\n');
                    std::cout << "Enter FIO for searching" << std::endl;
                    std::string FIO;
                    std::getline(std::cin, FIO, '\n');
                    dbScientificDivisions.FindFIO(name_directory, FIO);


                } else if (command == "Sort by Name") {
                    std::cout << "Enter name of directory you want sort" << std::endl;
                    std::cin >> name_directory;
                    dbScientificDivisions.SortName(name_directory);
                } else if (command == "Sort by Staff") {
                    std::cout << "Enter name of directory you want sort" << std::endl;
                    std::cin >> name_directory;
                    dbScientificDivisions.SortName(name_directory);
                } else if (command == "Selection Staff") {
                    std::cout << "Enter name of directory you want select" << std::endl;
                    std::cin >> name_directory;
                    size_t number;
                    std::cout << "Enter number staff>staff_sort";
                    std::cin >> number;
                    dbScientificDivisions.SelectionStuff(name_directory, number);

                } else if (command == "Selection Income") {
                    std::cout << "Enter name of directory you want select" << std::endl;
                    std::cin >> name_directory;
                    size_t number;
                    std::cout << "Enter number income for 1 staff > n ";
                    std::cin >> number;
                    dbScientificDivisions.SelectionIncome(name_directory, number);

                } else if (command == "Open") {
                    std::cout << "Enter name of directory you want select" << std::endl;
                    std::cin >> name_directory;
                    dbScientificDivisions.openDB(name_directory);

                } else if (command != "Open" && command != "Selection Income" && command != "Sort by Staff" &&
                           command != "Selection Staff" && command != "Sort by Name" && command != "Find FIO" &&
                           command != "Insert target" && command != "Insert Project" && command != "Insert DB" &&
                           command != "Calculating" && command != "rename DB" && command != "CreateDB" &&
                           command != "printDB" && command != "print target" && command != "delete target" &&
                           command != "delete DB") {
                    std::cout << "Follow the rules" << std::endl;
                    help();

                }
            }
            if (command == "Hybrid Division") {
                std::cout << "Enter what command you want to do" << std::endl;
                std::cout << "You can write only:" << std::endl;
                std::cout << "Education Division or Scientific Division or Hybrid Division" << std::endl;
                std::getline(std::cin, command, '\n');
                if (command == "Education Division") {
                    while (command != "quit") {
                        std::cout << "Enter what command you want to do" << std::endl;
                        std::getline(std::cin, command, '\n');
                        if (command == "CreateDB") {
                            std::cout << "Enter name of your directory for Education Division" << std::endl;
                            std::getline(std::cin, name_directory, '\n');
                            std::cout << "Enter name of your Education Division" << std::endl;
                            std::getline(std::cin, name_, '\n');
                            std::cout << "Enter manager name of your Education Division" << std::endl;
                            std::getline(std::cin, manager_, '\n');
                            std::cout << "Enter number of graduated students your Education Division" << std::endl;
                            std::cin >> graduate_students_;
                            std::cout << "Enter number of staff your Education Division" << std::endl;
                            std::cin >> staff_;
                            std::cout << "Enter number of students your Education Division for 1 course" << std::endl;
                            std::cin >> students_;
                            std::cout << "Enter tuition fee for 1 student for 1 course :" << std::endl;
                            std::cin >> tuition_fee_;
                            EducationalDivisions new_education_divisions;
                            new_education_divisions.SetName(name_);
                            new_education_divisions.SetManager(manager_);
                            new_education_divisions.SetStaff(staff_);
                            new_education_divisions.SetGraduate_students(graduate_students_);
                            std::map<size_t, course_info> course_new;
                            course_info courseInfo;
                            courseInfo.tuition_fee = tuition_fee_;
                            courseInfo.students = students_;
                            course_new[0] = courseInfo;
                            std::cout << "Enter number of students your Education Division for 2 course" << std::endl;
                            std::cin >> students_;
                            std::cout << "Enter tuition fee for 1 student for 2 course :" << std::endl;
                            std::cin >> tuition_fee_;
                            courseInfo.tuition_fee = tuition_fee_;
                            courseInfo.students = students_;
                            course_new[1] = courseInfo;
                            std::cout << "Enter number of students your Education Division for 3 course" << std::endl;
                            std::cin >> students_;
                            std::cout << "Enter tuition fee for 1 student for 3 course :" << std::endl;
                            std::cin >> tuition_fee_;
                            courseInfo.tuition_fee = tuition_fee_;
                            courseInfo.students = students_;
                            course_new[2] = courseInfo;
                            std::cout << "Enter number of students your Education Division for 4 course" << std::endl;
                            std::cin >> students_;
                            std::cout << "Enter tuition fee for 1 student for 4 course :" << std::endl;
                            std::cin >> tuition_fee_;
                            courseInfo.tuition_fee = tuition_fee_;
                            courseInfo.students = students_;
                            course_new[3] = courseInfo;
                            std::cout << "Enter number of students your Education Division for 5 course" << std::endl;
                            std::cin >> students_;
                            std::cout << "Enter tuition fee for 1 student for 5 course :" << std::endl;
                            std::cin >> tuition_fee_;
                            courseInfo.tuition_fee = tuition_fee_;
                            courseInfo.students = students_;
                            course_new[4] = courseInfo;
                            std::cout << "Enter number of students your Education Division for 6 course" << std::endl;
                            std::cin >> students_;
                            std::cout << "Enter tuition fee for 1 student for 6 course :" << std::endl;
                            std::cin >> tuition_fee_;
                            courseInfo.tuition_fee = tuition_fee_;
                            courseInfo.students = students_;
                            course_new[5] = courseInfo;
                            new_education_divisions.SetCourse(course_new);
                            std::vector<EducationalDivisions> vecED;
                            std::map<std::string, std::vector<EducationalDivisions>> mapED;
                            vecED.push_back(new_education_divisions);
                            mapED[name_directory] = vecED;
                            dbEducationalDivisions.createDB(name_directory, mapED);
                            ScientificDivisions new_scientific_divisions;
                            new_scientific_divisions.SetName(name_);
                            new_scientific_divisions.SetManager(manager_);
                            new_scientific_divisions.SetStaff(staff_);
                            new_scientific_divisions.SetGraduate_students(graduate_students_);
                            std::vector<project> project_new;
                            project projectInfo;
                            std::cout << "Enter number of your projects" << std::endl;
                            size_t number;
                            std::cin >> number;
                            for (size_t i = 0; i < number; ++i) {
                                std::cout << "Enter name for you " << i + 1 << " project" << std::endl;
                                std::getline(std::cin, name_project, '\n');
                                std::cout << "Enter cost for you " << i + 1 << " project" << std::endl;
                                std::cin >> cost_project;
                                projectInfo.name = name_project;
                                projectInfo.cost = cost_project;
                                project_new.push_back(projectInfo);
                            }

                            new_scientific_divisions.SetProject(project_new);

                            std::map<std::string, std::vector<ScientificDivisions>> mapSD;
                            std::vector<ScientificDivisions> vecSD;
                            vecSD.push_back(new_scientific_divisions);
                            mapSD[name_directory] = vecSD;
                            dbScientificDivisions.createDB(name_directory, mapSD);
                        } else if (command == "printDB") {
                            std::cout << "Enter name of directory which you want to print" << std::endl;
                            std::cin >> name_directory;
                            dbEducationalDivisions.printDB(name_directory);
                            std::cout << "Enter name of directory which you want to print" << std::endl;
                            std::cin >> name_directory;
                            dbScientificDivisions.printDB(name_directory);

                        } else if (command == "print target") {
                            std::cout << "Enter name of directory you want to print " << std::endl;
                            std::cin >> name_directory;
                            std::cout << "Enter name of education division you want to print" << std::endl;
                            std::cin >> name_;
                            dbEducationalDivisions.print_target(name_directory, name_);
                            std::cout << "Enter name of directory you want to print " << std::endl;
                            std::cin >> name_directory;
                            std::cout << "Enter name of Scientific Division you want to print" << std::endl;
                            std::cin >> name_;
                            dbScientificDivisions.print_target(name_directory, name_);
                        } else if (command == "delete DB") {
                            std::cout << "Enter name of directory you want to delete" << std::endl;
                            std::cin >> name_directory;
                            dbEducationalDivisions.deleteDB(name_directory);
                            std::cout << "Enter name of directory you want to delete" << std::endl;
                            std::cin >> name_directory;
                            dbScientificDivisions.deleteDB(name_directory);
                        } else if (command == "delete target") {
                            std::cout << "Enter name of directory you want to delete " << std::endl;
                            std::cin >> name_directory;
                            std::cout << "Enter name of education division you want to delete" << std::endl;
                            std::cin >> name_;
                            dbEducationalDivisions.deleteTarget(name_directory, name_);
                            std::cout << "Enter name of directory you want to delete " << std::endl;
                            std::cin >> name_directory;
                            std::cout << "Enter name of Scientific Division you want to delete" << std::endl;
                            std::cin >> name_;
                            dbScientificDivisions.deleteTarget(name_directory, name_);
                        } else if (command == "rename DB") {
                            std::cout << "Enter name of directory you want to rename" << std::endl;
                            std::cin >> name_;
                            std::cout << "Enter new name of directory" << std::endl;
                            std::string new_name;
                            std::cin >> new_name;
                            dbEducationalDivisions.renameBD(name_directory, new_name);
                            std::cout << "Enter name of directory you want to rename" << std::endl;
                            std::cin >> name_;
                            std::cout << "Enter new name of directory" << std::endl;
                            std::cin >> new_name;
                            dbScientificDivisions.renameBD(name_directory, new_name);
                        } else if (command == "Calculating") {
                            std::cout << "Enter name of directory you want calculate income" << std::endl;
                            std::cin >> name_directory;
                            std::cout << "Enter name of education division you want calculate income" << std::endl;
                            std::cin >> name_;
                            std::cout << "Enter name of directory you want calculate income" << std::endl;
                            std::cin >> name_directory;
                            std::cout << "Enter name of Scientific Division you want calculate income" << std::endl;
                            std::cin >> name_;
                            std::cout << "Income for 1 person is :"
                                      << dbScientificDivisions.Calculationfunction(name_directory, name_) +
                                         dbEducationalDivisions.Calculationfunction(name_directory, name_) << std::endl;


                        } else if (command == "Insert DB") {
                            std::cout << "Enter name of your directory for Education Division" << std::endl;
                            std::cin >> name_directory;
                            std::cout << "Enter name of your Education Division" << std::endl;
                            std::cin >> name_;
                            std::cout << "Enter manager name of your Education Division" << std::endl;
                            std::cin >> manager_;
                            std::cout << "Enter number of graduated students your Education Division" << std::endl;
                            std::cin >> graduate_students_;
                            std::cout << "Enter number of staff your Education Division" << std::endl;
                            std::cin >> staff_;
                            std::cout << "Enter number of students your Education Division for 1 course" << std::endl;
                            std::cin >> students_;
                            std::cout << "Enter tuition fee for 1 student for 1 course :" << std::endl;
                            std::cin >> tuition_fee_;
                            EducationalDivisions new_education_divisions;
                            new_education_divisions.SetName(name_);
                            new_education_divisions.SetManager(manager_);
                            new_education_divisions.SetStaff(staff_);
                            new_education_divisions.SetGraduate_students(graduate_students_);
                            std::map<size_t, course_info> course_new;
                            course_info courseInfo;
                            courseInfo.tuition_fee = tuition_fee_;
                            courseInfo.students = students_;
                            course_new[0] = courseInfo;
                            std::cout << "Enter number of students your Education Division for 2 course" << std::endl;
                            std::cin >> students_;
                            std::cout << "Enter tuition fee for 1 student for 2 course :" << std::endl;
                            std::cin >> tuition_fee_;
                            courseInfo.tuition_fee = tuition_fee_;
                            courseInfo.students = students_;
                            course_new[1] = courseInfo;
                            std::cout << "Enter number of students your Education Division for 3 course" << std::endl;
                            std::cin >> students_;
                            std::cout << "Enter tuition fee for 1 student for 3 course :" << std::endl;
                            std::cin >> tuition_fee_;
                            courseInfo.tuition_fee = tuition_fee_;
                            courseInfo.students = students_;
                            course_new[2] = courseInfo;
                            std::cout << "Enter number of students your Education Division for 4 course" << std::endl;
                            std::cin >> students_;
                            std::cout << "Enter tuition fee for 1 student for 4 course :" << std::endl;
                            std::cin >> tuition_fee_;
                            courseInfo.tuition_fee = tuition_fee_;
                            courseInfo.students = students_;
                            course_new[3] = courseInfo;
                            std::cout << "Enter number of students your Education Division for 5 course" << std::endl;
                            std::cin >> students_;
                            std::cout << "Enter tuition fee for 1 student for 5 course :" << std::endl;
                            std::cin >> tuition_fee_;
                            courseInfo.tuition_fee = tuition_fee_;
                            courseInfo.students = students_;
                            course_new[4] = courseInfo;
                            std::cout << "Enter number of students your Education Division for 6 course" << std::endl;
                            std::cin >> students_;
                            std::cout << "Enter tuition fee for 1 student for 6 course :" << std::endl;
                            std::cin >> tuition_fee_;
                            courseInfo.tuition_fee = tuition_fee_;
                            courseInfo.students = students_;
                            course_new[5] = courseInfo;
                            new_education_divisions.SetCourse(course_new);
                            dbEducationalDivisions.insertDB(new_education_divisions, name_directory);
                            std::cout << "Enter name of your directory for Scientific Division" << std::endl;
                            std::cin >> name_directory;
                            std::cout << "Enter name of your Scientific Division" << std::endl;
                            std::cin >> name_;
                            std::cout << "Enter name of your directory for Scientific Division" << std::endl;
                            std::getline(std::cin, name_directory, '\n');
                            std::cout << "Enter name of your Scientific Division" << std::endl;
                            std::getline(std::cin, name_, '\n');
                            std::cout << "Enter manager name of your Scientific Division" << std::endl;
                            std::getline(std::cin, manager_, '\n');
                            std::cout << "Enter number of graduated students your Scientific Division" << std::endl;
                            std::cin >> graduate_students_;
                            std::cout << "Enter number of staff your Scientific Division" << std::endl;
                            std::cin >> staff_;
                            ScientificDivisions new_scientific_divisions;
                            new_scientific_divisions.SetName(name_);
                            new_scientific_divisions.SetManager(manager_);
                            new_scientific_divisions.SetStaff(staff_);
                            new_scientific_divisions.SetGraduate_students(graduate_students_);
                            std::vector<project> project_new;
                            project projectInfo;
                            std::cout << "Enter number of your projects" << std::endl;
                            size_t number;
                            std::cin >> number;
                            for (size_t i = 0; i < number; ++i) {
                                std::cout << "Enter name for you " << i + 1 << " project" << std::endl;
                                std::getline(std::cin, name_project, '\n');
                                std::cout << "Enter cost for you " << i + 1 << " project" << std::endl;
                                std::cin >> cost_project;
                                projectInfo.name = name_project;
                                projectInfo.cost = cost_project;
                                project_new.push_back(projectInfo);
                            }
                            new_scientific_divisions.SetProject(project_new);
                            dbScientificDivisions.insertDB(new_scientific_divisions, name_directory);
                        } else if (command == "Insert Course") {
                            std::cout << "Enter name of directory you want insert" << std::endl;
                            std::cin >> name_directory;
                            std::cout << "Enter name of education division you want insert" << std::endl;
                            std::cin >> name_;
                            std::cout << "Enter number of course you want to change" << std::endl;
                            std::string number;
                            std::cin >> number;
                            std::cout << "Enter what field you want to change (only: Tution Fee or Number Students)"
                                      << std::endl;
                            std::string field;
                            std::getline(std::cin, field, '\n');
                            std::cout << "Enter new value of field that you want to change" << std::endl;
                            std::string new_field;
                            std::getline(std::cin, new_field, '\n');
                            dbEducationalDivisions.InsertCourse(number, field, new_field, name_directory, name_);
                            std::cout << "Enter name of directory you want insert" << std::endl;
                            std::cin >> name_directory;
                            std::cout << "Enter name of Scientific Division you want insert" << std::endl;
                            std::cin >> name_;
                            std::cout << "Enter field you want to change" << std::endl;
                            std::cout << "Only : Manager , Graduated Student , Staff";
                            std::getline(std::cin, field, '\n');
                            std::cout << "Enter new value for field" << std::endl;
                            std::string value;
                            std::cin >> value;
                            dbScientificDivisions.insertField(field, value, name_directory, name_);
                        } else if (command == "Insert target") {
                            std::cout << "Enter name of directory you want insert" << std::endl;
                            std::cin >> name_directory;
                            std::cout << "Enter name of education division you want insert" << std::endl;
                            std::cin >> name_;
                            std::cout << "Enter field you want to change" << std::endl;
                            std::cout << "Only : Manager , Graduated Student , Staff";
                            std::string field;
                            std::getline(std::cin, field, '\n');
                            std::cout << "Enter new value for field" << std::endl;
                            std::string value;
                            std::cin >> value;
                            dbEducationalDivisions.insert_target(field, value, name_directory, name_);
                            std::cout << "Enter name of directory you want insert" << std::endl;
                            std::cin >> name_directory;
                            std::cout << "Enter name of Scientific Division you want insert" << std::endl;
                            std::cin >> name_;
                            std::cout << "Enter field you want to change" << std::endl;
                            std::cout << "Only : Manager , Graduated Student , Staff";
                            std::getline(std::cin, field, '\n');
                            std::cout << "Enter new value for field" << std::endl;
                            std::cin >> value;
                            dbScientificDivisions.insertField(field, value, name_directory, name_);
                        } else if (command == "Find FIO") {
                            std::cout << "Enter name of directory you want find" << std::endl;
                            std::getline(std::cin, name_directory, '\n');
                            std::cout << "Enter FIO for searching" << std::endl;
                            std::string FIO;
                            std::getline(std::cin, FIO, '\n');
                            dbEducationalDivisions.FindFIO(name_directory, FIO);
                            std::cout << "Enter name of directory you want find" << std::endl;
                            std::getline(std::cin, name_directory, '\n');
                            std::cout << "Enter FIO for searching" << std::endl;
                            std::getline(std::cin, FIO, '\n');
                            dbScientificDivisions.FindFIO(name_directory, FIO);

                        } else if (command == "Sort by Name") {
                            std::cout << "Enter name of directory you want sort" << std::endl;
                            std::cin >> name_directory;
                            dbEducationalDivisions.SortName(name_directory);
                        } else if (command == "Sort by Staff") {
                            std::cout << "Enter name of directory you want sort" << std::endl;
                            std::cin >> name_directory;
                            dbEducationalDivisions.SortName(name_directory);
                        } else if (command == "Selection Staff") {
                            std::cout << "Enter name of directory you want select" << std::endl;
                            std::cin >> name_directory;
                            size_t number;
                            std::cout << "Enter number staff>staff_sort";
                            std::cin >> number;
                            dbEducationalDivisions.SelectionStuff(name_directory, number);

                        } else if (command == "Selection Income") {
                            std::cout << "Enter name of directory you want select" << std::endl;
                            std::cin >> name_directory;
                            size_t number;
                            std::cout << "Enter number income for 1 staff > n ";
                            std::cin >> number;
                            dbEducationalDivisions.SelectionIncome(name_directory, number);

                        } else if (command == "Open") {
                            std::cout << "Enter name of directory you want select" << std::endl;
                            std::cin >> name_directory;
                            dbEducationalDivisions.openDB(name_directory);
                        } else if (command != "Open" && command != "Selection Income" && command != "Sort by Staff" &&
                                   command != "Selection Staff" && command != "Sort by Name" && command != "Find FIO" &&
                                   command != "Insert target" && command != "Insert Course" && command != "Insert DB" &&
                                   command != "Calculating" && command != "rename DB" && command != "CreateDB" &&
                                   command != "printDB" && command != "print target" && command != "delete target" &&
                                   command != "delete DB") {
                            std::cout << "Follow the rules" << std::endl;
                            help();

                        }
                    }
                }

            }
        }
    }
}


















        /* EducationalDivisions sad ;
         sad.SetName("aksd");

         sad.SetManager("asdasfx");

         sad.SetGraduate_students(105);

         sad.SetStaff(25);

         std::map<size_t,course_info> rak;
         course_info kad;
         kad.students = 1231;
         kad.tuition_fee=12421;
         rak[0]=kad;
         sad.SetCourse(rak);

         std::vector<EducationalDivisions>casd;
         casd.push_back(sad);
         std::map<std::string,std::vector<EducationalDivisions>> map123;
         DbEducationalDivisions sae;
         std::string name = "name1";
         std::string FIO = "asdasfx";
         std::string *lines = nullptr;
         int count = CountLinesInFile(name);
         //sae.deleteDB(name); work
        //sae.createDB("name1", casd); work

        map123.insert({name,casd});
        // sae.createDB(name, map123);
        // sae.renameBD(name , "new_name"); //work
        // sae.printDB("name1"); work
         sad.SetName("Vasily");
         sad.SetManager("Me");
         std::string name_Division="Vasily";
     std::string aksd="aksd";
         sae.insertDB(sad,"name1");
         sae.insertDB(sad,name);
       //  sae.deleteTarget(name,aksd);
     //    sae.insert_target("Staff","500",name,name_Division);
         std::vector<EducationalDivisions>cas;
         cas.push_back(sad);
         sae.printDB(name);


         //sae.deleteDB(name); work
         //sae.createDB("name1", casd); work

         map123.insert({name,casd});

       //sae.FindFIO(name,FIO);*/
