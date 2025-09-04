#include <splashkit.h>
using std::stoi;
using std::to_string;

int main() 
{
    // Print welcome message
    write_line("Welcome to the simple stats calculator:");

    int count = 0;             // number of inputs
    double total = 0.0;        // sum of all values
    double minVal = 0.0, maxVal = 0.0; // min and max values
    bool keepGoing = true;     // keep asking user

    while (keepGoing) {
        write("Enter value: ");
        string line;
        line = read_line();

        if (line.empty()) {
            // user did not type anything
            write_line("You must enter a value.");
            continue;
        }
        double value;
        try {
            value = stod(line);  // convert input to number
        } catch (...) {
            // wrong format, not a number
            write_line("The input format is incorrect. Please enter valid number");
            continue;
        }

        count++;
        total += value;

        // set min and max for the first value
        if (count == 1) 
        {
            minVal = value;
            maxVal = value;
        } else {
            if (value < minVal) minVal = value;
            if (value > maxVal) maxVal = value;
        }

        double average = total / count; // calculate average

        // print stats
        write_line("Count: " + to_string(count));
        write_line("Total: " + to_string(total));
        write_line("Min: " + to_string(minVal));
        write_line("Max: " + to_string(maxVal));
        write_line("Average: " + to_string(average));

        // ask if user wants to continue
        write("\nAdd another value: [y/n] ");
        string response;
        response = read_line();
        keepGoing = (response == "y" || response == "Y");
    }

    // end of program
    write_line("I hope you got the information you are after!");
    return 0;
}


    write_line("I hope you got the information you are after!");
    return 0;
}
