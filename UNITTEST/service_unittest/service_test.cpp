// Copyright (c) 2018 Yiming Lin
// This file is the unit tests for the service record
// Five unit tests are included:
// (1) Default constructor
// (2) Constructor with arguments
// (3) Copy constructor
// (3) Filename generation
// (4) External file reading and writing

#include "service.h"
#include "gtest/gtest.h"


namespace {

// Tests the default c'tor.
TEST(FObjService, DefaultConstructor) {
    const FObjService service;

    // Asserts that all six fields in service shall be NULL.
    // The six testing purpose functions mentioned in 
    // service.h are used.
    EXPECT_STREQ(NULL, service.get_date());
    EXPECT_STREQ(NULL, service.get_time());
    EXPECT_STREQ(NULL, service.get_provider_num());
    EXPECT_STREQ(NULL, service.get_member_num());
    EXPECT_STREQ(NULL, service.get_service_code());
    EXPECT_STREQ(NULL, service.get_comment());
}

char dt[] = "11_30_2018";
char tm[] = "11_30_2018_11_13_20";
char p_number[] = "333333444";
char m_number[] = "444445555";
char s_code[] = "424532";
char comm[] = "This is a testing comment";

// Tests the c'tor that accepts a group of service information
TEST(FObjService, ConstructorFromFObjService) {
    const FObjService service(dt, tm, p_number, m_number, s_code, comm);

    // Asserts that all six fields are same as input 
    EXPECT_EQ(0, strcmp(service.get_date(), dt));
    EXPECT_EQ(0, strcmp(service.get_time(), tm));
    EXPECT_EQ(0, strcmp(service.get_provider_num(), p_number));
    EXPECT_EQ(0, strcmp(service.get_member_num(), m_number));
    EXPECT_EQ(0, strcmp(service.get_service_code(), s_code));
    EXPECT_EQ(0, strcmp(service.get_comment(), comm));
}

// Tests the copy c'tor.
TEST(FObjService, CopyConstructor) {
    const FObjService s1(dt, tm, p_number, m_number, s_code, comm);
    const FObjService s2 = s1;

    // Asserts that all six fields in s2 are same as s1
    EXPECT_EQ(0, strcmp(s2.get_date(), dt));
    EXPECT_EQ(0, strcmp(s2.get_time(), tm));
    EXPECT_EQ(0, strcmp(s2.get_provider_num(), p_number));
    EXPECT_EQ(0, strcmp(s2.get_member_num(), m_number));
    EXPECT_EQ(0, strcmp(s2.get_service_code(), s_code));
    EXPECT_EQ(0, strcmp(s2.get_comment(), comm));
}

// The expected file name is service time followed by the provider number
const char expected_filename[] = "11_30_2018_11_13_20_333333444.txt";

// Test file name generation.
TEST(FObjService, GenerateFilename) {
    char filename[512];
    const FObjService service(dt, tm, p_number, m_number, s_code, comm);

    // Asserts that the file name is generated which is same 
    // as expected_filename
    EXPECT_TRUE(true == service.GenerateFileName(filename));
    EXPECT_STREQ(expected_filename, filename);
}

// Test service record reading and writing from/into the external file
TEST(FObjService, ServiceReadWrite) {
    const FObjService s_write(dt, tm, p_number, m_number, s_code, comm);
    FObjService s_read;
    std :: ofstream out;
    std :: ifstream in;

    out.std :: ofstream :: open(expected_filename);
    EXPECT_TRUE(out);
    EXPECT_TRUE(true == s_write.Write(out));
    out.std :: ofstream :: close();

    in.std :: ifstream :: open(expected_filename);
    EXPECT_TRUE(in);
    EXPECT_TRUE(true == s_read.Read(in));
    in.std :: ifstream :: close();
    
    // Asserts that writing and reading have the same value of each field
    EXPECT_EQ(0, strcmp(s_read.get_date(), s_write.get_date()));
    EXPECT_EQ(0, strcmp(s_read.get_time(), s_write.get_time()));
    EXPECT_EQ(0, strcmp(s_read.get_provider_num(), s_write.get_provider_num()));
    EXPECT_EQ(0, strcmp(s_read.get_member_num(), s_write.get_member_num()));
    EXPECT_EQ(0, strcmp(s_read.get_service_code(), s_write.get_service_code()));
    EXPECT_EQ(0, strcmp(s_read.get_comment(), s_write.get_comment()));
    EXPECT_EQ(0, unlink(expected_filename));
}
} // namespace
