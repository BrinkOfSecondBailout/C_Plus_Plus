#include <iostream>

using namespace std;

int divide(int x, int y) {
    if (y == 0) throw 0;
    return x / y;
}

int main() {
    try {
        divide(10, 0);
    } catch (int &e) {
        cout << "Error: " << e;
    }
}
