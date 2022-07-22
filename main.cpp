#include <iostream>
#include <menu.h>
#include <file_make.h>


using namespace std;

int main()
{
    File_make files("a", "b", "c", "d");
    files.creat_work_file();

    Menu start;
    start.recognize_menu();

    return 0;
}
