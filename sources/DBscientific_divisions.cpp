// Copyright 2020 bartem1us <filkovghjynj@mail.ru>

#include "DBscientific_divisions.h"
#include "dop_function.h"
#include "scientific_divisions.h"

namespace fs = std::filesystem;
namespace library {
    const std::string current_library = fs::current_path();
}

void DbScientificDivisions::createDB(const std::string &name_,
                                     std::map<std::string, std::vector<ScientificDivisions>> &data) {
    const std::string nameDB = library::current_library + fs::path::preferred_separator + name_;
    fs::create_directory(nameDB);
    databaseSD = data;
    std::string our_directory = nameDB + fs::path::preferred_separator + "scientific.txt";
    std::ofstream Science(our_directory);
    for (size_t i = 0; i < data.size(); ++i) {
        Science << data[name_][i].GetName() << " Division" << std::endl;
        Science << "FIO of manager : " << data[name_][i].GetManager() << std::endl;
        Science << "Number of graduated students is : " << data[name_][i].GetGraduate_students() << std::endl;
        Science << "Number of staff : " << data[name_][i].GetStaff() << std::endl;
        Science << "-----------------------Information of course------------------------" << std::endl;
        for (size_t k = 0; k < data[name_][i].GetProject().size(); k++) {
            Science << "Name of project : " << data[name_][i].GetProject()[k].name << std::endl;
            Science << "Cost of project : " << data[name_][i].GetProject()[k].cost << std::endl;
        }
        Science << "---------------------------------------------------------------------" << std::endl;
        Science << "*********************************************************************" << std::endl;
    }
    Science.close();

}

void DbScientificDivisions::openDB(const std::string &name_) {
    const std::string nameDB = library::current_library + fs::path::preferred_separator + name_;
    const std::string our_directory = nameDB + fs::path::preferred_separator + "educational.txt";
    std::ofstream Education;
    Education.open(our_directory,std::ofstream::app);
}

void DbScientificDivisions::deleteDB(const std::string &name_) {
    const std::string nameDB = library::current_library + fs::path::preferred_separator + name_;
    fs::remove_all(nameDB);
}

void DbScientificDivisions::renameBD(const std::string old_name, const std::string &new_name) {
    const std::string nameDB = library::current_library + fs::path::preferred_separator;
    fs::rename(nameDB + old_name, nameDB + new_name);
    deleteDB(nameDB + old_name);
}

void DbScientificDivisions::printDB(const std::string &name_) {
    const std::string nameDB = library::current_library + fs::path::preferred_separator + name_;
    fs::create_directory(nameDB);
    std::string our_directory = nameDB + fs::path::preferred_separator + "educational.txt";
    std::ifstream Science;
    Science.open(our_directory, std::ios::in);
    char chr;
    while (Science.read((char *) &chr, sizeof(char))) {
        std::cout << chr;
    }
}

void DbScientificDivisions::insertDB(ScientificDivisions &division_, const std::string &name_) {
    std::string name = division_.GetName();
    std::string manager = division_.GetManager();
    size_t graduate_stud = division_.GetGraduate_students();
    size_t staff_ = division_.GetStaff();
    std::vector<project> course1 = division_.GetProject();
    const std::string nameDB = library::current_library + fs::path::preferred_separator + name_;
    std::string our_directory = nameDB + fs::path::preferred_separator + "educational.txt";
    databaseSD[name_].push_back(division_);
    std::ofstream Science(our_directory);
    for (size_t i = 0; i < databaseSD[name_].size(); ++i) {
        Science << databaseSD[name_][i].GetName() << " Division" << std::endl;
        Science << "FIO of manager : " << databaseSD[name_][i].GetManager() << std::endl;
        Science << "Number of graduated students is : " << databaseSD[name_][i].GetGraduate_students() << std::endl;
        Science << "Number of staff : " << databaseSD[name_][i].GetStaff() << std::endl;
        Science << "-----------------------Information of course------------------------" << std::endl;
        for (size_t k = 0; k < databaseSD[name_][i].GetProject().size(); k++) {
            Science << "Name of project : " << databaseSD[name_][i].GetProject()[k].name << std::endl;
            Science << "Cost of project : " << databaseSD[name_][i].GetProject()[k].cost << std::endl;
        }
        Science << "---------------------------------------------------------------------" << std::endl;
        Science << "*********************************************************************" << std::endl;
    }
    Science.close();
}

void DbScientificDivisions::deleteTarget(std::string &name_, std::string &name_Divisons) {
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

void print_target(std::string &name_, std::string &name_Divisons) {
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
DbScientificDivisions::insertField(const std::string &field, const std::string &field_name, std::string &name_,
                                   std::string &name_Division) {
    std::string *lines = nullptr;
    GetStringsFromFileS(name_, &lines);
    int count = CountLinesInFile(name_);
    if (field == "Manager") {
        std::string change_string = "FIO of manager : " + field_name;
        for (size_t i = 0; i < databaseSD[name_].size(); ++i)//13 all string in 1 base
        {
            if (databaseSD[name_][i].GetName() == name_Division) {
                databaseSD[name_][i].SetManager(field_name);
            }

        }
        for (size_t i = 0; i < count; ++i)//13 all string in 1 base
        {
            if (lines[i].find(name_Division) == 0) {
                ChangeStringInFileC(name_, i + 1, change_string);
            }
        }
    }
    if (field == "Graduated Students") {
        std::string change_string = "Number of graduated students is : " + field_name;
        for (size_t i = 0; i < databaseSD[name_].size(); ++i)//13 all string in 1 base
        {
            if (databaseSD[name_][i].GetName() == name_Division) {
                databaseSD[name_][i].SetGraduate_students(std::stoi(field_name));
            }

        }
        for (size_t i = 0; i < count; ++i)//13 all string in 1 base
        {
            if (lines[i].find(name_Division) == 0) {
                ChangeStringInFileC(name_, i + 2, change_string);
            }
        }
    }
    if (field == "Staff") {
        std::string change_string = "Number of staff : " + field_name;
        for (size_t i = 0; i < databaseSD[name_].size(); ++i)//13 all string in 1 base
        {
            if (databaseSD[name_][i].GetName() == name_Division) {
                databaseSD[name_][i].SetStaff(std::stoi(field_name));
            }

        }
        for (size_t i = 0; i < count; ++i)//13 all string in 1 base
        {
            if (lines[i].find(name_Division) == 0) {
                ChangeStringInFileC(name_, i + 3, change_string);
            }
        }
    }
}

void DbScientificDivisions::InsertCourse(const std::string &Field_change, const std::string &new_field,
                                         std::string &name_, std::string &name_Division){
    std::string *lines = nullptr;
    GetStringsFromFileS(name_, &lines);
    int count = CountLinesInFile(name_);
    if (Field_change == "Name") {
        std::string change_string = "Name of project : " + new_field;
        for (size_t i = 0; i < databaseSD[name_].size(); ++i)//13 all string in 1 base
        {
            for (size_t k = 0; k < databaseSD[name_][i].GetProject().size(); ++k) {
                if (databaseSD[name_][i].GetName() == name_Division) {
                    databaseSD[name_][i].GetProject()[k].name = new_field;
                }
            }

        }
        deleteDB(name_);
        createDB(name_, databaseSD);
    }
    if (Field_change == "Cost") {
        std::string change_string = "Cost of project : " + new_field;
        for (size_t i = 0; i < databaseSD[name_].size(); ++i)//13 all string in 1 base
        {
            for (size_t k = 0; k < databaseSD[name_][i].GetProject().size(); ++k) {
                if (databaseSD[name_][i].GetName() == name_Division) {
                    databaseSD[name_][i].GetProject()[k].cost = std::stoi(new_field);
                }
            }

        }
        deleteDB(name_);
        createDB(name_, databaseSD);
    }
}

void DbScientificDivisions::print_target(std::string &name_, std::string &name_Divisons) {
    int number;
    int count = CountLinesInFile(name_);
    std::string *lines = nullptr;
    GetStringsFromFileS(name_, &lines);
    int kar;
    for (size_t i = 0; i < databaseSD.size(); ++i)//13 all string in 1 base
    {
        if (databaseSD[name_][i].GetName() == name_Divisons) {
            number = databaseSD[name_][i].GetProject().size();

            for (size_t i = 0; i < count; ++i)//13 all string in 1 base
            {
                if (lines[i].find(name_Divisons) == 0) {
                    kar = i;
                    for (size_t k = kar; k < kar + (number * 2) + 6; ++k) {
                        std::cout << lines[k];
                    }

                }
            }
        }
    }
}

int DbScientificDivisions::Calculationfunction(std::string &name_, std::string &name_DB) {
    int cost_projects = 0;
    for (size_t i = 0; i < databaseSD[name_].size(); ++i)//13 all string in 1 base
    {
        if (databaseSD[name_][i].GetName() == name_DB) {
            for (size_t k = 0; i < databaseSD[name_][k].GetProject().size(); ++k)
                cost_projects += databaseSD[name_][i].GetProject()[k].cost;
        }

    }
    return cost_projects;
}

std::string &DbScientificDivisions::FindFIO(std::string &name_, std::string &FIO) {
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

bool CompareName(class ScientificDivisions &lhs, class ScientificDivisions &rhs) {
    return lhs.GetName() < rhs.GetName();
}

bool CompareNumber(class ScientificDivisions &lhs, class ScientificDivisions &rhs) {
    return lhs.GetStaff() < rhs.GetStaff();
}

void DbScientificDivisions::SortName(std::string &name_) {
    std::string *lines = nullptr;
    int count = CountLinesInFile(name_);
    GetStringsFromFileS(name_, &lines);
    //19
    std::sort(databaseSD[name_].begin(), databaseSD[name_].end(), CompareName);
    deleteDB(name_);
    createDB(name_, databaseSD);


}

void DbScientificDivisions::SortStuff(std::string &name_) {
    std::string *lines = nullptr;
    int count = CountLinesInFile(name_);
    GetStringsFromFileS(name_, &lines);
    //19
    std::sort(databaseSD[name_].begin(), databaseSD[name_].end(), CompareNumber);
    deleteDB(name_);
    createDB(name_, databaseSD);
}

void DbScientificDivisions::SelectionStuff(std::string &name_, size_t number) {
    for (size_t i = 0; i < databaseSD[name_].size(); ++i)//13 all string in 1 base
    {
        if (databaseSD[name_][i].GetStaff() > number) {
            print_target(name_, databaseSD[name_][i].GetName());
        }
    }
}

void DbScientificDivisions::SelectionIncome(std::string &name_, size_t number) {
    for (size_t i = 0; i < databaseSD[name_].size(); ++i) {
        double income = Calculationfunction(name_, databaseSD[name_][i].GetName()) / databaseSD[name_][i].GetStaff();
        if (income <= number) {
            print_target(name_, databaseSD[name_][i].GetName());
        }
    }
}