// Copyright (c) 2018 Yiming Lin

#include <cstring>
#include <iostream>
#include "uni.h"
#include "filesyspara.h"

using namespace std;


Date :: Date() : month(0), day(0), year(0)
{
}


Date :: Date(char* dt) {
    int m1, m2;
    int d1, d2;
    int y1, y2, y3, y4;

    if(strlen(dt) != LEN_DATE) {
        month = 0;
        day = 0;
        year = 0;
    } else {
        m1 = ch2int(dt[0]);
        m2 = ch2int(dt[1]);
        d1 = ch2int(dt[3]);
        d2 = ch2int(dt[4]);
        y1 = ch2int(dt[6]);
        y2 = ch2int(dt[7]);
        y3 = ch2int(dt[8]);
        y4 = ch2int(dt[9]);

        month = twobit2int(m1, m2);
        day = twobit2int(d1, d2);
        year = fourbit2int(y1, y2, y3, y4);
    }
}


Date :: Date(int m, int d, int y) 
    : month(m), day(d), year(y)
{
}


void Date :: getch(char* dt) {
    dt[0] = int2askii(month / 10);
    dt[1] = int2askii(month % 10);
    dt[2] = '_';
    dt[3] = int2askii(day / 10);
    dt[4] = int2askii(day % 10);
    dt[5] = '_';
    dt[6] = int2askii(year / 1000);
    dt[7] = int2askii((year % 1000) / 100);
    dt[8] = int2askii((year % 100) / 10);
    dt[9] = int2askii(year % 10);
    dt[10] = '\0';
}


int Date :: dtcmp(Date& dt) {
    if(year > dt.year) 
        return 1;
    if(year < dt.year)
        return -1;

    if(month > dt.month) 
        return 1;
    if(month < dt.month)    
        return -1;

    if(day > dt.day)    
        return 1;
    if(day < dt.day)
        return -1;
    return 0;
}


int Date :: dtcmp(Date& d1, Date& d2) {
    return d1.dtcmp(d2);
}


int Date :: dtcmp(char* d1, char* d2) {
    Date date1(d1);
    Date date2(d2);
    return date1.dtcmp(date2);
}


void Date :: getlwk() {
    int d, m, y;
    if(day > 7) {
        d = day - 7;
        m = month;
        y = year;
    } else {
        if(month == 2) {
            d = 28 + (day - 7);
            m = month - 1;
            y = year;
        } else if(month == 1 || 
                  month == 3 ||
                  month == 5 ||
                  month == 7 || 
                  month == 8 ||
                  month == 10 ||
                  month == 12) {
            if(month == 1) {
                d = 31 + (day - 7);
                m = 12;
                y = year - 1;
            } else {
                d = 31 + (day - 7);
                m = month - 1;
                y = year;
            }
        } else {
            d = 30 + (day - 7);
            m = month - 1;
            y = year;
        }
    }

    month = m;
    day = d;
    year = y;
}


void Date :: getnwk() {
    int d, m, y; 

    if(month == 2) {
        if(day <= 21) {
            d = day + 7;
            m = month;
            y = year;
        } else {
            d = day + 7 - 28;
            m = month + 1;
            y = year;
        }
    } else if(month == 1 || 
              month == 3 ||
              month == 5 ||
              month == 7 || 
              month == 8 ||
              month == 10 ||
              month == 12) {
        if(day <= 24) {
            d = day + 7;
            m = month;
            y = year;
        } else {
            if(month == 12) {
                d = day + 7 - 31;
                m = 1;
                y = year + 1;
            } else {
                d = day + 7 - 31;
                m = month + 1;
                y = year;
            }
        }
    } else {
        if(day <= 23) {
            d = day + 7;
            m = month;
            y = year;
        } else {
            d = day + 7 - 31;
            m = month + 1;
            y = year;
        }
    }

    month = m;
    day = d;
    year = y;
}


void Date :: getchlwk(char* dt) {
    getlwk();
    getch(dt);
}


void Date :: getchnwk(char* dt) {
    getnwk();
    getch(dt);
}


bool Date :: getstdformat(char* receiver, const char* dt) {
    if(!dt || strlen(dt) != LEN_DATE)
        return false;
    for(int i = 0; i < LEN_DATE; ++i)
        receiver[i] = dt[i];
    receiver[2] = '-';
    receiver[5] = '-';
    receiver[LEN_DATE] = '\0';
    return true;
}



Time :: Time() : hour(0), minute(0), second(0)
{
}


Time :: Time(int m, int d, int y, int h, int min, int s)
     : Date(m, d, y), hour(h), minute(min), second(s)
{
}


Time :: Time(char* tm) {
    int m1, m2;
    int d1, d2;
    int y1, y2, y3, y4;
    int h1, h2;
    int min1, min2;
    int s1, s2;

    if(strlen(tm) != LEN_TIME) {      
        month = 0;
        year = 0;
        day = 0;
        hour = 0;
        minute = 0;
        second = 0;
    } else {
        m1 = ch2int(tm[0]);
        m2 = ch2int(tm[1]);
        d1 = ch2int(tm[3]);
        d2 = ch2int(tm[4]);
        y1 = ch2int(tm[6]);
        y2 = ch2int(tm[7]);
        y3 = ch2int(tm[8]);
        y4 = ch2int(tm[9]);
        h1 = ch2int(tm[11]);
        h2 = ch2int(tm[12]);
        min1 = ch2int(tm[14]);
        min2 = ch2int(tm[15]);
        s1 = ch2int(tm[17]);
        s2 = ch2int(tm[18]);

        month = twobit2int(m1, m2);
        day = twobit2int(d1, d2);
        year = fourbit2int(y1, y2, y3, y4);
        hour = twobit2int(h1, h2);
        minute = twobit2int(min1, min2);
        second = twobit2int(s1, s2);
    }
}


void Time :: getch(char* tm) {
    tm[0] = int2askii(month / 10);
    tm[1] = int2askii(month % 10);
    tm[2] = '_';
    tm[3] = int2askii(day / 10);
    tm[4] = int2askii(day % 10);
    tm[5] = '_';
    tm[6] = int2askii(year / 1000);
    tm[7] = int2askii((year % 1000) / 100);
    tm[8] = int2askii((year % 100) / 10);
    tm[9] = int2askii(year % 10);
    tm[10] = '_';
    tm[11] = int2askii(hour / 10);
    tm[12] = int2askii(hour % 10);
    tm[13] = '_';
    tm[14] = int2askii(minute / 10);
    tm[15] = int2askii(minute % 10);
    tm[16] = '_';
    tm[17] = int2askii(second / 10);
    tm[18] = int2askii(second % 10);
    tm[19] = '\0';
}


int Time :: tmcmp(Time& tm) {
    int dt_ret;
    
    dt_ret = Date :: dtcmp(tm);
    if(dt_ret != 0) {
        return dt_ret;
    } else {
        if(hour > tm.hour)
            return 1;
        if(hour < tm.hour)
            return -1;

        if(minute > tm.minute)
            return 1;
        if(minute < tm.minute)
            return -1;
        
        if(second > tm.second)
            return 1;
        if(second < tm.second)
            return -1;
        return 0;
    }
}


int Time :: tmcmp(Time& t1, Time& t2) {
    return t1.tmcmp(t2);
}


int Time :: tmcmp(const char* t1, const char* t2) {
    char tm1[len2sz(LEN_TIME)];
    char tm2[len2sz(LEN_TIME)];
    strcpy(tm1, t1);
    strcpy(tm2, t2);
    Time time1(tm1);
    Time time2(tm2);
    return time1.tmcmp(time2);
}


bool Time :: getstdformat(char* receiver, const char* tm) {
    if(!tm || strlen(tm) != LEN_TIME)
        return false;
    for(int i = 0; i < LEN_TIME; ++i)
        receiver[i] = tm[i];
    receiver[2] = '-';
    receiver[5] = '-';
    receiver[10] = ' ';
    receiver[13] = ':';
    receiver[16] = ':';
    receiver[19] = '\0';
    return true;
}


//testing purpose function
void Date :: Display() {
    cout << month << " " << day << " " << year << endl;
}


void Time :: Display() {
    cout << month << " " << day << " " << year << " " << hour << " " << minute << " " << second << endl;
}


void incre3dig(char* num) {
    int n1, n2, n3;
    int val;
    
    if(!num || strlen(num) != 3) 
        return ;

    n1 = ch2int(num[0]);
    n2 = ch2int(num[1]);
    n3 = ch2int(num[2]);
    val = n1 * 100 + n2 * 10 + n3 + 1;
    if(val < 1000) {
        num[0] = int2askii(val / 100);
        num[1] = int2askii((val % 100) / 10);
        num[2] = int2askii(val % 10);
    } else {
        num[0] = '0';
        num[1] = '0';
        num[2] = '0';
    }
}


static const int prime_set[11] = 
{
    53, 97, 193, 389, 769,
    1543, 3079, 6151, 
    12289, 24593,49157
};


int GetPrime(int num) {
    const int* first = prime_set;
    const int* last = prime_set + 10;
    const int* position = lower_bound(first, last, num);
    int pos = position - prime_set;
    return prime_set[pos];   
}


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

