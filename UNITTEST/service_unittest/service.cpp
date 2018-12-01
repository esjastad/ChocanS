// Copyright (c) 2018 Yiming Lin

#include "service.h"
#include <iostream>
#include <cstring>

using namespace std;


int power10(int num) {
    int ret = 1;

    if(0 < num && num < 10) {
        for(int i = 0; i < num; ++i) {
            ret *= 10;
        }
    } else if(num == 0) {
        ret = 1;
    } else {
        ret = -1;
    }

    return ret;
}


int convertch2int(const char* ch) {
    int len;
    int ret = 0;

    if(!ch)
        return -1;

    len = strlen(ch);
    if(len > 10)
        return -1;
    for(int i = len - 1; i >= 0; --i) {
        ret += power10(i) * ch2int(ch[len - i - 1]);
    }

    return ret;
}


bool convertint2ch(int num, char* ch) {
    int bit;
    int count = 0;
    bool done = false;
    char tmp[10];

    if(num < 0)
        return false;

    if(num - 10 < 0) {
        ch[0] = num + '0';
        ch[1] = '\0';
        return true;
    }
     
    while(!done) {
        bit = num % 10;
        tmp[count++] = bit + '0';
        num /= 10;
        if(num - 10 < 0) {
            tmp[count++] = num + '0';
            done = true;
        }
    }

    for(int i = 0; i < count; ++i)
        ch[count - 1 - i] = tmp[i];
    ch[count] = '\0';
    return true;
}


FObjService :: FObjService() {
    date_ = NULL;
    time_ = NULL;
    provider_num_ = NULL;
    member_num_ = NULL;
    service_code_ = NULL;
    comment_ = NULL;
}


FObjService :: FObjService(char* date, char* time, char* p_num, char* m_num, char* sc, char* comm) {
    if(date) {
        date_ = new char[strlen(date) + 1];
        strcpy(date_, date);
    } else {
        date_ = NULL;
    }
    
    if(time) {
        time_ = new char[strlen(time) + 1];
        strcpy(time_, time);
    } else {
        time_ = NULL;
    }
    
    if(p_num) {
        provider_num_ = new char[strlen(p_num) + 1];
        strcpy(provider_num_, p_num);
    } else {
        provider_num_ = NULL;
    }

    if(m_num) {
        member_num_ = new char[strlen(m_num) + 1];
        strcpy(member_num_, m_num);
    } else {
        member_num_ = NULL;
    }
    
    if(sc) {
        service_code_ = new char[strlen(sc) + 1];
        strcpy(service_code_, sc);
    } else {
        service_code_ = NULL;
    }
    
    if(comm) {
        comment_ = new char[strlen(comm) + 1];
        strcpy(comment_, comm);
    } else {
        comment_ = NULL;
    }
}


FObjService :: FObjService(const FObjService& service) {
    if(service.date_) {
        date_ = new char[strlen(service.date_) + 1];
        strcpy(date_, service.date_);
    } else {
        date_ = NULL;
    }
    
    if(service.time_) {
        time_ = new char[strlen(service.time_) + 1];
        strcpy(time_, service.time_);
    } else {
        time_ = NULL;
    }
    
    if(service.provider_num_) {
        provider_num_ = new char[strlen(service.provider_num_) + 1];
        strcpy(provider_num_, service.provider_num_);
    } else {
        provider_num_ = NULL;
    }

    if(service.member_num_) {
        member_num_ = new char[strlen(service.member_num_) + 1];
        strcpy(member_num_, service.member_num_);
    } else {
        member_num_ = NULL;
    }
    
    if(service.service_code_) {
        service_code_ = new char[strlen(service.service_code_) + 1];
        strcpy(service_code_, service.service_code_);
    } else {
        service_code_ = NULL;
    }
    
    if(service.comment_) {
        comment_ = new char[strlen(service.comment_) + 1];
        strcpy(comment_, service.comment_);
    } else {
        comment_ = NULL;
    }
}


FObjService :: FObjService(struct ServiceReport& service) {
    date_ = new char[len2sz(LEN_DATE)];
    strcpy(date_, service.DoS);

    time_ = new char[len2sz(LEN_TIME)];
    strcpy(time_, service.CDT);

    char p_num[len2sz(LEN_PROVIDER_NUM)];
    if(convertint2ch(service.ProviderNum, p_num)) {
        provider_num_ = new char[len2sz(LEN_PROVIDER_NUM)];
        strcpy(provider_num_, p_num);
    } else {
        provider_num_ = NULL;
    }

    char m_num[len2sz(LEN_MEMBER_NUM)];
    if(convertint2ch(service.MemberNum, m_num)) {
        member_num_ = new char[len2sz(LEN_MEMBER_NUM)];
        strcpy(member_num_, m_num);
    } else {
        member_num_ = NULL;
    }
    
    char s_code[len2sz(LEN_SERVICE_CODE)];
    if(convertint2ch(service.ServiceCode, s_code)) {
        service_code_ = new char[len2sz(LEN_SERVICE_CODE)];
        strcpy(service_code_, s_code);
    } else {
        service_code_ = NULL;
    }

    if(strlen(service.Comments) == 0) {
        comment_ = NULL;
    } else {
        comment_ = new char[len2sz(LEN_COMMENT)];
        strcpy(comment_, service.Comments);
    }
}


FObjService :: ~FObjService() {
    Erase();
}


FObjService& FObjService :: operator=(const FObjService& service) {
    if(this == &service)
        return *this;
    
    Erase();

    if(service.time_) {
        time_ = new char[strlen(service.time_) + 1];
        strcpy(time_, service.time_);
    } else {
        time_ = NULL;
    }
    
    if(service.provider_num_) {
        provider_num_ = new char[strlen(service.provider_num_) + 1];
        strcpy(provider_num_, service.provider_num_);
    } else {
        provider_num_ = NULL;
    }

    if(service.member_num_) {
        member_num_ = new char[strlen(service.member_num_) + 1];
        strcpy(member_num_, service.member_num_);
    } else {
        member_num_ = NULL;
    }
    
    if(service.service_code_) {
        service_code_ = new char[strlen(service.service_code_) + 1];
        strcpy(service_code_, service.service_code_);
    } else {
        service_code_ = NULL;
    }
    
    if(service.comment_) {
        comment_ = new char[strlen(service.comment_) + 1];
        strcpy(comment_, service.comment_);
    } else {
        comment_ = NULL;
    } 

    return *this;
}


void FObjService :: Erase() {
    if(date_) {
        delete [] date_;
        date_ = NULL;
    }
        
    if(time_) {
        delete [] time_;
        time_ = NULL;
    }
        
    if(provider_num_) {
        delete [] provider_num_;
        provider_num_ = NULL;
    }
        
    if(member_num_) {
        delete [] member_num_;
        member_num_ = NULL;
    }
        
    if(service_code_) {
        delete []  service_code_;
        service_code_ = NULL;
    }
        
    if(comment_) {
        delete [] comment_;
        comment_ = NULL;
    }
}


bool FObjService :: Read(ifstream& in) {
    char dt[len2sz(LEN_DATE)];
    char tm[len2sz(LEN_TIME)];
    char p_num[len2sz(LEN_PROVIDER_NUM)];
    char m_num[len2sz(LEN_MEMBER_NUM)];
    char sc[len2sz(LEN_SERVICE_CODE)];
    char comm[len2sz(LEN_COMMENT)];
    
    if(!in)
        return false;
    
    Erase();

    if(in.peek() != EOF) {
        in.get(tm, len2sz(LEN_TIME), '\n');
        in.ignore(1000, '\n');
        time_ = new char[len2sz(LEN_TIME)];
        strcpy(time_, tm);
    } 

    if(in.peek() != EOF) {
        in.get(dt, len2sz(LEN_DATE), '\n');
        in.ignore(1000, '\n');
        date_ = new char[len2sz(LEN_DATE)];
        strcpy(date_, dt);
    }

    if(in.peek() != EOF) {
        in.get(p_num, len2sz(LEN_PROVIDER_NUM), '\n');
        in.ignore(1000, '\n');
        provider_num_ = new char[len2sz(LEN_PROVIDER_NUM)];
        strcpy(provider_num_, p_num);
    }
    
    if(in.peek() != EOF) {
        in.get(m_num, len2sz(LEN_MEMBER_NUM), '\n');
        in.ignore(1000, '\n');
        member_num_ = new char[len2sz(LEN_MEMBER_NUM)];
        strcpy(member_num_, m_num);
    }

    if(in.peek() != EOF) {
        in.get(sc, len2sz(LEN_SERVICE_CODE), '\n');
        in.ignore(1000, '\n');
        service_code_ = new char[len2sz(LEN_SERVICE_CODE)];
        strcpy(service_code_, sc);
    }

    if(in.peek() != EOF) {
        in.get(comm, len2sz(LEN_COMMENT), '#');
        in.ignore(1000, '#');
        comment_ = new char[len2sz(LEN_COMMENT)];
        strcpy(comment_, comm);
    }

    return true;
}


bool FObjService :: Write(ofstream& out) const {
    if(!out)
        return false;

    out << time_ << endl;
    out << date_ << endl;
    out << provider_num_ << endl;
    out << member_num_ << endl;
    out << service_code_ << endl;
    out << comment_ << "#";
    
    return true;
}


void FObjService :: Display() const {
    cout << endl << "Service record:" << endl;
    cout << time_ << endl;
    cout << date_ << endl;
    cout << provider_num_ << endl;
    cout << member_num_ << endl;
    cout << service_code_ << endl;
    cout << comment_ << endl;
}


bool FObjService :: GenerateFileName(char* receiver) const {
    if(!time_ || !provider_num_) 
        return false;
    
    char tmp[len2sz(LEN_TIME + LEN_PROVIDER_NAME + 5)];
    strcpy(tmp, time_);
    strcat(tmp, "_");
    strcat(tmp, provider_num_);
    strcat(tmp, ".txt");
    strcpy(receiver, tmp);
    return true;
}


bool FObjService :: get_date(char* receiver) const {
    if(!date_)
        return false;
    strcpy(receiver, date_);
    return true;
}


bool FObjService :: GetComputerReceivedDate(char* receiver) const {
    if(!time_)
        return false;
    strncpy(receiver, time_, 10);
    return true;
}


char* FObjService :: get_date() const {
    return date_;
}
       

char* FObjService :: get_time() const {
    return time_;
}
        
        
char* FObjService :: get_provider_num() const {
    return provider_num_;
}
        
        
char* FObjService :: get_member_num() const {
    return member_num_;
}
        
        
char* FObjService :: get_service_code() const {
    return service_code_;
}
        
    
char* FObjService :: get_comment() const {
    return comment_;
}