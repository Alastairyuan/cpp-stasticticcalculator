#include <splashkit.h>
using std::stoi;
using std::to_string;

int main() 
{
    write_line("Welcome to the simple stats calculator:");

    int count = 0;
    double total = 0.0;
    double minVal = 0.0, maxVal = 0.0;
    bool keepGoing = true;

    while (keepGoing) {
        write("Enter value: ");
        string line;
        line = read_line();

        if (line.empty()) {
            write_line("You must enter a value.");
            continue;
        }
        double value;
        try {
            value = stod(line);
        } catch (...) {
            write_line("The input format is incorrect. Please enter valid number");
            continue;
        }

        count++;
        total += value;

        if (count == 1) 
        {
            minVal = value;
            maxVal = value;
        } else {
            if (value < minVal) minVal = value;
            if (value > maxVal) maxVal = value;
        }

        double average = total / count;

        write_line("Count: " + to_string(count));
        write_line("Total: " + to_string(total));
        write_line("Min: " + to_string(minVal));
        write_line("Max: " + to_string(maxVal));
        write_line("Average: " + to_string(average));

        write("\nAdd another value: [y/n] ");
        string response;
        response = read_line();
        keepGoing = (response == "y" || response == "Y");
    }

    write_line("I hope you got the information you are after!");
    return 0;
}
