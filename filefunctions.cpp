#include<iostream>
#include<string.h>
#include<string>
#include<cstring>
#include<fstream>
#include<sstream>
using namespace std;
// int main(){}
//will take 2 args
int findWord2(const string& batch_no,const string& medicine_name)
{
    int line_number=0;
    ifstream stock;
    stock.open("stockfile.txt");
    string line;
    if(!stock.is_open())
    {
        cout<<"Error in opening stock file"<<endl;
        return 0;
    }
    while(stock.good())
    {
        getline(stock,line);
        line_number++;
        if(line==batch_no)
        {
            getline(stock,line);
            line_number++;
            if(line==medicine_name)
            {
                return line_number;
            }
        }
    }
    stock.close();
    return 0;
}
// single argument
int findWord1(const string& medicine_name)
{
    int line_number=0;
    ifstream stock;
    stock.open("stockfile.txt");
    string line;
    if(!stock.is_open())
    {
        cout<<"Error in opening stock file"<<endl;
        return 0;
    }
    while(stock.good())
    {
        getline(stock,line);
        line_number++;
        if(line==medicine_name)
        {
            stock.close();
            return line_number;
        }
    }
    stock.close();
    return 0;
}


void SaveToStock(string detail,int* i)
{
    fstream stock;
    stock.open("stockfile.txt",ios::app);
    if(*i==1)
    { 
        stock<<endl;   
    }
    stock<<detail<<endl;
    *i=*i+1;
}

void SaveToSale(string detail,int* q)
{
    fstream sale;
    sale.open("salefile.txt",ios::app);
    if(*q==1)
    { 
        sale<<endl;   
    }
    sale<<detail<<endl;
    *q=*q+1;
}



void update(const string& file1 , int line_number , const string& qty)
{
    int typecasted_qty = stoi(qty);
    int stored_quantity, currentLine;
    ifstream inputFile(file1);
    if (!inputFile.is_open())
    {
        cout << "Error opening Stock File" << endl;
        return;
    }
    ofstream tempfile("tempfile.txt");

    if (!tempfile.is_open())
    {
        cout << "Error opening Temporary File" << endl;
        inputFile.close();
        return;
    }

    int final_quantity;
    string line;
    currentLine = 1;

    while (getline(inputFile, line))
    {
        if (currentLine == line_number+1)
        {
            stored_quantity = stoi(line);
            final_quantity = stored_quantity+typecasted_qty;
            tempfile << final_quantity << endl;
        }
        else
        {
            tempfile << line << endl;
        }
        currentLine++;
    }

    //stock.close();
    inputFile.close();
    tempfile.close();

    if (remove(file1.c_str()) != 0)
    {
        cout << "Error deleting file" << endl;
        return;
    }

    if (rename("tempfile.txt", file1.c_str()) != 0)
    {
        cout << "Error renaming file!!" << endl;
        return;
    }

    cout << "Stock updated successfully!! :-)" << endl;
}


void update_j(const string& file1 , int line_number , const string& qty)
{
    int typecasted_qty = stoi(qty);
    int stored_quantity, currentLine;
    ifstream inputFile(file1);
    if (!inputFile.is_open())
    {
        cout << "Error opening Stock File" << endl;
        return;
    }
    ofstream tempfile("tempfile.txt");

    if (!tempfile.is_open())
    {
        cout << "Error opening Temporary File" << endl;
        inputFile.close();
        return;
    }

    int final_quantity;
    string line;
    currentLine = 1;

    while (getline(inputFile, line))
    {
        if (currentLine == line_number+1)
        {
            
            tempfile <<typecasted_qty<< endl;
        }
        else
        {
            tempfile << line << endl;
        }
        currentLine++;
    }

    //stock.close();
    inputFile.close();
    tempfile.close();

    if (remove(file1.c_str()) != 0)
    {
        cout << "Error deleting file" << endl;
        return;
    }

    if (rename("tempfile.txt", file1.c_str()) != 0)
    {
        cout << "Error renaming file!!" << endl;
        return;
    }
}



void update_stock(const string& file1, int line_number, const string& qty)
{
    ifstream stock;
    stock.open("stockfile.txt");
    int typecasted_qty = 0;
    int current_line=0;
    try
    {
        typecasted_qty = stoi(qty);
    }
    catch(invalid_argument e1)
    {
        cout << "Check your quantity provided" << endl;
        return;
    }
    
    int stored_quantity, currentLine;
    ifstream inputFile(file1);
    if (!inputFile.is_open())
    {
        cout << "Error opening Stock File" << endl;
        return;
    }
    ofstream tempfile("tempfile1.txt");

    if (!tempfile.is_open())
    {
        cout << "Error opening Temporary File" << endl;
        inputFile.close();
        return;
    }

    int final_quantity;
    string line;
    currentLine = 1;

    while (getline(inputFile, line))
    {
        if (currentLine == line_number+1)
        {
                // cout<<"stored quantity in the line in udate stock fn"<<line<<endl;
                stored_quantity = stoi(line);
        
            
            final_quantity = stored_quantity - typecasted_qty;
            if (final_quantity < 0)
            {
                cout << "We dont have enough stock" << endl;
                while(stock.good())
                {
                    getline(stock,line);
                    current_line++;
                    if(line_number+1==current_line)
                    {
                        cout<<"Available stock :"<<line<<endl;
                        cout<<"Come back later for more"<<endl;
                    }
                }
                inputFile.close();
                tempfile.close();
                remove("tempfile1.txt");
                return;
            }
            tempfile << final_quantity << endl;
        }
        else
        {
            tempfile << line << endl;
        }
        currentLine++;
    }

    inputFile.close();
    tempfile.close();
    stock.close();

    if (remove(file1.c_str()) != 0)
    {
        cout << "Error removing file" << endl;
        return;
    }

    if (rename("tempfile1.txt", file1.c_str()) != 0)
    {
        cout << "Error renaming file" << endl;
        return;
    }

    cout << "Stock updated successfully" << endl;
}

// int check_quantity()
// {
//     ifstream stock;
//     stock.open("stockfile.txt");

// }

