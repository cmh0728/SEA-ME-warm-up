#include "include/PhoneBook.hpp"
#include <iostream>

int main(){
    std::cout << "Welcome to Kevin's PhoneBook application!!";
    PhoneBook ph; // 객체 생성 

    while(1){
        ph.show_menu();
        int menu_num ;
        std::cin >> menu_num ;

        if(menu_num == 1) // add
        {
            ph.add();
        }
        else if(menu_num == 2) //search
        {
            ph.search();
        }
        else if(menu_num == 3) // bookmark
        {
            ph.bookmark();
        }
        else if(menu_num == 4) // remove
        {
            ph.remove();
        }
        else if(menu_num == 5) // exit 
        {
            break;
        }
        
    }
    
    std::cout << "Program is shut down!!\n";
    return 0;
}