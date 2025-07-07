#ifndef STRING_CONVERTER_HPP
#define STRING_CONVERTER_HPP
//헤더가드 --> 중복을 막아준다.

#include <string>

class StringConverter {
public:
    // 생성자
    std::string convert(std::string mt, std::string s);

private:
    // 필요 시 private 멤버 추가 가능
};

#endif // STRING_CONVERTER_HPP
