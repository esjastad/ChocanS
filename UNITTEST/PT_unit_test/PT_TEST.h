/* November 30 2018
 * Kathryn Silva
 * CS 300-003: Group 7
 */

#include "scanner.h"

/* 
 * Provider Terminal test object for unit testing.
 */
class PT_TEST {

	public:

		PT_TEST();

		int ValidateMember();	
		int ValidateProvider();	

	private:

		void LogMemberIn(int);
		void LogMemberOut(int);
		bool MemberLoggedIn(int);
		int CheckProviderNum();

		int ProviderNum;
		int MemberNum[10];	

};
