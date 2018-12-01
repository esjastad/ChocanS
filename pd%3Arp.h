// This file is used to declear following classes:
// ProviderDirectoryHandler : the interface for ProviderTerminal and ManagerTerminal to use
// ProviderDirectoryLogging : DO NOT create this class's object individually, this class is 
//                            used during generating reports
// ReportGenerator : the interface for generating reports
// Concrete report factory classes : the classes which produce different types of reports
// Data Structure related classes : contain / transfer data purpose

#include "filesyspara.h"
#include "filesysclass.h"
#include "uni.h"

#define DEFAULT_PD_MAX            50
#define REMOVE_BY_CODE            1
#define REMOVE_BY_NAME            2
#define RETRIEVE_CODE             1
#define RETRIEVE_NAME             2

#define TRAVERSE_SERVICE          1
#define TRAVERSE_MEMBER_REPORT    2
#define TRAVERSE_PROVIDER_REPORT  3

#define PARSE_SERVICE             1
#define PARSE_REPORT              2

#define MAX_REPORT_SERVICE        50

//temporary parameter: the maximum number of services in 7 days 
#define MAX_SERVICE_RECORD        200

#define SUN 1
#define MON 2
#define TUE 3
#define WED 4
#define THU 5
#define FRI 6
#define SAT 7



class ProviderDirectoryEntry : public FObj {
    public:     
        ProviderDirectoryEntry();
        ProviderDirectoryEntry(char*, char*, float);
        ProviderDirectoryEntry(const ProviderDirectoryEntry&);

        ~ProviderDirectoryEntry();

        ProviderDirectoryEntry& operator=(const ProviderDirectoryEntry&);

        bool Read(ifstream&);
        bool Write(ofstream&) const;
        void Display() const;
        void Display(int) const;

        int CompareServiceName(ProviderDirectoryEntry&) const;
        int CompareServiceName(const char*) const;

        char* get_service_code() const;
        char* get_service_name() const;
        float get_fee() const;

    private:
        void Erase();

        char* service_name_;
        char* service_code_;
        float service_fee_;
};


class PdEntry : public ProviderDirectoryEntry {
    public: 
        PdEntry();
        PdEntry(char*, char*, float);
        PdEntry(const PdEntry&);

        bool Read(ifstream&);
        bool Write(ofstream&) const;
        void Display() const; 

        void Display(int) const;

        PdEntry* get_next() const;
        void set_next(PdEntry*);

    private: 
        PdEntry* next_;
};


class HashNode : public FObj {
    public: 
        HashNode();
        HashNode(char*);
        HashNode(int, char*);
        HashNode(const HashNode&);

        ~HashNode();

        bool Read(ifstream&);
        bool Write(ofstream&) const;
        void Display() const; 

        void set_next(HashNode*);
        HashNode* get_next() const;

        int CompareTime(const char*) const;
        int CompareTime(const HashNode*) const;

        float SearchFee(const char*) const;
        bool SearchServiceName(const char*, char*) const;

        int Hashing(const char*) const;

        char* get_time() const;
        void set_time(const char*);

    protected:
        PdEntry* CopyList(PdEntry* dst, PdEntry* scr);
        PdEntry* ClearList(PdEntry* phead);

        PdEntry** table_;
        int size_;
        char* time_;
    
    private:
        HashNode* next_;
};


class PdBinaryEntry {
    public: 
        PdBinaryEntry();
        PdBinaryEntry(PdEntry*);

        int CompareServiceName(const char*) const;
        int CompareServiceName(const PdBinaryEntry*) const;

        void set_entry(PdEntry*);
        PdEntry* get_entry() const;

        void set_left(PdBinaryEntry*);
        PdBinaryEntry* get_left() const;

        void set_right(PdBinaryEntry*);
        PdBinaryEntry* get_right() const;

        void Display() const;

    private:
        PdEntry* entry_ptr_;
        PdBinaryEntry* left_;
        PdBinaryEntry* right_;
};


// The interface of provider directory
// To create an object requires FileManager pointer and current time.
// For Manager Terminal:
// (1) Insert
// (2) Remove
// (3) Update
// (4) Display
// Once these modifications are done, call SavingChanges(). Otherwise 
// all the changes cannot be saved into the disk, which will cause 
// data inconsistency in the later report 
// For Provider Terminal:
// (1) Request a Provider Directory: Display()
// (2) Verify service code during interacting with member: VerifyCode()
// (3) The last step of interaction between member and provider is to 
//     display the overall information of service: Display(int)
//     pass in the service code in the previous step to display info.
// Do not call other functions.
class ProviderDirectoryHandler : public HashNode {
    public: 
        ProviderDirectoryHandler();
        ProviderDirectoryHandler(char*, FileManager*);
        ProviderDirectoryHandler(char*, int, FileManager*);
        ProviderDirectoryHandler(const ProviderDirectoryHandler&);

        ~ProviderDirectoryHandler();

        bool Insert();
        bool Remove();
        bool Update();
        void Display() const;
        bool Display(int) const;
        int VerifyCode() const;
        bool SavingChanges() const;

    private:
        void Init(); 
        bool ImportExternal();
        PdBinaryEntry* TreeInsertion(PdBinaryEntry* item, PdBinaryEntry* proot);
        PdBinaryEntry* TreeRemoveAll(PdBinaryEntry* proot);
        PdBinaryEntry* TreeRemove(PdEntry* pos, PdBinaryEntry* proot);
        PdBinaryEntry* ReplaceIOS(PdBinaryEntry* lchild, PdEntry** pdptr);
        void TreeDisplay(PdBinaryEntry* proot) const;
        bool Insert(PdEntry*);        
        int DisplayHash() const;
        bool RemoveAtPos(int pos);
        PdEntry* GetEntryAtPos(int pos);

        PdBinaryEntry* root_;
        char* current_time_;
        FileManager* f_manager_;
};


// This class is used in ReportGenerator, DO NOT create this 
// class's object, it connects to the FileManager directly 
// and modify external files in its constructors. 
// This class reads all versions of provider directories 
// in the time interval "char*" to "char*" in the constructor,
// which are assigned to time_max_ and time_min_.
// Then all the services fetch data from correct version of 
// provider directory based on its own current date and time 
// field. 
class ProviderDirectoryLogging {
    public: 
        ProviderDirectoryLogging();
        ProviderDirectoryLogging(FileManager*, char*, char*);
        ProviderDirectoryLogging(const ProviderDirectoryLogging&);

        ~ProviderDirectoryLogging();

        float SerachFee(const char*, const char*) const;
        bool SearchServiceName(const char*, const char*, char*) const;

        // test purpose function
        void Display();

    private: 
        bool ImportExternal();
        HashNode* Insert(HashNode&, HashNode*);
        HashNode* Clear(HashNode* phead);

        char* time_max_;
        char* time_min_;
        HashNode* head_;
        FileManager* f_manager_;
};



// service collection's length is MAX_REPORT_SERVICE
class DistrubutionNode {
    public: 
        DistrubutionNode();
        DistrubutionNode(char*);
        DistrubutionNode(const DistrubutionNode&);

        ~DistrubutionNode();

        int Compare(char*) const;

        FObjMemberReport* GenerateMemberReport(DataCenter*, char*);   
        FObjProviderReport* GenerateProviderReport(DataCenter*, char*);  

        void Insert(const FObjService*);

        DistrubutionNode* get_left() const;
        void set_left(DistrubutionNode*);

        DistrubutionNode* get_right() const;
        void set_right(DistrubutionNode*);

    private: 
        char* num_;
        FObjService** service_collection_;
        int collection_size_;
        DistrubutionNode* left_;
        DistrubutionNode* right_;
};


class ReportFactory {
    public: 
        ReportFactory();
        virtual ~ReportFactory();
        virtual int Produce(FObj**) = 0;
};


class MaterialFactory : public ReportFactory {
    public: 
        MaterialFactory();
        MaterialFactory(DataCenter*, FileManager*, char*, char*);
        MaterialFactory(const MaterialFactory&);

        ~MaterialFactory();

        MaterialFactory& operator=(const MaterialFactory&);

        int Produce(FObj**);

    protected:
        void Erase();

        DataCenter* data_center_;
        FileManager* file_manager_;
        FObjService* material_;
        int material_num_;
        char* date_min_;
        char* date_max_;
};

// member => 1
// provider => 2
class GeneralReportFactory : public MaterialFactory {
    public: 
        GeneralReportFactory();
        GeneralReportFactory(DataCenter*, FileManager*, char*, char*, int);
        GeneralReportFactory(const GeneralReportFactory&);

        ~GeneralReportFactory();

        GeneralReportFactory& operator=(const GeneralReportFactory&);

        int Produce(FObj**);
    
    protected:
        void Erase();
        DistrubutionNode* Copy(DistrubutionNode* dst, DistrubutionNode* scr);
        DistrubutionNode* Clear(DistrubutionNode* proot);
        DistrubutionNode* Insert(DistrubutionNode* proot, FObjService* item, char* pnum);

        void Produce(FObj**, DistrubutionNode* proot, int& index);
        void Generation();

        int type_;
        DistrubutionNode* assembler_;
};


class ManagerReportFactory : public ReportFactory {
    public: 
        ManagerReportFactory();
        ManagerReportFactory(FileManager*, char*, char*);
        ManagerReportFactory(const ManagerReportFactory&);

        ~ManagerReportFactory();

        int Produce(FObj**);

    private: 
        char* date_min_;
        char* date_max_;
        FileManager* file_manager_;
};


class EftReportFactory : public ReportFactory {
    public: 
        EftReportFactory();
        EftReportFactory(FileManager*, char*, char*);
        EftReportFactory(const EftReportFactory&);

        ~EftReportFactory();

        int Produce(FObj**);

    private: 
        char* date_min_;
        char* date_max_;
        FileManager* file_manager_;
};

// day_of_week: MON, TUE, WED, THU, FRI, SAT, SUN
// This class creates concrete factories to produce report.
// To create an object requires (1) FileManager pointer, 
// (2) DataCenter pointer, (3) current date and (4) day of
// week. Then, the service records from current date to 
// previous 7 days are read into the program and generate 
// reports. 
// The reports are saving in /report directory, but they
// won't display on the screen when these functions are called.
// Currently, no functions is provided to display reports via
// standard output.
// Member report path: 
//      /report/member/<member_number>/<report_name>.txt
// Provider report path: 
//      /report/provider/<provider_number>/<report_name>.txt
// Manager report path: 
//      /report/manager/<manager_number>/<report_name>.txt
// Member report path: 
//      /report/EFT/<report_name>.txt
class ReportGenerator {
    public: 
        ReportGenerator();
        ReportGenerator(FileManager*, DataCenter*, char*, int);
        ReportGenerator(const ReportGenerator&);

        ~ReportGenerator();

        bool GenerateMemberReport();
        bool GenerateProviderReport();
        bool GenerateManagerReport();
        bool GenerateEftReport();

    private:  
        char* date_;
        int day_of_week_;
        FileManager* file_manager_;
        DataCenter* data_center_;
};
