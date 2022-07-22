#ifndef FILE_MAKE_H
#define FILE_MAKE_H
#include <string>


class File_make
{
public:
    File_make(std::string a, std::string b, std::string c, std::string d); // a - путь к файлу, b - метка, c - информация для чтения, d - информация для записи
    ~File_make();

    void creat_work_file();  // - создание рабочего файла
    void reading_root();    // считываем информацию основного файла
    void creat_file();  // создание файла
    void delete_file();  // удаляет файл
    void copy_file();    // копирует содержимое файла
    void copy_info_file(); // копирует содержимое в новый файл
    void write_to_file();  // пишет в файл
    void read_file();    // чтение файла

private:
    std::string file_for_work;      // файл, с которым работаем
    std::string metka;              // метка для рута
    std::string information_save;   // информация для внесения
    std::string information_load;   // информация для считывания
    std::string root_text;          // содержимое рута
};

#endif // FILE_MAKE_H
