// Copyright 2020 bartem1us <filkovghjynj@mail.ru>
#include "Intruction.h"
void help()
{
        setlocale(LC_ALL, "Russian");
        std::cout << std::endl;
        std::cout << "--------Функции:--------" << std::endl;
        std::cout << "----Доступные функции:--------------------------------------------------------------" << std::endl;
        std::cout << "----Печать доступных предметов - print------------------------------------------" << std::endl;
        std::cout << "----Создание БД - createDB <type> <name>-------------------------------------" << std::endl;
        std::cout << "----Вывод на экран списка БД - printDB <typeDB>-----------------------------------" << std::endl;
        std::cout << "----Удаление БД - deleteDB <type> <name>----------------------------------------" << std::endl;
        std::cout << "----Переименование БД - rename <typeDB> <name> <new_name>--------------------------" << std::endl;
        std::cout << "----Открытие БД - open <typeBD> <name>---------------------------------------------" << std::endl;
        std::cout << "----Закрытие БД - close ------------------------------------------------------------" << std::endl;
        std::cout << "----Добавление записи в БД - insert <variable> (for Hybrid)-------------------------" << std::endl;
        std::cout << "----Редактирование записи в БД - update <variable> (for Hybrid) <name>----" << std::endl;
        std::cout << "----Удаление записи в БД - delete <name>--------------------------------------" << std::endl;
        std::cout << "----Вывод на экран записей БД - print_record --------------------------------------" << std::endl;
        std::cout << "----Сортировка записей БД - sort <parametr> <comparison>-------------------------------" << std::endl;
        std::cout << "----Сохранение выборки как новый БД - select_and_save <param> in <new name>---------" << std::endl;
        std::cout << "----Завершение работы - quit--------------------------------------------------------" << std::endl;
        std::cout << std::endl;
}
