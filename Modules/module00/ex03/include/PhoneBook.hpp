#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP
// 헤더가드 설정 
#include <string>
#include <vector>

//전화번호 저장을 위한 구조체 선언 
struct file {
    std::string name;
    std::string number;
    std::string nickname;
    bool bookmarked = false;
};

//class 선언
class PhoneBook{
public :
    void add();
    void search();
    void remove();
    void bookmark();
    void show_menu();
private:
    std::vector<file> files; 
};

#endif