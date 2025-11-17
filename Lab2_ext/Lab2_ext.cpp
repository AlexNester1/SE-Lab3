#include <iostream>
#include <cmath>
#include <string>


using namespace std;

void showMainScreen() {
	// Show entry screen
	cout << endl;
	cout << "*******************************************************************************************************************" << endl << endl
		<< "                                        Calculating Function Application" << endl << endl
		<< "*******************************************************************************************************************" << endl << endl
		<< "                                            Press Enter to start" << endl;

}

void showMainMenu() {
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

}

void showHelpScreen() {

	cout << "\033[2J\033[1;1H";
	cout.flush();

	cout << endl;
	cout << "*******************************************************************************************************************" << endl << endl
		<< "                                                         Help" << endl << endl
		<< "*******************************************************************************************************************" << endl
		<< "The program calculates the following function:\n\tif x < 6 then: y = sum(i=1..n)prod(j=0..n+1) (j^2 - i^2) / (10*x + 1)\n\tif x >= 6 then: y = sum(i=5..7) x*i + prod(j=1..n) (x - j) / (x + j)" << endl << endl
		<< "All conditions are to be met, otherwise an error will be raised!\nThe conditions:\n\tn > 1,\n\ta < b,\n\tb - a > step." << endl << endl
		<< "                                            Press Enter to return to Main Menu" << endl;

}

void showCalculationScreen() {

	cout << "\033[2J\033[1;1H";
	cout.flush();

	cout << endl;
	cout << "*******************************************************************************************************************" << endl << endl
		<< "                                        Calculating Function Application" << endl << endl
		<< "*******************************************************************************************************************" << endl << endl
		<< "All conditions are to be met, otherwise an error will be raised!\nThe conditions:\n\tn > 1,\n\ta < b,\n\tb - a > step." << endl << endl;

}

void showAboutScreen() {

	cout << "\033[2J\033[1;1H";
	cout.flush();

	cout << endl;
	cout << "*******************************************************************************************************************" << endl << endl
		<< "                                                 About the application" << endl << endl
		<< "*******************************************************************************************************************" << endl
		<< "                                           The application calculates a function" << endl
		<< "                                            Author: Nesterenko Oleksii, KN-225e" << endl << endl
		<< "                                            Press Enter to return to Main Menu" << endl;

}

void showExitScreen() {

	cout << "\033[2J\033[1;1H";
	cout.flush();

	cout << endl;
	cout << "*******************************************************************************************************************" << endl << endl
		<< "                                          Are you sure you want to exit?" << endl << endl
		<< "*******************************************************************************************************************" << endl << endl
		<< "                                     Enter y to exit, or press Enter to return to Main Menu: ";

}

void checkValidInput(const char* err_message) {

	if (cin.fail())
		throw err_message;
}

void checkNParam(int n, const char* err_message) {

	if (n <= 1)
		throw err_message;
}

void checkX2Param(double x1, double x2, const char* err_message) {

	if (x1 >= x2)
		throw err_message;
}

void checkStepParam(double step, double x1, double x2, const char* err_message) {

	if (step <= 0 || step >= x2 - x1)
		throw err_message;
}

void checkDenominatorIsZero(double x, const char* err_message) {

	if (10 * x + 1 == 0)
		throw err_message;
}

double doRealCalculation(double x, int n) {

	double sum = 0;
	double prod = 1;

	if (x < 6) {
		try {
			checkDenominatorIsZero(x, "Error: a denominator shouldn't be zero!");
		}
		catch (const char* ex) {
			cout << ex << endl;
			return 0;
		}

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n + 1; j++) {
				prod *= (pow(j, 2) + pow(i, 2)) / (10 * x + 1);

			}

			sum += prod;
		}

		return sum;
	}
	else {
		for (int i = 5; i <= 7; i++) {
			sum += x * i;
		}

		for (int j = 1; j <= n; j++) {
			prod *= (x - j) / (x + j);
		}

		return sum - prod;
	}

}

void doCalculation() {

	double x1 = 0, x2 = 0, step = 0;
	int n = 0;

	cout << endl << "Start input values for calculate function" << endl;

	while (true) {

		try {
			cout << "Enter n value(n > 1): ";
			cin >> n;
			checkValidInput("Error: Invalid input (must be an integer)!");
			checkNParam(n, "Error: n must be greater than 1!");
			break;
		}
		catch (const char* ex) {
			cout << ex << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
		catch (...) {
			cout << "Unknown error!" << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}

	while (true) {

		try {
			cout << "Enter a value: ";
			cin >> x1;
			checkValidInput("Error: Invalid input(must be a float)!");
			break;
		}
		catch (const char* ex) {
			cout << ex << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
		catch (...) {
			cout << "Unknown error!" << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}

	while (true) {

		try {
			cout << "Enter b value(b > a): ";
			cin >> x2;
			checkValidInput("Error: Invalid input (must be a float)!");
			checkX2Param(x1, x2, "Error: b must be bigger than a!");
			break;
		}
		catch (const char* ex) {
			cout << ex << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
		catch (...) {
			cout << "Unknown error!" << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}

	while (true) {

		try {
			cout << "Enter step value(b - a > step): ";
			cin >> step;
			checkValidInput("Error: Invalid input (must be a float)!");
			checkStepParam(step, x1, x2, "Error: \"step\" must meet the condition: step > 0 and b - a > step!");
			break;
		}
		catch (const char* ex) {
			cout << ex << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
		catch (...) {
			cout << "Unknown error!" << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}

	double y;

	for (double x = x1; x <= x2; x += step) {

		y = doRealCalculation(x, n);

		cout << "x = " << x << " y = " << y << endl;
	}

}

int main() // Hello world!
{

	int key = 0;

	showMainScreen();

	while (key != 10)
		key = cin.get();

	while (true) {

		showMainMenu();

		key = cin.get();

		if (key < 49 || key > 52)
			continue;

		cin.ignore();

		if (key == 49) {

			showHelpScreen();

			cin.get();

			continue;
		}

		if (key == 50) {

			showCalculationScreen();

			doCalculation();

			cin.ignore();
			cout << "                                            Press Enter to return to Main Menu" << endl;
			cin.get();

			continue;
		}

		if (key == 51) {

			showAboutScreen();

			cin.get();

			continue;
		}

		if (key == 52) {

			showExitScreen();

			key = cin.get();

			if (key == 0x59 || key == 0x79) // Y or y
				break;

		}
	}

	return 0;
}
