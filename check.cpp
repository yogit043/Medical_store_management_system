#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
using namespace std;
void take_bill_no(int &typecasted_bill_no,string& bill_no,int& i_for_bill_no)
{
    try
    {
        if(i_for_bill_no==0)
        cout<<"Enter the bill number.."<<endl;
        else
        cout<<"Enter the correct quantity pls"<<endl;
        cin>>bill_no;
        i_for_bill_no=i_for_bill_no+1;
        typecasted_bill_no = std::stoi(bill_no);
    }
    catch(std::invalid_argument e1)
    {
        std::cout << "Error: Invalid bill number given msg from check" << std::endl;
        take_bill_no(typecasted_bill_no,bill_no,i_for_bill_no);
    }
}

int findWord2_from_sale(const string& batch_no,const string& medicine_name)
{
    int line_number=0;
    ifstream sale;
    sale.open("salefile.txt");
    string line;
    if(!sale.is_open())
    {
        cout<<"Error in opening sale file"<<endl;
        return 0;
    }
    while(sale.good())
    {
        getline(sale,line);
        line_number++;
        if(line==batch_no)
        {
            getline(sale,line);
            line_number++;
            if(line==medicine_name)
            {
                return line_number;
            }
        }
    }
    sale.close();
    if(!sale.is_open())
    {
        cout<<"sale is closed in find word 2"<<endl;
    }
    return 0;
}

int findWord1_from_sale(const int& bill_no)
{
    int line_number=0;
    ifstream sale;
    sale.open("salefile.txt");
    string line;
    if(!sale.is_open())
    {
        cout<<"Error in opening sale file"<<endl;
        return 0;
    }
    while(sale.good())
    {
        getline(sale,line);
        line_number++;
        if(line==to_string(bill_no))
        {
            sale.close();
            return line_number;
        }
    }
    sale.close();
    return 0;
}

int* return_line_numbers_from_sale(int bill_no)
{
    static int line_number_array[]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int i=0;
    fstream sale;
    string line;
    int line_num=0;
    sale.open("salefile.txt");
    while(sale.good())
    {
        getline(sale,line);
        line_num++;
        if(line==to_string(bill_no))
        {
            line_number_array[i]=line_num;
            i++;
        }
    }
    sale.close();
    if(!sale.is_open())
    {
        cout<<"sale closed in return line numbers in check .cpp"<<endl;
    }
    return line_number_array;
}