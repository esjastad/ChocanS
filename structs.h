
/* 
 * Author: Erik Jastad 
 * Date: 2 Nov 2018
 * Structures used in classes to hold and transfer data
 */

struct ServiceReport
{
	char CDT[20];	//Current Date and Time
	char DoS[11];	//Date of service
	int ProviderNum;
	int MemberNum;
	int ServiceCode;
	char Comments[101];
	ServiceReport * next;
};

struct ProviderMember
{
	char Name[26];
	int IDNumber;
	char StreetAddress[26];
	char City[15];
	char State[3];
	int ZipCode;
	int Status;	//member status, 0 for suspended, 1 for valid
};

struct ServiceCode
{
	int Code;
	char ServiceName[20];
	float Fee;
};

struct Mhash
{
	ProviderMember Member;
	Mhash * next;
};

struct Phash
{
	ProviderMember Provider;
	Phash * next;
};

struct Dhash
{
	ServiceCode Service;
	Dhash * next;
};

struct MConsults
{
	char DoS[10];
	char ProviderName[25];
	char ServiceName[20];
	MConsults * next;
};

struct MReport
{
	ProviderMember Report;
	MConsults * Consults;
};

struct MRepHash
{
	MReport Member;
	MRepHash * next;
};

struct PConsults
{
	char DoS[10];
	char CDT[19];
	char MemberName[25];
	int MemberNum;
	int ServiceCode;
	float Fee;
	PConsults * next;
};

struct PReport
{
	ProviderMember Report;
	PConsults * Consults;
	int TotalConsults;
	float TotalFee;
};

struct PRepHash
{
	PReport Provider;
	PRepHash * next;
};

