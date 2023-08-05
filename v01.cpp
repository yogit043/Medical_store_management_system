#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
#include<sstream>
#include<ctime>
#include<cstring>
#include "filefunctions.cpp"
#include "DisplayFunctions.cpp"
#include "check.cpp"
#include "DateFunctions.cpp"
#include "Bill.cpp"
#include "ReturnFunctions.cpp"
#include "income_function.cpp"
using namespace std;
void menu()
{
    cout<<"Enter 1 to add a medicine"<<endl;
    cout<<"Enter 2 to display the stock of a medicine"<<endl;
    cout<<"Enter 3 to bill a medicine"<<endl;
    cout<<"Enter 4 to return a medicine"<<endl;
    cout<<"Enter 5 to view the income"<<endl;
    cout<<"Enter 6 to exit"<<endl;
}

void add()
{
    //TODO:1) make sure input formats are correct
    //TODO: look about expiry date
    int line_number,i=1;
    string med_id,med_name,qty,price,sell;
    fstream stock;
    stock.open("stockfile.txt",ios::app);
    cout<<"Enter Batch Number of medicine"<<endl;
    cin>>med_id;
    cout<<"Enter Name of the Medicine"<<endl;
    getline(cin>>ws,med_name);
    cout<<"Enter the Quantity available"<<endl;
    cin>>qty;
    cout<<"Enter the Expiry date"<<endl;
    int month,year;
    int day;
    cin>>day;
    cin.get();
    cin>>month;
    cin.get();
    cin>>year;
    cout<<"Enter the Price of the medicine"<<endl;
    cin>>price;
    cout<<"Can the medicine be sold without doctor's prescription? (enter false if medicine is not to be sold)"<<endl;
    cin>>sell;
    line_number=findWord2(med_id,med_name);
    if(line_number==0)
    {   
        SaveToStock(med_id,&i);
        SaveToStock(med_name,&i);
        SaveToStock(qty,&i);
        SaveToStock(to_string(day),&i);
        SaveToStock(to_string(month),&i);
        SaveToStock(to_string(year),&i);
        SaveToStock(price,&i);
        stock<<sell;
        cout<<endl;
        cout<<"New Medicine added successfully!! :)"<<endl;
    }
    else
    {
        cout<<endl;
        string file1 = "stockfile.txt";
        update(file1,line_number,qty);
        

    }
    stock.close();
}

int main()
{
    int day,month,year;
    int choice;
    string med_name;
    int j;
    ifstream jfile;
    jfile.open("jfile.txt");
    string jline;
    getline(jfile,jline);
    j = stoi(jline);
    jfile.close();
    menu();
    cout<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;

    switch(choice)
    {
        case 1:
            add();
            break;
        case 2:
            cout<<endl;
            cout<<"Enter the name of the medicine you wanted to know about."<<endl;
            getline(cin,med_name);
            // cout<<"one getline skipped"<<endl;
            getline(cin,med_name);
            // cin>>med_name;
            cout<<endl;
            display(med_name);
            break;
        case 3:
            cout<<date()<<endl;
            cout<<"Bill Number :"<<j<<endl;
            bill(&j);
            cout<<endl;

            break;
        case 4:
            cout<<endl;
            To_Return();
            break;
        
        case 5:
            cout<<"Enter the date"<<endl;
            cin>>day;
            cin.get();
            cin>>month;
            cin.get();
            cin>>year;
            income(&day,&month,&year);
            break;
        case 6:
            cout<<endl;
            cout<<"Bye Bye..!!"<<endl;
            break;
        default :
            cout<<"Choose from the options given."<<endl;

    } 
}