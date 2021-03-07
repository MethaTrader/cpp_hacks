//
// Created by Admin on 07.03.2021.
//

#ifndef THIRD_MANAGEMEMORY_H
#define THIRD_MANAGEMEMORY_H

#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class ManageMemory {

public:

    HANDLE OpenProc(string windowTitle) {
        DWORD process_id;
        auto hw = FindWindow(0, "Counter-Strike");
        /////////////
        GetWindowThreadProcessId(hw, &process_id);

        if(!hw) {
            cout<<"Process not found";
        }

        HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS,FALSE,process_id);

        return handle;
    }
    void ChangeMoney(int new_money) {
        DWORD pl = 0x102D75E4; //адресс для денег
        HANDLE handle = OpenProc("Counter-Strike");

        int money = 0;
        ReadProcessMemory(handle, (LPVOID)pl, &money, sizeof(money), 0);
        cout<< money;
        money = new_money; // новое значение денег
        pl = 0x0AA313C4; //значение адресса денег

        if(WriteProcessMemory(handle, (LPVOID)pl, &money, sizeof(money), 0)) {
            cout<<endl<<"Баланс успешно обновлен"<<endl;
        }
    }
    void ChangeHealth(int new_health) {
        DWORD pl = 0x0AA2D640; //адресс для здоровья
        HANDLE handle = OpenProc("Counter-Strike");

        int health = 100;
        ReadProcessMemory(handle, (LPVOID)pl, &health, sizeof(health), 0);
        cout<< health;
        health = new_health; // новое значение здоровья

        if(WriteProcessMemory(handle, (LPVOID)pl, &health, sizeof(health), 0)) {
            cout<<endl<<"Здоровье успешно обновлено"<<endl;
        }
    }
};


#endif //THIRD_MANAGEMEMORY_H
