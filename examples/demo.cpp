#include "educational_divisions.h"
#include "Divisions.h"
#include "DBeducational_divisions.h"
#include "Intruction.h"
#include <map>
#include "dop_function.h"
int main() {
    help();
    std::string command;
    std::string openDB;
    DBHybrid dbHybrid;
    DBOverallPlan dbOverallPlan;
    DBIndividualPlan dbIndividualPlan;

    while (true){
        std::vector<std::string> wordsVector;
        std::getline(std::cin, command, '\n');
        getWords(command, wordsVector);

        try{
            if (wordsVector.at(0) == "PRINT_DIS"){
                for (auto &semester : studentSpace::disciplinesAll){
                    std::cout << "Семестер: " << semester.second << " название: " << semester.first << '\n';
                }
            }

            else if (wordsVector.at(0) == "CREATE_DB"){
                if (wordsVector.at(1) == "Individual"){
                    dbIndividualPlan.createDB(wordsVector.at(2) , studentSpace::disciplines);
                }
                else if (wordsVector.at(1) == "Overall"){
                    dbOverallPlan.createDB(wordsVector.at(2), studentSpace::disciplinesAll);
                }
                else if (wordsVector.at(1) == "Hybrid"){
                    dbHybrid.createDB(wordsVector.at(2), studentSpace::disciplinesAll);
                }
                else{
                    std::cout << "Неверный ввод команды попробуйте еще раз" << '\n';
                }
            }

            else if (wordsVector.at(0)  == "PRINT_DB"){
                if (wordsVector.at(1) == "Individual"){
                    dbIndividualPlan.printBD();
                }
                else if (wordsVector.at(1) == "Overall"){
                    dbOverallPlan.printBD();
                }
                else if (wordsVector.at(1) == "Hybrid"){
                    dbHybrid.printBD();
                }
                else{
                    std::cout << "Неверный ввод команды попробуйте еще раз" << '\n';
                }
            }

            else if (wordsVector.at(0) == "DELETE_DB"){
                if (wordsVector.at(1) == "Individual"){
                    dbIndividualPlan.deleteDB(wordsVector.at(2));
                }
                else if (wordsVector.at(1)== "Overall"){
                    dbOverallPlan.deleteDB(wordsVector.at(2));
                }
                else if (wordsVector.at(1)== "Hybrid"){
                    dbHybrid.deleteDB(wordsVector.at(2));
                }
                else{
                    std::cout << "Неверный ввод команды попробуйте еще раз" << '\n';
                }
            }

            else if (wordsVector.at(0)  == "RENAME"){
                if (wordsVector.at(1) == "Individual"){
                    dbIndividualPlan.renameDB(wordsVector.at(2), wordsVector.at(3));
                }
                else if (wordsVector.at(1)== "Overall"){
                    dbOverallPlan.renameDB(wordsVector.at(2), wordsVector.at(3));
                }
                else if (wordsVector.at(1)== "Hybrid"){
                    dbHybrid.renameDB(wordsVector.at(2), wordsVector.at(3));
                }
                else{
                    std::cout << "Неверный ввод команды попробуйте еще раз" << '\n';
                }
            }

            else if (wordsVector.at(0)  == "OPEN"){
                if (wordsVector.at(1) == "Individual"){
                    dbIndividualPlan.open(wordsVector.at(2));
                    openDB = "Individual";
                }
                else if (wordsVector.at(1)== "Overall"){
                    dbOverallPlan.open(wordsVector.at(2));
                    openDB = "Overall";
                }
                else if (wordsVector.at(1)== "Hybrid"){
                    dbHybrid.open(wordsVector.at(2));
                    openDB = "Hybrid";
                }
                else{
                    std::cout << "Неверный ввод команды попробуйте еще раз" << '\n';
                }
            }

            else if (wordsVector.at(0)  == "CLOSE"){
                if (openDB == "Individual") {
                    dbIndividualPlan.close();
                }
                else if (openDB == "Overall"){
                    dbOverallPlan.close();
                }
                else if (openDB == "Hybrid"){
                    dbHybrid.close();
                }
                openDB = "";
            }

            else if (wordsVector.at(0)  == "INSERT"){
                if (openDB == "Individual" || openDB == "Hybrid" && wordsVector.at(1) == "Individual") {
                    if (openDB == "Individual"){
                        dbIndividualPlan.insert(getIndividual());
                    }
                    else{
                        dbHybrid.insertIndividual(getIndividual());
                    }

                }
                else if (openDB == "Overall" || openDB == "Hybrid" && wordsVector.at(1) == "Overall"){
                    if (openDB == "Overall"){
                        dbOverallPlan.insert(getOverall());
                    }
                    else {
                        dbHybrid.insertOverall(getOverall());
                    }
                }
                else{
                    std::cout << "Неверный ввод команды попробуйте еще раз" << '\n';
                }
            }

            else if (wordsVector.at(0)  == "UPDATE") {
                if (openDB == "Individual" || openDB == "Hybrid" && wordsVector.at(1) == "Individual") {
                    if (openDB == "Individual") {
                        dbIndividualPlan.editRecords(wordsVector.at(2), getIndividual());
                    } else {
                        dbHybrid.editIndividual(wordsVector.at(3), getIndividual());
                    }

                }
                else if (openDB == "Overall" || openDB == "Hybrid" && wordsVector.at(1) == "Overall") {
                    if (openDB == "Overall") {
                        dbOverallPlan.editRecords(wordsVector.at(2), getOverall());
                    } else {
                        dbHybrid.editOverall(wordsVector.at(3), getOverall());
                    }
                }
                else {
                    std::cout << "Неверный ввод команды попробуйте еще раз" << '\n';
                }
            }

            else if (wordsVector.at(0)  == "DELETE_WHERE"){
                if (openDB == "Individual") {
                    dbIndividualPlan.deleteRecord(wordsVector.at(1));
                }
                else if (openDB == "Overall"){
                    dbOverallPlan.deleteRecord(wordsVector.at(1));
                }
                else if (openDB == "Hybrid"){
                    dbHybrid.deleteRecord(wordsVector.at(1));
                }
            }

            else if (wordsVector.at(0)  == "PRINT_RECORDS"){
                if (openDB == "Individual") {
                    dbIndividualPlan.printRecords();
                }
                else if (openDB == "Overall"){
                    dbOverallPlan.printRecords();
                }
                else if (openDB == "Hybrid"){
                    dbHybrid.printRecords();
                }
            }

            else if (wordsVector.at(0)  == "SORT") {
                if (openDB == "Individual") {
                    if (wordsVector.at(1) == "SEMESTER") {
                        if (wordsVector.at(2) == ">") {
                            dbIndividualPlan.sort([](IndividualPlan a, IndividualPlan b) {
                                return a.GetSemester() > b.GetSemester();
                            });
                        } else if (wordsVector.at(2) == "<") {
                            dbIndividualPlan.sort([](IndividualPlan a, IndividualPlan b) {
                                return a.GetSemester() < b.GetSemester();
                            });
                        }
                    } else if (wordsVector.at(1) == "NAME") {
                        if (wordsVector.at(2) == ">") {
                            dbIndividualPlan.sort([](IndividualPlan a, IndividualPlan b) {
                                return a.GetName() > b.GetName();
                            });
                        } else if (wordsVector.at(2) == "<") {
                            dbIndividualPlan.sort([](IndividualPlan a, IndividualPlan b) {
                                return a.GetName() < b.GetName();
                            });
                        }
                    }
                }
                else if (openDB == "Overall") {
                    if (wordsVector.at(1) == "SEMESTER") {
                        if (wordsVector.at(2) == ">") {
                            dbOverallPlan.sort([](OverallPlan a, OverallPlan b) {
                                return a.GetSemester() > b.GetSemester();
                            });
                        } else if (wordsVector.at(2) == "<") {
                            dbOverallPlan.sort([](OverallPlan a, OverallPlan b) {
                                return a.GetSemester() < b.GetSemester();
                            });
                        }
                    } else if (wordsVector.at(1) == "NAME") {
                        if (wordsVector.at(2) == ">") {
                            dbOverallPlan.sort([](OverallPlan a, OverallPlan b) {
                                return a.GetName() > b.GetName();
                            });
                        } else if (wordsVector.at(2) == "<") {
                            dbOverallPlan.sort([](OverallPlan a, OverallPlan b) {
                                return a.GetName() < b.GetName();
                            });
                        }
                    }
                }
                else if (openDB == "Hybrid") {
                    if (wordsVector.at(1) == "SEMESTER") {
                        if (wordsVector.at(2) == ">") {
                            dbHybrid.sortOverall([](OverallPlan a, OverallPlan b) {
                                return a.GetSemester() > b.GetSemester();
                            });
                            dbHybrid.sortIndividual([](IndividualPlan a, IndividualPlan b) {
                                return a.GetSemester() > b.GetSemester();
                            });
                        } else if (wordsVector.at(2) == "<") {
                            dbHybrid.sortOverall([](OverallPlan a, OverallPlan b) {
                                return a.GetSemester() < b.GetSemester();
                            });
                            dbHybrid.sortIndividual([](IndividualPlan a, IndividualPlan b) {
                                return a.GetSemester() < b.GetSemester();
                            });
                        }
                    } else if (wordsVector.at(1) == "NAME") {
                        if (wordsVector.at(2) == ">") {
                            dbHybrid.sortOverall([](OverallPlan a, OverallPlan b) {
                                return a.GetName() > b.GetName();
                            });
                            dbHybrid.sortIndividual([](IndividualPlan a, IndividualPlan b) {
                                return a.GetName() > b.GetName();
                            });
                        } else if (wordsVector.at(2) == "<") {
                            dbHybrid.sortOverall([](OverallPlan a, OverallPlan b) {
                                return a.GetName() < b.GetName();
                            });
                            dbHybrid.sortIndividual([](IndividualPlan a, IndividualPlan b) {
                                return a.GetName() < b.GetName();
                            });
                        }
                    }
                }
            }

            else if (wordsVector.at(0)  == "SELECT_AND_SAVE"){
                if (openDB == "Individual") {
                    if (wordsVector.at(1) == "SEMESTER") {
                        size_t num;
                        std::vector<IndividualPlan> students;

                        std::cout << "Введите номер семестра,по которому хотите совершить выборку\n";
                        std::cin >> num;
                        std::cin.ignore();
                        students = dbIndividualPlan.selectBySem(num);

                        dbIndividualPlan.createDB(wordsVector.at(3), studentSpace::disciplines);
                        dbIndividualPlan.open(wordsVector.at(3));

                        for (auto &student : students){
                            dbIndividualPlan.insert(student);
                        }
                    }
                    else if (wordsVector.at(1) == "DISCIPLINE") {
                        std::string name;
                        std::vector<IndividualPlan> students;

                        std::cout << "Введите название дисциплины, по которой осуществляется выборка\n";
                        std::getline(std::cin, name, '\n');
                        students = dbIndividualPlan.selectByDis(name);

                        dbIndividualPlan.createDB(wordsVector.at(3), studentSpace::disciplines);
                        dbIndividualPlan.open(wordsVector.at(3));

                        for (auto &student : students){
                            dbIndividualPlan.insert(student);
                        }
                    }
                }
                else if (openDB == "Overall"){
                    if (wordsVector.at(1) == "SEMESTER") {
                        size_t num;
                        std::vector<OverallPlan> students;

                        std::cout << "Введите номер семестра,по которому хотите совершить выборку\n";
                        std::cin >> num;
                        std::cin.ignore();
                        students = dbOverallPlan.selectBySem(num);

                        dbOverallPlan.createDB(wordsVector.at(3), studentSpace::disciplinesAll);
                        dbOverallPlan.open(wordsVector.at(3));

                        for (auto &student : students){
                            dbOverallPlan.insert(student);
                        }
                    }
                    else if (wordsVector.at(1) == "DISCIPLINE") {
                        std::string name;
                        std::vector<OverallPlan> students;

                        std::cout << "Введите название дисциплины, по которой осуществляется выборка\n";
                        std::getline(std::cin, name, '\n');
                        students = dbOverallPlan.selectByDis(name);

                        dbOverallPlan.createDB(wordsVector.at(3), studentSpace::disciplinesAll);
                        dbOverallPlan.open(wordsVector.at(3));

                        for (auto &student : students){
                            dbOverallPlan.insert(student);
                        }
                    }
                }
                else if (openDB == "Hybrid"){
                    if (wordsVector.at(1) == "SEMESTER") {
                        size_t num;
                        std::pair<std::vector<OverallPlan>, std::vector<IndividualPlan>> students;

                        std::cout << "Введите номер семестра,по которому хотите совершить выборку\n";
                        std::cin >> num;
                        std::cin.ignore();
                        students = dbHybrid.selectBySem(num);

                        dbHybrid.createDB(wordsVector.at(3), studentSpace::disciplinesAll);
                        dbHybrid.open(wordsVector.at(3));

                        for (auto &student : students.first){
                            dbHybrid.insertOverall(student);
                        }
                        for (auto &student : students.second){
                            dbHybrid.insertIndividual(student);
                        }
                    }
                    else if (wordsVector.at(1) == "DISCIPLINE") {
                        std::string name;
                        std::pair<std::vector<OverallPlan>, std::vector<IndividualPlan>> students;

                        std::cout << "Введите название дисциплины, по которой осуществляется выборка\n";
                        std::getline(std::cin, name, '\n');
                        students = dbHybrid.selectByDis(name);

                        dbHybrid.createDB(wordsVector.at(3), studentSpace::disciplinesAll);
                        dbHybrid.open(wordsVector.at(3));

                        for (auto &student : students.first){
                            dbHybrid.insertOverall(student);
                        }
                        for (auto &student : students.second){
                            dbHybrid.insertIndividual(student);
                        }
                    }
                }
            }

            else if (wordsVector.at(0)  == "QUIT"){
                break;
            }

            else{
                std::cout << "Неверный ввод команды попробуйте еще раз" << '\n';
            }
        }
        catch (std::out_of_range){
            std::cout << "Неверный ввод команды попробуйте еще раз" << '\n';
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
}