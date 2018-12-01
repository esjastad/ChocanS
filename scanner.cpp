/**
 * Scanner suite 
 * All input buffers must be initialized before passing to functions.
 * Created for CS 202-003 (Spring 2018)
 * @author Kathryn Silva
 */

#include "scanner.h"

/**
 * Read a string limited by the specified length.
 * @param input The input buffer.
 * @param length The limit for the input length.
 */
void get_string(char* input, int length) {
	cin.get(input, length+1, '\n');
	while (cin.peek() != '\n') {
		cout << "Invalid length. Enter a shorter string: ";
		cin.ignore(1000, '\n');
		cin.get(input, length+1, '\n');
	}
	cin.ignore(1000, '\n');	
}

/**
 * Read a string.
 * @param input The input buffer.
 */
void get_string(char* input) {
	const int length = 10000; // arbitrary limit
	cin.get(input, length, '\n');
	while (cin.peek() != '\n') {
		cout << "Invalid length. Enter a shorter string: ";
		cin.ignore(1000, '\n');
		cin.get(input, length, '\n');
	}
	cin.ignore(1000, '\n');	
}

/** 
 * Read an integer in the given range.
 * @param input The input buffer.
 * @param min The minimum allowed value.
 * @param max The maximum allowed value.
 */
void get_int(int& input, int min, int max) {
	while (!cin || (input > max || input < min)) {
		cout << "Invalid entry. Enter a number in the range [";
		cout << min << ", " << max << "]: ";
		cin.clear();
		cin >> input;
	}
	cin.ignore(1000, '\n');	
}

/**
 * Read an n-digit integer.
 * @param input The input buffer.
 * @param n The desired number of digits.
 */
void get_digits(int& input, int n) {
	int divisor = 1;
	for (int i = 1; i < n; ++i) divisor *= 10;

	input = 0;
	while(!input)
	{
		cin >> input;

	       	if (!cin || (input/divisor >= 10 || input/divisor < 1))
		{
			cout << "Invalid entry. Enter a " << n << "-digit number: ";
			input = 0;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	} 

	cin.ignore(1000,'\n');
}

/** 
 * Read a positive integer.
 * @param input The input buffer.
 */
void get_pos_int(int& input) {
	while (cin >> input || (input <= 0)) {
		cout << "Invalid entry. Enter a positive number: ";
		cin.clear();
		cin >> input;
	}
}

/** 
 * Read an uppercase character.
 * Does not check character type.
 * @param input The input buffer.
 */
void get_up_char(char& input) {
    cin >> input;
    cin.ignore(100, '\n'); 
    input = toupper(input);
}

/**
 * Read a date in MM-DD-YYYY format.
 * Currently only allows 2YYY dates.
 * @param input The input buffer.
 */
void get_date(char* input) {

	char MM[2];
	char DD[2];
	char YYYY[4];
	bool done = false;
	char * ptr;

	do {
		cout << "Enter month (MM): ";
		get_string(MM, 2);

		if (MM[0] == '0') 					// check 01-09
			if (MM[1] > '0' && MM[1] <= '9') done = true;
		if (MM[0] == '1') 					// check 10-12
			if (MM[1] >= '0' && MM[1] <= '2') done = true;

		if (!done) cout << "Invalid entry. ";

	} while (!done);
	done = false;
	
	ptr = &MM[0]; // required for strcpy to work
	strcpy(input, ptr);
	strcat(input, "-");
	
	do{
		cout << "Enter day (DD): ";
		get_string(DD, 2);

		if (DD[0] == '0') 					// check 01-09
			if (DD[1] > '0' && DD[1] <= '9') done = true;
		if (DD[0] == '1' || DD[0] == '2') 	// check 10-29
			if (DD[1] > '0' && DD[1] <= '9') done = true;
		if (DD[0] == '3') 					// check 30-31
			if (DD[1] == '0' || DD[1] == '1') done = true;

		if (!done) cout << "Invalid entry. ";

	} while (!done);
	done = false;

	ptr = &DD[0];
	strcat(input, ptr);
	strcat(input, "-");

	do {
		cout << "Enter year (YYYY): ";
		get_string(YYYY, 4);
		
		// XXX maybe change this to allow 19xx years?
		if (YYYY[0] == '2') done = true; // This should never != '2'
		for (int i = 1; i <= 3; ++i) // Ensure rest of chars are digits
			if (YYYY[i] < '0' || YYYY[i] > '9') done = false; 

		if (!done) cout << "Invalid entry. ";

	} while (!done);
	done = false;

	ptr = &YYYY[0];	
	strcat(input, ptr);
}

/**
 * Read answer to a yes/no question.
 * @return true Received yes answer.
 * @return false Received no answer.
 */
bool yes() {
	char input;
	get_up_char(input);
    while (input != 'Y' && input != 'N') {
        cout << "Invalid response. (y/n): ";
        get_up_char(input);
    }
    return input == 'Y'; 
}

/** 
 * Capitalize the input buffer.
 * @param input The input buffer to capitalize.
 */
void capitalize(char* input) {
	bool cap = false;
	input[0] = toupper(input[0]);
	for (int i = 0; input[i] != '\0'; ++i) {
		if (cap) {
			input[i] = toupper(input[i]);
			cap = false;
		} 
	
		if (input[i] == ' ') 
			cap = true;
	}
}
