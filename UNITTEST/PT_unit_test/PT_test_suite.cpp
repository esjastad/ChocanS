/* November 30 2018
 * Kathryn Silva
 * CS 300-003: Group 7
 */

#include <iostream>
#include "PT_TEST.h"

using namespace std;

bool test_ValidateProvider(PT_TEST*);
bool test_ValidateMember(PT_TEST*);

/*
 * Provider Terminal unit test suite. 
 * Tests member and provider validation, and input handler (scanner).
 */
int main () {
	cout << "Running ProviderTerminal unit tests..." << endl << endl;

	PT_TEST* PTT;

	PTT = new PT_TEST();
	if (!test_ValidateProvider(PTT))
		cout << "[FAIL] ValidateProvider has failed some unit tests." << endl << endl;
	else cout << "[PASS] ValidateProvider successfully passed all tests." << endl << endl;

	if (!test_ValidateMember(PTT)) 
		cout << "[FAIL] ValidateMember has failed some unit tests." << endl << endl;
	else cout << "[PASS] ValidateMember successfully passed all tests." << endl << endl;
	delete PTT;

	return 0;
}

bool test_ValidateProvider(PT_TEST* PTT) {
	cout << "Running ValidateProvider tests..." << endl << endl;

	bool success = true;
	int result;
	int expected;


	/* Invalid inputs: inputs containing non-digits, 
     * inputs of invalid length, and a nonexistent provider number.
	 */
	cout << "[TEST] ValidateProvider: Invalid provider numbers" << endl << endl;
	expected = 0;
	result = PTT->ValidateProvider();
	if (result != expected) {
		cout << endl << "[FAIL] ValiateProvider: Invalid provider numbers" << endl;
		cout << "Expected: " << expected << ", result: " << result << endl << endl;
		success = false;
	} else cout << endl << "[PASS] ValidateProvider: Invalid provider numbers" << endl << endl;
	

	// Valid provider number: 1
	cout << "[TEST] ValidateProvider: Valid provider number (provider not logged in)" << endl << endl;
	expected = 1;
	result = PTT->ValidateProvider();
	if (result != expected) {
		cout << endl << "[FAIL] ValiateProvider: Valid provider number (not logged in)" << endl;
		cout << "Expected: " << expected << ", result: " << result << endl << endl;
		success = false;
	} else cout << endl << "[PASS] ValidateProvider: Valid provider number (provider not logged in)" << endl << endl;


	// Provider already logged in: 1
	cout << "[TEST] ValidateProvider: Valid provider number (provider logged in)" << endl << endl;
	expected = 1;
	result = PTT->ValidateProvider();
	if (result != expected) {
		cout << endl << "[FAIL] ValidateProvider: Valid provider number (provider logged in)" << endl;
		cout << "Expected: " << expected << ", result: " << result << endl << endl;
		success = false;
	} else cout << endl << "[PASS] ValidateProvider: Valid provider number (provider logged in)" << endl << endl;


	return success;
}

bool test_ValidateMember(PT_TEST* PTT) {
	cout << "Running ValidateMember tests..." << endl << endl; 
	
	bool success = true;
	int result;
	int expected;


	/* Invalid inputs: inputs containing non-digits, 
     * inputs of invalid length, and a nonexistent member number.
	 */
	cout << "[TEST] ValidateMember: Invalid member numbers" << endl << endl;
	expected = 2;
	result = PTT->ValidateMember();
	if (result != expected) {
		cout << endl << "[FAIL] ValidateMember: Invalid member numbers" << endl;
		cout << "Expected: " << expected << ", result: " << result << endl << endl;
		success = false;
	} else cout << endl << "[PASS] ValidateMember: Invalid member numbers" << endl << endl;


	// Suspended member number: 0
	cout << "[TEST] ValidateMember: Suspended member number" << endl << endl;
	expected = 0;
	result = PTT->ValidateMember();
	if (result != expected) {
		cout << endl << "[FAIL] ValidateMember: Suspended member number" << endl;
		cout << "Expected: " << expected << ", result: " << result << endl << endl;
		success = false;
	} else cout << endl << "[PASS] ValidateMember: Suspended member number" << endl << endl;


	// Valid member number: 1
	cout << "[TEST] ValidateMember: Valid member number (member not logged in)" << endl << endl;
	expected = 1;
	result = PTT->ValidateMember();
	if (result != expected) {
		cout << endl << "[FAIL] ValidateMember: Valid member number (member not logged in)" << endl;
		cout << "Expected: " << expected << ", result: " << result << endl << endl;
		success = false;
	} else cout << endl << "[PASS] ValidateMember: Valid member number (member not logged in)" << endl << endl;


	// Member already logged in: 1
	cout << "[TEST] ValidateMember: Valid member number (member logged in)" << endl << endl;
	expected = 1;
	result = PTT->ValidateMember();
	if (result != expected) {
		cout << endl << "[FAIL] ValidateMember: Valid member number (member logged in)" << endl;
		cout << "Expected: " << expected << ", result: " << result << endl << endl;
		success = false;
	} else cout << endl << "[PASS] ValidateMember: Valid member number (member logged in)" << endl << endl;


	return success;
}
