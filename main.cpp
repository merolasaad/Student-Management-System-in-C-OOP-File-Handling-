#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class Student {
public:
    int id;
    string name;
    int grade;

    Student(int i, string n, int g) {
        id = i;
        name = n;
        grade = g;
    }

    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Grade: " << grade << endl;
        cout << "-------------------" << endl;
    }
};

vector<Student> students;
void saveToFile(vector<Student> &students) {
    ofstream file;
    file.open("students.txt");
    for (int i = 0; i < students.size(); i++) {
        file << students[i].id << " " << students[i].name <<" " << students[i].grade << endl;
    }
    file.close();
}
void loadFromFile(vector<Student> &students) {
    ifstream file;

    file.open("students.txt");
    students.clear();
    Student s(0,"",0);

    while (file >> s.id >> s.name >> s.grade) {
        students.push_back(s);
    }
    file.close();
}
double averageOfGrades() {
    if (students.empty()) return 0;

    double sum = 0;
    for (int i = 0; i < students.size(); i++) {
        sum += students[i].grade;
    }
    return sum / students.size();
}

int searchStudent(int id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}

int getHighestStudent() {
    if (students.empty()) return -1;

    int idx = 0;
    int maxGrade = students[0].grade;

    for (int i = 1; i < students.size(); i++) {
        if (students[i].grade > maxGrade) {
            maxGrade = students[i].grade;
            idx = i;
        }
    }
    return idx;
}

void addStudents() {
    int t;
    cout << "Enter number of students: ";
    cin >> t;

    for (int i = 0; i < t; i++) {
        int id, grade;
        string name;

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Grade: ";
        cin >> grade;

        students.push_back(Student(id, name, grade));
    }
}

void showStudents() {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        students[i].display();
    }
}

void searchMenu() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    int idx = searchStudent(id);

    if (idx == -1) {
        cout << "Student not found.\n";
    } else {
        students[idx].display();
    }
}

void showHighest() {
    int idx = getHighestStudent();

    if (idx == -1) {
        cout << "No students available.\n";
    } else {
        students[idx].display();
    }
}

int main() {
    int choice;
loadFromFile(students);
    while (true) {

        cout << "\n===== MENU =====\n";
        cout << "1. Add Student\n";
        cout << "2. Show Students\n";
        cout << "3. Search Student\n";
        cout << "4. Highest Grade\n";
        cout << "5. Average Grade\n";
        cout << "6. Exit\n";
        cout << "================\n";

        cin >> choice;

        if (choice == 1) {
            addStudents();
            saveToFile(students);
        }
        else if (choice == 2) {
            showStudents();
        }
        else if (choice == 3) {
            searchMenu();
        }
        else if (choice == 4) {
            showHighest();
        }
        else if (choice == 5) {
            cout << "Average = " << averageOfGrades() << endl;
        }
        else {
            cout << "Exiting...\n";
            break;
        }
    }

    return 0;
}
