#include <iostream>
#include <list>

using namespace std;

int main() {
    list<double> lst = {1.2, 4.5, 2.0, 8.3, 0.5};

    cout << "Initial list: ";
    for (double x : lst) {
        cout << x << " ";
    }
    cout << endl;

    for (auto it = lst.begin(); it != lst.end(); ++it) {
        if (*it > 2.0) {
            auto next_it = next(it);
            lst.insert(next_it, 13.5);
            break;
        }
    }

    if (!lst.empty()) {
        lst.pop_back();
    }

    cout << "Result list:  ";
    for (double x : lst) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}