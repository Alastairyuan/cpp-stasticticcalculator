#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    cout << "Welcome to the simple stats calculator:" << endl;

    int count = 0;
    double total = 0.0;
    double minVal = 0.0, maxVal = 0.0;
    bool keepGoing = true;

    while (keepGoing) {
        cout << "Enter value: ";
        string line;
        getline(cin, line);

        if (line.empty()) {
            cout << "You must enter a value." << endl;
            continue;
        }
        double value;
        try {
            value = stod(line); // string 转 double
        } catch (...) {
            cout << "The input format is incorrect. Please enter valid number" << endl;
            continue;
        }

        count++;
        total += value;

        if (count == 1) {
            minVal = value;
            maxVal = value;
        } else {
            if (value < minVal) minVal = value;
            if (value > maxVal) maxVal = value;
        }

        double average = total / count;

        cout << "Count: " << count << endl;
        cout << "Total: " << total << endl;
        cout << "Min: " << minVal << endl;
        cout << "Max: " << maxVal << endl;
        cout << "Average: " << average << endl;

        cout << "\nAdd another value: [y/n] ";
        string response;
        getline(cin, response);
        keepGoing = (response == "y" || response == "Y");
    }

    cout << "I hope you got the information you are after!" << endl;
    return 0;
}
