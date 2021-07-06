//#include <iostream>
//
//using namespace std;
//
////2. Разработать программу, которая имеет своё меню и позволяет хранить массив Person.
////Пункты меню :
////-Добавить человека
////- Удалить человека
////- Показать всех
////- Найти по имени
////- Показать всех старше определённого возраста
////
////Все операции реализовать в функциях.Массив людей динамический.
//
//struct people {
//    char* name;
//    char* lastname;
//    int age;
//    
//};
//
//people DATA() {
//    
//    int age;
//    char Name[20];
//    char lastname[20];
//    cout << "Name: ";
//    cin >> Name;
//    cout << "Last Name: ";
//    cin >> lastname;
//    cout << "Age: ";
//    cin >> age;
//    cout << endl;
//    //имя
//    people p;
//    p.name = new char[strlen(Name) + 1];
//    strcpy(p.name, Name);
//    //фамилия
//  
//    p.lastname = new char[strlen(lastname) + 1];
//    strcpy(p.lastname, lastname);
//    //возраст
//    p.age = age;
//   
//
//    return p;
//}
//
//void printp(people* p, int Q) 
//{
//    for (int i = 0; i < Q; i++)
//    {
//        cout << p[i].name << '\t' << p[i].lastname << endl << "Age: " << p[i].age << endl;
//    }
//}
//
//void search(people* p, int Q)
//{
//    bool t = true;
//    int ls = 0;
//    people* ps = new people[10];
//    for (int i = 0; i < Q; i++)
//    {
//       
//        {
//            ps[ls] = p[i];
//            ls++;
//            t = false;
//        }
//    }
//    if (t) 
//    {
//        cout << "Нет информации" << endl << endl;
//    }
//    else {
//        printp(ps, ls);
//    }
//    delete[] ps;
//}
//void age(people* p, int Q)
//{
//
//}
//
//
//
//int main()
//{
//    int k, Q = 0;
//
//    people* p = new  people[10];
//    do {
//        cout << " \t\tProgram that has its own menu and allows you to store the Person information" << endl;
//        cout << "\t\tMain menu" << endl;
//        cout << "Please choose the menu number you need" << endl;
//
//
//        cout << "1. - Enter the person information" << endl;
//        cout << "2. - Show all person" << endl;
//        cout << "3. - Find person by name" << endl;
//        cout << "4. - Show everyone over a certain age" << endl;
//        cout << "5. - delete" << endl;
//        cout << "6. - exit" << endl;
//        cout << "7. - cls. - clear screen" << endl;
//        cin >> k;
//        cout << endl;
//        switch (k) 
//        {
//        case 1: p[Q] = DATA(); Q++; break;
//        case 2: printp(p, Q); break;
//        case 3: search(p, Q); break;
//
//        case 7:system("cls"); break;
//        }
//    } while (k != 6);
//    delete[] p;
//   
//}
#include <iostream>

/**
 * Разработать программу, которая имеет своё меню и позволяет хранить массив Person.
 * Пункты меню:
 * - Добавить человека
 * - Удалить человека
 * - Показать всех
 * - Найти по имени
 * - Показать всех старше определённого возраста
 *
 * Все операции реализовать в функциях. Массив людей динамический.
 * */

struct Person {
    static unsigned personsCount;

    char* firstName = new char[20];
    char* lastName = new char[20];
    unsigned age = 0;
    unsigned height = 0;
};

unsigned Person::personsCount = 0;

typedef void(*personsFunction)(Person**, int);

void openMenu();

void addPerson(Person** persons, int personsLength) {
    unsigned personsCountTmp = Person::personsCount;

    if (personsCountTmp > personsLength - 1) {
        std::cout << "You can't add more persons!" << std::endl;
        return;
    }

    Person* person = new Person();

    std::cout << "Type a first name: ";
    std::cin >> person->firstName;
    std::cout << std::endl;

    std::cout << "Type a last name: ";
    std::cin >> person->lastName;
    std::cout << std::endl;

    std::cout << "Type an age: ";
    std::cin >> person->age;
    std::cout << std::endl;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');

        std::cout << "Invalid person age!" << std::endl;

        return;
    }

    std::cout << "Type a height: ";
    std::cin >> person->height;
    std::cout << std::endl;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');

        std::cout << "Invalid person height!" << std::endl;

        return;
    }

    for (int i = 0; i < personsCountTmp + 1; ++i) {
        if (persons[i] == nullptr) {
            persons[i] = person;
            ++Person::personsCount;
        }
    }
}

void deletePerson(Person** persons, int personsLength) {
    if (Person::personsCount == 0) {
        std::cout << "There are no persons!" << std::endl;
        return;
    }

    int personIndex;

    std::cout << "Type a index: ";
    std::cin >> personIndex;
    std::cout << std::endl;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');

        std::cout << "Invalid index to remove person!" << std::endl;

        return;
    }

    if (personIndex > personsLength - 1 || persons[personIndex] == nullptr) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    delete persons[personIndex];

    persons[personIndex] = nullptr;

    std::cout << "The person under the index " << personIndex << " was deleted!" << std::endl;

    --Person::personsCount;
}

void showPerson(Person* person) {
    std::cout << "-------------------------" << std::endl;
    std::cout << "First name: " << person->firstName << std::endl;
    std::cout << "Last name: " << person->lastName << std::endl;
    std::cout << "Age: " << person->age << std::endl;
    std::cout << "Height: " << person->height << std::endl;
    std::cout << "-------------------------" << std::endl;
}

void showPersons(Person** persons, int personsLength) {
    if (Person::personsCount == 0) {
        std::cout << "There are no persons!" << std::endl;
        return;
    }

    for (int i = 0; i < personsLength; ++i) {
        if (persons[i] != nullptr) {
            std::cout << "Person index: " << i << std::endl;
            showPerson(persons[i]);
        }
    }
}

void findByName(Person** persons, int personsLength) {
    bool wasPersonFound = false;

    char* personName = new char[20];
    std::cout << "Type a person name: ";
    std::cin >> personName;
    std::cout << std::endl;

    for (int i = 0; i < personsLength; ++i) {
        if (persons[i] != nullptr && strcmp(persons[i]->firstName, personName) == 0) {
            std::cout << "Person index: " << i << std::endl;
            showPerson(persons[i]);
            wasPersonFound = true;
        }
    }

    if (!wasPersonFound)
        std::cout << "Person not found!" << std::endl;
}

void showOlderACertAge(Person** persons, int personsLength) {
    unsigned age;

    std::cout << "Type a age: ";
    std::cin >> age;
    std::cout << std::endl;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');

        std::cout << "Invalid age!" << std::endl;

        return;
    }

    for (int i = 0; i < personsLength; ++i) {
        if (persons[i] != nullptr && persons[i]->age >= age) {
            std::cout << "Person index: " << i << std::endl;
            showPerson(persons[i]);
        }
    }
}

int main() {
    openMenu();

    return 0;
}

void openMenu() {
    int menuIndex = 0;

    int personsLength;

    std::cout << "Type a persons length: ";
    std::cin >> personsLength;
    std::cout << std::endl;

    if (personsLength <= 0) {
        std::cout << "Invalid persons length!";
        return;
    }

    Person** persons = new Person * [personsLength] {nullptr};

    personsFunction* functions = new personsFunction[5];
    functions[0] = addPerson;
    functions[1] = deletePerson;
    functions[2] = showPersons;
    functions[3] = findByName;
    functions[4] = showOlderACertAge;

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "-------------------------" << std::endl;
        std::cout << "1. Add Person" << std::endl;
        std::cout << "2. Delete Person" << std::endl;
        std::cout << "3. Show Persons" << std::endl;
        std::cout << "4. Find Person by name" << std::endl;
        std::cout << "5. Show older than a certain age" << std::endl;
        std::cout << "6. Exit" << std::endl;

        std::cout << ">";
        std::cin >> menuIndex;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');

            std::cout << "Invalid menu index!" << std::endl;
        }
        else if (menuIndex <= 0)
            std::cout << "Invalid menu index!" << std::endl;

        else if (menuIndex == 6) break;

        else if (menuIndex == 0 || menuIndex >= 7)
            std::cout << "Invalid index!" << std::endl;

        else
            functions[menuIndex - 1](persons, personsLength);
    }

    for (int i = 0; i < personsLength; ++i)
        delete[] persons[i];

    delete[] persons;
    delete[] functions;
}
