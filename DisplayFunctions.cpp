#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
// #include"filefunctions.cpp"
using namespace std;
// int main(){}

void add_again()
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
    stock.close();
}

int* return_line_numbers(string med_name)
{
    static int line_number_array[]={-1,-1,-1,-1,-1};
    int i=0;
    fstream stock;
    string line;
    int line_num=0;
    stock.open("stockfile.txt");
    while(stock.good())
    {
        getline(stock,line);
        line_num++;
        if(line==med_name)
        {
            line_number_array[i]=line_num;
            i++;
        }
    }
    stock.close();
    return line_number_array;
}

void display(string medicine_name)
{
    int j=0;
    int* pointer_to_line_numbers=return_line_numbers(medicine_name);
    ifstream stock;
    stock.open("stockfile.txt");
    string line;
    if(medicine_name.length()!=0)
    {
        int currentLine=1;
        if (pointer_to_line_numbers[0]==-1)
        {
            cout<<"NO MEDICINE FOUND!! Check for typos."<<endl<<endl;
            cout<<"Enter the name of the medicine again OR Enter 1 to add the medicine. "<<endl;
            getline(cin,medicine_name);
            if(medicine_name=="1")
            {
                add_again();
                return;
            }
            display(medicine_name);
        }
        else
        {
            currentLine=0;
            for(int iterator=0;iterator<5;iterator++)
            {
                // cout<<"array of line nums are "<<pointer_to_line_numbers[iterator]<<endl;
                // currentLine=0;
                while(stock.good())
                {
                    getline(stock,line);
                    currentLine++;
                    // cout<<"iterator "<<iterator<<"value of line number"<<pointer_to_line_numbers[iterator]<<" current line no "<<currentLine<<" line is "<<line<<endl;
                    if(pointer_to_line_numbers[iterator]-1==currentLine)
                    {
                            
                            cout<<"Batch Number       :"<<line<<endl;
                            getline(stock,line);
                            cout<<"Medicine Name      :"<<line<<endl;
                            getline(stock,line);
                            cout<<"Quantity Available :"<<line<<endl;
                            getline(stock,line);
                            cout<<"Expiry date        :"<<line<<"-";
                            getline(stock,line);
                            cout<<line<<"-";
                            getline(stock,line);
                            cout<<line<<endl;
                            getline(stock,line);
                            cout<<"Price per Item     :"<<line<<endl;
                            getline(stock,line);
                            cout<<"LEGAL??            :"<<line<<endl;
                            cout<<endl;
                            // TODO:update this if expiry is added make it currentLine+=5
                            currentLine+=7;
                            break;
                    }
                    
                }
            }
        }
    }
    else
    {
        
        while(stock.good())
        {
            getline(stock,line);
            cout<<"Batch Number       :"<<line<<endl;
            getline(stock,line);
            cout<<"Medicine Name      :"<<line<<endl;
            getline(stock,line);
            cout<<"Quantity Available :"<<line<<endl;
            getline(stock,line);
            cout<<"Expiry date        :"<<line<<"-";
            getline(stock,line);
            cout<<line<<"-";
            getline(stock,line);
            cout<<line<<endl;
            getline(stock,line);
            cout<<"Price per Item     :"<<line<<endl;
            getline(stock,line);
            cout<<"LEGAL??            :"<<line<<endl;
            cout<<endl;
        }
    }
    stock.close();
}

