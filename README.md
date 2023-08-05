# Medical_store_management_system
The Medical Store Management was a project which was coded in c++ language using its major concepts and file handling methods.
    
                                                Variable names and their description

•	Medicine Name: The medicine name is given uniquely to different medicines.
	 med_name, medicine, medicine_name, Medicine are the variables used to represent Medicine name in the program.

•	Quantity: Quantity represents the number of units of the product.
	qty, quantity are the variables used in the program that represents Quantity of the products.

•	Expiry Date: It is the period till when the product can be consumed safely.
	day, month, and year combinedly represent the date.
 
•	Batch Number: A unique id given to the set of medicines that are manufactured at the same time as a single unit
	They exhibit the same properties like the same expiry date and price of the product.
	med_id, batch_no, and Batch are the variables that are used in the program to represent Batch Number.

•	Stock: The stock file has all the stored information of the medicines sold in the pharmacy.

•	Sale: The sale file has the record of all the medicines that are sold.

•	Jfile: j is an iterator to track how many bills were generated this helps to give unique bill numbers for each transaction happened and this is stored in a file named jfile.txt.

Functions and their descriptions:
•	add(): This function enables the user to give details of the medicine that he wants to store in the file.

•	display(parameter): This function takes in the medicine name as a parameter to display the details of the medicine in our stock
	If nothing is given as the argument then that displays the entire stock available in the pharmacy.

•	bill(parameter): Bill function is used to make a bill for the customers to record the medicines they are purchasing. This also calls other functions to perform the task and also updates the quantities of all the functions in the stock file.
	The parameter passed is used to track the number of times the function is called and gives a proper prompt depending on the parameter.

•	To_Return(): To_Return function is called when the customer asks for a return. This function checks if the customer is eligible for the return and updates the stock file if the product is returnable and if the product is not eligible for return it prints the same message on the screen.

•	income(parameter): This function takes in date as the parameter and gives the sum of all the transactions happened on that day and outputs the income of that day.



Algorithm: 

So, this is how basically our code is going to work: 

We made a menu function, which displays the following details when called:

                           Enter 1 to Add a medicine 

    			Enter 2 to Display the stock of a medicine 

    			Enter 3 to Bill a medicine 

    			Enter 4 to Return a medicine 

    			Enter 5 to view the income 

    			Enter 6 to EXIT 

 

-When the user chooses 1 

		We created a file named stockfile.txt which will be opened and asks the shopkeeper to enter the batch number, medicine name, quantity, expiry, price of the medicine, and if the medicine can be sold without a doctor’s prescription. Now we will be passing medicine and batch number as our arguments to the function findword2(parameter 1, parameter 2). This function reads the stock file and returns the line number of the medicine name if the input medicine name and batch number match with the data already available in the stock. If it returns a non-zero value which is the line number of the medicine name, we use it and directly increase the quantity of the product instead of adding it as a new product to avoid duplicates. This task is achieved using the update function. It takes in the file name, line number, and quantity as parameters and does the job.
		
		The update function does its work by creating a new temporary file and duplicating the entire data available in the stock file and when it reaches the quantity line it rewrites the quantity with the new value. After updating the value rest of the data is duplicated into this temporary file. Now the original file is destroyed and the duplicate file will be renamed as stockfile.txt.
 		If the findword2 function returns 0. Then the medicine will be added as a new entity into the stock file using the SavetoStock function.

-When the user chooses 2 

		Display function gets called which will be taking the medicine name as input and this function we will be calling a function named return_line_number which takes the medicine name as a parameter and returns a pointer pointing to an array that contains the line numbers of all the occurrences of given medicine name.

This returned line number array is assigned to a pointer variable named pointer_to_line_numbers, now if the entered medicine name is incorrect or not present in the existing stock file then the return_line_number function returns an array of -1. Now program asks the user to reinput the medicine name correctly or add this new product into the stock file.

If the entered product exists in the file, then details of the product are printed using the line numbers in the array pointer_to_line_numbers.


		If the user doesn’t enter any name just hits enter, then the program outputs the entire available stock.

- When the user chooses 3

		we created a variable int j and the file with the name jfile which stores the value of j and generates a bill number every time we run the billing program, the date function will be called which is of no arguments, which prints the current system date, and into the bill function, we will be sending the value of j with reference. Inside the bill function we will be opening the stock file and the sale file, and we used int i, when the value of it is 0 it means for billing it’s asking the user to enter the name of the medicine that is to be billed first and it shows you the available batches for a particular medicine then based upon stock, availability, and shopkeeper’s interest he will be selecting the batch that needed to be sold. Next, the customer will be giving his input that the no: of tablets that he needs of that type, then it will be displaying a msg such that the customer wants any extra tablets or that’s it, if he completes his requirements the shopkeeper presses 0 to terminate the bill. After all, based on the quantity of the medicines purchased the sale and stock file will be updated

- When the user chooses 4

	This input is used when the customer comes and returns the medicine, so for this first, the input of the bill number is taken, and all the medicines billed on that number will be displayed such that the customer can select which medicine he can return and then he will be entering the quantity that he is going to return now this quantity is compared with two things one with – the billed date that the billed date and returned date has a gap of less than or equal to 7 days and second – is he returning within the expiry and also is he returning less than or equal to the quantity he purchased if all the conditions satisfy the stock and sale file will be updated.

- When the user chooses 5
		
		This displays the total income earned on the particular date. Date will be taken as input and passed as parameter to the function income(parameter 1) function.
The income function iterates through the sale file and adds up all the transactions that happened on the particular date

-When the user chooses 6
		The program terminates with the prompt “Bye Bye!!”.
