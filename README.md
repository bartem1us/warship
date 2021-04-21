# Task
СУБД – система управления базами данных.
БД – совокупность объектов класса.
Запись БД – объект класса.
Однотипные БД – БД, содержащие объекты одного класса.
Гибридные БД – БД, содержащие объекты разных классов.
Через интерфейс СУБД == через взаимодействие с пользователем (с помощью ввода команды с клавиатуры).
Задание:
1. Реализовать абстрактный класс, содержащий чистые виртуальные функции,
   функционал которых различается для наследников, в соответствии с вариантом и
   заданной им организацией данных (группировкой).
2. Реализовать разбор текстовых команд, введённых с клавиатуры.
3. Разработать формат сохранения БД в файл.
4. Реализовать функции в соответствии с вариантом.
5. Реализовать управление базами данных через интерфейс СУБД:
   
   5.1) Создание однотипных БД и гибридных БД.
   
   5.2) Вывод на экран* списка существующих БД.
   
   5.3) Удаление* БД.
   
   5.4) Переименование* БД.
   
   5.5) Открытие** БД.
   
   5.6) Сохранение** БД.

   5.7) Добавление записей в БД.
   
   5.8) Редактирование записей в БД.
   
   5.9) Удаление записей в БД.
   
   5.10) Вывод на экран записей БД.
   
   5.11) Сортировка записей БД.
   
   5.12) Выборка записей БД по правилу (значению поля).
   
   5.13) Сохранение** выборки как новой БД.

# Вариант №21.
БД – совокупность подразделений (организация). Класс 1 – образовательные подразделения. Класс 2 – научные
подразделения. Каждое подразделение имеет название, руководителя (ФИО), число аспирантов, число
сотрудников. У научных подразделений указаны проекты (название, стоимость). У образовательных
подразделений указано число студентов и стоимость обучения одного студента, сгруппированные по курсам.

##Функции (п. 4):
 Подсчёт дохода для подразделения.

 Поиск подразделения внутри БД по ФИО.

###Правила сортировки записей БД (п. 5.11):
 По названию подразделения (по алфавиту).

 По числу сотрудников.

###Правила выборки записей из БД (п. 5.12):
 Подразделения, где число сотрудников превышает number (number задаётся с клавиатуры).
 Подразделения, доход которых на 1 сотрудника не превышает n (n задаётся с клавиатуры).

[![Build Status](https://travis-ci.org/bartem1us/RK1_TIMP.svg?branch=master)](https://travis-ci.org/bartem1us/RK1_TIMP)