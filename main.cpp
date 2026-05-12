#include <iostream>
#include <string>

using namespace std;

float CalculateAverage(float* grades, int subjects) {
    float total = 0;
    
    for (int i = 0; i < subjects; i++) {
        total += *(grades + i);
    }
    
    return total / subjects;
}

float CalculateGPA(float average) {
    return (average / 100.0) * 4.0;
}

void DisplayGrades(float* grades, int size) {
    cout << "\nStudent Grades:\n";

    for (int i = 0; i < size; i++) {

        cout << "Subject " << i + 1 << ": " << *(grades + i) << endl;
    }
}

int main() {
    int NumberOfSubjects, StudentID;

    cout << "Enter Student ID: ";
    cin >> StudentID;
    
    if (cin.fail()) { cout << "Please input a valid number." << endl; return 0; }

    cout << "Enter Number of Subjects: ";
    cin >> NumberOfSubjects;

    if (cin.fail()) { cout << "Please input a valid number." << endl; return 0; }

    float grades[100];
    
    for (int i = 0; i < NumberOfSubjects; i++) {
        cout << "Enter Grade for Subject " << i + 1 << ": ";

        cin >> grades[i];
        if (cin.fail()) { cout << "Please input a valid number." << endl; return 0; }
    }

    float average = CalculateAverage(grades, NumberOfSubjects);
    float gpa = CalculateGPA(average);

    cout << "\n========== STUDENT REPORT ==========" << endl;

    cout << "Student ID: " << StudentID << endl;

    if (gpa > 2)
        cout << "Status: Passing" << endl;
    else
        cout << "Status: Failing" << endl;

    DisplayGrades(grades, NumberOfSubjects);

    cout << "\nAverage Grade: " << average << endl;
    cout << "GPA: " << gpa << endl;


    cout << "====================================";

    return 0;
}
