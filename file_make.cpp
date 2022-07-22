#include "file_make.h"
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include <ctime>

File_make::File_make(std::string a, std::string b, std::string c, std::string d)
    :file_for_work(a)
    ,metka(b)
    ,information_save(c)
    ,information_load(d)
{

}

File_make::~File_make()
{

}

void File_make::creat_work_file()  // открытие рабочего файла
{
    std::ofstream file_open ("C://study/file_work/root.all");
    file_open.close();
}

void File_make::reading_root()
{
    std::ifstream root_file("C://study/file_work/root.all");
    std::string long_string;
    root_text.erase();
    char c;
    while (!root_file.eof())
    {
        root_file.get(c);
        long_string.push_back(c);
    }
    root_file.close();
    root_text = long_string;

}

void File_make::copy_file()  // копирует содержимое файла в рут
{
    std::fstream root_file("C://study/file_work/root.all");
    std::string long_string;

    std::ifstream working_file(file_for_work);

    char c;
    std::string copy_text_file;
    while (!working_file.eof())
    {
        working_file.get(c);
        copy_text_file.push_back(c);
    }
    working_file.close();

    long_string = metka;
    long_string += " ";
    long_string += information_save;
    long_string += " ";
    long_string += copy_text_file;
    long_string += " ";
    long_string += metka;

    std::cout << "Copy: " << long_string << std::endl;

    root_file << long_string;
    root_file.close();
}

void File_make::copy_info_file()
{
    reading_root();

    std::fstream working_file(file_for_work);

    int step;
    int place = root_text.find(metka);

    std::cout << "place = " << place << std::endl;
    std::cout << "sizeof - " << information_save.size() << std::endl;

    step = place + information_save.size() + 2;

    std::cout << "step = " << step << std::endl;
    std::cout << "sizeof = " << metka.size() << std::endl;

    root_text.erase(place, metka.size());
    int place2 = root_text.find(metka);

    std::cout << "place2 = " << place2 << std::endl;
    std::cout << "new root: " << root_text << std::endl;

    for (step; step!=place2; ++step)
    {
        working_file << root_text[step];
    }

    root_text.erase(place, place2 + metka.size());
    working_file.close();

    std::cout << "new root: " << root_text << std::endl;

    std::fstream file_root("C://study/file_work/root.all");
    file_root.clear();
    file_root << root_text;
    file_root.close();
}

void File_make::creat_file() // создание нового файла
{
    std::ofstream creating_file(file_for_work);
    creating_file.close();

    std::fstream working_file("C://study/file_work/root.all");

    std::string long_string;
    long_string = metka;
    long_string += " ";
    long_string += information_save;
    long_string += " ";

    working_file << long_string;

    working_file.close();

}

void File_make::delete_file()
{
    std::filesystem::remove(file_for_work);
}

void File_make::write_to_file()
{
    std::fstream working_file(file_for_work);
    working_file << information_save;
    working_file.close();
}

void File_make::read_file()
{
    copy_file();
    reading_root();

    int step;
    int place = root_text.find(metka);
    step = place + information_save.size() + 2;

    root_text.erase(place, metka.size());
    int place2 = root_text.find(metka);

    for (step; step!=place2; ++step)
    {
        std::cin >> root_text[step];
    }

    root_text.erase(place, place2 + metka.size());

    std::fstream file_root("C://study/file_work/root.all");
    file_root.clear();
    file_root << root_text;
    file_root.close();

}
