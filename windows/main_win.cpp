#include <cctype>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <limits>
#include <stdio.h>
#include <string>
#include <thread>
#include <unistd.h>
//#include <bits/std_thread.h>
//#define _GLIBCXX_HAS_GTHREADS
using namespace std;
string input_s="";
int port = 5555;
string command = "";
string temp = "";
int pdport = 5555;

int rs = 0;
string ip ="";
int input_i = 0;
int clear(){
    std::system("adb disconnect");
    std::system("adb kill-server");
    return 0;
};
int userinput_string(){
    std::cin >> input_s;
    return 0;
};

int userinput_int(){
    std::cin >> input_i;
    if (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "��Ч����\n";
        rs = 1;
        input_i = 0;
        return 1;  
        
    } else {
        rs = 0;
        return 0;
    };
};
int main(int argc, char *argv[]){
    _main:
    std::cout << "�����밲װģʽ(1.��������     2.��������):";
    userinput_int();
    if (rs == 1) {
        input_i = 0;
        goto _main;
    };
    if (input_i == 1) {
        std::cout << "������ip:";
        userinput_string();
        ip = input_s;
        _1_1:
        std::cout << "���������Ӷ˿�:";
        userinput_int();
        if (rs == 1) {
            input_i = 0;
            goto _1_1;
        } else {
            port = input_i;
        };
        _c1:
        std::cout << "��ѡ��(1.���[Android 11 ����]     2.ֱ�Ӱ�װ    3.����)";
        userinput_int();
        if (rs == 1) {
            input_i = 0;
            goto _c1;
        };
        if (input_i == 1) {
            _1_1_1:
            std::cout << "��������Զ˿�:";
            userinput_int();
            if (rs == 1) {
                input_i = 0;
                goto _1_1_1;
            } else {
                input_i = pdport;
            };
            command = ip+":"+to_string(pdport);
            std::cout << "��Ե�ַ:" << command;
            command = "adb pair "+command;
         
            std::system(command.c_str());
            command ="adb connect "+ip+":"+to_string(port);
            std::system(command.c_str());
            temp = argv[1];
            command = "adb install "+temp;
            std::system(command.c_str());
            //std::this_thread::sleep_for(std::chrono::seconds(5));
            sleep(5);
            clear();
            exit(0);
        } else if (input_i == 2) {
            command = "adb connect "+ip+":"+to_string(port);
            std::system(command.c_str());
            temp = argv[1];
            command = "adb install "+temp;
            std::system(command.c_str());
            //std::this_thread::sleep_for(std::chrono::seconds(5));
            sleep(5);
            clear();
            exit(0);
        } else if (input_i == 3) {
            goto _main;
        };
    } else if (input_i == 2) {
        temp = argv[1];
        command = "adb install "+temp;
        std::system(command.c_str());
        //std::this_thread::sleep_for(std::chrono::seconds(5));
        sleep(5);
        clear();
        exit(0);
    };

}
