#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

int runClock(int h, int m, int s) {
    while (true) {
        system("cls");
        cout << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << ":" << setw(2) << setfill('0') << s << endl;
        Sleep(1000);
        s++;
        if (s > 59) {
            s = 0;
            m++;
        }
        if (m > 59) {
            m = 0;
            h++; 
        }
        if (h > 23) {
            h = 0;
        }
    }
}

int main() {
    int h, m, s, a, err;
    err = a = 0;
    while (true) {
        cout << "Let's set the current time!" << endl;
        cout << "Enter hour: " << endl;
        cin >> h;
        cout << "Enter minutes: " << endl;
        cin >> m;
        cout << "Enter seconds: " << endl;
        cin >> s;
        if (h < 24 && m < 60 && s < 60) {
            runClock(h, m, s);
        } else {
            system("cls");
        }
    }
    return 0;
}