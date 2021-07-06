#include <iostream>
#include <cstring>
#include <string>

using namespace std;

struct student {
    char* name;
    int kurs;
    float rating;
};

student makep() {
    float rating;
    int kurs;
    char Name[20];

    cout << "���: ";
    cin >> Name;
    cout << "����: ";
    cin >> kurs;
    cout << "�������: ";
    cin >> rating;
    cout << endl;

    student p;
    p.name = new char[strlen(Name) + 1];

    strcpy(p.name, Name);
    p.kurs = kurs;
    p.rating = rating;

    return p;
}

void printp(student* p, int l) {
    for (int i = 0; i < l; i++) {
        cout << p[i].name << endl << "����: " << p[i].kurs << endl << "�������: " << p[i].rating << endl << endl;
    }
}

void searchp(student* p, int l) {
    bool t = true;
    int ls = 0;
    student* ps = new student[10];

    for (int i = 0; i < l; i++) {
        if (p[i].rating < 3) {
            ps[ls] = p[i];
            ls++;
            t = false;
        }
    }
    if (t) {
        cout << "��� ����������" << endl << endl;
    }
    else {
        printp(ps, ls);
    }
    delete[] ps;
}

void makestr(char** strm, int a) {
    for (int i = 0; i < a; i++) {
        int count = 0;
        char str[256];

        cout << "������� ������ " << i + 1 << ": ";
        cin >> str;

        count = strlen(str);
        strm[i] = new char[count + 1];
        strcpy(strm[i], str);
    }
    cout << endl;
}

void printstr(char** strm, int a, int b) {
    for (int i = 0; i < a; i++) {
        cout << strm[i];
        cout << endl;
    }
    cout << endl;
}

void delmas(char** strm, int a, int b, int n) {
    printstr(strm, a - n, b);
}

int main() {
    int k,
        l = 0,
        lnstr,
        nstr;

    student* p = new student[10];
    char** strm;

    do {
        cout << "1. �������� ��������" << endl;
        cout << "2. ������� ������ ���������" << endl;
        cout << "3. �����" << endl;
        cout << "4. ������� ������ �����" << endl;
        cout << "5. ���������� ������ �����" << endl;
        cout << "6. �������" << endl;
        cout << "7. �����" << endl << endl;

        cin >> k;
        cout << endl;

        switch (k) {
        case 1: p[l] = makep(); l++; break;
        case 2: printp(p, l); break;
        case 3: searchp(p, l); break;
        case 4: cin >> lnstr; cin >> nstr;
            strm = new char* [lnstr];
            makestr(strm, lnstr); break;
        case 5: printstr(strm, lnstr, nstr); break;
        case 6: int n; cin >> n; delmas(strm, lnstr, nstr, n); break;
        }
    } while (k != 7);

    delete[] p;
    for (int i = 0; i < lnstr; i++) {
        delete[] strm[i];
    }
}