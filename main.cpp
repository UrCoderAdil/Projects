#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

class PasswordManager {
public:
    std::string website;
    std::string password;

    // Constructor to initialize website and password
    PasswordManager(std::string website, std::string password) {
        this->website = website;
        this->password = password;
    }

    // Save website and password to a file
    void saveToFile() {
        std::ofstream file("passwords.txt", std::ios::app);  // Open file in append mode useful for not losing previous data
        if (file.is_open()) {
            file << website << "," << password << "\n";
            file.close();
        } else {
            std::cout << "Error opening file to save password.\n";
        }
    }
};

// Function declarations
void startUp();
void addPassword();
void searchPassword();
bool loadPasswordData(const std::string& website, PasswordManager& pwManager);

using namespace std;

int main() {
    cout << "______________Welcome to the Social Media Password Manager!______________" << endl;

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
    cout << "\nDo you want to add a password or search for one?" << endl;
    cout << "Press 'a' to add a password\nPress 's' to search for a password\nEnter your choice here: ";
    cin >> choice;

    if (choice == 'a') {
        addPassword();
    }
    else if (choice == 's') {
        searchPassword();
    }
    else {
        cout << "Invalid choice! Please try again." << endl;
    }
}

void addPassword() {
    std::string website;
    std::string password;

    cout << "\n\nAdd a new password entry.\n";
    cout << "Please enter the website name: ";
    cin >> website;

    // Check if the website already has a password saved
    PasswordManager existingPassword("", "");
    if (loadPasswordData(website, existingPassword)) {
        cout << "\nA password for this website already exists.\n";
        return;  // Exit if the website already exists
    }

    cout << "Please enter the password for " << website << ": ";
    cin >> password;

    // Create PasswordManager object and save it to the file
    PasswordManager newPassword(website, password);
    newPassword.saveToFile();

    cout << "\nPassword for " << website << " has been saved successfully!\n";
}

void searchPassword() {
    string website;
    cout << "\n\nSearch for a saved password.\n";
    cout << "Please enter the website name: ";
    cin >> website;

    PasswordManager foundPassword("", "");
    if (loadPasswordData(website, foundPassword)) {
        // Display the password if the website is found
        cout << "\nWebsite: " << foundPassword.website << "\n";
        cout << "Password: " << foundPassword.password << "\n";
    } else {
        cout << "\nNo password found for " << website << ".\n";
    }
}

// Load password data for a specific website from the file
bool loadPasswordData(const std::string& website, PasswordManager& pwManager) {
    std::ifstream file("passwords.txt");
    if (!file.is_open()) {
        cout << "Error opening password data file!" << endl;
        return false;
    }

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string site, pass;
        getline(ss, site, ',');
        getline(ss, pass, ',');

        if (site == website) {
            pwManager.website = site;
            pwManager.password = pass;
            return true;  // Website found
        }
    }

    return false;  // Website not found
}
