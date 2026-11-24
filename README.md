#Лабораторна робота №11: Опрацювання двозв'язних списків

**Виконала:** студентка групи 4 СОМ Вікторія Михайленко (Варіант №9)

**Мета:** набути практичних навичок створення, модифікації та опрацювання
двозв’язних списків за допомогою стандартного шаблонного контейнера std::list та
двонаправлених ітераторів.

##  Завдання.
**Завдання 1:** <img width="533" height="34" alt="image" src="https://github.com/user-attachments/assets/7906d819-d3f5-44ff-a4cb-863f9777537d" />

### 💻 Код програми:
```cpp
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
```

## Результат: <img width="858" height="512" alt="image" src="https://github.com/user-attachments/assets/d2e2cfac-b372-4ea9-90c6-cc12998fffa3" />


**Завдання 2:** <img width="543" height="55" alt="image" src="https://github.com/user-attachments/assets/d13d5585-040b-4de0-a35b-c2d00f69ea90" />


### 💻 Код програми:
```cpp
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
```

## Результат: 
<img width="874" height="592" alt="image" src="https://github.com/user-attachments/assets/c32f6bfd-1a39-4c55-8be8-762d8fc1e32f" />

**Висновок:** У ході виконання лабораторної роботи я закріпила навички роботи з std::list у C++, 
навчилася створювати списки, додавати й видаляти елементи (push_front, push_back, insert, pop_back, remove_if), 
фільтрувати та сортувати записи (sort). std::list зручний для частого вставлення й вилучення елементів без зсуву інших даних.
