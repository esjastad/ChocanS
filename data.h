/* 
 * Author: Floris Creyf
 * Date: 12 Nov 2018
 * Stores and fetches information.
 */

#ifndef DATA_H
#define DATA_H

#include "structs.h"
#include <vector>
#include <map>
#include <deque>

class Data {
protected:
	/* Pretend this is the database or something. */
	std::map<int, ProviderMember> members;
	std::map<int, ProviderMember> providers;
	std::map<int, ServiceCode> serviceCodes;
	std::deque<std::map<int, ServiceReport> > services;
	int serviceid;

	/* List of members/providers to be deleted. */	
	std::vector<int> removedMembers;
	std::vector<int> removedProviders;

	ProviderMember merge(ProviderMember&, ProviderMember&);

public:
	Data();

	bool validateMember(ProviderMember &);
	bool addMember(ProviderMember);
	bool editMember(ProviderMember);
	/** Zero/null fields are not replaced. */
	ProviderMember getMember(int);
	bool validateProvider(ProviderMember &);
	bool addProvider(ProviderMember);
	/** Zero/null fields are not replaced. */
	bool editProvider(ProviderMember);
	ProviderMember getProvider(int);
	bool removeMember(int);
	bool removeProvider(int);

	bool addServiceCode(ServiceCode);
	std::map<int, ServiceCode> getServiceCodes();
	bool validateService(ServiceReport &);
	int addService(ServiceReport);
	std::map<int, ServiceReport> getServices(int);
	bool removeService(int);	
	/** Creates a new time period for the next report. */
	void archiveServices();

	bool requestDirectory(int);
};

#endif /* DATA_H */


/*
 * Author: Yiming Lin
 * Date: 20 Nov 2018
 * Import & Export data center records
 */

class DataCenter : public Data {
	public: 
		DataCenter();
		DataCenter(class FileManager*);
		
		~DataCenter();

		int ValidateMember(int);
		int ValidateProvider(int);
		int SavingServiceRecord();
		bool SavingServiceRecord(struct ServiceReport&);
		void ManagerInterface();

	private: 
		bool ImportExternal();
		bool ExportExternal();

		FileManager* f_manager_;
};
