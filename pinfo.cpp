// Copyright (c) 2018 Yiming Lin

#include "pdrp.h"


Provider :: Provider() {
    name_ = NULL;
    number_ = NULL;
    address_ = NULL;
    city_ = NULL;
    state_ = NULL;
    zip_code_ = NULL;
}


Provider :: Provider(char* nm, char* num, char* addr, char* cty, char* stat, char* zc) {
    if(nm) {
        name_ = new char[len2sz(strlen(nm))];
        strcpy(name_, nm);
    } else {
        name_ = NULL;
    }

    if(num) {
        number_ = new char[len2sz(strlen(num))];
        strcpy(number_, num);
    } else {
        number_ = NULL;
    }

    if(addr) {
        address_ = new char[len2sz(strlen(addr))];
        strcpy(address_, addr);
    } else {
        address_ = NULL;
    }

    if(cty) {
        city_ = new char[len2sz(strlen(cty))];
        strcpy(city_, cty);
    } else {
        city_ = NULL;
    }

    if(stat) {
        state_ = new char[len2sz(strlen(stat))];
        strcpy(state_, stat);
    } else {
        state_ = NULL;
    }

    if(zc) {
        zip_code_ = new char[len2sz(strlen(zc))];
        strcpy(zip_code_, zc);
    } else {
        zip_code_ = NULL;
    }
}


Provider :: Provider(struct ProviderMember& provider) {
    name_ = new char[len2sz(strlen(provider.Name))];
    strcpy(name_, provider.Name);

    char num[len2sz(LEN_PROVIDER_NUM)];
    if(convertint2ch(provider.IDNumber, num)) {
        number_ = new char[len2sz(strlen(num))];
        strcpy(number_, num);
    } else {
        number_ = NULL;
    }
    
    address_ = new char[len2sz(strlen(provider.StreetAddress))];
    strcpy(address_, provider.StreetAddress);

    state_ = new char[len2sz(strlen(provider.State))];
    strcpy(state_, provider.State);

    char zp[len2sz(LEN_ZIP_CODE)];
    if(convertint2ch(provider.ZipCode, zp)) {
        zip_code_ = new char[len2sz(strlen(zp))];
        strcpy(zip_code_, zp);
    } else{
        zip_code_ = NULL;
    }

    city_ = new char[len2sz(strlen(provider.City))];
    strcpy(city_, provider.City);
}


Provider :: Provider(const Provider& provider) {
    if(provider.name_) {
        name_ = new char[len2sz(strlen(provider.name_))];
        strcpy(name_, provider.name_);
    } else {
        name_ = NULL;
    }

    if(provider.number_) {
        number_ = new char[len2sz(strlen(provider.number_))];
        strcpy(number_, provider.number_);
    } else {
        number_ = NULL;
    }

    if(provider.address_) {
        address_ = new char[len2sz(strlen(provider.address_))];
        strcpy(address_, provider.address_);
    } else {
        address_ = NULL;
    }

    if(provider.city_) {
        city_ = new char[len2sz(strlen(provider.city_))];
        strcpy(city_, provider.city_);
    } else {
        city_ = NULL;
    }

    if(provider.state_) {
        state_ = new char[len2sz(strlen(provider.state_))];
        strcpy(state_, provider.state_);
    } else {
        state_ = NULL;
    }

    if(provider.zip_code_) {
        zip_code_ = new char[len2sz(strlen(provider.zip_code_))];
        strcpy(zip_code_, provider.zip_code_);
    } else {
        zip_code_ = NULL;
    }
}


Provider :: ~Provider() {
    Erase();
}


void Provider :: Erase() {
    if(name_) {
        delete [] name_;
        name_ = NULL;
    }

    if(number_) {
        delete [] number_;
        number_ = NULL;
    }

    if(address_) {
        delete [] address_;
        address_ = NULL;
    }

    if(city_) {
        delete [] city_;
        city_ = NULL;
    }

    if(state_) {
        delete [] state_;
        state_ = NULL;
    }

    if(zip_code_) {
        delete [] zip_code_;
        zip_code_ = NULL;
    }
}


Provider& Provider :: operator=(const Provider& provider) {
    if(this == &provider) 
        return *this;

    Erase();

    if(provider.name_) {
        name_ = new char[len2sz(strlen(provider.name_))];
        strcpy(name_, provider.name_);
    } else {
        name_ = NULL;
    }

    if(provider.number_) {
        number_ = new char[len2sz(strlen(provider.number_))];
        strcpy(number_, provider.number_);
    } else {
        number_ = NULL;
    }

    if(provider.address_) {
        address_ = new char[len2sz(strlen(provider.address_))];
        strcpy(address_, provider.address_);
    } else {
        address_ = NULL;
    }

    if(provider.city_) {
        city_ = new char[len2sz(strlen(provider.city_))];
        strcpy(city_, provider.city_);
    } else {
        city_ = NULL;
    }

    if(provider.state_) {
        state_ = new char[len2sz(strlen(provider.state_))];
        strcpy(state_, provider.state_);
    } else {
        state_ = NULL;
    }

    if(provider.zip_code_) {
        zip_code_ = new char[len2sz(strlen(provider.zip_code_))];
        strcpy(zip_code_, provider.zip_code_);
    } else {
        zip_code_ = NULL;
    }
    
    return *this;
}


bool Provider :: Read(ifstream& in) {
    char nm[len2sz(LEN_MEMBER_NAME)];
    char num[len2sz(LEN_MEMBER_NUM)];
    char addr[len2sz(LEN_ADDRESS)];
    char cty[len2sz(LEN_CITY)];
    char stat[len2sz(LEN_STATE)];
    char zc[len2sz(LEN_ZIP_CODE)];

    if(!in) {
        cout << "Read provider info. error" << endl;
        return false;
    }
        

    Erase();
    
    if(in.peek() != EOF) {
        in.get(nm, len2sz(LEN_MEMBER_NAME), '#');
        in.ignore(1000, '#');
        name_ = new char[len2sz(strlen(nm))];
        strcpy(name_, nm);
    }

    if(in.peek() != EOF) {
        in.get(num, len2sz(LEN_MEMBER_NUM), '\n');
        in.ignore(1000, '\n');
        number_ = new char[len2sz(strlen(num))];
        strcpy(number_, num);
    }
    
    if(in.peek() != EOF) {
        in.get(addr, len2sz(LEN_ADDRESS), '\n');
        in.ignore(1000, '\n');
        address_ = new char[len2sz(strlen(addr))];
        strcpy(address_, addr);
    }

    if(in.peek() != EOF) {
        in.get(cty, len2sz(LEN_CITY), '#');
        in.ignore(1000, '#');
        city_ = new char[len2sz(strlen(cty))];
        strcpy(city_, cty);
    }

    if(in.peek() != EOF) {
        in.get(stat, len2sz(LEN_STATE), '#');
        in.ignore(1000, '#');
        state_ = new char[len2sz(strlen(stat))];
        strcpy(state_, stat);
    }

    if(in.peek() != EOF) {
        in.get(zc, len2sz(LEN_ZIP_CODE), '\n');
        in.ignore(1000, '\n');
        zip_code_ = new char[len2sz(strlen(zc))];
        strcpy(zip_code_, zc);
    }

    return true;
}


bool Provider :: Write(ofstream& out) const {
    if(!out)
        return false;

    out << name_ << "#" << number_ << endl;
    out << address_ << endl;
    out << city_ << "#" << state_ << "#" << zip_code_ << endl;

    return true;
}


bool Provider :: FormattedWrite(ofstream& out) const {
    if(!out)
        return false;
    
    out.setf(ios :: left);
    out << "+----------+" << "------------------------------+" << endl;
    out << "| Name     | " << setw(29) << name_  << "|" << endl;
    out << "+----------+------------------------------+" << endl;
    out << "| Number   | " << setw(29) << number_ << "|" << endl;
    out << "+----------+------------------------------+" << endl;
    out << "| Address  | " << setw(29) << address_ << "|" << endl;
    out << "+----------+------------------------------+" << endl;
    out << "| City     | " << setw(29) << city_ << "|" << endl;
    out << "+----------+------------------------------+" << endl;
    out << "| State    | " << setw(29) << state_ << "|" << endl;
    out << "+----------+------------------------------+" << endl;
    out << "| Zip code | " << setw(29) << zip_code_ << "|" << endl;
    out << "+----------+------------------------------+" << endl;
    out << endl;
    out.unsetf(ios :: left);
    
    return true;
}



void Provider :: Display() const {
    cout << endl << name_ << endl;
    cout << number_ << endl;
    cout << address_ << endl;
    cout << city_ << endl;
    cout << state_ << endl;
    cout << zip_code_ << endl;
}


bool Provider :: operator<(const Provider& provider) const {
    if(strcmp(number_, provider.number_) < 0)
        return true;
    return false;
}
        
        
bool Provider :: operator>(const Provider& provider) const {
    if(strcmp(number_, provider.number_) > 0)
        return true;
    return false;
}
        
        
bool Provider :: operator==(const Provider& provider) const {
    if(strcmp(number_, provider.number_) == 0)
        return true;
    return false;
}

bool operator<(const Provider& provider1, const Provider& provider2) {
    return provider1.operator<(provider2);
}


bool operator>(const Provider& provider1, const Provider& provider2) {
    return provider1.operator>(provider2);
}
        
        
bool operator==(const Provider& provider1, const Provider& provider2) {
    return provider1.operator==(provider2);
}


bool Provider :: GetProviderMemberStruct(ProviderMember& item) const {
    if(!name_ || !number_ || !address_ || !zip_code_ || !city_ || !state_)
        return false;

    strcpy(item.Name, name_);
    item.IDNumber = convertch2int(number_);
    strcpy(item.StreetAddress, address_);
    strcpy(item.City, city_);
    strcpy(item.State, state_);
    item.ZipCode = convertch2int(zip_code_);
    return true;
}


char* Provider :: get_number() const {
    return number_;
}


char* Provider :: get_name() const {
    return name_;
}


Member :: Member() {
    status_ = NULL;
}


Member :: Member(char* nm, char* num, char* addr, char* cty, char* stat, char* zc, char* status) 
    : Provider(nm, num, addr, cty, stat, zc) {
        if(status) {
            status_ = new char[len2sz(strlen(status))];
            strcpy(status_, status);
        } else {
            status_ = NULL;
        }
}


Member :: Member(struct ProviderMember& member)
    : Provider(member) {
    if(member.Status == 0) {
        status_ = new char[len2sz(LEN_STATUS)];
        strcpy(status_, "Suspended");
    } else if(member.Status == 1) {
        status_ = new char[len2sz(LEN_STATUS)];
        strcpy(status_, "Valid");
    } else {
        status_ = new char[len2sz(LEN_STATUS)];
        strcpy(status_, "Unknown"); 
    }
}


Member :: Member(const Member& member) : Provider(member) {
    if(member.status_) {
        status_ = new char[len2sz(strlen(member.status_))];
        strcpy(status_, member.status_);
    } else {
        status_ = NULL;
    }
}


Member :: ~Member() {
    Erase();
}


void Member :: Erase() {
    Provider :: Erase();
    
    if(status_) {
        delete [] status_;
        status_ = NULL;
    }
}


Member& Member :: operator=(const Member& member) {
    if(this == &member) 
        return *this;

    this -> Provider :: operator=(member);

    if(member.status_) {
        status_ = new char[len2sz(strlen(member.status_))];
        strcpy(status_, member.status_);
    } else {
        status_ = NULL;
    }

    return *this; 
}


bool Member :: Read(ifstream& in) {
    char status[len2sz(LEN_STATUS)];

    if(!in) 
        return false;

    if(!Provider :: Read(in))
        return false;

    if(in.peek() != EOF) {
        in.get(status, len2sz(LEN_STATUS), '\n');
        in.ignore(1000, '\n');
        status_ = new char[len2sz(strlen(status))];
        strcpy(status_, status);
    }

    return true;
}


bool Member :: Write(ofstream& out) const {
    if(!out)
        return false;

    if(!Provider :: Write(out))
        return false;
    
    out << status_ << endl;
    return true;
}


bool Member :: FormattedWrite(ofstream& out) const {
    if(!out)
        return false;
    
    out << endl;
    out.setf(ios :: left);
    out << "+----------+" << "------------------------------+" << endl;
    out << "| Name     | " << setw(29) << name_  << "|" << endl;
    out << "+----------+------------------------------+" << endl;
    out << "| Number   | " << setw(29) << number_ << "|" << endl;
    out << "+----------+------------------------------+" << endl;
    out << "| Address  | " << setw(29) << address_ << "|" << endl;
    out << "+----------+------------------------------+" << endl;
    out << "| City     | " << setw(29) << city_ << "|" << endl;
    out << "+----------+------------------------------+" << endl;
    out << "| State    | " << setw(29) << state_ << "|" << endl;
    out << "+----------+------------------------------+" << endl;
    out << "| Zip code | " << setw(29) << zip_code_ << "|" << endl;
    out << "+----------+------------------------------+" << endl;
    out.unsetf(ios :: left);
    
    return true;
}



void Member :: Display() const {
    Provider :: Display();
    cout << status_ << endl;
}


bool operator<(const Member& member1, const Member& member2) {
    return member1.operator<(member2);
}
        
        
bool operator>(const Member& member1, const Member& member2) {
    return member1.operator>(member2);
}


bool operator==(const Member& member1, const Member& member2) {
    return member1.operator==(member2);
}   


bool Member :: GetProviderMemberStruct(ProviderMember& item) const {
    if(!status_)
        return false;

    if(!Provider :: GetProviderMemberStruct(item))
        return false;

    if(strcmp(status_, "Valid") == 0)
        item.Status = 1;
    else if(strcmp(status_, "Suspended") == 0)
        item.Status = 0;
    else    
        item.Status = -1;

    return true;
}


ProviderDirectoryEntry :: ProviderDirectoryEntry() {
    service_code_ = NULL;
    service_name_ = NULL;
    service_fee_ = 0.0;
}


ProviderDirectoryEntry :: ProviderDirectoryEntry(char* s_code, char* s_name, float fee) {
    if(s_code) {
        service_code_ = new char[len2sz(strlen(s_code))];
        strcpy(service_code_, s_code);
    } else {
        service_code_ = NULL;
    }

    if(s_name) {
        service_name_ = new char[len2sz(strlen(s_name))];
        strcpy(service_name_, s_name);
    } else {
        service_name_ = NULL;
    }

    service_fee_ = fee;
}


ProviderDirectoryEntry :: ProviderDirectoryEntry(const ProviderDirectoryEntry& entry) {
    if(entry.service_code_) {
        service_code_ = new char[len2sz(strlen(entry.service_code_))];
        strcpy(service_code_, entry.service_code_);
    } else {
        service_code_ = NULL;
    }

    if(entry.service_name_) {
        service_name_ = new char[len2sz(strlen(entry.service_name_))];
        strcpy(service_name_, entry.service_name_);
    } else {
        service_name_ = NULL;
    }

    service_fee_ = entry.service_fee_;
}


ProviderDirectoryEntry :: ~ProviderDirectoryEntry() {
    Erase();
}


void ProviderDirectoryEntry :: Erase() {
    if(service_code_) {
        delete [] service_code_;
        service_code_ = NULL;
    } 
    
    if(service_name_) {
        delete [] service_name_;
        service_name_ = NULL;
    }
}


ProviderDirectoryEntry& ProviderDirectoryEntry :: operator=(const ProviderDirectoryEntry& entry) {
    if(this == &entry)
        return *this;

    Erase();

    if(entry.service_code_) {
        service_code_ = new char[len2sz(strlen(entry.service_code_))];
        strcpy(service_code_, entry.service_code_);
    } else {
        service_code_ = NULL;
    }

    if(entry.service_name_) {
        service_name_ = new char[len2sz(strlen(entry.service_name_))];
        strcpy(service_name_, entry.service_name_);
    } else {
        service_name_ = NULL;
    }

    service_fee_ = entry.service_fee_;

    return *this; 
}


bool ProviderDirectoryEntry :: Read(ifstream& in) {
    char s_code[len2sz(LEN_SERVICE_CODE)];
    char s_name[len2sz(LEN_SERVICE_NAME)];
    
    if(!in) 
        return false;

    Erase();
    if(in.peek() != EOF) {
        in.get(s_code, len2sz(LEN_SERVICE_CODE), '#');
        in.ignore(1000, '#');
        service_code_ = new char[len2sz(strlen(s_code))];
        strcpy(service_code_, s_code);
    }

    if(in.peek() != EOF) {
        in.get(s_name, len2sz(LEN_SERVICE_NAME), '#');
        in.ignore(1000, '#');
        service_name_ = new char[len2sz(strlen(s_name))];
        strcpy(service_name_, s_name);
    }
    
    if(in.peek() != EOF) {
        in >> service_fee_;
        in.ignore(1000, '\n');
    }

    return true;
}


bool ProviderDirectoryEntry :: Write(ofstream& out) const {
    if(!out)
        return false;

    out << service_code_ << "#";
    out << service_name_ << "#";
    out << service_fee_ << endl;

    return true;
}


void ProviderDirectoryEntry :: Display() const {
    cout.setf(ios :: left);
    cout << "| " << setw(7) << service_code_ << "| " << setw(24) << service_name_;
    cout << " | $" << setw(8) << service_fee_ << "|" << endl;
    cout << "+--------+--------------------------+----------+" << endl;
    cout.unsetf(ios :: left);
}


void ProviderDirectoryEntry :: Display(int rowid) const {
    cout.setf(ios :: left);
    cout << "|" << setw(3) << rowid << "| " << setw(7) << service_code_ << "| " << setw(24) << service_name_;
    cout << " | $" << setw(8) << service_fee_ << "|" << endl; 
    cout << "+---+--------+--------------------------+----------+" << endl; 
    cout.unsetf(ios :: left);
}


int ProviderDirectoryEntry :: CompareServiceName(ProviderDirectoryEntry& entry) const {
    return strcmp(service_name_, entry.service_name_);
}


int ProviderDirectoryEntry :: CompareServiceName(const char* string) const {
    return strcmp(string, service_name_);
}


char* ProviderDirectoryEntry :: get_service_code() const {
    return service_code_;
}


char* ProviderDirectoryEntry :: get_service_name() const {
    return service_name_;
}


float ProviderDirectoryEntry :: get_fee() const {
    return service_fee_;
}


PdEntry :: PdEntry() {
    next_ = NULL;
}
        

PdEntry :: PdEntry(char* s_code, char* s_name, float s_fee) 
    : ProviderDirectoryEntry(s_code, s_name, s_fee) {
    next_ = NULL;
}


PdEntry :: PdEntry(const PdEntry& entry) 
    : ProviderDirectoryEntry(entry), next_(NULL) 
{
}



bool PdEntry :: Read(ifstream& in) {
    return ProviderDirectoryEntry :: Read(in);
}
        
        
bool PdEntry :: Write(ofstream& out) const {
    return ProviderDirectoryEntry :: Write(out);
}
        
        
void PdEntry :: Display() const {
    ProviderDirectoryEntry :: Display();
}


void PdEntry :: Display(int rowid) const {
    ProviderDirectoryEntry :: Display(rowid);
}

        
PdEntry* PdEntry :: get_next() const {
    return next_;
}
        
      
void PdEntry :: set_next(PdEntry* next) {
    next_ = next;
}




HashNode :: HashNode() {
    size_ = DEFAULT_PD_MAX;
    table_ = new PdEntry*[size_];
    for(int i = 0; i < size_; ++i)
        table_[i] = NULL;
    time_ = NULL;
    next_ = NULL;
}
        
        
HashNode :: HashNode(char* tm) {
    if(tm) {
        time_ = new char[len2sz(strlen(tm))];
        strcpy(time_, tm);
    } else {
        time_ = NULL;
    }
    
    size_ = DEFAULT_PD_MAX;
    table_ = new PdEntry*[size_];
    for(int i = 0; i < size_; ++i)
        table_[i] = NULL; 

    next_ = NULL;
}
        
        
HashNode :: HashNode(int sz, char* tm) {
    if(tm) {
        time_ = new char[len2sz(strlen(tm))];
        strcpy(time_, tm);
    } else {
        time_ = NULL;
    }

    size_ = GetPrime(sz);
    table_ = new PdEntry*[size_];
    for(int i = 0; i < size_; ++i)
        table_[i] = NULL; 

    next_ = NULL;
}
        
        
HashNode :: HashNode(const HashNode& node) {
    if(node.time_) {
        time_ = new char[len2sz(strlen(node.time_))];
        strcpy(time_, node.time_);
    } else {
        time_ = NULL;
    }

    size_ = node.size_;
    table_ = new PdEntry*[size_];
    for(int i = 0; i < size_; ++i)
        if(node.table_[i])
            table_[i] = CopyList(table_[i], node.table_[i]);
        else 
            table_[i] = NULL;
    
    next_ = NULL;
}


PdEntry* HashNode :: CopyList(PdEntry* dst, PdEntry* scr) {
    if(!scr)
        return NULL;
    
    dst = new PdEntry(*scr);
    PdEntry* after_head_ptr = CopyList(NULL, scr -> get_next());
    dst -> set_next(after_head_ptr);
    return dst;
}


HashNode :: ~HashNode() {
    if(time_) {
        delete [] time_;
        time_ = NULL;
    }

    if(table_ && size_) {
        for(int i = 0; i < size_; ++i) 
            table_[i] = ClearList(table_[i]);
        delete [] table_;
    }
}


PdEntry* HashNode :: ClearList(PdEntry* phead) {
    if(!phead)
        return NULL;
    
    PdEntry* after_head_ptr = ClearList(phead -> get_next());
    phead -> set_next(after_head_ptr);
    delete phead;
    phead = NULL;
    return NULL;
}


void HashNode :: set_next(HashNode* next) {
    next_ = next;
}
        
        
HashNode* HashNode :: get_next() const {
    return next_;
}


int HashNode :: CompareTime(const char* tm) const {
    return Time :: tmcmp(tm, time_);
}
 

int HashNode :: CompareTime(const HashNode* node) const {
    return Time :: tmcmp(node -> time_, time_);
}
        
        
float HashNode :: SearchFee(const char* code) const {
    int index = -1;
    PdEntry* curr = NULL;
    bool found = false;
    float ret = -1;

    if(!code) 
        return -1;
    
        
    index = Hashing(code);
    if(index >= 0 && index < size_) {
        curr = table_[index];
        while(curr && !found) {
            if(strcmp(code, curr -> get_service_code()) == 0) {
                found = true;
                ret = curr -> get_fee();
            } else {
                curr = curr -> get_next();
            }
        }
    }

    return ret;
}
        
        
bool HashNode :: SearchServiceName(const char* code, char* receiver) const {
    int index = -1;
    PdEntry* curr = NULL;
    bool found = false;

    if(!code)
        return false;
    
    index = Hashing(code);
    if(index >= 0 && index < size_) {
        curr = table_[index];
        while(curr && !found) {
            if(strcmp(code, curr -> get_service_code()) == 0) {
                found = true;
                strcpy(receiver, curr -> get_service_name());
            } else {
                curr = curr -> get_next();
            }
        }
    }

    return found;
}
 

bool HashNode :: Read(ifstream& in) {
    int index = 0;

    if(!in)
        return false;

    while(in.peek() != EOF) {
        PdEntry* item = new PdEntry();
        item -> Read(in);
        index = Hashing(item -> get_service_code());
        if(!table_[index]) {
            table_[index] = item;
        } else {
            item -> set_next(table_[index]);
            table_[index] = item;
        }
    }
    in.close();

    return true;
}
        

bool HashNode :: Write(ofstream& out) const {
    PdEntry* curr = NULL;

    if(!out)
        return false;

    for(int i = 0; i < size_; ++i)
        if(table_[i]) {
            curr = table_[i];
            while(curr) {
                curr -> Write(out);
                curr = curr -> get_next();
            }
        }
    
    return true;
}
        
     
void HashNode :: Display() const {
    PdEntry* head = NULL;

    if(table_ && size_) {
        for(int i = 0; i < size_ ; ++i) {
            if(table_[i]) {
                head = table_[i];
                while(head) {
                    head -> Display();
                    head = head -> get_next();
                }
            }
        }
    }
}

        
int HashNode :: Hashing(const char* code) const {
    if(!code || strlen(code) != LEN_SERVICE_CODE || size_ == 0) {
        return -1;
    }
        
    int n1 = ch2int(code[0]);
    int n2 = ch2int(code[1]);
    int n3 = ch2int(code[2]);
    int n4 = ch2int(code[3]);
    int n5 = ch2int(code[4]);
    int n6 = ch2int(code[5]);

    int val = n1 * 100000 + n2 * 10000 + n3 * 1000 + n4 * 100 + n5 * 10 + n6;
    return val % size_;  
}


void HashNode :: set_time(const char* tm) {
    if(time_) {
        delete [] time_;
        time_ = NULL;
    }

    if(tm) {
        time_ = new char[len2sz(strlen(tm))];
        strcpy(time_, tm);
    } else {
        time_ = NULL;
    }
}


char* HashNode :: get_time() const {
    return time_;
}


PdBinaryEntry :: PdBinaryEntry() {
    entry_ptr_ = NULL;
    left_ = NULL;
    right_ = NULL;
}


PdBinaryEntry :: PdBinaryEntry(PdEntry* entry) {
    entry_ptr_ = entry;
    left_ = NULL;
    right_ = NULL;
}



int PdBinaryEntry :: CompareServiceName(const char* name) const {
    return strcmp(name, entry_ptr_ -> get_service_name());
}
      

int PdBinaryEntry :: CompareServiceName(const PdBinaryEntry* node) const {
    return strcmp(node -> entry_ptr_ -> get_service_name(), entry_ptr_ -> get_service_name());
}


void PdBinaryEntry :: set_entry(PdEntry* entry) {
    entry_ptr_ = entry;
}


PdEntry* PdBinaryEntry :: get_entry() const {
    return entry_ptr_;
}


void PdBinaryEntry :: set_left(PdBinaryEntry* left) {
    left_ = left;
}
     

PdBinaryEntry* PdBinaryEntry :: get_left() const {
    return left_;
}

        
void PdBinaryEntry :: set_right(PdBinaryEntry* right) {
    right_ = right;
}
       
 
PdBinaryEntry* PdBinaryEntry :: get_right() const {
    return right_;
}

  
void PdBinaryEntry :: Display() const {
    if(entry_ptr_)
        entry_ptr_ -> Display();
}


ProviderDirectoryHandler :: ProviderDirectoryHandler() {
    root_ = NULL;
    f_manager_ = NULL;
    current_time_ = NULL;
}


ProviderDirectoryHandler :: ProviderDirectoryHandler(char* tm, FileManager* f_man) 
    : HashNode() {
    f_manager_ = f_man;
    root_ = NULL;

    int count = 0;
    if(tm) {
        current_time_ = new char[len2sz(strlen(tm))];
        strcpy(current_time_, tm);
        count = f_manager_ -> Read(this, current_time_);
    } else {
        current_time_ = NULL;
        count = f_manager_ -> Read(this);
    }

    if(count > 0) {
        PdEntry* curr = NULL;
        if(table_ && size_) {
            for(int i = 0; i < size_; ++i) {
                if(table_[i]) {
                    curr = table_[i];
                    while(curr) {
                        PdBinaryEntry* item = new PdBinaryEntry(curr);
                        root_ = TreeInsertion(item, root_);
                        curr = curr -> get_next();
                    }
                }
            }
        }
    } else {
        Init();
    }
}


ProviderDirectoryHandler :: ProviderDirectoryHandler(char* tm, int sz, FileManager* f_man) 
    : HashNode(sz, tm) {
    f_manager_ = f_man;
    root_ = NULL;

    int count = 0;
    if(tm) {
        current_time_ = new char[len2sz(strlen(tm))];
        strcpy(current_time_, tm);
        count = f_manager_ -> Read(this, current_time_);
    } else {
        current_time_ = NULL;
        count = f_manager_ -> Read(this);
    } 

    if(count > 0) {
       PdEntry* curr = NULL;
        if(table_ && size_) {
            for(int i = 0; i < size_; ++i) {
                if(table_[i]) {
                    curr = table_[i];
                    while(curr) {
                        PdBinaryEntry* item = new PdBinaryEntry(curr);
                        root_ = TreeInsertion(item, root_);
                        curr = curr -> get_next();
                    }
                }
            }
        } 
    } else {
        Init();
    }
}


void ProviderDirectoryHandler :: Init() {
    bool done = false;
    char response;

    cout << endl << "Cannot find any record before " << current_time_ << endl;
    cout << "Initialization process starting..." << endl;
    while(!done) {
        Insert();
        cout << endl << "Continue adding entry or not? (Y/N)" << endl;
        do{
            cin >> response;
            cin.ignore(1000, '\n');
            if(response != 'Y' && response != 'y' && response != 'N' && response != 'n')
                cout << "Invalid input. Y/y represents YES, N/n represents NO. Enter again." << endl; 
        } while(response != 'Y' && response != 'y' && response != 'N' && response != 'n'); 

        if(response == 'N' || response == 'n')
            done = true;
    }

    time_ = new char[len2sz(LEN_TIME)];
    strcpy(time_, current_time_);
    if(f_manager_ -> Write(this)) 
        cout << endl << "Initialization process done..."  << endl; 
    else {
        cout << endl << "Initialization process failed..." << endl;
        if(root_)
            root_ = TreeRemoveAll(root_);
        if(table_) {
            for(int i = 0; i < size_; ++i) {
                if(table_) 
                    table_[i] = ClearList(table_[i]);
            }
        }
    }
}


ProviderDirectoryHandler :: ProviderDirectoryHandler(const ProviderDirectoryHandler& handler) 
    : HashNode(handler) {
    f_manager_ = handler.f_manager_;
    root_ = NULL;

    if(handler.current_time_) {
        current_time_ = new char[len2sz(strlen(handler.current_time_))];
        strcpy(current_time_, handler.current_time_);
    } else {
        current_time_ = NULL;
    }

    PdEntry* curr = NULL;
    if(table_ && size_) {
        for(int i = 0; i < size_; ++i) {
            if(table_[i]) {
                curr = table_[i];
                while(curr) {
                    PdBinaryEntry* item = new PdBinaryEntry(curr);
                    root_ = TreeInsertion(item, root_);
                    curr = curr -> get_next();
                }
            }
        }
    }
}


PdBinaryEntry* ProviderDirectoryHandler :: TreeInsertion(PdBinaryEntry* item, PdBinaryEntry* proot) {
    if(!item)
        return proot;
    
    if(!proot)
        return item;
    
    if(proot -> CompareServiceName(item) < 0) {
        PdBinaryEntry* left_child_ptr = TreeInsertion(item, proot -> get_left());
        proot -> set_left(left_child_ptr);
        return proot;
    } else {
        PdBinaryEntry* right_child_ptr = TreeInsertion(item, proot -> get_right());
        proot -> set_right(right_child_ptr);
        return proot;
    }
}


ProviderDirectoryHandler :: ~ProviderDirectoryHandler() {
    if(current_time_) {
        delete [] current_time_;
        current_time_ = NULL;
    }

    root_ = TreeRemoveAll(root_);
}


PdBinaryEntry* ProviderDirectoryHandler :: TreeRemoveAll(PdBinaryEntry* proot) {
    if(!proot)
        return NULL;
    
    PdBinaryEntry* left_child_ptr = TreeRemoveAll(proot -> get_left());
    PdBinaryEntry* right_child_ptr = TreeRemoveAll(proot -> get_right());
    proot -> set_left(left_child_ptr);
    proot -> set_right(right_child_ptr);
    delete proot;
    proot = NULL;
    return NULL;
}


void ProviderDirectoryHandler :: Display() const {
    char stdtime[len2sz(LEN_TIME)];

    if(!Time :: getstdformat(stdtime, time_)) {
        strcpy(stdtime, time_);
    }

    cout.setf(ios :: left);
    cout << "+----------------------------------------------+" << endl;
    cout << "|              Provider Directory              |" << endl;
    cout << "+----------------------------------------------+" << endl;
    cout << "| Last change: " << setw(32) << stdtime << "|" << endl;
    cout << "+----------------------------------------------+" << endl;
    cout << "|  Code  |       Service Name       |    Fee   |" << endl;
    cout << "+--------+--------------------------+----------+" << endl;
    cout.unsetf(ios :: left);
    TreeDisplay(root_);
}


bool ProviderDirectoryHandler :: Display(int code) const {
    char service_code[len2sz(LEN_SERVICE_CODE)];
    int index = -1;
    bool found = false;
    PdEntry* curr = NULL;

    if(!convertint2ch(code, service_code))
        return false;
    
    index = Hashing(service_code);
    if(index >= 0 && index < size_) {
        curr = table_[index];
        while(curr && !found) {
            if(strcmp(service_code, curr -> get_service_code()) == 0) {
                found = true;
                cout << "+--------+--------------------------+----------+" << endl;
                curr -> Display();
            } else {
                curr = curr -> get_next();
            }
        }
    }

    return found;
}


void ProviderDirectoryHandler :: TreeDisplay(PdBinaryEntry* proot) const {
    if(proot) {
        TreeDisplay(proot -> get_left());
        proot -> Display();
        TreeDisplay(proot -> get_right());
    }
}


bool ProviderDirectoryHandler :: Insert() {
    char check_existence[len2sz(LEN_SERVICE_NAME)];
    char input_code[100];
    char input_name[100];
    float fee;
    bool valid = false;
    bool not_digit = false;
    PdEntry* item = NULL;

    cout << endl << "+----------------------------------+" << endl;
    cout << "|   Provider Directory Insertion   |" << endl;
    cout << "+----------------------------------+" << endl;

    while(!valid) {
        cout << endl << "[1] What is the code for the service (6-digit)" << endl;
        cin.get(input_code, 100, '\n');
        cin.ignore(1000, '\n');
        if(strlen(input_code) != LEN_SERVICE_CODE) 
            cout << "Invalid input. The length must be 6" << endl;
        else {
            for(int i = 0; i < LEN_SERVICE_CODE; ++i)
            if(input_code[i] < 48 && input_code[i] > 57)
                not_digit = true;
            if(not_digit)
                cout << "Invalid input. The code must be digit (0 - 9)" << endl;
            else 
                valid = true;
        }

        if(SearchServiceName(input_code, check_existence)) {
            valid = false;
            cout << "The input code " << input_code << " has already existed." << endl;
            cout << "The service name corresponding to it is " << check_existence << endl;
            cout << "Enter again." << endl;
        }    
    }

    valid = false;
    while(!valid) {
        cout << endl << "[2] What is the name for the service (no more than 20 characters) " << endl;
        cin.get(input_name, 100, '\n');
        cin.ignore(1000, '\n');
        if(strlen(input_name) > 20)
            cout << "Invalid input. The length must no more than 20 characters." << endl;
        else 
            valid = true;
    }
    
    valid = false;
    while(!valid) {
        cout << endl << "[3] What is the fee for the service (no more than $999.99)" << endl;
        cin >> fee;
        cin.ignore(1000, '\n');
        if(fee < 0 || fee > 999.99)
            cout << "Invalid input. The fee must no more than 999.99 and not be negative." << endl;
        else 
            valid = true;
    }
    
    item = new PdEntry(input_code, input_name, fee);
    if(Insert(item)) {
        cout << "New provider directory entry is inserted successfully!" << endl;
        return true;
    }
    return false;
}


bool ProviderDirectoryHandler :: Insert(PdEntry* item) {
    int index;

    if(!item) {
        cerr << "Entry creation exception. Insertion failed!" << endl;
        return false;
    }

    index = Hashing(item -> get_service_code());
    if(index < 0 || index >= size_ || !table_) {
        cerr << "Hashing error. Insertion failed!" << endl;
        return false;
    } 
    if(!table_[index])
        table_[index] = item;
    else {
        item -> set_next(table_[index]);
        table_[index] = item;
    }

    PdBinaryEntry* node = new PdBinaryEntry(item);
    root_ = TreeInsertion(node, root_);
    return true;
}


bool ProviderDirectoryHandler :: Remove() {
    int count_entry;
    int pos;
    bool valid = false;
    bool halt = false;
    bool ret = false;

    cout << endl << "+----------------------------------+" << endl;
    cout << "|    Provider Directory Deletion   |" << endl;
    cout << "+----------------------------------+" << endl;

    if(!size_ || !table_) {
        cerr << "Provider Directory handler data lost. Program exception." << endl;
        return false;
    }

    count_entry = DisplayHash();
    if(!count_entry) {
        cerr << "Nothing in the current provider directory" << endl;
        return false;
    }
    while(!valid && !halt) {
        cout << endl << "Enter the number of entry to be removed (1 - " << count_entry << ")" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> pos;
        cin.ignore(1000, '\n');
        if(pos == 0)
            halt = true;
        else if(pos > count_entry || pos < 0) 
            cout << "Invalid input. Enter again. " << endl;
        else {
            valid = true;
            ret = RemoveAtPos(pos);
        }
    }
    if(halt) {
        cout << "Nothing is removed. Exit deletion" << endl;
        return false;
    } 
    return ret;
}


int ProviderDirectoryHandler :: DisplayHash() const {
    int number = 0;
    PdEntry* curr = NULL;

    if(!size_ || !table_)
        return 0;

    cout << "+--------------------------------------------------+" << endl;
    cout << "|                Provider Directory                |" << endl;
    cout << "+--------------------------------------------------+" << endl;
    cout << "|Row|  Code  |       Service Name       |    Fee   |" << endl;
    cout << "+---+--------+--------------------------+----------+" << endl;

    for(int i = 0; i < size_; ++i) {
        if(table_[i]) {
            curr = table_[i];
            while(curr) {
                curr -> Display(++number);
                curr = curr -> get_next();
            }
        }
    }
    return number;
}


bool ProviderDirectoryHandler :: RemoveAtPos(int pos) {
    int number = 0;
    bool found = false;
    PdEntry* curr = NULL;
    PdEntry* prev = NULL;

    if(pos <= 0 || !table_ || !size_)
        return false;
    
    for(int i = 0; i < size_; ++i) {
        if(table_[i] && !found) {
            curr = table_[i];
            prev = NULL;
            while(curr) {
                ++number;
                if(number == pos) {
                    found = true;
                    if(!prev) {
                        table_[i] = curr -> get_next();
                        curr -> set_next(NULL);
                    } else {
                        prev -> set_next(curr -> get_next());
                        curr -> set_next(NULL);
                    }
                    root_ = TreeRemove(curr, root_);
                    delete curr;
                    curr = NULL;
                } else {
                    prev = curr;
                    curr = curr -> get_next();
                }
            }
        }
    }

    return found;
}


PdBinaryEntry* ProviderDirectoryHandler :: TreeRemove(PdEntry* pos, PdBinaryEntry* proot) {
    PdEntry* ios = NULL;

    if(!proot)
        return NULL;
    if(proot -> CompareServiceName(pos -> get_service_name()) < 0) {
        PdBinaryEntry* left_child_ptr = TreeRemove(pos, proot -> get_left());
        proot -> set_left(left_child_ptr);
        return proot;
    } else if(proot -> CompareServiceName(pos -> get_service_name()) > 0) {
        PdBinaryEntry* right_child_ptr = TreeRemove(pos, proot -> get_right());
        proot -> set_right(right_child_ptr);
        return proot;
    } else {
        if(!proot -> get_left() && !proot -> get_right()) {
            delete proot;
            proot = NULL;
            return NULL;
        } else if(!proot -> get_left()) {
            PdBinaryEntry* ret = proot -> get_right();
            proot -> set_right(NULL);
            delete proot;
            proot = NULL;
            return ret;
        } else if(!proot -> get_right()) {
            PdBinaryEntry* ret = proot -> get_left();
            proot -> set_left(NULL);
            delete proot;
            proot = NULL;
            return ret;
        } else {
            PdBinaryEntry* left_subroot;
            left_subroot = ReplaceIOS(proot -> get_left(), &ios);
            proot -> set_left(left_subroot);
            proot -> set_entry(ios);
            return proot;
        }
    }
}


PdBinaryEntry* ProviderDirectoryHandler :: ReplaceIOS(PdBinaryEntry* lchild, PdEntry** pdptr) {
    if(!lchild -> get_right()) {
        *pdptr = lchild -> get_entry();
        if(!lchild -> get_left()) {
            delete lchild;
            lchild = NULL;
            return NULL;
        } else {
            PdBinaryEntry* ret = lchild -> get_left();
            lchild -> set_left(NULL);
            delete lchild;
            lchild = NULL;
            return ret;
        }
    } 
    PdBinaryEntry* right_child_ptr = ReplaceIOS(lchild -> get_right(), pdptr);
    lchild -> set_right(right_child_ptr);
    return lchild;
}


PdEntry* ProviderDirectoryHandler :: GetEntryAtPos(int pos) {
    int number = 0;
    PdEntry* curr = NULL;
    PdEntry* ret = NULL;
    bool found = false;

    if(!size_ || !table_)
        return 0;
    
    for(int i = 0; i < size_ && !found; ++i) {
        if(table_[i]) {
            curr = table_[i];
            while(curr && !found) {
                ++number;
                if(number == pos) {
                    found = true;
                    ret = curr;
                }
                curr = curr -> get_next();
            }
        }
    }
    return ret;
}


bool ProviderDirectoryHandler :: Update() {
    bool done = false;
    bool valid = false;
    bool halt = false;
    bool not_digit = false;
    int count_entry = 0;
    int pos = -1;
    bool ret = false;
    const PdEntry* item;
    char code[len2sz(LEN_SERVICE_CODE)];
    char name[len2sz(LEN_SERVICE_NAME)];
    char check_existence[len2sz(LEN_SERVICE_NAME)];
    float fee;
    char input_code[100];
    char input_name[100];
    float input_fee;
    int choice;
    char finish[2];

    if(!size_ || !table_) {
        cerr << "Provider Directory handler data lost. Program exception." << endl;
        return false;
    }

    cout << endl << "+----------------------------------+" << endl;
    cout << "|     Provider Directory Update    |" << endl;
    cout << "+----------------------------------+" << endl;
    count_entry = DisplayHash();
    if(!count_entry) {
        cerr << "Nothing in the current provider directory" << endl;
        return false;
    } 
    while(!valid && !halt) {
        cout << endl << "Enter the number of entry to be updated (1 - " << count_entry << ")" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> pos;
        cin.ignore(1000, '\n');
        if(pos == 0)
            halt = true;
        else if(pos > count_entry || pos < 0) 
            cout << "Invalid input. Enter again. " << endl;
        else 
            valid = true;
    }
    if(halt) {
        cout << "Nothing is updated. Exit update" << endl;
        return false;
    }  

    item = GetEntryAtPos(pos);
    if(!item) {
        cerr << "Invalid data exception. " << endl;
        return false;
    }
    strcpy(code, item -> get_service_code());
    strcpy(name, item -> get_service_name());
    fee = item -> get_fee();
    
    while(!done && valid) {
        cout << "Current data entry: " << endl;
        cout << "[1] Service Code:  " << code << endl;
        cout << "[2] Service Name:  " << name << endl;
        cout << "[3] Service Fee:   " << fee << endl;
        cout << endl << "Enter 1 - 3 to update information:" << endl;
        
        do{
            cin >> choice;
            cin.ignore(1000, '\n');
            if(choice < 1 || choice > 3)
                cout << "Invalid input. The choice must between 1 to 3." << endl; 
        }while(choice < 1 || choice > 3);
        
        if(choice == 1) {
            bool valid_1 = false;
            while(!valid_1) {
                cout << endl << "What is the code for the service (6-digit)" << endl;
                cin.get(input_code, 100, '\n');
                cin.ignore(1000, '\n');
                if(strlen(input_code) != LEN_SERVICE_CODE) 
                    cout << "Invalid input. The length must be 6" << endl;
                else {
                    for(int i = 0; i < LEN_SERVICE_CODE; ++i)
                        if(input_code[i] < 48 && input_code[i] > 57)
                            not_digit = true;
                    if(not_digit)
                        cout << "Invalid input. The code must be digit (0 - 9)" << endl;
                    else 
                        valid_1 = true;
                }

                if(SearchServiceName(input_code, check_existence)) {
                    valid_1 = false;
                    cout << "The input code " << input_code << " has already existed." << endl;
                    cout << "The service name corresponding to it is " << check_existence << endl;
                    cout << "Enter again." << endl;
                }  
            }
            strcpy(code, input_code);
        } else if(choice == 2) {
            bool valid_2 = false;
            while(!valid_2) {
                cout << endl << "What is the name for the service (no more than 20 characters) " << endl;
                cin.get(input_name, 100, '\n');
                cin.ignore(1000, '\n');
                if(strlen(input_name) > 20)
                    cout << "Invalid input. The length must no more than 20 characters." << endl;
                else 
                    valid_2 = true;
            }   
            strcpy(name, input_name);
        } else {
            bool valid_3 = false;
            while(!valid_3) {
                cout << endl << "[3] What is the fee for the service (no more than $999.99)" << endl;
                cin >> input_fee;
                cin.ignore(1000, '\n');
                if(input_fee < 0 || input_fee > 999.99)
                    cout << "Invalid input. The fee must no more than 999.99 and not be negative." << endl;
                else 
                    valid_3 = true;
            } 
            fee = input_fee;
        }

        cout << endl << "Whether provider directory entry updating is done? (Y/N)" << endl;
        do{
            cin.get(finish, 2, '\n');
            cin.ignore(1000, '\n');
            if(strcmp(finish, "Y") != 0 && strcmp(finish, "y") != 0 
                && strcmp(finish, "N") != 0 && strcmp(finish, "n") != 0)
                cout << "Invalid input. Y/y represents YES, N/n represents NO. Enter again." << endl; 
        } while(strcmp(finish, "Y") != 0 && strcmp(finish, "y") != 0 
            && strcmp(finish, "N") != 0 && strcmp(finish, "n") != 0);

        if(strcmp(finish, "Y") == 0 || strcmp(finish, "y") == 0) 
            done = true;
    }
    
    PdEntry* updated = new PdEntry(code, name, fee);
    if(RemoveAtPos(pos))
        ret = Insert(updated);
    return ret;
}


int ProviderDirectoryHandler :: VerifyCode() const {
    char input_code[100];
    char result[100];
    bool ret = true;
    bool prompt_needed = false;
    int code = 0;

    do{
        cout << endl << "Please enter the code for the serivce to verify" << endl;
        cout << "Enter 0 or -1 to display the provider directory" << endl;
        cin.get(input_code, 101, '\n');
        cin.ignore(1000, '\n');
        if(strcmp(input_code, "0") == 0 || strcmp(input_code, "-1") == 0) {
            Display();
            prompt_needed = true;
        } else {
            prompt_needed = false;
        }
    } while(prompt_needed);
    
    if(!SearchServiceName(input_code, result)) {
        cout << "+-----------------------------+" << endl;
        cout << "|       Nonexistent code      |" << endl;
        cout << "+-----------------------------+" << endl;
        ret = false;
    } else {
        cout << endl << "Service name:" << endl;
        cout << "--------------------" << endl;
        cout << result << endl;
        cout << "--------------------" << endl;
    }

    if(ret)
        code = convertch2int(input_code);
    return code;
}


bool ProviderDirectoryHandler :: SavingChanges() const {
    int m, d, h, min, sec;
    int y = 2018;
    char tm[len2sz(LEN_TIME)];
    bool day_valid = false;

    cout << "+--------------------------+" << endl;
    cout << "|      Saving changes      |" << endl;
    cout << "+--------------------------+" << endl;

    if(!f_manager_) {
        cerr << "File system error!" << endl;
        return false;
    }

    cout << endl << "Enter the current time to save changes:" << endl;
    cout << "Month (1 - 12):" << endl;
    do{
        cin >> m;
        cin.ignore(1000, '\n');
        if(m > 12 || m < 0)
            cout << "Invalid input. The month must between 1 to 12" << endl;
    } while(m > 12 || m < 0);

    cout << "day (1 - 30) or (1 - 31) or (1 - 28)" << endl;
    do{
        cin >> d;
        cin.ignore(1000, '\n');
        if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            if(d <= 0 || d > 31)
                cout << "Invalid input. The day must between 1 to 31" << endl;
            else
                day_valid = true;
        } else if(m == 2) {
            if(d <= 0 || d > 28) 
                cout << "Invalid input. The day must between 1 to 28" << endl;
            else 
                day_valid = true;
        } else {
            if(d <= 0 || d > 30)
                cout << "Invalid input. The day must between 1 to 30" << endl;
            else 
                day_valid = true;
        }
    } while(!day_valid);

    cout << "Hour (0 - 23):" << endl;
    do{
        cin >> h;
        cin.ignore(1000, '\n');
        if(h > 23 || h < 0)
            cout << "Invalid input. The hour must between 0 to 23" << endl;
    } while(h > 23 || m < 0);

    cout << "Minute (0 - 59):" << endl;
    do{
        cin >> min;
        cin.ignore(1000, '\n');
        if(min > 59 || m < 0)
            cout << "Invalid input. The minute must between 0 to 59" << endl;
    } while(min > 59 || m < 0);
    
    cout << "second (0 - 59):" << endl;
    do{
        cin >> sec;
        cin.ignore(1000, '\n');
        if(sec > 59 || sec < 0)
            cout << "Invalid input. The second must between 0 to 59" << endl;
    } while(sec > 59 || sec < 0);

    cout << "The year has automatically been set to 2018" << endl;
    Time t(m, d, y, h, min, sec);
    t.getch(tm);
    strcpy(current_time_, tm);
    strcpy(time_, tm);
    return f_manager_ -> Write(this);
}


ProviderDirectoryLogging :: ProviderDirectoryLogging() {
    time_max_ = NULL;
    time_min_ = NULL;
    head_ = NULL;
    f_manager_ = NULL;
}


ProviderDirectoryLogging :: ProviderDirectoryLogging(FileManager* f_man, char* t_min, char* t_max) {
    f_manager_ = f_man;
    head_ = NULL;
    
    if(t_max) {
        time_max_ = new char[len2sz(strlen(t_max))];
        strcpy(time_max_, t_max);
    } else {
        time_max_ = NULL;
    }

    if(t_min) {
        time_min_ = new char[len2sz(strlen(t_min))];
        strcpy(time_min_, t_min);
    } else {
        time_min_ = NULL;
    }

    if(!ImportExternal())
        head_ = NULL;
}


bool ProviderDirectoryLogging :: ImportExternal() {
    int count = 0;
    HashNode arr[50];

    count = f_manager_ -> Read(arr, time_min_, time_max_);
    if(!count)
        return false;
    for(int i = 0; i < count; ++i)
        head_ = Insert(arr[i], head_);
    return true;
}


HashNode* ProviderDirectoryLogging :: Insert(HashNode& node, HashNode* phead) {
    if(!phead) {
        phead = new HashNode(node);
        return phead;
    }

    if(phead -> CompareTime(&node) > 0) {
        HashNode* new_node_ptr = new HashNode(node);
        new_node_ptr -> set_next(phead);
        return new_node_ptr;
    } else {
        HashNode* after_head_ptr = Insert(node, phead -> get_next());
        phead -> set_next(after_head_ptr);
        return phead;
    }
}



ProviderDirectoryLogging :: ~ProviderDirectoryLogging() {
    if(time_max_) {
        delete [] time_max_;
        time_max_ = NULL;
    }

    if(time_min_) {
        delete [] time_min_;
        time_min_ = NULL;
    }

    head_ = Clear(head_);
}


HashNode* ProviderDirectoryLogging :: Clear(HashNode* phead) {
    if(!phead)
        return NULL;
    
    HashNode* after_head_ptr = Clear(phead -> get_next());
    phead -> set_next(after_head_ptr);
    delete phead;
    phead = NULL;
    return NULL;
}


float ProviderDirectoryLogging :: SerachFee(const char* tm, const char* code) const {
    HashNode* curr = head_;
    bool found = false;
    float ret;

    if(!tm || ! code)
        return -1;
    if(!curr) {
        return -1;
    }
    if(curr -> CompareTime(tm) > 0) {
        return curr -> SearchFee(code);
    } else {
       while(!found && curr) {
            if(curr -> CompareTime(tm) < 0) {
                curr = curr -> get_next();
            } else {
                ret = curr -> SearchFee(code);
                found = true;
            }
       } 
        if(!found) {
            return -1;
        }
            
       return ret;
    }
}
        
        
bool ProviderDirectoryLogging :: SearchServiceName(const char* tm, const char* code, char* receiver) const {
    HashNode* curr = head_;
    bool found = false;
    float ret;

    if(!tm || ! code)
        return false;
    if(head_ -> CompareTime(tm) > 0) {
        return head_ -> SearchServiceName(code, receiver);
    } else {
       while(!found && curr) {
            if(curr -> CompareTime(tm) < 0) {
                curr = curr -> get_next();
            } else {
                ret = curr -> SearchServiceName(code, receiver);
                found = true;
            }
       } 
       return ret;
    }
}


// test purpose function
void ProviderDirectoryLogging :: Display() {
    HashNode* curr = head_;
    int count = 1;
    while(curr) {
        cout <<"--------------- " <<count++ << " ---------------" << endl;
        curr -> Display();
        curr = curr -> get_next();
    }
}



DistrubutionNode :: DistrubutionNode() {
    num_ = NULL;
    service_collection_ = new FObjService*[MAX_REPORT_SERVICE];
    for(int i = 0; i < MAX_REPORT_SERVICE; ++i)
        service_collection_[i] = NULL;
    collection_size_ = 0;
    left_ = NULL;
    right_ = NULL;
}


DistrubutionNode :: DistrubutionNode(char* number) {
    if(number) {
        num_ = new char[len2sz(strlen(number))];
        strcpy(num_, number);
    } else {
        num_ = NULL;
    }

    service_collection_ = new FObjService*[MAX_REPORT_SERVICE];
    for(int i = 0; i < MAX_REPORT_SERVICE; ++i)
        service_collection_[i] = NULL;
    collection_size_ = 0;

    left_ = NULL;
    right_ = NULL;
}


DistrubutionNode :: DistrubutionNode(const DistrubutionNode& node) {
    if(node.num_) {
        num_ = new char[len2sz(strlen(node.num_))];
        strcpy(num_, node.num_);
    } else {
        num_ = NULL;
    }

    collection_size_ = 0;
    if(node.service_collection_ && node.collection_size_) {
        service_collection_ = new FObjService*[MAX_REPORT_SERVICE];
        for(int i = 0; i < node.collection_size_; ++i) {
            FObjMemberService* ms = dynamic_cast<FObjMemberService*>(node.service_collection_[i]);
            if(ms) {
                service_collection_[collection_size_++] = new FObjMemberService(*ms);
            } else {
                FObjProviderService* ps = dynamic_cast<FObjProviderService*>(node.service_collection_[i]);
                if(ps) {
                    service_collection_[collection_size_++] = new FObjProviderService(*ps);
                } else {
                    service_collection_[collection_size_++] = NULL;
                } 
            }
        }
        for(int i = collection_size_; i < MAX_REPORT_SERVICE; ++i)
            service_collection_[i] = NULL;
    } else {
        service_collection_ = new FObjService*[MAX_REPORT_SERVICE];
        for(int i = 0; i < MAX_REPORT_SERVICE; ++i)
            service_collection_[i] = NULL;
    }

    left_ = NULL;
    right_ = NULL;
}


DistrubutionNode :: ~DistrubutionNode() {
    if(service_collection_ && collection_size_) {
        for(int i = 0; i < collection_size_; ++i) {
            delete service_collection_[i];
            service_collection_[i] = NULL;
        } 
        delete [] service_collection_;
    }

    if(num_) {
        delete [] num_;
        num_ = NULL;
    }
}


int DistrubutionNode :: Compare(char* key) const {
    return strcmp(key, num_);
}


void DistrubutionNode :: Insert(const FObjService* item) {
    if(collection_size_ < MAX_REPORT_SERVICE && service_collection_) {
       const FObjMemberService* ms = dynamic_cast<const FObjMemberService*>(item);
        if(ms) {
            service_collection_[collection_size_++] = new FObjMemberService(*ms);
        } else {
            const FObjProviderService* ps = dynamic_cast<const FObjProviderService*>(item);
            if(ps) {
                service_collection_[collection_size_++] = new FObjProviderService(*ps);
            } else {
                service_collection_[collection_size_] = NULL;
            }
        } 
    }
}


DistrubutionNode* DistrubutionNode :: get_left() const {
    return left_;
}
        
        
void DistrubutionNode :: set_left(DistrubutionNode* left) {
    left_ = left;
}

        
DistrubutionNode* DistrubutionNode :: get_right() const {
    return right_;
}
        
        
void DistrubutionNode :: set_right(DistrubutionNode* right) {
    right_ = right;
}


FObjMemberReport* DistrubutionNode :: GenerateMemberReport(DataCenter* dc, char* dt) {
    struct ProviderMember member;

    if(service_collection_ && collection_size_) {
        if(!dc) {
            cerr << "Cannot connect to the ChocAn Data Center." << endl;
            return NULL;
        }

        try {
		    member = dc -> getMember(convertch2int(num_));
	    } catch (std::exception &e) {
	    	return NULL;
	    }

        Member report_member(member);
        FObjMemberReport* mr = new FObjMemberReport(&report_member, dt);
        for(int i = 0; i < collection_size_; ++i) {
            if(service_collection_[i]) {
                FObjMemberService* ms = dynamic_cast<FObjMemberService*>(service_collection_[i]);
                if(ms) 
                    mr -> InsertMemberService(*ms); 
            }
        }
        return mr;
    }
    return NULL;
}


FObjProviderReport* DistrubutionNode :: GenerateProviderReport(DataCenter* dc, char* dt) {
    struct ProviderMember provider;

    if(service_collection_ && collection_size_) {
        if(!dc) {
            cerr << "Cannot connect to the ChocAn Data Center." << endl;
            return NULL;
        }

        try {
		    provider = dc -> getProvider(convertch2int(num_));
	    } catch (std::exception &e) {
	    	return NULL;
	    }

        Provider report_provider(provider);
        FObjProviderReport* pr = new FObjProviderReport(&report_provider, dt);
        for(int i = 0; i < collection_size_; ++i) {
            if(service_collection_[i]) {
                FObjProviderService* ps = dynamic_cast<FObjProviderService*>(service_collection_[i]);
                if(ps)
                    pr -> InsertProviderService(*ps);
            }
        }
        return pr;
    }
    return NULL;
}


ReportFactory :: ReportFactory() 
{
}


ReportFactory :: ~ReportFactory() 
{
}


MaterialFactory :: MaterialFactory() {
    data_center_ = NULL;
    file_manager_ = NULL;
    material_num_ = 0;
    material_ = NULL;
    date_max_ = NULL;
    date_min_ = NULL;
}


MaterialFactory :: MaterialFactory(DataCenter* dc, FileManager* f, char* d_min, char* d_max) {
    data_center_ = dc;
    file_manager_ = f;

    if(d_min) {
        date_min_ = new char[len2sz(strlen(d_min))];
        strcpy(date_min_, d_min);
    } else {
        date_min_ = NULL;
    }

    if(d_max) {
        date_max_ = new char[len2sz(strlen(d_max))];
        strcpy(date_max_, d_max);
    } else {
        date_max_ = NULL;
    }

    if(date_max_ && date_min_) {
        material_ = new FObjService[MAX_SERVICE_RECORD];
        material_num_ = file_manager_ -> Read(material_, date_min_, date_max_);
        if(material_num_ <= 0) {
            delete [] material_;
            material_ = NULL;
            material_num_ = 0;
        }
    } else {
        material_ = NULL;
        material_num_ = 0;
    }
}


MaterialFactory :: MaterialFactory(const MaterialFactory& factory) {
    data_center_ = factory.data_center_;
    file_manager_ = factory.file_manager_;

    if(factory.date_min_) {
        date_min_ = new char[len2sz(strlen(factory.date_min_))];
        strcpy(date_min_, factory.date_min_);
    } else {
        date_min_ = NULL;
    }

    if(factory.date_max_) {
        date_max_ = new char[len2sz(strlen(factory.date_max_))];
        strcpy(date_max_, factory.date_max_);
    } else {
        date_max_ = NULL;
    } 

    if(factory.material_num_) {
        material_num_ = factory.material_num_;
        material_ = new FObjService[material_num_];
        for(int i = 0; i < material_num_; ++i) {
            material_[i] = factory.material_[i];
        }
    } else {
        material_num_ = 0;
        material_ = NULL;
    }
}


MaterialFactory :: ~MaterialFactory() {
    Erase();
}


void MaterialFactory :: Erase() {
    if(date_min_) {
        delete [] date_min_;
        date_min_ = NULL;
    } 

    if(date_max_) {
        delete [] date_max_;
        date_max_ = NULL;
    }

    if(material_) {
        delete [] material_;
        material_ = NULL;
    }

    data_center_ = NULL;
    file_manager_ = NULL;
}


MaterialFactory& MaterialFactory :: operator=(const MaterialFactory& factory) {
    if(this == &factory)
        return *this;

    Erase();

    data_center_ = factory.data_center_;
    file_manager_ = factory.file_manager_;

    if(factory.date_min_) {
        date_min_ = new char[len2sz(strlen(factory.date_min_))];
        strcpy(date_min_, factory.date_min_);
    } else {
        date_min_ = NULL;
    }

    if(factory.date_max_) {
        date_max_ = new char[len2sz(strlen(factory.date_max_))];
        strcpy(date_max_, factory.date_max_);
    } else {
        date_max_ = NULL;
    } 

    if(factory.material_num_) {
        material_num_ = factory.material_num_;
        material_ = new FObjService[material_num_];
        for(int i = 0; i < material_num_; ++i) {
            material_[i] = factory.material_[i];
        }
    } else {
        material_num_ = 0;
        material_ = NULL;
    }

    return *this;
}


int MaterialFactory :: Produce(FObj** array) {
    if(material_ && material_num_) {
        for(int i = 0; i < material_num_; ++i)
            *(array + i) = &material_[i];
        return material_num_;
    } else{
        return 0;
    }
}


GeneralReportFactory :: GeneralReportFactory() {
    assembler_ = NULL;
}


GeneralReportFactory :: GeneralReportFactory(DataCenter* dc, FileManager* f, char* d_min, char* d_max, int type)
    : MaterialFactory(dc, f, d_min, d_max), type_(type), assembler_(NULL)
{
}


GeneralReportFactory :: GeneralReportFactory(const GeneralReportFactory& factory)
    : MaterialFactory(factory), type_(factory.type_) {
    if(factory.assembler_) {
        assembler_ = Copy(assembler_, factory.assembler_);
    } else {
        assembler_ = NULL;
    }
}


DistrubutionNode* GeneralReportFactory :: Copy(DistrubutionNode* dst, DistrubutionNode* scr) {
    if(!scr)
        return NULL;
    
    dst = new DistrubutionNode(*scr);
    DistrubutionNode* left_child_ptr = Copy(NULL, scr -> get_left());
    DistrubutionNode* right_child_ptr = Copy(NULL, scr -> get_right());
    dst -> set_left(left_child_ptr);
    dst -> set_right(right_child_ptr);
    return dst;
}


GeneralReportFactory :: ~GeneralReportFactory() {
    Erase();
}


void GeneralReportFactory :: Erase() {
    if(assembler_) {
        assembler_ = Clear(assembler_);
        assembler_ = NULL;
    }
}


DistrubutionNode* GeneralReportFactory :: Clear(DistrubutionNode* proot) {
    if(!proot)  
        return NULL;
    
    DistrubutionNode* left_child_ptr = Clear(proot -> get_left());
    DistrubutionNode* right_child_ptr = Clear(proot -> get_right());
    proot -> set_left(left_child_ptr);
    proot -> set_right(right_child_ptr);
    delete proot;
    proot = NULL;
    return NULL;
}


GeneralReportFactory& GeneralReportFactory :: operator=(const GeneralReportFactory& factory) {
    if(this == &factory)    
        return *this;

    this -> MaterialFactory :: operator=(factory);

    Erase();

    type_ = factory.type_;

    if(factory.assembler_) {
        assembler_ = Copy(assembler_, factory.assembler_);
    } else {
        assembler_ = NULL;
    }

    return *this;
}


int GeneralReportFactory :: Produce(FObj** product) {
    int ret = 0;
    
    if(!material_ || !material_num_)
        return 0;

    Generation();
    Produce(product, assembler_, ret);
    return ret;
}


void GeneralReportFactory :: Generation() {
    char t_max[len2sz(LEN_TIME)];
    char t_min[len2sz(LEN_TIME)];

    assembler_ = Clear(assembler_);

    if(date_max_ && date_min_) {
        strcpy(t_max, date_max_);
        strcat(t_max, "_00_00_00");
        strcpy(t_min, date_min_);
        strcat(t_min, "_00_00_00");
    } else {
        cerr << "Cannot found date interval.\nMember/Provider report generation failed." << endl;
        return ;
    }

    if(material_ && material_num_) {
        ProviderDirectoryLogging pd(file_manager_, t_min, t_max);
        if(type_ == 1) {
            for(int i = 0; i < material_num_; ++i) {
                FObjMemberService ms(material_[i]);
                if(ms.get_info(data_center_, &pd))
                    assembler_ = Insert(assembler_, &ms, ms.get_num());
            }
        } else if(type_ == 2) {
            for(int j = 0; j < material_num_; ++j) {
                FObjProviderService ps(material_[j]);
                if(ps.get_info(data_center_, &pd))
                    assembler_ = Insert(assembler_, &ps, ps.get_num());
            }
        }
    } else {
        cout << "No service to be written into Member/Provider report." << endl;
        return ;
    }
}


void GeneralReportFactory :: Produce(FObj** product, DistrubutionNode* proot, int& index) {
    if(proot) {
        if(type_ == 1) {
            product[index] = proot -> GenerateMemberReport(data_center_, date_max_);
            if(product[index])
                ++index;
        } else if(type_ == 2) {
            product[index] = proot -> GenerateProviderReport(data_center_, date_max_);
            if(product[index])
                ++index;
        }

        Produce(product, proot -> get_left(), index);
        Produce(product, proot -> get_right(), index);
    }
}



DistrubutionNode* GeneralReportFactory :: Insert(DistrubutionNode* proot, FObjService* item, char* pnum) {
    if(!proot) {
        proot = new DistrubutionNode(pnum);
        proot -> Insert(item);
        return proot;
    }

    if(proot -> Compare(pnum) < 0) {
        DistrubutionNode* left_child_ptr = Insert(proot -> get_left(), item, pnum);
        proot -> set_left(left_child_ptr);
        return proot;
    } else if(proot -> Compare(pnum) > 0) {
        DistrubutionNode* right_child_ptr = Insert(proot -> get_right(), item, pnum);
        proot -> set_right(right_child_ptr);
        return proot;
    } else {
        proot -> Insert(item);
        return proot;
    }
}


ManagerReportFactory :: ManagerReportFactory() {
    date_max_ = NULL;
    date_min_ = NULL;
    file_manager_ = NULL;
}


ManagerReportFactory :: ManagerReportFactory(FileManager* f_manager, char* d_min, char* d_max) {
    file_manager_ = f_manager;
    
    if(d_min) {
        date_min_ = new char[len2sz(strlen(d_min))];
        strcpy(date_min_, d_min);
    } else {
        date_min_ = NULL;
    }

    if(d_max) {
        date_max_ = new char[len2sz(strlen(d_max))];
        strcpy(date_max_, d_max);
    } else {
        date_max_ = NULL;
    }
}


ManagerReportFactory :: ManagerReportFactory(const ManagerReportFactory& factory) {
    file_manager_ = factory.file_manager_;
    if(factory.date_max_) {
        date_max_ = new char[len2sz(strlen(factory.date_max_))];
        strcpy(date_max_, factory.date_max_);
    } else {
        date_max_ = NULL;
    }

    if(factory.date_min_) {
        date_min_ = new char[len2sz(strlen(factory.date_min_))];
        strcpy(date_min_, factory.date_min_);
    } else {
        date_min_ = NULL;
    }
}


ManagerReportFactory :: ~ManagerReportFactory() {
    if(date_max_) {
        delete [] date_max_;
        date_max_ = NULL;
    }

    if(date_min_) {
        delete [] date_min_;
        date_min_ = NULL;
    }
}


int ManagerReportFactory :: Produce(FObj** product) {
    int count = 0;
    FObjProviderReportSummary material[MAX_CDC_ENTRIES];
    FObjManagerReport* mr;

    if(file_manager_) {
        count = file_manager_ -> Read(material, date_min_, date_max_);
        if(count > 0) {
            mr = new FObjManagerReport(material, count, date_max_);
            product[0] = mr;
            return 1;
        }
    }
    return 0;
}


EftReportFactory :: EftReportFactory() {
    date_min_ = NULL;
    date_max_ = NULL;
    file_manager_ = NULL;
}


EftReportFactory :: EftReportFactory(FileManager* f_manager, char* d_min, char* d_max) {
    file_manager_ = f_manager;
    
    if(d_min) {
        date_min_ = new char[len2sz(strlen(d_min))];
        strcpy(date_min_, d_min);
    } else {
        date_min_ = NULL;
    }

    if(d_max) {
        date_max_ = new char[len2sz(strlen(d_max))];
        strcpy(date_max_, d_max);
    } else {
        date_max_ = NULL;
    }
}


EftReportFactory :: EftReportFactory(const EftReportFactory& factory) {
    file_manager_ = factory.file_manager_;
    if(factory.date_max_) {
        date_max_ = new char[len2sz(strlen(factory.date_max_))];
        strcpy(date_max_, factory.date_max_);
    } else {
        date_max_ = NULL;
    }

    if(factory.date_min_) {
        date_min_ = new char[len2sz(strlen(factory.date_min_))];
        strcpy(date_min_, factory.date_min_);
    } else {
        date_min_ = NULL;
    }
}


EftReportFactory :: ~EftReportFactory() {
    if(date_max_) {
        delete [] date_max_;
        date_max_ = NULL;
    }

    if(date_min_) {
        delete [] date_min_;
        date_min_ = NULL;
    }
}


int EftReportFactory :: Produce(FObj** product) {
    int ret = 0;
    FObjEFT material[MAX_CDC_ENTRIES];
    FObjEftReport* report;

    if(file_manager_) {
        ret = file_manager_ -> Read(material, date_min_, date_max_);
        if(ret) {
            report = new FObjEftReport(date_max_);
            for(int i = 0; i < ret; ++i) 
                report -> InsertEftRecord(material[i]);
            product[0] = report;
            return 1;
        }
    }
    return ret;
}


ReportGenerator :: ReportGenerator() {
    date_ = NULL;
    day_of_week_ = -1;
    file_manager_ = NULL;
    data_center_ = NULL;
}


ReportGenerator :: ReportGenerator(FileManager* f_manager, DataCenter* dc, char* date, int dow) {
    if(date) {
        date_ = new char[len2sz(strlen(date))];
        strcpy(date_, date);
    } else {
        date_ = NULL;
    }

    file_manager_ = f_manager;
    data_center_ = dc;
    day_of_week_ = dow;
}


ReportGenerator :: ReportGenerator(const ReportGenerator& generator) {
    if(generator.date_) {
        date_ = new char[len2sz(strlen(generator.date_))];
        strcpy(date_, generator.date_);
    } else {
        date_ = NULL;
    }

    file_manager_ = generator.file_manager_;
    data_center_ = generator.data_center_;
    day_of_week_ = generator.day_of_week_;
}


ReportGenerator :: ~ReportGenerator() {
    if(date_) {
        delete [] date_;
        date_ = NULL;
    }
}


bool ReportGenerator :: GenerateMemberReport() {
    FObj* product[MAX_CDC_ENTRIES];
    int report_num = 0;
    Date dt(date_);
    char last_week[len2sz(LEN_DATE)];

    if(file_manager_ && data_center_ && date_) {
        if(day_of_week_ != FRI) {
            cout << "Member report must be generated on Friday" << endl;
            return false;
        }
        dt.getchlwk(last_week);

        GeneralReportFactory factory(data_center_, file_manager_, last_week, date_, 1);
        report_num = factory.Produce(product);
        if(!report_num) {
            cout << "No weekly member report available at present" << endl;
            cout << "Generate 0 member report" << endl;
            return false;
        }
        cout << "Generate " << report_num << " member reports" << endl;
        
        for(int i = 0; i < report_num; ++i)
            file_manager_ -> Write(product[i]);

        for(int i = 0; i < report_num; ++i) { 
            delete product[i];
            product[i] = NULL;
        }

        return true;
    }
    return false;
}


bool ReportGenerator :: GenerateProviderReport() {
    FObj* product[MAX_CDC_ENTRIES];
    FObjProviderReportSummary* concomitant;
    FObjProviderReportSummary* sum = NULL;
    int report_num = 0;
    Date dt(date_);
    char last_week[len2sz(LEN_DATE)];

    if(file_manager_ && data_center_ && date_) {
        if(day_of_week_ != FRI) {
            cout << "Provider report must be generated on Friday" << endl;
            return false;
        }
        dt.getchlwk(last_week);

        GeneralReportFactory factory(data_center_, file_manager_, last_week, date_, 2);
        report_num = factory.Produce(product);
        if(!report_num) {
            cout << "No weekly provider report available at present" << endl;
            cout << "Generate 0 provider report" << endl;
            return false;
        } 
        cout << "Generate " << report_num << " provider reports" << endl;

        concomitant = new FObjProviderReportSummary[report_num];
        for(int i = 0; i < report_num; ++i) {
            sum = dynamic_cast<FObjProviderReportSummary*>(product[i]);
            concomitant[i] = *sum;
            file_manager_ -> Write(&concomitant[i]);
        }
        delete [] concomitant;
        
        for(int i = 0; i < report_num; ++i)
            file_manager_ -> Write(product[i]);

        for(int i = 0; i < report_num; ++i) {
            delete product[i];
            product[i] = NULL;
        }

        return true;
    }
    return false;
}


bool ReportGenerator :: GenerateManagerReport() {
    FObj* product[1];
    Date dt(date_);
    char last_week[len2sz(LEN_DATE)];
    int ret;

    if(file_manager_ && date_) {
        if(day_of_week_ != FRI) {
            cout << "Manager payable report must be generated on Friday" << endl;
            return false;
        }
        dt.getchlwk(last_week);
        ManagerReportFactory factory(file_manager_, last_week, date_);
        ret = factory.Produce(product);
        if(!ret) {
            cout << "No weekly manager payable report available at present" << endl;
            cout << "Generate 0 manager payable report" << endl;
            return false;
        } 
        cout << "Generate " << ret << " manager reports" << endl;
        
        ret = file_manager_ -> Write(product[0]);
        delete product[0];
        product[0] = NULL;
        return ret;
    }
    return false;
}


bool ReportGenerator :: GenerateEftReport() {
    FObj* product[MAX_CDC_ENTRIES];
    int report_num = 0;
    Date dt(date_);
    char last_week[len2sz(LEN_DATE)];
    int ret = 0;

    if(file_manager_ && date_) {
        if(day_of_week_ != FRI) {
            cout << "EFT report must be generated on Friday" << endl;
            return false;
        } 
        dt.getchlwk(last_week);
        EftReportFactory factory(file_manager_, last_week, date_);
        report_num = factory.Produce(product);
        if(!report_num) {
            cout << "No weekly EFT report available at present" << endl;
            cout << "Generate 0 EFT report" << endl;
            return false;
        } 
        ret = file_manager_ -> Write(product[0]);
        delete product[0];
        product[0] = NULL;
        cout << "Generate " << ret << " EFT reports" << endl;

        return ret;
    }    
    return ret;
}
