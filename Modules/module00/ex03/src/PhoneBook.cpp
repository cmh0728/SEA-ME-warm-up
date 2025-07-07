#include "../include/PhoneBook.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

void PhoneBook::add(){
    file f;
    std::cout << "Input your name : ";
    std::cin.ignore(); 
    std::getline(std::cin, f.name);
    std::cout << "Input your number : ";
    std::getline(std::cin, f.number);
    std::cout << "Input your nickname : ";
    std::getline(std::cin, f.nickname);

    //전화번호 중복 체크(저장된게 있는지)
    bool flag = false ;
    for(int i = 0 ; i<PhoneBook::files.size();i++)
    {
        if(PhoneBook::files[i].number == f.number) 
        {
            flag = true ;
        }
    }

    if(flag == false)
    {
        PhoneBook::files.push_back(f); // 구조체를 객체 벡터에 저장 --> static이 아니라 이렇게 할 필요 없나?
        std::cout << "Saved sucessfully!\n";
    }
    else std::cout << "Number already exist! , save another number";
}

void PhoneBook::bookmark() {
    bool found = false; // 북마크 된게 있는지 확인 
    std::cout << "Bookmarked files:\n";

    for (int i = 0; i < files.size(); i++) {
        if (files[i].bookmarked) {
            std::cout << i << ": "
                      << files[i].name << " ("
                      << files[i].number << ") - "
                      << files[i].nickname << "\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "No bookmarked contacts.\n";
    }
}

void PhoneBook::search(){
    for(int i = 0 ; i<PhoneBook::files.size();i++)
    {
        std::cout << "\nidx : " << i << "\n name : " << files[i].name << "\n number :  " << files[i].number << "\n nickname : " << files[i].nickname << std::endl;
    }
    int idx ;
    std::cout << "Choose idx : " ;
    std::cin >> idx;

    int bk_num ;
    std::cout <<  "\nDo you want to bookmark?(yes : 1 , no : 2) : ";
    std::cin >> bk_num ;
    if(bk_num == 1 ) {
        files[idx].bookmarked = true ; 
        std::cout << "Bookmarkde sucessfully.\n";
    }
    else std::cout << "Not bookmarked.\n";

}

void PhoneBook::remove() {
    if (files.empty()) {
        std::cout << "No file to remove.\n";
        return;
    }

    std::cout << "Choose how to remove:\n";
    std::cout << "1. index\n";
    std::cout << "2. phone number\n";
    int choice;
    std::cin >> choice;

    if (choice == 1) { 
        for (int i = 0; i < files.size(); i++) {
            std::cout << i << ": " << files[i].name << " (" << files[i].number << ")\n";
        }
        std::cout << "Enter index to remove: ";
        int idx;
        std::cin >> idx;

        if (idx >= 0 && idx < files.size()) {
            files.erase(files.begin() + idx);
            std::cout << "file removed.\n";
        } else {
            std::cout << "Invalid index.\n";
        }

    } else if (choice == 2) {
        std::string num;
        std::cout << "Enter phone number to remove: ";
        std::cin >> num;

        bool found = false;
        for (auto it = files.begin(); it != files.end(); ++it) {
            if (it->number == num) {
                files.erase(it);
                std::cout << "file removed.\n";
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "Phone number not found.\n";
        }

    } else {
        std::cout << "Invalid choice.\n";
    }
}

void PhoneBook::show_menu()
{
    std::cout << "\nChoose the menu : " ;
    std::cout << "\n 1 : Add number \n 2 : Search number \n 3 : Bookmark number \n 4 : Remove number \n 5 : Exit\n";
}


