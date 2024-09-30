#include <iostream>
using namespace std;

// Function prototypes
void length();
void volume();
void mass();
void time();
void temperature();
void area();

int main() {
    char choose;

    cout << "_________________ Welcome to Unit Converter _________________________\n";

    do {
        cout << "\nWhat unit do you want to convert?\n";
        cout << "For Length press '0'\n";
        cout << "For Area press '1'\n";
        cout << "For Temperature press '2'\n";
        cout << "For Volume press '3'\n";
        cout << "For Time press '4'\n";
        cout << "For Mass/Weight press '5'\n";
        cout << "To Quit press 'q'\n";
        cout << "Enter your choice here: ";
        cin >> choose;

        switch (choose) {
            case '0': length(); break;
            case '1': area(); break;
            case '2': temperature(); break;
            case '3': volume(); break;
            case '4': time(); break;
            case '5': mass(); break;
            case 'q':
            case 'Q': cout << "Exiting the program. Goodbye!\n"; break;
            default: cout << "Invalid choice! Please try again.\n"; break;
        }
    } while (choose != 'q' && choose != 'Q');

    return 0;
}

void length() {
    double val;
    char choice;

    cout << "\n--- Length Conversion ---\n";
    cout << "For Inches to Centimeters Enter '0'\n";
    cout << "For Feet to Meters Enter '1'\n";
    cout << "For Miles to Kilometers Enter '2'\n";
    cout << "For Centimeters to Inches Enter '3'\n";
    cout << "Enter your choice here: ";
    cin >> choice;

    cout << "Enter the value to convert: ";
    cin >> val;

    switch (choice) {
        case '0':
            cout << "Value " << val << " converted to " << val * 2.54 << " cm\n";
            break;
        case '1':
            cout << "Value " << val << " converted to " << val * 0.3048 << " m\n";
            break;
        case '2':
            cout << "Value " << val << " converted to " << val * 1.60934 << " km\n";
            break;
        case '3':
            cout << "Value " << val << " converted to " << val / 2.54 << " inches\n";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }
}

void volume() {
    double val;
    char choice;

    cout << "\n--- Volume Conversion ---\n";
    cout << "For Gallons to Liters Enter '0'\n";
    cout << "For Cubic Feet to Cubic Meters Enter '1'\n";
    cout << "For Pints to Milliliters Enter '2'\n";
    cout << "Enter your choice here: ";
    cin >> choice;

    cout << "Enter the value to convert: ";
    cin >> val;

    switch (choice) {
        case '0':
            cout << "Value " << val << " converted to " << val * 3.78541 << " L\n";
            break;
        case '1':
            cout << "Value " << val << " converted to " << val * 0.0283168 << " m³\n";
            break;
        case '2':
            cout << "Value " << val << " converted to " << val * 473.176 << " mL\n";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }
}

void mass() {
    double val;
    char choice;

    cout << "\n--- Mass Conversion ---\n";
    cout << "For Pounds to Kilograms Enter '0'\n";
    cout << "For Ounces to Grams Enter '1'\n";
    cout << "For Tons to Metric Tons Enter '2'\n";
    cout << "Enter your choice here: ";
    cin >> choice;

    cout << "Enter the value to convert: ";
    cin >> val;

    switch (choice) {
        case '0':
            cout << "Value " << val << " converted to " << val * 0.453592 << " kg\n";
            break;
        case '1':
            cout << "Value " << val << " converted to " << val * 28.3495 << " g\n";
            break;
        case '2':
            cout << "Value " << val << " converted to " << val * 0.907185 << " metric tons\n";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }
}

void time() {
    double val;
    char choice;

    cout << "\n--- Time Conversion ---\n";
    cout << "For Seconds to Minutes Enter '0'\n";
    cout << "For Minutes to Hours Enter '1'\n";
    cout << "For Hours to Seconds Enter '2'\n";
    cout << "Enter your choice here: ";
    cin >> choice;

    cout << "Enter the value to convert: ";
    cin >> val;

    switch (choice) {
        case '0':
            cout << "Value " << val << " converted to " << val / 60 << " min\n";
            break;
        case '1':
            cout << "Value " << val << " converted to " << val / 60 << " h\n";
            break;
        case '2':
            cout << "Value " << val << " converted to " << val * 3600 << " s\n";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }
}

void temperature() {
    double val;
    char choice;

    cout << "\n--- Temperature Conversion ---\n";
    cout << "For Celsius to Fahrenheit Enter '0'\n";
    cout << "For Fahrenheit to Celsius Enter '1'\n";
    cout << "For Celsius to Kelvin Enter '2'\n";
    cout << "For Kelvin to Celsius Enter '3'\n";
    cout << "Enter your choice here: ";
    cin >> choice;

    cout << "Enter the value to convert: ";
    cin >> val;

    switch (choice) {
        case '0':
            cout << "Value " << val << " converted to " << (val * 9 / 5) + 32 << " F\n";
            break;
        case '1':
            cout << "Value " << val << " converted to " << (val - 32) * 5 / 9 << " C\n";
            break;
        case '2':
            cout << "Value " << val << " converted to " << val + 273.15 << " K\n";
            break;
        case '3':
            cout << "Value " << val << " converted to " << val - 273.15 << " C\n";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }
}

void area() {
    double val;
    char choice;

    cout << "\n--- Area Conversion ---\n";
    cout << "For Square Feet to Square Meters Enter '0'\n";
    cout << "For Acres to Hectares Enter '1'\n";
    cout << "For Square Miles to Square Kilometers Enter '2'\n";
    cout << "Enter your choice here: ";
    cin >> choice;

    cout << "Enter the value to convert: ";
    cin >> val;

    switch (choice) {
        case '0':
            cout << "Value " << val << " converted to " << val * 0.092903 << " m²\n";
            break;
        case '1':
            cout << "Value " << val << " converted to " << val * 0.404686 << " ha\n";
            break;
        case '2':
            cout << "Value " << val << " converted to " << val * 2.58999 << " km²\n";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }
}


