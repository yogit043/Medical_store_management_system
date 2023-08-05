#include<iostream>
#include<string.h>
#include<string>
#include<time.h>
// #include<fstream>
// #include<ctime>
using namespace std;

string date()
{
    string dates;
    time_t Unix=time(nullptr);
    struct tm* current_time=localtime(&Unix);
    int day=current_time->tm_mday;
    int month=current_time->tm_mon+1;
    int year=current_time->tm_year+1900;
    dates="Date        :"+to_string(day)+"-"+to_string(month)+"-"+to_string(year);
    return dates;
}

void sale_date(int *day,int *month,int *year)
{
    string dates;
    time_t Unix=time(nullptr);
    struct tm* current_time=localtime(&Unix);
    *day=current_time->tm_mday;
    *month=current_time->tm_mon+1;
    *year=current_time->tm_year+1900;
}

void format_date(int* day_stock,int* month_stock,int* year_stock,tm* date_expiry)
{
    cout<<"entered format fn"<<endl;
    date_expiry->tm_mday=*day_stock;
    date_expiry->tm_mon=*month_stock-1;
    date_expiry->tm_year=*year_stock-1900;
}