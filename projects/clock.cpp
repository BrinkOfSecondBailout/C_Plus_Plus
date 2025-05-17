#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>

using namespace std;

int runClock(int h, int m, int s) {
    while (true) {
        system("cls");
        cout << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << ":" << setw(2) << setfill('0') << s << endl;
        cout << "\nPress 'q' to re-enter time, ESC to exit program" << endl;
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
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'q' || ch == 'Q') {
                return 1;
            }
            if (ch == 27) {
                return 2;
            }
        }
    }
}

int main() {
    int h, m, s;
    while (true) {
        cout << "Let's set the current time!" << endl;
        cout << "Enter hour: " << endl;
        cin >> h;
        cout << "Enter minutes: " << endl;
        cin >> m;
        cout << "Enter seconds: " << endl;
        cin >> s;
        if (h < 24 && m < 60 && s < 60  && h >= 0 && m >= 0 && s >= 0) {
            int result = runClock(h, m, s);
            if (result == 2) break;
        } else {
            system("cls");
            cout << "Invalid time! Hours (0-23), Minutes (0-59), Seconds (0-59)" << endl;
            Sleep(3000);
        }
    }
    system("cls");
    cout << "Program exited." << endl;
    return 0;
}