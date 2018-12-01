#define DIR_service           0
#define DIR_report            DIR_service+1
#define DIR_cdc               DIR_report+1
#define DIR_eft               DIR_cdc+1
#define DIR_pd                DIR_eft+1

#define DIR_member_rpt        0
#define DIR_provider_rpt      DIR_member_rpt+1
#define DIR_manager_rpt       DIR_provider_rpt+1
#define DIR_eft_rpt           DIR_manager_rpt+1

#define FILE_service_record   1
#define FILE_member_report    FILE_service_record+1
#define FILE_provider_report  FILE_member_report+1
#define FILE_manager_report   FILE_provider_report+1
#define FILE_cdc_member       FILE_manager_report+1
#define FILE_cdc_provider     FILE_cdc_member+1
#define FILE_provider_directory FILE_cdc_provider+1
#define FILE_eft_record       FILE_provider_directory+1

#define LEN_MEMBER_NUM        9
#define LEN_PROVIDER_NUM      9
#define LEN_SERVICE_CODE      6
#define LEN_DATE              10
#define LEN_TIME              19
#define LEN_COMMENT           100
#define LEN_PROVIDER_NAME     25
#define LEN_MEMBER_NAME       25
#define LEN_SERVICE_NAME      20
#define LEN_ADDRESS           25
#define LEN_CITY              14
#define LEN_STATE             2
#define LEN_ZIP_CODE          5
#define LEN_STATUS            50
#define LEN_CONSULTATION_NUM  3

#define LEN_PATH_MAX          512
#define LEN_SERVICE_FILE      34
#define LEN_MEMBER_FILE       36
#define LEN_EFT_FILE          28
#define LEN_MANAGER_FILE      14
#define LEN_PD_FILE           42

#define MANAGER_REPORT_MAX    50
#define MAX_CDC_ENTRIES       100

#define len2sz(x) ((int)(x) + 1)

extern char* report_classes[];
extern char* file_classes[];
