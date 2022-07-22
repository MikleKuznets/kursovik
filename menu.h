#ifndef MENU_H
#define MENU_H
#include <string>
#include <iostream>

class Menu
{
public:
    Menu();
    ~Menu();

    void main_menu(); // основное меню
    void recognize_menu(); // определение, какое меню вызвать
    void creat_menu(); // меню создания файла
    void creat_menu_file(); //создает файл в пути по умолчанию
    void creat_menu_wayknow_file(); // создает файл в папке по умолчанию
    void creat_menu_anotherway_file(); // создает файл в другом месте
    void menu_delete_file(); // удаляет файл
    void menu_rename_file(); // переименование файла
    void menu_remove_file(); // перемещение файла
    void menu_write_to_file(); // меню для записи в файл
    void menu_read_file(); // меню для чтения файла


private:

    int first_menu_choise = 0;  // переменная для перемещения внутри меню
    int creat_menu_choise = 0;  // переменная не уверен для чего (возможно перемещение другого меню)
    std::string file_way = "C://study/file_work/";       // переменная пути (где работаем с файлом)
    std::string file_name;      // переменная имени файла
    std::string file_type;      // переменная расширения файла
    std::string file_hole_name; // полное название пути и имени файла

    std::string metka;          // метка, для занесения в рут
    std::string information_in; // информация для внесения
    std::string information_out;// информация, которая нужна
};

#endif // MENU_H
