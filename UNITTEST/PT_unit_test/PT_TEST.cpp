/* November 30 2018
 * Kathryn Silva
 * CS 300-003: Group 7
 */

#include "PT_TEST.h"

/* 
 * Provider terminal test object for unit testing.
 * Calls to Data Center are omitted. 
 */
PT_TEST::PT_TEST() {
	ProviderNum = 0; 
	for (int i = 0; i < 10; ++i)
		MemberNum[i] = 0;
}


int PT_TEST::ValidateProvider() {

	/* Test data */	
	int test_provider = 123456789;
	
	if (ProviderNum) {
		cout << "Provider " << ProviderNum << " is logged in." << endl;
		return 1;
	}
	
	int input = 0; 
	cout << "Enter provider ID number: ";
	get_digits(input, 9);

	//int result = DC->ValidateProvider(input);
	int result = (input == test_provider);

	if (result == 1) {
		cout << "VALIDATED" << endl;
		ProviderNum = input;
	} else cout << "INVALID" << endl;
	
	return result;
}


int PT_TEST::CheckProviderNum() {
	if (!ProviderNum) { // provider not logged in
		cout << "Permission denied: Provider is not logged in." << endl;
		return ValidateProvider();
	} else return 1;
}


int PT_TEST::ValidateMember() {
	
	/* Test data */
	struct member {
		int IDNumber;
		int Status;
	}; 
	
	member m[2];  // dummy members	
	m[0].IDNumber = 100000000; // suspended member
	m[0].Status = 0;
	m[1].IDNumber = 111111111; // valid member
	m[1].Status = 1;

	if (!CheckProviderNum()) return 0;

	int input = 0; 
	cout << "Enter member ID number: ";
	get_digits(input, 9);

	if (!MemberLoggedIn(input)) {

		//int result = DC->ValidateMember(input);
		int result;
		if (input == m[0].IDNumber) result = m[0].Status;
		else if (input == m[1].IDNumber) result = m[1].Status;
		else result = 2; // nonexistant id

		if (result == 1) {
			LogMemberIn(input);
			cout << "VALIDATED" << endl; 
		} else if (result == 0) {
			cout << "SUSPENDED" << endl;
		} else { 
			cout << "INVALID" << endl;
		}

		return result;

	} else { // member is logged in
		//return DC->ServiceReport(input);
		cout << "Member " << input << " is logged in." << endl;
		return 1;
	}
}


bool PT_TEST::MemberLoggedIn(int IDNum) {
	for (int i = 0; i < 10; ++i) 
		if (MemberNum[i] == IDNum) return true;
	return false;
}

void PT_TEST::LogMemberOut(int IDNum) {
	for (int i = 0; i < 10; ++i) {
		if (MemberNum[i] == IDNum) {
			MemberNum[i] = 0;
			return;
		}
	}
}

void PT_TEST::LogMemberIn(int IDNum) {
	for (int i = 0; i < 10; ++i) {
		if (MemberNum[i] == 0) {
			MemberNum[i] = IDNum;
			return;
		}
	}
	// Too many members logged in. Overwrite first member.
	MemberNum[0] = IDNum;
}


