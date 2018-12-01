// Copyright (c) 2018 Yiming Lin
// This file is the header for the service record unit tests
// Some functions are only testing purposes, they are not
// going to appear in the product's source code.

#include <fstream>

#define len2sz(x) ((int)(x) + 1)
#define ch2int(x) ((char)(x) - 48)
#define LEN_MEMBER_NUM        9
#define LEN_PROVIDER_NUM      9
#define LEN_SERVICE_CODE      6
#define LEN_DATE              10
#define LEN_TIME              19
#define LEN_COMMENT           100
#define LEN_PROVIDER_NAME     25
#define LEN_MEMBER_NAME       25


struct ServiceReport {
	char CDT[20];	
	char DoS[11];	
	int ProviderNum;
	int MemberNum;
	int ServiceCode;
	char Comments[101];
	ServiceReport * next;
};


class FObjService {
    public:
        FObjService();
        FObjService(char*, char*, char*, char*, char*, char*);
        FObjService(struct ServiceReport&);
        FObjService(const FObjService&);

        ~FObjService();

        FObjService& operator=(const FObjService&);
        
        bool Read(std :: ifstream&);
        bool Write(std :: ofstream&) const;
        void Display() const;

        bool GenerateFileName(char*) const;
        bool get_date(char*) const;
        bool GetComputerReceivedDate(char*) const;

        // testing purpose function
        // the following functions only exist in the unit test
        // these functions are not going to exist in the product's 
        // source code
        char* get_date() const;
        char* get_time() const;
        char* get_provider_num() const;
        char* get_member_num() const;
        char* get_service_code() const;
        char* get_comment() const;

    protected:
        void Erase();

        char* date_;
        char* time_;
        char* provider_num_;
        char* member_num_;
        char* service_code_;
        
    private:
        char* comment_;
};
