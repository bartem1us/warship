//
// Created by bartem1us on 18.04.2021.
#include "dop_function.h"

// - _lines - список строк файла типа (string*).
// Функция возвращает общее количество прочитанных строк.
int CountLinesInFile(std::string &name_) {
    std::string filename =
            "/home/bartem1us/bartem1us/homework/DbEducationalDivisions/" + name_ + "/educational.txt";
    // 1. Объявить экземпляр F, который связан с файлом filename.
    // Файл открывается для чтения в текстовом формате.
    std::ifstream F(filename, std::ios::in);

    // 2. Проверка, существует ли файл
    if (!F) {
        return -1;
    }

    // 3. Вычислить количество строк в файле
    // 3.1. Объявить дополнительные переменные
    int count = 0;
    char buffer[1000]; // буфер для сохранения одной строки

    // 3.2. Цикл чтения строк.
    // Каждая строка файла читается функцией getline().
    // Проверка конца файла осуществляется функцией eof().
    while (!F.eof()) {
        // Увеличить счетчик строк
        count++;

        // Считать одну строку в буфер
        F.getline(buffer, 1000);
    }

    // 4. Закрыть файл F
    F.close();

    // 5. Вернуть результат
    return count;
}

int GetStringsFromFileS(std::string name_, std::string **_lines) {
    // 1. Дополнительные переменные
    std::string filename =
            "/home/bartem1us/bartem1us/homework/DbEducationalDivisions/" + name_ + "/educational.txt";
    // 1. Дополнительные переменные
    std::string* lines; // временный список строк
    int n = CountLinesInFile(name_); // Получить количество строк в файле

    // 2. Проверка, правильно ли прочитаны строки из файла
    if (n == -1) return -1;

    // 3. Объявить файловую переменную и открыть файл filename для чтения
    std::ifstream F(filename);

    // 4. Проверка, открыт ли файл
    if (!F) return -1;

    // 5. Попытка выделить память для n строк типа string
    try
    {
        lines = new std::string[n];
    }
    catch (std::bad_alloc e)
    {
        std::cout << e.what() << std::endl; // вывести сообщение об ошибке
        F.close();
        return -2; // возврат с кодом -2
    }

    // 6. Чтение строк из файла и запись строк в список lines
    char buffer[1000]; // буфер для чтения строки

    for (int i = 0; i < n; i++)
    {
        // 6.1. Прочитать строку из файла в буфер buffer
        F.getline(buffer, 1000);

        // 6.2. Вычислить длину прочитанной строки
        int len;
        for (len = 0; buffer[len] != '\0'; len++);

        // 6.3. Записать buffer => lines[i], использовать метод assign().
        // Скопировать len байт из buffer в lines[i].
        lines[i].assign(buffer, len);
    }

    // 7. Закрыть файл
    F.close();

    // 8. Вернуть результат
    *_lines = lines;
    return n;
}

// Функция, которая записывает массив строк типа string в текстовый файл.
// Параметры:
// - filename - имя файла;
// - lines - массив строк, которые записываются в файл;
// - count - количество строк.
// Функция возвращает true, если запись строк произошла успешно.
bool SetStringsToFileS(std::string name_, std::string *lines, int count) {
    // 1. Объявить дополнительные переменные
    std::string filename =
            "/home/bartem1us/bartem1us/homework/DbEducationalDivisions/" + name_ + "/educational.txt";
    std::ofstream F(filename); // открыть файл для записи

    // 2. Проверка, успешно ли открылся файл
    if (!F) return false;

    // 3. Запись строк в файл кроме последней строки
    for (int i = 0; i < count - 1; i++)
        F << lines[i] << std::endl;

    // 4. Последнюю строку записать как есть (без символа '\n')
    F << lines[count - 1];

    // 5. Закрыть файл
    F.close();

    // 6. Вернуть результат
    return true;
}

// Функция, удаляющая строку в файле по заданному номеру,
// номер строки начинается с 0.
// Параметры функции:
// - filename - имя файла, из которого удаляется строка;
// - position - номер строки в файле, которую нужно удалить.
// Если операция прошла успешно, функция возвращает true, если
// строка не удалена, функция возвращает false.
bool RemoveStringFromFileByIndex(std::string &name_, int position) {
    // 1. Проверка, правильно ли указана строка

    if (position < 0) return false;

    // 2. Дополнительные переменные
    std::string *lines; // список строк
    int n; // количество строк в списке (файле)

    // 3. Прочитать количество строк в файле
    n = CountLinesInFile(name_); // вызов функции из пункта 2

    // 4. Проверка, прочитался ли файл filename
    if (n == -1) return false;

    // 5. Проверка, корректно ли значение position
    if (position >= n) return false;

    // 6. Получить список строк lines типа string*
    n = GetStringsFromFileS(name_, &lines); // функция из пункта 4

    // 7. Удалить строку в позиции position
    for (int i = position; i < n - 1; i++)
        lines[i] = lines[i + 1];

    // 8. Уменьшить общее количество строк
    n--;

    // 9. Записать список в файл - использовать функцию SetStringsToFileS()
    bool res = SetStringsToFileS(name_, lines, n); // запись списка

    // 10. Освободить массив lines
    if (n > 0) delete[] lines;

    // 11. Вернуть результат
    return res;
}
int GetStringsFromFileC(std::string name_, char*** _lines)
{
    // 1. Дополнительные переменные
    _lines= nullptr;
    char** lines;
    int n = CountLinesInFile(name_); // получить количество строк в файле
    std::string filename =
            "/home/bartem1us/bartem1us/homework/DbEducationalDivisions/" + name_ + "/educational.txt";
    // 2. Проверка, известно ли количество строк
    if (n == -1) return -1;

    // 3. Объявить файловую переменную
    std::ifstream F(filename); // открыть файл для чтения

    // 4. Проверка, открылся ли файл
    if (!F) return -1;

    // 5. Попытка выделить память для n строк
    try
    {
        lines = new char* [n];
    }
    catch (std::bad_alloc e)
    {
        // если невозможно выделить память, то выход
        std::cout << e.what() << std::endl; // вывести сообщение об ошибке
        F.close(); // закрыть файл
        return -1;
    }

    // 6. Цикл чтения строк и выделения памяти для них
    int len; // длина одной строки
    char buffer[1000]; // память, куда записывается одна строка из файла

    for (int i = 0; i < n; i++)
    {
        // 6.1. Считать строку из файла
        F.getline(buffer, 1000);

        // 6.2. Определить длину прочитанной строки
        for (len = 0; buffer[len] != '\0'; len++);

        // 6.3. Выделить память для len+1 символов
        lines[i] = new char[len + 1];

        // 6.4. Скопировать данные из buffer в lines[i]
        for (int j = 0; j < len; j++)
            lines[i][j] = buffer[j];
        lines[i][len] = '\0'; // добавить символ конца строки
    }

    // 7. Закрыть файл
    F.close();

    // 8. Записать результат
    *_lines = lines;
    return n;
}
bool ChangeStringInFileC(std::string name_, int position, std::string str)
{
    // 1. Получить строки файла в виде списка
    char** lines; // список строк файла
    int count; // количество строк файла
    count = GetStringsFromFileC(name_, &lines); // получить список lines
    std::string filename =
            "/home/bartem1us/bartem1us/homework/DbEducationalDivisions/" + name_ + "/educational.txt";
    // 2. Проверка, корректно ли прочитан файл
    if (count < 0) return false;

    // 3. Проверка, корректна ли позиция 0 <= position < count
    if ((position < 0) || (position >= count)) return false;

    // 4. Запись строк lines в файл до позиции position
    std::ofstream F(filename); // открыть файл для записи

    // 5. Проверка, открылся ли файл корректно - функция is_open()
    if (!F.is_open()) return false;

    for (int i = 0; i < position; i++)
        F << lines[i] << std::endl; // вывести строку в файл

    // 6. Запись строки с позиции position
    F << str.c_str() << std::endl; // здесь пишется строка str

    // 7. Запись строк после позиции position
    for (int i = position + 1; i < count - 1; i++)
        F << lines[i] << std::endl;

    // 8. Записать последнюю строку без символа '\n'
    F << lines[count - 1];

    // 9. Закрыть файл
    F.close();

    // 10. Освободить память, выделенную для строк
    for (int i = 0; i < count; i++)
        delete lines[i];

    // 11. Освободить указатели на строки
    delete[] lines;
}
// Функция, которая меняет местами две строки в указанных позициях.
// Параметры:
// - filename - имя файла;
// - pos1 - позиция строки обмена 1 (нумеруется с 0);
// - pos2 - позиция строки обмена 2 (нумеруется с 0).
// Если обмен прошел успешно, то функция возвращает true. Иначе false.
bool SwapStringsInFile(std::string &name_, int pos1, int pos2)
{
    // 1. Проверка, корректны ли значения pos1, pos2
    if ((pos1 < 0) || (pos2 < 0)) return false;

    // 2. Объявить дополнительные переменные
    int count;
    std::string* lines = nullptr; // массив строк файла
    std::string s;

    // 3. Получить массив строк файла
    count = GetStringsFromFileS(name_, &lines); // функция из п.4

    // 4. Проверка, произошло ли успешно чтение из файла
    if (count < 0) return false;

    // 5. Проверка, лежат ли значения pos1, pos2 в пределах count
    if (pos1 >= count) return false;
    if (pos2 >= count) return false;

    // 6. Поменять местами строки lines[pos1] и lines[pos2]
    s = lines[pos1];
    lines[pos1] = lines[pos2];
    lines[pos2] = s;

    // 7. Записать массив lines обратно в файл
    bool res = SetStringsToFileS(name_, lines, count);

    // 8. Освободить память, выделенную для массива lines
    if (lines != nullptr)
        delete[] lines;

    // 9. Вернуть результат
    return res;
}
