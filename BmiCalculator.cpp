#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double weight, height, bmi;

    // Get weight input
    cout << "Enter your weight in kilograms: ";
    cin >> weight;

    // Get height input
    cout << "Enter your height in meters: ";
    cin >> height;

    // Calculate BMI
    bmi = weight / (height * height);

    // Display BMI with two decimal precision
    cout << fixed << setprecision(2);
    cout << "\nYour BMI is: " << bmi << endl;

    // Determine BMI category
    if (bmi < 18.5) {
        cout << "Category: Underweight" << endl;
    } else if (bmi >= 18.5 && bmi < 24.9) {
        cout << "Category: Normal weight" << endl;
    } else if (bmi >= 25 && bmi < 29.9) {
        cout << "Category: Overweight" << endl;
    } else {
        cout << "Category: Obesity" << endl;
    }

    return 0;
}
