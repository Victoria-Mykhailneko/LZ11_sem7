#include <iostream>
#include <list>
#include <string>
#include <iomanip>

using namespace std;

struct Athlete {
    string surname;
    string sport;
    int age;
    int medals;
};

void printAthletes(const list<Athlete>& athletes) {
    cout << left << setw(16) << "Surname"
         << setw(16) << "Sport"
         << setw(8)  << "Age"
         << setw(8)  << "Medals" << endl;
    cout << string(48, '-') << endl;
    for (const auto& a : athletes) {
        cout << left << setw(16) << a.surname
             << setw(16) << a.sport
             << setw(8)  << a.age
             << setw(8)  << a.medals << endl;
    }
    cout << endl;
}

int main() {
    list<Athlete> athletes = {
        {"Kovalenko", "Swimming",   19, 3},
        {"Bondarenko", "Athletics", 24, 0},
        {"Tkachenko", "Gymnastics", 17, 5},
        {"Melnyk",    "Boxing",     22, 2},
        {"Shevchenko","Fencing",    20, 0}
    };

    cout << "Initial list:" << endl;
    printAthletes(athletes);

    athletes.push_front({"Kravchenko", "Tennis", 18, 1});
    athletes.push_back({"Lysenko", "Rowing", 25, 4});
    cout << "After push_front and push_back:" << endl;
    printAthletes(athletes);

    cout << "Athletes under 21:" << endl;
    for (const auto& a : athletes) {
        if (a.age < 21) {
            cout << a.surname << " (" << a.sport << ", age " << a.age
                 << ", medals: " << a.medals << ")" << endl;
        }
    }
    cout << endl;

    athletes.remove_if([](const Athlete& a) {
        return a.medals == 0;
    });
    cout << "After removing athletes with 0 medals:" << endl;
    printAthletes(athletes);

    athletes.sort([](const Athlete& a, const Athlete& b) {
        return a.medals > b.medals;
    });
    cout << "After sorting by medals descending:" << endl;
    printAthletes(athletes);

    return 0;
}