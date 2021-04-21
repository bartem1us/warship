// Copyright 2020 bartem1us <filkovghjynj@mail.ru>
#include "DBeducational_divisions.h"
#include "educational_divisions.h"
#include "dop_function.h"
#include <filesystem>
#include <iostream>


namespace fs = std::filesystem;
namespace library {
    const std::string cur = fs::current_path();
    const std::string current_library = cur+ fs::path::preferred_separator+"DbEducationalDivisions";

}

void DbEducationalDivisions::createDB(const std::string &name_, std::vector<EducationalDivisions> &data) {
    const std::string nameDB = library::current_library + fs::path::preferred_separator + name_;
    fs::create_directory(nameDB);
    database = data;
    std::string our_directory = nameDB + fs::path::preferred_separator + "educational.txt";
    std::ofstream Education(our_directory);
    for (size_t i = 0; i < data.size(); ++i) {
        Education << data[i].GetName() << " Division" << std::endl;
        Education << "FIO of manager : " << data[i].GetManager() << std::endl;
        Education << "Number of graduated students is : " << data[i].GetGraduate_students() << std::endl;
        Education << "Number of staff : " << data[i].GetStaff() << std::endl;
        Education << "-----------------------Information of course------------------------" << std::endl;
        Education << "Number course : 1 " << "Number of students " << data[i].GetCourse()[0].students << std::endl
                  << " Tuition Fee for one student : " << data[i].GetCourse()[0].tuition_fee << std::endl;
        Education << "Number course : 2 " << "Number of students " << data[i].GetCourse()[1].students << std::endl
                  << " Tuition Fee for one student : " << data[i].GetCourse()[1].tuition_fee << std::endl;
        Education << "Number course : 3 " << "Number of students " << data[i].GetCourse()[2].students << std::endl
                  << " Tuition Fee for one student : " << data[i].GetCourse()[2].tuition_fee << std::endl;
        Education << "Number course : 4 " << "Number of students " << data[i].GetCourse()[3].students << std::endl
                  << " Tuition Fee for one student : " << data[i].GetCourse()[3].tuition_fee << std::endl;
        Education << "Number course : 5 " << "Number of students " << data[i].GetCourse()[4].students << std::endl
                  << " Tuition Fee for one student : " << data[i].GetCourse()[4].tuition_fee << std::endl;
        Education << "Number course : 6 " << "Number of students " << data[i].GetCourse()[5].students << std::endl
                  << " Tuition Fee for one student : " << data[i].GetCourse()[5].tuition_fee << std::endl;
        Education << "---------------------------------------------------------------------" << std::endl;
        Education << "*********************************************************************" << std::endl;


    }
    Education.close();

}

void DbEducationalDivisions::openDB(const std::string &name_) {
    const std::string nameDB = library::current_library + fs::path::preferred_separator + name_;
    const std::string our_directory = nameDB + fs::path::preferred_separator + "educational.txt";
    system("/home/bartem1us/bartem1us/homework/DbEducationalDivisions");
}

void DbEducationalDivisions::deleteDB(const std::string &name_) {
    const std::string nameDB = library::current_library + fs::path::preferred_separator + name_;
    fs::remove_all(nameDB);
}

void DbEducationalDivisions::renameBD(const std::string old_name, const std::string &new_name) {
    const std::string nameDB = library::current_library + fs::path::preferred_separator;
    fs::rename(nameDB + old_name, nameDB + new_name);
    deleteDB(nameDB + old_name);
}

void DbEducationalDivisions::printDB(const std::string &name_) {
    const std::string nameDB = library::current_library + fs::path::preferred_separator + name_;
    fs::create_directory(nameDB);
    std::string our_directory = nameDB + fs::path::preferred_separator + "educational.txt";
    std::ifstream Education1;
    Education1.open(our_directory, std::ios::in);
    char chr;
    while (Education1.read((char *) &chr, sizeof(char))) {
        std::cout << chr;
    }


}

void DbEducationalDivisions::insertDB(EducationalDivisions &division_, const std::string &name_) {
    std::string name = division_.GetName();
    std::string manager = division_.GetManager();
    size_t graduate_stud = division_.GetGraduate_students();
    size_t staff_ = division_.GetStaff();
    std::map<size_t, course_info> course1 = division_.GetCourse();
    const std::string nameDB = library::current_library + fs::path::preferred_separator + name_;
    std::string our_directory = nameDB + fs::path::preferred_separator + "educational.txt";
    database.push_back(division_);
    std::ofstream Education(our_directory);
    for (size_t i = 0; i < database.size(); ++i) {
        Education << name_ << " Division" << std::endl;
        Education << "FIO of manager : " << database[i].GetManager() << std::endl;
        Education << "Number of graduated students is : " << database[i].GetGraduate_students() << std::endl;
        Education << "Number of staff : " << database[i].GetStaff() << std::endl;
        Education << "-----------------------Information of course------------------------" << std::endl;
        Education << "Number course : 1 " << "Number of students " << database[i].GetCourse()[0].students << std::endl
                  << " Tuition Fee for one student : " << database[i].GetCourse()[0].tuition_fee << std::endl;
        Education << "Number course : 2 " << "Number of students " << database[i].GetCourse()[0].students << std::endl
                  << " Tuition Fee for one student : " << database[i].GetCourse()[1].tuition_fee << std::endl;
        Education << "Number course : 3 " << "Number of students " << database[i].GetCourse()[0].students << std::endl
                  << " Tuition Fee for one student : " << database[i].GetCourse()[2].tuition_fee << std::endl;
        Education << "Number course : 4 " << "Number of students " << database[i].GetCourse()[0].students << std::endl
                  << " Tuition Fee for one student : " << database[i].GetCourse()[3].tuition_fee << std::endl;
        Education << "Number course : 5 " << "Number of students " << database[i].GetCourse()[0].students << std::endl
                  << " Tuition Fee for one student : " << database[i].GetCourse()[4].tuition_fee << std::endl;
        Education << "Number course : 6 " << "Number of students " << database[i].GetCourse()[0].students << std::endl
                  << " Tuition Fee for one student : " << database[i].GetCourse()[5].tuition_fee << std::endl;
        Education << "---------------------------------------------------------------------" << std::endl;
        Education << "*********************************************************************" << std::endl;


    }
    Education.close();
}

void DbEducationalDivisions::deleteTarget(std::string &name_, std::string &name_Divisons) {
    std::string *lines = nullptr;
    int count = CountLinesInFile(name_);
    GetStringsFromFileS(name_, &lines);
    int kar;
    for (size_t i = 0; i < count; ++i)//13 all string in 1 base
    {
        if (lines[i].find(name_Divisons) == 0) {
            kar = i;

            for (size_t i = kar; i < kar + 19; ++i) {
                bool raz = RemoveStringFromFileByIndex(name_, kar);
            }

        }
    }
}

void DbEducationalDivisions::print_target(std::string &name_, std::string &name_Divisons) {
    std::string *lines = nullptr;
    int count = CountLinesInFile(name_);
    GetStringsFromFileS(name_, &lines);
    int kar;
    for (size_t i = 0; i < count; ++i)//13 all string in 1 base
    {
        if (lines[i].find(name_Divisons) == 0) {
            kar = i;
            for (size_t k = kar; k < kar + 13; ++k) {
                std::cout << lines[k];
            }

        }
    }
}

void
DbEducationalDivisions::insertDB1(const std::string &field, const std::string &field_name, std::string &name_,
                                  std::string &name_Division) {
    std::string *lines = nullptr;
    int count = CountLinesInFile(name_);
    GetStringsFromFileS(name_, &lines);
    int del = 19;
    if (field == "Manager") {
        std::string change_string = "FIO of manager : " + field_name;
        for (size_t i = 0; i < count; ++i)//13 all string in 1 base
        {
            if (lines[i].find(name_Division) == 0) {

                int number = i / del;
                database[number].SetManager(field_name);


                ChangeStringInFileC(name_, i + 1, change_string);
            }
        }
    }
    if (field == "Graduated Students") {
        std::string change_string = "Number of graduated students is : " + field_name;
        for (size_t i = 0; i < count; ++i)//13 all string in 1 base
        {
            if (lines[i].find(name_Division) == 0) {
                int number = i / del;
                database[number].SetGraduate_students(std::stoi(field_name));
                ChangeStringInFileC(name_, i + 2, change_string);
            }
        }
    }
    if (field == "Staff") {
        std::string change_string = "Number of staff : " + field_name;
        for (size_t i = 0; i < count; ++i)//13 all string in 1 base
        {
            if (lines[i].find(name_Division) == 0) {
                int number = i / del;
                database[number].SetStaff(std::stoi(field_name));
                ChangeStringInFileC(name_, i + 3, change_string);
            }
        }
    }
}

void DbEducationalDivisions::InsertCourse(const std::string &number_course, const std::string &field,
                                          const std::string &field_name,
                                          std::string &name_, std::string &name_Division) {
    std::string *lines = nullptr;
    int count = CountLinesInFile(name_);
    GetStringsFromFileS(name_, &lines);
    int del = 19;
    if (field == "Tution Fee") {
        if (number_course == "1") {
            std::string change_string =
                    " Tuition Fee for one student : " + field_name;
            for (size_t i = 0; i < count; ++i)//13 all string in 1 base
            {
                if (lines[i].find(name_Division) == 0) {
                    int number = i / del;
                    database[number].SetCourseTutionFee(std::stoi(field_name), 1);
                    ChangeStringInFileC(name_, i + 6, change_string);
                }
            }
        }
        if (number_course == "2") {
            std::string change_string =
                    " Tuition Fee for one student : " + field_name;
            for (size_t i = 0; i < count; ++i)//13 all string in 1 base
            {
                if (lines[i].find(name_Division) == 0) {
                    int number = i / del;
                    database[number].SetCourseTutionFee(std::stoi(field_name), 2);
                    ChangeStringInFileC(name_, i + 8, change_string);
                }
            }
        }
        if (number_course == "3") {
            std::string change_string =
                    " Tuition Fee for one student : " + field_name;
            for (size_t i = 0; i < count; ++i)//13 all string in 1 base
            {
                if (lines[i].find(name_Division) == 0) {
                    int number = i / del;
                    database[number].SetCourseTutionFee(std::stoi(field_name), 3);
                    ChangeStringInFileC(name_, i + 10, change_string);
                }
            }
        }
        if (number_course == "4") {
            std::string change_string =
                    " Tuition Fee for one student : " + field_name;
            for (size_t i = 0; i < count; ++i)//13 all string in 1 base
            {
                if (lines[i].find(name_Division) == 0) {
                    int number = i / del;
                    database[number].SetCourseTutionFee(std::stoi(field_name), 4);
                    ChangeStringInFileC(name_, i + 12, change_string);
                }
            }
        }
        if (number_course == "5") {
            std::string change_string =
                    " Tuition Fee for one student : " + field_name;
            for (size_t i = 0; i < count; ++i)//13 all string in 1 base
            {
                if (lines[i].find(name_Division) == 0) {
                    int number = i / del;
                    database[number].SetCourseTutionFee(std::stoi(field_name), 5);
                    ChangeStringInFileC(name_, i + 14, change_string);
                }
            }
        }
        if (number_course == "6") {
            std::string change_string =
                    " Tuition Fee for one student : " + field_name;
            for (size_t i = 0; i < count; ++i)//13 all string in 1 base
            {
                if (lines[i].find(name_Division) == 0) {
                    int number = i / del;
                    database[number].SetCourseTutionFee(std::stoi(field_name), 6);
                    ChangeStringInFileC(name_, i + 16, change_string);
                }
            }
        }
    }
    if (field == "Number Students") {
        if (number_course == "1") {
            std::string change_string =
                    "Number course : 1 Number of students " + field_name;
            for (size_t i = 0; i < count; ++i)//13 all string in 1 base
            {
                if (lines[i].find(name_Division) == 0) {
                    int number = i / del;
                    database[number].SetCourseStudentsNumber(std::stoi(field_name), 1);
                    ChangeStringInFileC(name_, i + 5, change_string);
                }
            }
        }
        if (number_course == "2") {
            std::string change_string =
                    "Number course : 2 Number of students " + field_name;
            for (size_t i = 0; i < count; ++i)//13 all string in 1 base
            {
                if (lines[i].find(name_Division) == 0) {
                    int number = i / del;
                    database[number].SetCourseStudentsNumber(std::stoi(field_name), 2);
                    ChangeStringInFileC(name_, i + 7, change_string);
                }
            }
        }
        if (number_course == "3") {
            std::string change_string =
                    "Number course : 3 Number of students " + field_name;
            for (size_t i = 0; i < count; ++i)//13 all string in 1 base
            {
                if (lines[i].find(name_Division) == 0) {
                    int number = i / del;
                    database[number].SetCourseStudentsNumber(std::stoi(field_name), 3);
                    ChangeStringInFileC(name_, i + 9, change_string);
                }
            }
        }
        if (number_course == "4") {
            std::string change_string =
                    "Number course : 4 Number of students " + field_name;
            for (size_t i = 0; i < count; ++i)//13 all string in 1 base
            {
                if (lines[i].find(name_Division) == 0) {
                    int number = i / del;
                    database[number].SetCourseStudentsNumber(std::stoi(field_name), 4);
                    ChangeStringInFileC(name_, i + 11, change_string);
                }
            }
        }
        if (number_course == "5") {
            std::string change_string =
                    "Number course : 5 Number of students " + field_name;
            for (size_t i = 0; i < count; ++i)//13 all string in 1 base
            {
                if (lines[i].find(name_Division) == 0) {
                    int number = i / del;
                    database[number].SetCourseStudentsNumber(std::stoi(field_name), 5);
                    ChangeStringInFileC(name_, i + 13, change_string);
                }
            }
        }
        if (number_course == "6") {
            std::string change_string =
                    "Number course : 6 Number of students " + field_name;
            for (size_t i = 0; i < count; ++i)//13 all string in 1 base
            {
                if (lines[i].find(name_Division) == 0) {
                    int number = i / del;
                    database[number].SetCourseStudentsNumber(std::stoi(field_name), 6);
                    ChangeStringInFileC(name_, i + 15, change_string);
                }
            }
        }
    }
}

int DbEducationalDivisions::Calculationfunction(std::string &name_, std::string &name_DB) {
    std::string *lines = nullptr;
    int count = CountLinesInFile(name_);
    GetStringsFromFileS(name_, &lines);
    int kar = 0;
    std::string int_number = "";
    std::string int_number2 = "";
    int kar2 = 0;
    int our_nubmer = 0;
    for (size_t i = 0; i < count; ++i)//13 all string in 1 base
    {
        if (lines[i].find(name_DB) == 0) {
            for (size_t r = 0; r < 12; r += 2) {
                while (lines[i + 5 + r][37 + kar]) {
                    int_number += lines[i + 5 + r][37 + kar];
                    kar++;
                }
                while (lines[i + 6 + r][31 + kar2]) {
                    int_number2 += lines[i + 6 + r][31 + kar2];
                    kar2++;
                }
                our_nubmer += std::stoi(int_number) * std::stoi(int_number2);
                kar = 0;
                kar2 = 0;
                int_number = "";
                int_number2 = "";
            }
            break;

        }
    }


    return our_nubmer;

}

std::string &DbEducationalDivisions::FindFIO(std::string &name_, std::string &FIO) {
    std::string *lines = nullptr;
    int count = CountLinesInFile(name_);
    GetStringsFromFileS(name_, &lines);
    int kar;
    for (size_t i = 0; i < count; ++i)//13 all string in 1 base
    {
        if (lines[i].find(FIO) == 17) {
            kar = i - 1;
        }
    }
    std::cout << name_ << " find in : " << lines[kar] << std::endl;
    return lines[kar];
}

bool CompareName(class EducationalDivisions &lhs, class EducationalDivisions &rhs) {
    return lhs.GetName() < rhs.GetName();
}

bool CompareNumber(class EducationalDivisions &lhs, class EducationalDivisions &rhs) {
    return lhs.GetStaff() < rhs.GetStaff();
}

void DbEducationalDivisions::SortName(std::string &name_) {
    std::string *lines = nullptr;
    int count = CountLinesInFile(name_);
    GetStringsFromFileS(name_, &lines);
    //19
    std::sort(database.begin(), database.end(), CompareName);
    deleteDB(name_);
    createDB(name_, database);


}

void DbEducationalDivisions::SortStuff(std::string &name_) {
    std::string *lines = nullptr;
    int count = CountLinesInFile(name_);
    GetStringsFromFileS(name_, &lines);
    //19
    std::sort(database.begin(), database.end(), CompareNumber);
    deleteDB(name_);
    createDB(name_, database);
}

void DbEducationalDivisions::SelectionStuff(std::string &name_, size_t number) {
    for (size_t i = 0; i < database.size(); ++i)//13 all string in 1 base
    {
        if (database[i].GetStaff() > number) {
            print_target(name_, database[i].GetName());
        }
    }
}

void DbEducationalDivisions::SelectionIncome(std::string &name_, size_t number) {
    for (size_t i = 0; i < database.size(); ++i) {
        double income = Calculationfunction(name_, database[i].GetName()) / database[i].GetStaff();
        if (income <= number) {
            print_target(name_, database[i].GetName());
        }
    }
}










