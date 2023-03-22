#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

int err = 0;
ifstream vcredist;
ifstream crosec;
ifstream cbrmap;
ifstream cbtp;
ofstream cmd1 ("cmd1.ps1");
string instype = "";
string choice2 = "2";
string choice1 = "1";
string choice3 = "3";
string choice4 = "4";
string deflt = "";
string opt;

void chromebook() {

    cout << "[\033[0;32mWinSetup\033[0m] Downloading VC_redist.x64.exe... \n";
    system("curl -O https://download.visualstudio.microsoft.com/download/pr/8b92f460-7e03-4c75-a139-e264a770758d/26C2C72FBA6438F5E29AF8EBC4826A1E424581B3C446F8C735361F1DB7BEFF72/VC_redist.x64.exe");
    vcredist.open("VC_redist.x64.exe");

    if (vcredist){
        cout << "[\033[0;32mWinSetup\033[0m] VC_redist.x64.exe downloaded sucessfully! \n";
        cout << "[\033[0;32mWinSetup\033[0m] Running VC_redist.x64.exe... \n";
        system("VC_redist.x64.exe");

    } else {
        cout << "[\033[0;31mError\033[0m] VC_redist.x64.exe did not download sucessfully, skipping install.";
        err = err+1;
    }

    system("del VC_redist.x64.exe");

    cout << "[\033[0;32mWinSetup\033[0m] Downloading crosec.1.0-installer.exe \n";
    system("curl -O https://raw.githubusercontent.com/coolstar/driverinstallers/master/crosec/crosec.1.0-installer.exe");
    crosec.open("crosec.1.0-installer.exe");

    if (crosec){
        cout << "[\033[0;32mWinSetup\033[0m] crosec.1.0-installer.exe downloaded sucessfully! \n";
        cout << "[\033[0;32mWinSetup\033[0m] Running crosec.1.0-installer.exe... \n";
        system("crosec.1.0-installer.exe");

    } else {
        cout << "[\033[0;31mError\033[0m] crosec.1.0-installer.exe did not download sucessfully, skipping install.";
        err = err+1;
    }

    system("del crosec.1.0-installer.exe");

    cout << "[\033[0;32mWinSetup\033[0m] Downloading chromebookremap.1.0.4-installer.exe \n";
    system("curl -O https://raw.githubusercontent.com/coolstar/driverinstallers/master/chromebookremap/chromebookremap.1.0.4-installer.exe");
    cbrmap.open("chromebookremap.1.0.4-installer.exe");

    if (cbrmap){
        cout << "[\033[0;32mWinSetup\033[0m] chromebookremap.1.0.4-installer.exe downloaded sucessfully! \n";
        cout << "[\033[0;32mWinSetup\033[0m] Running chromebookremap.1.0.4-installer.exe... \n";
        system("chromebookremap.1.0.4-installer.exe");
    } else {
        cout << "[\033[0;31mError\033[0m] chromebookremap.1.0.4-installer.exe did not download sucessfully, skipping install.";
        err = err+1;
    }

    system("del chromebookremap.1.0.4-installer.exe");

    cout << "[\033[0;32mWinSetup\033[0m] Downloading crostouchpad.4.1.3-installer.exe \n";
    system("curl -O https://raw.githubusercontent.com/coolstar/driverinstallers/master/crostouchpad/crostouchpad.4.1.3-installer.exe");
    cbtp.open("crostouchpad.4.1.3-installer.exe");

    if (cbtp){
        cout << "[\033[0;32mWinSetup\033[0m] crostouchpad.4.1.3-installer.exe downloaded sucessfully! \n";
        cout << "[\033[0;32mWinSetup\033[0m] Running crostouchpad.4.1.3-installer.exe... \n";
        system("crostouchpad.4.1.3-installer.exe");
    } else {
        cout << "[\033[0;31mError\033[0m] crostouchpad.4.1.3-installer.exe did not download sucessfully, skipping install.";
        err = err+1;
    }

    system("del chromebookremap.1.0.4-installer.exe");
        
    cout << "[\033[0;32mWinSetup\033[0m] Setting compactos to always to save space... \n";
    system("compact.exe /compactos:always");

    cout << "[\033[0;32mWinSetup\033[0m] Finished driver install with [" << err << "] errors.";

    }

void extras() {

    cmd1 << "iwr -useb https://christitus.com/win | iex" << std::endl;
    cmd1.close();
    system("powershell ./cmd1.ps1");
    system("del cmd1.ps1");
    
}

int main() {


    system("CLS");
    
    cout << "[ \033[0;32mCBWinSetup\033[0m - v0.1 by \033[0;35mTris\033[0m ] \n \n";
    cout << "Please select an option to continue: \n";
    cout << "1) All \n";
    cout << "2) Drivers Only \n";
    cout << "3) Chris Titus's WinUtil \n";
    getline(cin , opt);
    
    if (opt == choice2){

        cout << "[\033[0;32mWinSetup\033[0m] You selected: \033[0;32mDrivers Only\033[0m \n";
        chromebook();

    } else if (opt == choice1){
        
        cout << "[\033[0;32mWinSetup\033[0m] You selected: \033[0;32mAll\033[0m \n";
        chromebook();
        extras();

    } else if (opt == choice3){

        cout << "[\033[0;32mWinSetup\033[0m] You selected: \033[0;32mChris Titus's WinUtil\033[0m \n";
        extras();

    } else {
        //unknown
        cout << "[\033[0;31mError\033[0m] Unknown option? (wedoalittletrolling)";
        Sleep(1);
        main();

    }

    cout << "[\033[0;32mWinSetup\033[0m] Done!";

    return 0;
}