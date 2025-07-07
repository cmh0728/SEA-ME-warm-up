#include "../include/StringConverter.hpp"
#include <algorithm> // std::transform
#include <cctype>    // std::toupper, std::tolower
using namespace std;

string StringConverter::convert(string mt, string s) // 생성자 
{
    //65~90 , 97~122    

    string ans = "";

    if(mt == "up") // 소문자들 대문자로 
    {
        for(char c : s)
        {
            if(c >= 'a' and c <= 'z')
            {
                c -= 32;
            }
            ans += c;
        }
    }
    else if (mt == "down") // 대문자들 소문자로 
    {
        for(char c : s)
        {
            if(c>='A' and c <= 'Z')
            {
                c += 32;
            }
            ans += c;
        }
    }

    return ans;
}   
