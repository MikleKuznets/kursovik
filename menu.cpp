#include "menu.h"
#include <iostream>
#include <conio.h>
#include <file_make.h>

Menu::Menu()
{

}

Menu::~Menu()
{


}

void Menu::recognize_menu()
{
    if (first_menu_choise == 0)
            main_menu();
    if (first_menu_choise == 1)
            creat_menu();
    if (first_menu_choise == 2)
            menu_delete_file();
    if (first_menu_choise == 3)
            menu_read_file();
    if (first_menu_choise == 4)
            menu_write_to_file();
    if (first_menu_choise == 5)
            menu_rename_file();
    if (first_menu_choise == 6)
            menu_remove_file();
    if (first_menu_choise == 7)
            main_menu();

}

void Menu::main_menu()
{
    system ("cls");
    std::cout << "(C)reat a file" << std::endl;
    std::cout << "(D)elete a file" << std::endl;
    std::cout << "(R)ead a file" << std::endl;
    std::cout << "(W)rite to a file" << std::endl;
    std::cout << "R(e)name a file" << std::endl;
    std::cout << "Re(m)ove a file" << std::endl;
    std::cout << "M(a)ke hosts to system" << std::endl;
    std::cout << "(Q)uit" << std::endl;

    while (first_menu_choise == 0)
    {
        char press = getch();

        if ((press == 'c')||(press == 'C'))
                first_menu_choise = 1;
        if ((press == 'd')||(press == 'D'))
                first_menu_choise = 2;
        if ((press == 'r')||(press == 'R'))
                first_menu_choise = 3;
        if ((press == 'w')||(press == 'W'))
                first_menu_choise = 4;
        if ((press == 'e')||(press == 'E'))
                first_menu_choise = 5;
        if ((press == 'm')||(press == 'M'))
                first_menu_choise = 6;
        if ((press == 'a')||(press == 'A'))
                first_menu_choise = 7;
        if ((press == 'q')||(press == 'Q'))
                exit;
    }

    recognize_menu();

}

void Menu::creat_menu()
{
    system ("cls");
    std::cout << "(C)reat a file in this way" << std::endl;
    std::cout << "C(r)eat a file in anothe way" << std::endl;
    std::cout << "(B)ack menu" << std::endl;
    std::cout << "(Q)uit" << std::endl;

    while (creat_menu_choise == 0)
    {
        char press = getch();

        if ((press == 'c')||(press == 'C'))
        {
            creat_menu_choise = 1;
            creat_menu_wayknow_file();
        }
        if ((press == 'r')||(press == 'R'))
        {
            creat_menu_choise = 2;
            creat_menu_anotherway_file();
        }
        if ((press == 'b')||(press == 'B'))
        {
            creat_menu_choise = 0;
            first_menu_choise = 0;
            recognize_menu();
        }
        if ((press == 'Q')||(press == 'q'))
                exit;
    }
}

void Menu::creat_menu_wayknow_file()
{

    system ("cls");
    std::cout << "\n Enter file name: ";
    std::cin >> file_name;
    std::cout << "\n Enter file type: ";
    std::cin >> file_type;

    file_hole_name = file_way;
    file_hole_name += file_name;
    file_hole_name += ".";
    file_hole_name += file_type;

    metka = "newfile";
    information_in = file_name;
    information_in += ".";
    information_in += file_type;

    File_make file_work(file_hole_name, metka, information_in, information_out);
    file_work.creat_file();

    std::cout << "\n File created: " << file_hole_name << std::endl;

    std::cout << "\n Press any key to continue" << std::endl;
    char pause = getch();

    first_menu_choise = 0;
    recognize_menu();
}

void Menu::creat_menu_anotherway_file()
{
    system ("cls");
    
    std::cout << "Now way - " << std::endl;
    std::cout << file_way << std::endl;
    std::cout << "(R)eturn fold" << std::endl;
    std::cout << "(O)pen fold" << std::endl;
    std::cout << "(L)ist direction" << std::endl;
    
    while(true)
    {
        char press = getch();
        if ((press == 'R')||(press == 'r'))
            ;
        if ((press == 'O')||(press == 'o'))
            ;
        if ((press == 'L')||(press == 'l'))
            ;
    }       
    
}

void Menu::menu_delete_file()
{
    system ("cls");
    std::cout << "\n Enter file name for delete: ";
    std::cin >> file_name;
    std::cout << "\n Enter file type: ";
    std::cin >> file_type;

    file_hole_name = file_way;
    file_hole_name += file_name;
    file_hole_name += ".";
    file_hole_name += file_type;

    metka = "oldfile";
    information_in = file_name;
    information_in += ".";
    information_in += file_type;

    File_make file_work(file_hole_name, metka, information_in, information_out);
    file_work.delete_file();

    std::cout << "\n File deleted: " << file_hole_name << std::endl;

    std::cout << "\n Press any key to continue" << std::endl;
    char pause = getch();

    first_menu_choise = 0;
    recognize_menu();

}

void Menu::menu_rename_file()
{
    system ("cls");

    std::cout << "\n Name of file for rename: ";
    std::cin >> file_name;
    std::cout << "\n Enter file type: ";
    std::cin >> file_type;

    file_hole_name = file_way;

    metka = "cf";
    information_in = file_name;
    information_in += ".";
    information_in += file_type;

    file_hole_name += information_in;

    File_make rename_file(file_hole_name, metka, information_in, information_out);
    rename_file.copy_file();
    rename_file.delete_file();

    std::cout << "\n New name of file: ";
    std::cin >> file_name;
    std::cout << "\n Enter file type: ";
    std::cin >> file_type;

    file_hole_name = file_way;

    metka = "cf";
    information_in = file_name;
    information_in += ".";
    information_in += file_type;

    file_hole_name += information_in;

    File_make rename_file2(file_hole_name, metka, information_in, information_out);
    rename_file2.creat_file();
    rename_file2.copy_info_file();

    std::cout << "\n File renamed: " << file_hole_name << std::endl;

    std::cout << "\n Press any key to continue" << std::endl;
    char pause = getch();

    first_menu_choise = 0;
    recognize_menu();

}

void Menu::menu_remove_file()
{
    system ("cls");

    std::cout << "\n Name of file for remove: ";
    std::cin >> file_name;
    std::cout << "\n Enter file type: ";
    std::cin >> file_type;

    file_hole_name = file_way;

    metka = "rm";
    information_in = file_name;
    information_in += ".";
    information_in += file_type;

    file_hole_name += information_in;

    File_make remove_file(file_hole_name, metka, information_in, information_out);
    remove_file.copy_file();
    remove_file.delete_file();

    std::cout << "\n New way of file: ";
    std::cin >> file_way;

    file_hole_name = file_way;

    metka = "rm";
    information_in = file_name;
    information_in += ".";
    information_in += file_type;

    file_hole_name += information_in;

    File_make remove_file2(file_hole_name, metka, information_in, information_out);
    remove_file2.creat_file();
    remove_file2.copy_info_file();

    std::cout << "\n File removed: " << file_hole_name << std::endl;

    std::cout << "\n Press any key to continue" << std::endl;
    char pause = getch();

    first_menu_choise = 0;
    recognize_menu();

}

void Menu::menu_write_to_file()
{
    system ("cls");

    std::cout << "\n Name of file for write: ";
    std::cin >> file_name;
    std::cout << "\n Enter file type: ";
    std::cin >> file_type;

    file_hole_name = file_way;
    file_hole_name += file_name;
    file_hole_name += ".";
    file_hole_name += file_type;

    metka = "wr";

    std::cout << "\n What do you want to write? " << std::endl;
    std::cin >> information_in;

    File_make write_file(file_hole_name, metka, information_in, information_out);
    write_file.write_to_file();

    std::cout << "\n You wrote to file: " << information_in << std::endl;

    std::cout << "\n Press any key to continue" << std::endl;
    char pause = getch();

    first_menu_choise = 0;
    recognize_menu();

}

void Menu::menu_read_file()
{
    system ("cls");

    std::cout << "\n Name of file for read: ";
    std::cin >> file_name;
    std::cout << "\n Enter file type: ";
    std::cin >> file_type;

    file_hole_name = file_way;
    file_hole_name += file_name;
    file_hole_name += ".";
    file_hole_name += file_type;

    metka = "rd";

    File_make rename_file(file_hole_name, metka, information_in, information_out);
    rename_file.read_file();

    std::cout << "\n Press any key to continue" << std::endl;
    char pause = getch();

    first_menu_choise = 0;
    recognize_menu();
}
