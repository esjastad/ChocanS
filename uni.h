// Copyright (c) 2018 Yiming Lin

#define ch2int(x) ((char)(x) - 48)
#define int2askii(x) ((int)(x) + 48)
#define twobit2int(x1, x2) ((int)(x1) * 10 + (int)(x2))
#define fourbit2int(x1, x2, x3, x4) ((int)(x1) * 1000 + (int)(x2) * 100 + (int)(x3) * 10 + (int)(x4))

void incre3dig(char* num);
int GetPrime(int num);
int convertch2int(const char*);
bool convertint2ch(int, char*);
int power10(int num);

class Date {
    public: 
        Date();
        Date(char*);
        Date(int, int, int);

        void getch(char*);
        int dtcmp(Date&);

        static int dtcmp(Date&, Date&);
        static int dtcmp(char*, char*);
        
        void getlwk();
        void getnwk();
        void getchlwk(char*);
        void getchnwk(char*);

        static bool getstdformat(char*, const char*);

        void Display();

    protected:
        int month;
        int day;
        int year;
};


class Time : public Date {
    public: 
        Time();
        Time(char*);
        Time(int, int, int, int, int, int);

        void getch(char*);
        int tmcmp(Time&);

        static int tmcmp(Time&, Time&);
        static int tmcmp(const char*, const char*);

        static bool getstdformat(char*, const char*);

        void Display();

    private: 
        int hour;
        int minute;
        int second;
};