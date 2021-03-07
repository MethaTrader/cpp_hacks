#include <iostream>
#include <Windows.h>
#include <string>
#include "ManageMemory.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    ManageMemory manageMemory;

    manageMemory.ChangeMoney(15000);
    manageMemory.ChangeHealth(900);

    return 0;
}
