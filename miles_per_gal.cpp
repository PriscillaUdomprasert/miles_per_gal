#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "Miles Per Gallon" << endl << endl;

    string filename = "trips.txt";

    double miles, gas_gal;

    char choice = 'y';

    while (choice == 'y' || choice == 'Y')
    {
        while (true)
        {
            cout << "Enter miles driven: ";
            cin >> miles;

            if (miles < 0)
            {
                cout << "Miles driven must be greater zero. Please try again.";
                cout << endl;
                continue;
            }
            break;
        }
        while (true)
        {
            cout << "Enter gallons of gas used: ";
            cin >> gas_gal;

            if (gas_gal < 0)
            {
                cout << "Gallons of gas must be greater than zero. Please try again.";
                cout << endl;
                continue;
            }
            break;
        }

        ofstream output_file;
        output_file.open(filename);

        double mpg = miles / gas_gal;

        cout << fixed << setprecision(1);
        output_file << miles << '\t' << gas_gal << '\n';
        
        cout << "Miles per gallon: " << mpg << endl;

        output_file.close();

        cout << "\nPress y for another trip or any other letter to quit: ";
        cin >> choice;
        cout << endl;
    }

    cout << "Bye!" << endl;
}
