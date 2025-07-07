#include <iostream>
#include "include/StringConverter.hpp"
using namespace std;

int main(int argc, char* argv[]) // 함수 실행하며 인자 받기
{
    //argv[0] : 실행경로, argv[1]~ : 사용자가 넘겨주는 인자 

    string method = argv[1];
    string input;

    // argv[2]부터 끝까지 공백으로 이어붙이기
    for (int i = 2; i < argc; ++i) {
        input += argv[i];
        if (i != argc - 1) input += " ";
    }
    StringConverter sc;
    string answer = sc.convert(method,input);
    cout << answer <<endl;

    //for debug
    // cout << "Command: " << method << endl;
    // cout << "Input String: " << input << endl;



    return 0;
}
