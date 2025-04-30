#include<iostream>
using namespace std;

char arr1[20][50], arr2[20][20], arr3[20][50], arr4[20][20], arr5[20][20];
int total = 0;

// Function to enter student data
void enter() {
    int ch = 0;
    cout << "How many students do you want to enter?" << endl;
    cin >> ch;

    for (int i = total; i < ch + total; i++) {
        cout << "\nEnter the Data of student " << i + 1 << endl;
        cout << "Enter name: ";
        cin >> arr1[i];
        cout << "Enter Roll no: ";
        cin >> arr2[i];
        cout << "Enter course: ";
        cin >> arr3[i];
        cout << "Enter class: ";
        cin >> arr4[i];
        cout << "Enter contact: ";
        cin >> arr5[i];
    }

    total += ch;
}

// Function to display student data
void show() {
    if (total == 0) {
        cout << "No data is entered." << endl;
    }
    else {
        for (int i = 0; i < total; i++) {
            cout << "\nData of Student " << i + 1 << endl;
            cout << "Name: " << arr1[i] << endl;
            cout << "Roll no: " << arr2[i] << endl;
            cout << "Course: " << arr3[i] << endl;
            cout << "Class: " << arr4[i] << endl;
            cout << "Contact: " << arr5[i] << endl;
        }
    }
}

// Function to search student by roll number
void search() {
    if (total == 0) {
        cout << "No data is entered." << endl;
    }
    else {
        char rollno[20];
        bool found = false;

        cout << "Enter the roll no of the student: ";
        cin >> rollno;

        for (int i = 0; i < total; i++) {
            if (strcmp(rollno, arr2[i]) == 0) {
                cout << "\nData of Student " << i + 1 << endl;
                cout << "Name: " << arr1[i] << endl;
                cout << "Roll no: " << arr2[i] << endl;
                cout << "Course: " << arr3[i] << endl;
                cout << "Class: " << arr4[i] << endl;
                cout << "Contact: " << arr5[i] << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student with roll number " << rollno << " not found." << endl;
        }
    }
}

// Function to update student data by roll number
void update() {
    if (total == 0) {
        cout << "No data is entered." << endl;
    }
    else {
        char rollno[20];
        cout << "Enter the roll no of student which you want to update: ";
        cin >> rollno;

        for (int i = 0; i < total; i++) {
            if (strcmp(rollno, arr2[i]) == 0) {
                cout << "\nPrevious data" << endl;
                cout << "Name: " << arr1[i] << endl;
                cout << "Roll no: " << arr2[i] << endl;
                cout << "Course: " << arr3[i] << endl;
                cout << "Class: " << arr4[i] << endl;
                cout << "Contact: " << arr5[i] << endl;

                cout << "\nEnter new data" << endl;
                cout << "Enter name: ";
                cin >> arr1[i];
                cout << "Enter Roll no: ";
                cin >> arr2[i];
                cout << "Enter course: ";
                cin >> arr3[i];
                cout << "Enter class: ";
                cin >> arr4[i];
                cout << "Enter contact: ";
                cin >> arr5[i];
                break;
            }
        }
    }
}

// Function to delete student data
void deleterecord() {
    if (total == 0) {
        cout << "No data is entered." << endl;
    }
    else {
        int a;
        cout << "Press 1 to delete all records" << endl;
        cout << "Press 2 to delete specific record" << endl;
        cin >> a;

        if (a == 1) {
            total = 0;
            cout << "All records are deleted!" << endl;
        }
        else if (a == 2) {
            char rollno[20];
            cout << "Enter the roll no of student to delete: ";
            cin >> rollno;

            for (int i = 0; i < total; i++) {
                if (strcmp(rollno, arr2[i]) == 0) {
                    for (int j = i; j < total - 1; j++) {
                        strcpy(arr1[j], arr1[j + 1]);
                        strcpy(arr2[j], arr2[j + 1]);
                        strcpy(arr3[j], arr3[j + 1]);
                        strcpy(arr4[j], arr4[j + 1]);
                        strcpy(arr5[j], arr5[j + 1]);
                    }
                    total--;
                    cout << "The record of student with roll number " << rollno << " is deleted!" << endl;
                    break;
                }
            }
        }
        else {
            cout << "Invalid input" << endl;
        }
    }
}

int main() {
    int value;
    while (true) {
        cout << "\nPress 1 to enter data" << endl;
        cout << "Press 2 to show data" << endl;
        cout << "Press 3 to search data" << endl;
        cout << "Press 4 to update data" << endl;
        cout << "Press 5 to delete data" << endl;
        cout << "Press 6 to exit" << endl;
        cin >> value;

        switch (value) {
        case 1:
            enter();
            break;
        case 2:
            show();
            break;
        case 3:
            search();
            break;
        case 4:
            update();
            break;
        case 5:
            deleterecord();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }
}
