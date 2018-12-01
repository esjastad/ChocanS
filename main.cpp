/* 
 * Author: Erik Jastad 
 * Date: 17 Nov 2018
 * Simulates either a manager or provider terminal.
 */

#include "ManagerTerminal.h"

int main()
{
	//Get current date and time
	char CDT[len2sz(LEN_TIME)];
	time_t rawtime;
	struct tm * timestring;
	time(&rawtime);
	timestring = localtime(&rawtime);
	strftime(CDT, len2sz(LEN_TIME), "%m_%d_%Y_%H_%M_%S", timestring);
	

	//Create classes
	FileManager* f = new FileManager();
	f -> Initialize();
	DataCenter* d = new DataCenter(f);
	ProviderDirectoryHandler* handler = new ProviderDirectoryHandler(CDT, f);
	ProviderTerminal* pterminal = new ProviderTerminal(d, handler);
	ManagerTerminal* mterminal = new ManagerTerminal(f,d,handler, 3);

	int Selection=0;	//Menu selection variable	

	//Menu Options	
	while(Selection!=3)
	{
		cout << "\n\nCHOCAN SIMULATOR\n";
		cout << "Please enter a number selection from the menu below\n"
		     << "1)  Simulate a Provider Terminal.\n"
		     << "2)  Simulate a Managers Terminal.\n"
		     << "3)  Quit\n"
		     << "Menu Choice: ";
		get_digits(Selection, 1);

		if(Selection == 1)
		{
			pterminal->menu();	//Start provider terminal menu
			Selection = 0;
		}

		if(Selection == 2)
		{
			mterminal->menu();	//start manager terminal menu
			Selection = 0;
		}
	}

	delete handler;
	delete d;
	delete f;
	delete pterminal;
	delete mterminal;

	return 0;
}
