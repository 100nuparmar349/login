#include<iostream>
#include<fstream>
using namespace std;

class temp {
    string username, Email, password;
    string searchname, searchpass, searchemail;
    fstream file;

public:
    void login();
    void signup();
    void forgotpassword();
};

void temp::signup() {
    cout << "\nEnter your user name :: ";
    getline(cin, username);
    cout << "Enter your Email Address :: ";
    getline(cin, Email);
    cout << "Enter your password :: ";
    getline(cin, password);
    file.open("logindata.txt", ios::out | ios::app);
    file << username << "*" << Email << "*" << password << endl;
    file.close();
}

void temp::login() {
    cout << "----------LOGIN----------" << endl;
    cout << "Enter your  username :: " << endl;
    getline(cin, searchname);
    cout << "Enter your password :: " << endl;
    getline(cin, searchpass);
    file.open("logindata.txt", ios::in);
    while (getline(file, username, '*') && getline(file, Email, '*') && getline(file, password, '\n')) {
        if (username == searchname && password == searchpass) {
            cout << "\nAccount login successful...!" << endl;
            cout << "username :: " << username << endl;
            cout << "Email :: " << Email << endl;
            file.close();
            return;
        }
    }
    file.close();
    cout << "Login failed. Invalid username or password." << endl;
}

void temp::forgotpassword() {
    cout << "----Enter your username--- :: ";
    getline(cin, searchname);
    cout << "\nEnter your email address :: ";
    getline(cin, searchemail);
    file.open("logindata.txt", ios::in);
    while (getline(file, username, '*') && getline(file, Email, '*') && getline(file, password, '\n')) {
        if (username == searchname && Email == searchemail) {
            cout << "\nAccount found...." << endl;
            cout << "Your password :: " << password << endl;
            file.close();
            return;
        }
    }
    file.close();
    cout << "Account not found." << endl;
}

int main() {
    temp obj;
    char choice;
    do {
        cout << "\n1 - Login";
        cout << "\n2 - SignUp";
        cout << "\n3 - Forgot Password";
        cout << "\n4 - Exit";
        cout << "\n Enter your choice :: ";
        cin >> choice;
        cin.ignore();  // To clear the newline character from the input buffer

        switch (choice) {
            case '1':
                obj.login();
                break;
            case '2':
                obj.signup();
                break;
            case '3':
                obj.forgotpassword();
                break;
            case '4':
                return 0;
            default:
                cout << "Invalid Selection...!";
        }
    } while (true);

    return 0;
}
