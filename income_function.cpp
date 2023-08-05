#include<iostream>
#include<fstream>
#include <string.h>
using namespace std;
void income(int* day ,int * month,int * year)
{
    int toatl_income=0;
    string line;
    ifstream sale;
    sale.open("salefile.txt");
    while(sale.good())
    {
        getline(sale,line);
        if(line==to_string(*day))
        {
            getline(sale,line);
            if(line==to_string(*month))
            {
                getline(sale,line);
                if(line==to_string(*year))
                getline(sale,line);
                getline(sale,line);
                getline(sale,line);
                getline(sale,line);
                toatl_income+=stoi(line);
                // cout<<line<<endl;

            }
            
        }
    }
    cout<<"Total income of the day is "<<toatl_income<<endl;
}



