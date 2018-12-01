#include "ProviderTerminal.h"

class ManagerTerminal {

    public:
        ManagerTerminal(FileManager* ,DataCenter*, ProviderDirectoryHandler*,int);
        int AddProvider(void);
        int AddMember(void);
        int AddService(void);
        int EditProvider(void);
        int EditMember(void);
        int EditService(void);
        int DeleteProvider(void);
        int DeleteMember(void);
        int DeleteService(void);
        int ReportMembers(void);
        int ReportProviders(void);
        int ReportSummary(void);
        int ReportEFT(void);
        int ReportAll(void);
	void menu();

    private:
        bool InputDate(char*);
        int InputDayOfWeek();

        int TerminalID;
        struct ProviderMember person;
        DataCenter * DC;
        ProviderDirectoryHandler* pd_handler_;
        FileManager* file_manager_;
};
