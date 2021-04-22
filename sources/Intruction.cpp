// Copyright 2020 bartem1us <filkovghjynj@mail.ru>
#include "Intruction.h"

void help() {
    setlocale(LC_ALL, "Russian");
    std::cout << std::endl;
    std::cout << "--------Функции:--------" << std::endl;
    std::cout << "----Доступные функции:------------------------------------------------------------" << std::endl;
    std::cout << "----Печать data base - printDB----------------------------------------------------" << std::endl;
    std::cout << "----Создание БД - CreateDB--------------------------------------------------------" << std::endl;
    std::cout << "----Удаление БД - delete DB-------------------------------------------------------" << std::endl;
    std::cout << "----Переименование БД - rename DB-------------------------------------------------" << std::endl;
    std::cout << "----Открытие БД - Open------------------------------------------------------------" << std::endl;
    std::cout << "----Поиск по Фамилии Имени Отчеству - Find FIO------------------------------------" << std::endl;
    std::cout << "----Selection - Selection Staff or Selection Income-------------------------------" << std::endl;
    std::cout << "----Удаление записи в БД - delete target------------------------------------------" << std::endl;
    std::cout << "----Сортировка записей БД - Sort by Name or Sort by Staff-------------------------" << std::endl;
    std::cout<< "----Занесение в БД записей - Insert Project(for SD) or Insert Course(for ED)-------"<< std::endl;
    std::cout<< "----Занесение в БД записей - Insert target or Insert DB----------------------------"<< std::endl;
    std::cout << "----Завершение работы - quit------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}
