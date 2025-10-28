#include <iostream>
#include <cmath>
#include <string>


using namespace std;

int main()
{
	
	// Show entry screen
	cout << endl;
	cout << "*******************************************************************************************************************" << endl << endl
		<< "                                        Calculating Function Application" << endl << endl
		<< "*******************************************************************************************************************" << endl << endl
		<< "                                            Press Enter to start" << endl;

	int key = 0;

	while (key != 10)
		key = cin.get();

	while (true) {

		// Show main menu
		cout << "\033[2J\033[1;1H";
		cout.flush();

		cout << endl;
		cout << "*******************************************************************************************************************" << endl << endl
			<< "                                                    Main Menu" << endl << endl
			<< "*******************************************************************************************************************" << endl << endl
			<< "1) Help" << endl
			<< "2) Calculate function" << endl
			<< "3) About application" << endl
			<< "4) Exit" << endl
			<< "Enter value 1-4 to select action: ";

		key = cin.get();

		// cin.ignore();

		if (key < 49 || key > 52)
			continue;

		cin.ignore();

		if (key == 49) {

			cout << "\033[2J\033[1;1H";
			cout.flush();

			cout << endl;
			cout << "*******************************************************************************************************************" << endl << endl
				<< "                                                         Help" << endl << endl
				<< "*******************************************************************************************************************" << endl
				<< "The program calculates the following function:\n\tif x < 6 then: y = sum(i=1..n)prod(j=0..n+1) (j^2 - i^2) / (10*x + 1)\n\tif x >= 6 then: y = sum(i=5..7) x*i + prod(j=1..n) (x - j) / (x + j)" << endl << endl
				<< "All conditions are to be met, otherwise an error will be raised!\nThe conditions:\n\tn > 1,\n\ta < b,\n\tb - a > step." << endl << endl
				<< "                                            Press Enter to return to Main Menu" << endl;

			cin.get();
		}

		if (key == 50) {

			cout << "\033[2J\033[1;1H";
			cout.flush();

			cout << endl;
			cout << "*******************************************************************************************************************" << endl << endl
				<< "                                        Calculating Function Application" << endl << endl
				<< "*******************************************************************************************************************" << endl << endl
				<< "All conditions are to be met, otherwise an error will be raised!\nThe conditions:\n\tn > 1,\n\ta < b,\n\tb - a > step." << endl << endl;

			double x1 = 0, x2 = 0, step = 0;
			int n = 0;



			cout << endl << "Start input values for calculate function" << endl;

			while (true) {
				cout << "Enter n value(n > 1): ";

				if (!(cin >> n)) {
					cout << "Error: Invalid input (must be an integer)!" << endl;
					cin.clear();
					cin.ignore(100, '\n');

					continue;
				}

				if (n <= 1) {
					cout << "Error: n must be greater than 1!" << endl;
					continue;
				}
				break;
			}

			while (true) {
				cout << "Enter a value: ";

				if (!(cin >> x1)) {
					cout << "Error: Invalid input (must be a float)!" << endl;
					cin.clear();
					cin.ignore(100, '\n');

					continue;
				}
				break;
			}

			while (true) {
				cout << "Enter b value(b > a): ";
				if (!(cin >> x2)) {
					cout << "Error: Invalid input (must be a float)!" << endl;
					cin.clear();
					cin.ignore(100, '\n');

					continue;
				}

				if (x1 >= x2) {
					cout << "Error: b must be bigger than a!" << endl;
					continue;
				}
				break;
			}

			while (true) {
				cout << "Enter step value(b - a > step): ";
				if (!(cin >> step)) {
					cout << "Error: Invalid input (must be a float)!" << endl;
					cin.clear();
					cin.ignore(100, '\n');

					continue;
				}

				if (step <= 0 || step >= x2 - x1) {
					cout << "Error: \"step\" must meet the condition: step > 0 and b - a > step!" << endl;
					continue;
				}
				break;
			}

			for (double x = x1; x <= x2; x += step) {

				double sum = 0;
				double prod = 1;

				if (x < 6) {
					if (10 * x + 1 == 0) {
						// cout << "Error: a denominator shouldn't be zero" << endl;
						continue;
					}

					for (int i = 0; i <= n; i++) {
						for (int j = 0; j <= n + 1; j++) {
							prod *= (pow(j, 2) + pow(i, 2)) / (10 * x + 1);

						}

						sum += prod;
					}

					double y = sum;

					cout << "x = " << x << " y = " << y << endl;
				}
				else {
					for (int i = 5; i <= 7; i++) {
						sum += x * i;
					}

					for (int j = 1; j <= n; j++) {
						prod *= (x - j) / (x + j);
					}

					double y = sum - prod;

					cout << "x = " << x << " y = " << y << endl;
				}
			}

			cin.ignore();
			cout << "                                            Press Enter to return to Main Menu" << endl;
			cin.get();
		}

		if (key == 51) {

			cout << "\033[2J\033[1;1H";
			cout.flush();

			cout << endl;
			cout << "*******************************************************************************************************************" << endl << endl
				<< "                                                 About the application" << endl << endl
				<< "*******************************************************************************************************************" << endl
				<< "                                           The application calculates a function" << endl
				<< "                                            Author: Nesterenko Oleksii, KN-225e" << endl << endl
				<< "                                            Press Enter to return to Main Menu" << endl;

			cin.get();
		}

		if (key == 52) {

			cout << "\033[2J\033[1;1H";
			cout.flush();

			cout << endl;
			cout << "*******************************************************************************************************************" << endl << endl
				<< "                                          Are you sure you want to exit?" << endl << endl
				<< "*******************************************************************************************************************" << endl << endl
				<< "                                     Enter y to exit, or press Enter to return to Main Menu: ";

			key = cin.get();

			if (key == 0x59 || key == 0x79) // Y or y
				break;

		}
	}

	return 0;
}
