/*#include <iostream>
class Student{
public:
    std::string name;
    std::string section;
    std::string school;
    std::string cms_id;
    Student(std::string name,std::string section,std::string school,std::string cms_id){
        this->name=name;
        this->section=section;
        this->school=school;
        this->cms_id=cms_id;
           };
};
void startUp();
void Registeration();
using namespace std;

int main()
{
    cout << "_________________________Welcome Students!!___________________________" << endl;
     startUp();
    return 0;
}
void startUp(){
    char choice;
    cout<<"Do you want to login or register?"<<endl;
    cout<<"press 'r' for registration\npress 'l' for login \nEnter your choice here: ";
    cin>>choice;
    if(choice != 'r' && choice != 'l'){
          cout<<"Invalid Choice!!\n Try again!!\n";
          startUp();
    }
    else{
         if(choice == 'r'){
             Registeration();
        }















    }
}



    void Registeration(){
    std::string cms;
    std::string school;
    std::string name;
    std::string section;
    std::string registerationno;
    cout<<"\n\nWelcome to Student Registration form!!\n";
    cout<<"Please Enter your cms_id here :";
    cin>>cms;
    cout<<"\nPlease Enter your school here :";
    cin>>school;
    registerationno="stud24"+school+"_"+ cms;
    cin.ignore();
    cout<<"\nPlease Enter your name here :";
    getline(cin,name);
    cout<<"\nPlease Enter your section here :";
    cin>>section;
    Student NewStudent(name,section,school,cms);
    cout<<"\nYour successfully registered!!\n";
    cout<<"Your Registration_no is : "<<registerationno;

     }*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class Student {
public:
    std::string name;
    std::string section;
    std::string school;
    int cms_id;
    std::string registrationNo;

    Student(std::string name, std::string section, std::string school, int cms_id, std::string registrationNo) {
        this->name = name;
        this->section = section;
        this->school = school;
        this->cms_id = cms_id;
        this->registrationNo = registrationNo;
    }

    // Save student data to a file
    void saveToFile() {
        std::ofstream file("students.txt", std::ios::app);  // Open file in append mode
        if (file.is_open()) {
            file << name << "," << section << "," << school << "," << cms_id << "," << registrationNo << "\n";
            file.close();
        }
    }
};

// Function declarations
void startUp();
void Register();
void Login();
bool loadStudentData(const std::string& cms_id, Student& student);

using namespace std;

int main() {
    cout << "_________________________Welcome Students!!___________________________" << endl;

    string input;
    while (true) {
        startUp();
        cout << "\nType 'quit' to exit or press any other key to continue: ";
        cin >> input;
        if (input == "quit") {
            break;
        }
    }

    return 0;
}

void startUp() {
    char choice;
    cout << "\nDo you want to login or register?" << endl;
    cout << "Press 'r' for registration\nPress 'l' for login\nEnter your choice here: ";
    cin >> choice;

    if (choice == 'r') {
        Register();
    }
    else if (choice == 'l') {
        Login();
    }
    else {
        cout << "Invalid choice! Please try again." << endl;
    }
}

void Register() {
    std::string cms;
    std::string school;
    std::string name;
    std::string section;
    std::string registrationNo;

    cout << "\n\nWelcome to Student Registration form!!\n";
    cout << "Please Enter your cms_id here: ";
    cin >> cms;

    // Check if the cms_id already exists
    Student existingStudent("", "", "", 0, "");
    if (loadStudentData(cms, existingStudent)) {
        cout << "\nThis CMS ID is already registered. You cannot register again with the same ID.\n";
        return;  // Exit registration process if the cms_id exists
    }

    cout << "\nPlease Enter your school here: ";
    cin >> school;

    // Concatenate to create the registration number
    registrationNo = "stud24" + school + "_" + cms;

    // Fixing issue with getline and cin
    cin.ignore();  // Ignore the leftover newline character from cin

    cout << "\nPlease Enter your name here: ";
    getline(cin, name);

    cout << "\nPlease Enter your section here: ";
    cin >> section;

    // Assuming cms_id should be an integer, convert cms to int
    int cms_id = stoi(cms);

    // Create Student object and save it to the file
    Student newStudent(name, section, school, cms_id, registrationNo);
    newStudent.saveToFile();

    cout << "\nYou're successfully registered!!\n";
    cout << "Your Registration_no is: " << registrationNo << endl;
}

void Login() {
    string cms;
    cout << "\n\nWelcome to Student Login form!!\n";
    cout << "Please Enter your cms_id here: ";
    cin >> cms;

    Student loggedInStudent("", "", "", 0, "");

    if (loadStudentData(cms, loggedInStudent)) {
        // Display student details after successful login
        cout << "\nLogin successful! Here are your details:\n";
        cout << "Name: " << loggedInStudent.name << "\n";
        cout << "Section: " << loggedInStudent.section << "\n";
        cout << "School: " << loggedInStudent.school << "\n";
        cout << "Registration No: " << loggedInStudent.registrationNo << "\n";
    } else {
        cout << "No student found with CMS ID: " << cms << "\n";
    }
}

// Load student data from the file
bool loadStudentData(const std::string& cms_id, Student& student) {
    std::ifstream file("students.txt");
    if (!file.is_open()) {
        cout << "Error opening student data file!" << endl;
        return false;
    }

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string name, section, school, cms_str, registrationNo;
        getline(ss, name, ',');
        getline(ss, section, ',');
        getline(ss, school, ',');
        getline(ss, cms_str, ',');
        getline(ss, registrationNo, ',');

        if (cms_str == cms_id) {
            student.name = name;
            student.section = section;
            student.school = school;
            student.cms_id = stoi(cms_str);
            student.registrationNo = registrationNo;
            return true;
        }
    }

    return false;
}



