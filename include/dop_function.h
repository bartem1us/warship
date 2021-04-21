//
// Created by bartem1us on 18.04.2021.
//
#include <iostream>
#include <string>
#include <fstream>

#ifndef DZ_DOP_FUNCTION_H
#define DZ_DOP_FUNCTION_H

int CountLinesInFile(std::string &name_);

int GetStringsFromFileS(std::string name_, std::string **_lines);

bool SetStringsToFileS(std::string name_, std::string *lines, int count);

bool RemoveStringFromFileByIndex(std::string &name_, int position);

bool ChangeStringInFileC(std::string name_, int position, std::string str);

int GetStringsFromFileC(std::string name_, char ***_lines = nullptr);

bool SwapStringsInFile(std::string &name_, int pos1, int pos2);

#endif //DZ_DOP_FUNCTION_H
