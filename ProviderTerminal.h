/* November 30 2018
 * Kathryn Silva
 * CS 300-003: Group 7
 */

#include "scanner.h"
#include <ctime>
#include "pdrp.h"

/* 
 * Provider Terminal class.
 */
class ProviderTerminal {

	public:

		ProviderTerminal(DataCenter*, ProviderDirectoryHandler*);

		int ValidateMember();	
		int ValidateProvider();	
		int DirectoryRequest();	
		void menu();

	private:

		int ServiceReport(int);	
		void LogMemberIn(int);
		void LogMemberOut(int);
		bool MemberLoggedIn(int);
		int CheckProviderNum();

		int ProviderNum;
		int MemberNum[10];	
		struct ServiceReport Report;
		DataCenter* DC;
		ProviderDirectoryHandler* pd_handler_;	
};



