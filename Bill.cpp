#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
using namespace std;
// int main(){}
void take_qty(int &typecasted_qty,string& qty,int& i_for_take_qty)
{
    try
    {
        if(i_for_take_qty==0)
        cout<<"Also the quantity please!"<<endl;
        else
        cout<<"Enter the correct quantity pls"<<endl;
        cin>>qty;
        i_for_take_qty=i_for_take_qty+1;
        typecasted_qty = std::stoi(qty);
        if(typecasted_qty<2000)
        {
            typecasted_qty+=2000;
        }
    }
    catch(std::invalid_argument e1)
    {
        std::cout << "Error: Invalid quantity provided msg from bill" << std::endl;
        take_qty(typecasted_qty,qty,i_for_take_qty);
    }
}


int return_price(int line_number)
{
    ifstream stock;
    string price1;
    int price2;
    stock.open("stockfile.txt");
    for(int i=0;i<5+line_number;i++)
    {
        getline(stock,price1);
    }

    price2 = stoi(price1);

    return price2;
    stock.close();
    if(!stock.is_open())
    {
        cout<<"stock closed in return price in bill.cpp"<<endl;
    }
}
void return_batch_no(string medicine_name)
{

    int* pointer_to_line_numbers=return_line_numbers(medicine_name);
    ifstream stock;
    stock.open("stockfile.txt");
    string line;
    int currentLine=0;
    for(int iterator=0;iterator<5;iterator++)
    {
        //cout<<"array of line nums are "<<pointer_to_line_numbers[iterator]<<endl;
        // currentLine=0;
        while(stock.good())
        {
            getline(stock,line);
            currentLine++;
            // cout<<"iterator "<<iterator<<"value of line number"<<pointer_to_line_numbers[iterator]<<" current line no "<<currentLine<<" line is "<<line<<endl;         
            if(pointer_to_line_numbers[iterator]-1==currentLine)
            {
                cout<<line<<endl;
                //getline(stock,line);
                iterator++;
            }   
        }
    }
    stock.close();
            
}

void file_bill(string medicine_name,string batch_no,string qty,int* j)
{
    int q=1;
    string line;
    fstream stock;
    fstream sale;
    int day,month,year;
    stock.open("stockfile.txt",ios::app);
    sale.open("salefile.txt",ios::app);
    sale_date(&day,&month,&year);
    SaveToSale(to_string(*j),&q);
    SaveToSale(to_string(day),&q);
    SaveToSale(to_string(month),&q);
    SaveToSale(to_string(year),&q);
    SaveToSale(batch_no,&q);
    SaveToSale(medicine_name,&q);
    SaveToSale(qty,&q);  //TODO: undo these if any bugs found
    // sale<<qty;
    stock.close();
    // if(!stock.is_open())
    // {
    //     cout<<"stock closed in file bill in display functions.cpp"<<endl;
    // }
}
 

void bill(int *j)
{
    fstream stock;
    fstream sale;
    stock.open("stockfile.txt",ios::app);
    sale.open("salefile.txt",ios::app);
    string medicine_name, batch_no,qty;
    int i=0;
    int total_price=0,typecasted_qty=0;
    int line_number = findWord2(batch_no,medicine_name);
    int line1;
    // cout<<line_number<<endl;
    string line;
    int current_line=0;
    
    while(true)
    {
        int i_for_take_qty=0;
        if(i==0)
        {
            cout<<"C'mon! Let me know the medicine you want."<<endl;
            getline(cin,medicine_name);
        }
        else
        {
            cout<<"Wanna add more medicines?? \nEnter the name of the medicine.OR press 0 to exit"<<endl;
            getline(cin,medicine_name);
        }
        
        getline(cin,medicine_name);

        if(medicine_name!="0")
        {
            cout<<"Available Batches:"<<endl;
            return_batch_no(medicine_name);
            // cout<<"!!"<<endl;
            cin>>batch_no;
            int line_number = findWord2(batch_no,medicine_name);
            line1 = line_number;
            int price_per_item=return_price(line_number);

            take_qty(typecasted_qty,qty,i_for_take_qty);

            total_price=total_price+(typecasted_qty*price_per_item);
            // cout<<"this is price per item"<<price_per_item<<endl;
            i++;
            file_bill(medicine_name,batch_no,qty,j);
            cout<<"Batch number   :"<<batch_no<<endl;
            cout<<"Medicine name  :"<<medicine_name<<endl;
            cout<<"Quantity       :"<<qty<<endl;
            cout<<"Price          :"<<stoi(qty)*price_per_item<<endl<<endl;
           // SaveToSale(to_string(stoi(qty)*price_per_item));
            sale<<stoi(qty)*price_per_item;

        }
        else
        {
            break;
        }
    }
    if(i!=1)
    {
        cout<<"Amount to be paid is : "<<total_price<<endl;
    }
    *j=*j+1;
    update_j("jfile.txt",0,to_string(*j));
    stock.close();
    update_stock("stockfile.txt",line1,qty);
}