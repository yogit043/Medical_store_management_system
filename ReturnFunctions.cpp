#include<iostream>
#include<string.h>
#include<string>
#include<fstream>
#include<ctime>
// #include "check.cpp"
using namespace std;

void update_stock_after_return(const std::string& file1, int line_number, const std::string& qty)
{
    ifstream stock;
    stock.open("stockfile.txt");
    int typecasted_qty = 0;
    int current_line=0;
    try
    {
        typecasted_qty = std::stoi(qty);
        // throw (55);
    }
    catch(std::invalid_argument e1)
    {
        std::cout << "Check your quantity provided" << std::endl;
        return;
    }
    
    int stored_quantity, currentLine;
    std::ifstream inputFile(file1);
    if (!inputFile.is_open())
    {
        std::cout << "Error opening Stock File" << std::endl;
        return;
    }
    std::ofstream tempfile("tempfile1.txt");

    if (!tempfile.is_open())
    {
        std::cout << "Error opening Temporary File" << std::endl;
        inputFile.close();
        return;
    }

    int final_quantity;
    std::string line;
    currentLine = 1;

    while (std::getline(inputFile, line))
    {
        if (currentLine == line_number+1)
        {
                // cout<<"stored quantity in the line in udate stock fn"<<line<<endl;
                stored_quantity = std::stoi(line);
        
            
            final_quantity = stored_quantity + typecasted_qty;
            tempfile << final_quantity << std::endl;
        }
        else
        {
            tempfile << line << std::endl;
        }
        currentLine++;
    }

    inputFile.close();
    tempfile.close();
    stock.close();

    if (std::remove(file1.c_str()) != 0)
    {
        std::cout << "Error removing file" << std::endl;
        return;
    }

    if (std::rename("tempfile1.txt", file1.c_str()) != 0)
    {
        std::cout << "Error renaming file" << std::endl;
        return;
    }

    std::cout << "Stock updated successfully" << std::endl;
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

void checker(int day1Num,int month1Num,int year1Num,int day2Num,int month2Num,int year2Num,int expiryDayNum,int expiryMonthNum,int expiryYearNum,string batch_no,string med_name,string qty)
{
    int gap = 0;
    bool canReturn = false;

    // Calculate the difference between dates
    if (year1Num == year2Num && month1Num == month2Num) {
        gap = day2Num - day1Num;
    } else {
        int daysInMonth = getDaysInMonth(month1Num, year1Num);
        gap = daysInMonth - day1Num + day2Num;

        for (int month = month1Num + 1; month < month2Num; month++) {
            daysInMonth = getDaysInMonth(month, year1Num);
            gap += daysInMonth;
        }
    }

    // Compare with expiry date
    if (year2Num < expiryYearNum) {
        canReturn = true;
    } else if (year2Num == expiryYearNum) {
        if (month2Num < expiryMonthNum) {
            canReturn = true;
        } else if (month2Num == expiryMonthNum) {
            if (day2Num <= expiryDayNum) {
                canReturn = true;
            }
        }
    }

    // Check if return is possible
    if (gap <= 7 && canReturn)
    {
        int line_number2 = findWord2(batch_no,med_name);
        update_stock_after_return("stockfile.txt",line_number2,qty);
    } 
    else
    {
        cout << "YOU POSSIBILY DO NOT MEET THE CONDITIONS REQUIRED TO RETURN !!";
    }

}

void To_Return()
{
    //TODO:1) make sure input formats are correct
    //TODO: look about expiry date
    // fstream stock;
    int line_number;
    int line_number_stock,line_number_sale;
    int day_stock,month_stock,year_stock;
    int day_sale=123,month_sale=456,year_sale=789;
    int day_return,month_return,year_return;
    string batch_no,med_name,qty,line;
    int typecasted_bill_no,typecasted_qty,i_for_take_qty=0,i_for_bill_no=0,currentLine;
    string bill_no;
    int* pointer_to_line_numbers;
    ifstream sale;
    sale.open("salefile.txt");
    ifstream stock;
    stock.open("stockfile.txt");
    take_bill_no(typecasted_bill_no,bill_no,i_for_bill_no);
    pointer_to_line_numbers=return_line_numbers_from_sale(typecasted_bill_no);
    
    cout<<"Medicines that can be returned:"<<endl;
    currentLine=0;
    for(int iterator=0;iterator<20;iterator++)
    {
        // cout<<"array of line nums are "<<pointer_to_line_numbers[iterator]<<endl;
        // currentLine=0;
        while(sale.good())
        {
            getline(sale,line);
            currentLine++;
            // cout<<"iterator "<<iterator<<"value of line number "<<pointer_to_line_numbers[iterator]<<" current line no "<<currentLine<<" line is "<<line<<endl;
            if(pointer_to_line_numbers[iterator]+5==currentLine)
            {
                    cout<<line<<endl;
                    break;
            }
        }
    }
    sale.close();
    cout<<"Enter Name of the Medicine you wanted to return."<<endl;
    getline(cin,med_name);
    // second getline changed
    getline(cin>>ws,med_name);

    cout<<"Enter Batch Number of medicine you wanted to return."<<endl;
    cin>>batch_no;

    take_qty(typecasted_qty,qty,i_for_take_qty );
    line_number_stock = findWord2(batch_no,med_name);
    // int line_number1 = line_number+4;
    int count = 0;
    while(stock.good())
    {
        string line_stock;
        getline(stock,line_stock);
        count ++;
        if(line_number_stock+2 == count)
        {
            day_stock=stoi(line_stock);
            getline(stock,line_stock);
            month_stock=stoi(line_stock);
            getline(stock,line_stock);
            year_stock=stoi(line_stock);
            break;
        }
    }

    ifstream sale2;
    sale2.open("salefile.txt");

    line_number_sale = findWord2_from_sale(batch_no,med_name);
    int count1 = 0;
    string line_sale;
    while(sale2.good())
    {
        getline(sale2,line_sale);
        count1 ++;
        if(line_number_sale-4== count1)
        {
            day_sale=stoi(line_sale);
            getline(sale2,line_sale);
            month_sale=stoi(line_sale);
            getline(sale2,line_sale);
            year_sale=stoi(line_sale);
            break;
        }
    }

    sale_date(&day_return,&month_return,&year_return);
    stock.close();
    checker(day_sale,month_sale,year_sale,day_return,month_return,year_return,day_stock,month_stock,year_stock,batch_no,med_name,qty);

    

}