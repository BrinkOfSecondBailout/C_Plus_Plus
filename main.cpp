#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main() {
    std::vector<int> v = {1, 2, 4, 7, 8};
    int last = -1;
    auto print_v = [&](int n){last = n; std::cout << n << ",";};
    std::for_each(begin(v), end(v), print_v);
    std::cout << '\n' << last << std::endl;
}
