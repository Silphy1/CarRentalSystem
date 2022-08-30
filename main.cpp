//Header Files
#include <iostream>
#include <stdio.h>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <dos.h>
#include <iomanip> 
#include <conio.h>
#include <Windows.h>
#include <cmath>

//Namespace
using namespace std;

//global functions
void frontpage();
void rentcar();
void termacc();
void registeruser();
void registercar();
void login();
void exitapp();
void reservecar();
int main();

class User
{
public:
	string username;
};

//classes
class car
{
private:
public:
	string name;
};

int main()
{
	int resp;

	//Login/Ragister Page
	cout << "*********Car Register System Application********" << endl;
	cout << "                1 : Register" << endl;
	cout << "                2 : Login" << endl;

	//Getting User reponce
	cout << "Enter your responce here : ";
		cin >> resp;
	//linking functions to reponce
		if (resp == 1)
		{
			Sleep(1000);
			registeruser();
		}
		else if (resp == 2)
		{
			Sleep(400);
			login();
		}
		else
			cout << "No valid input detected!" << endl;

	return 0;
}

void registeruser()
{
	//declaring variables
	string usernme, password;
	int userresp;
	User obj1;

	//getting un & ps
	cout << "Enter your prefered username: ";
	cin >> usernme;

	cout << "Enter your prefered password: ";
	cin >> password;

	fstream file;
	file.open(usernme + ".DAT", ios_base::app);

	file << usernme << endl;
	file << password << endl;

	file.close();
	cout << "Saving Login Information...." << endl;
	Sleep(400);
	obj1.username = usernme;
	//linking to functions
	cout << "Would you like to login now?\n Type 1 for Yes & 2 for No " << endl;
	cin >> userresp;

	if (userresp == 1)
	{
		login();
	}
	else if (userresp == 2)
	{
		exitapp();
	}

}

void login()
{
	//delaring
	string username, password,un,ps;

	//taking input
	cout << "Enter you username: ";
	cin >> username;

	cout << "Enter your password: ";
	cin >> password;

	ifstream read;
	read.open(username + ".DAT");
	getline(read, un);
	getline(read, ps);

	//checking against input/ linking functions and exits
	if (username == un)
	{
		if (password == ps)
		{
			cout << "Your In!" << endl;
			cout << "Lets Go....." << endl;
			Sleep(1000);
			frontpage();
		}
		else
			cout << "Wrong Password Try Aagin." << endl;
		login();
	}
	else
		cout << "wrong username. Try Again" << endl;
		login();
}

void exitapp()
{
	//exiting application
	exit(1);
}

void frontpage()
{
	//delaring variables
	int resp;

	//main page
	cout << "          Welcome to Drivex!         " << endl;
	cout << "            1 : Rent Car             " << endl;
	cout << "            2 : OutRent Car          " << endl;
	cout << "            3 : Reserve Car          " << endl;
	cout << "            4 : Exit App             " << endl;

	//taking user input
	cout << "Enter yout Input here: ";
	cin >> resp;

	//linking to functions
	if (resp == 1)
	{
		Sleep(900);
		rentcar();
	}
	else if (resp == 2)
	{
		Sleep(900);
		registercar();
	}
	else if (resp == 3)
	{
		Sleep(900);
		reservecar();
	}
	else if (resp == 4)
	{
		Sleep(900);
		exitapp();
	}
	else
		cout << "No allowed responce identified try again\n";
	Sleep(2000);
	frontpage();
}

void rentcar()
{
	//declaring the variables
	string brandname;
	string speed, transmission, year;
	string perdaycost; // turn into an interger from car file
	int numresp;
	int rentcost;
	int days;
	User obj2;

	//asking for user input
	cout << "              What Are you looking for?" << endl;
	cout << "\n" << "\n" << "Enter the Brand name here (no spaces): " << endl;
	//taking in the brand name of the car
	cin >> brandname;

	//open the file to the specified car name
	ifstream file;
	file.open(brandname + ".txt");

	getline(file, brandname);
	getline(file, year);
	getline(file, speed);
	getline(file, transmission);
	getline(file, perdaycost);

	//number of days wanting to use the car
	cout << "How many day do you want to use the car? : ";
	cin >> days;

	//rent car data
	//converting the string value to an interger to be multiplied
	string str = perdaycost;
	int perdaycostmod = stoi(str);
	rentcost = days * perdaycostmod;

	// Output the cost and the details of the car here
	cout << "      Here are the details of the transaction and of the vehicle.....\n";
	cout << "Name : " << obj2.username << endl;
	cout << "Brand Name : " << brandname  << year << endl;
	cout << "Speed Information : " << speed << endl;
	cout << "Transmission type : " << transmission << endl;
	cout << "Your total should be : $" << rentcost << " for " << days << "days.\n";
	cout << "\n" << "Would you like to go through with this purchase?\n Enter 1 for Yes & 2 for No : ";
	cin >> numresp;

	//Linking functions and ending the program;
	if (numresp == 1)
	{
		cout << "Have a great day bye :)" << endl;
		cout << "Were taking you back to the fron menu.....\n";
		Sleep(1500);
		frontpage();
	}
	else if (numresp == 2)
	{
		cout << "OK! Were going to take you back to the front page :)" << endl;
		frontpage();
	}
	else
		cout << "No valid responce accepted please try again" << endl;
	rentcar();

}

void registercar()
{
	//declaring variables
	string brandname;
	string speed, transmission, year, zerosixty;
	string perdaycost;
	int numresp;
	//use classes here to register the car
	
	//taking in the users vehicle information
	cout << "Enter the name of the car/truck with no spaces and all lowercasre : ";
	cin >> brandname;
	cout << "Enter the year of the car or truck : ";
	cin >> year;
	cout << "Enter the top speed : ";
	cin >> speed;
	cout << "Enter the 0-60 time : ";
	cin >> zerosixty;
	cout << "Enter the transmission type : ";
	cin >> transmission;
	cout << "Enter your per day cost of your truck or car : ";
	cin >> perdaycost;

	//turning the data into a file
	fstream file;
	file.open(brandname + ".txt", ios_base::app);
	//inpting the data into the txt file
	file << brandname << endl;
	file << year << endl;
	file << "Top Speed - " << speed << "mph 0-60 - " << zerosixty << " sec" << endl;
	file << transmission << endl;
	file << perdaycost << endl;

	file.close();
	//outputting the vehicle information
	cout << "Submitting information...." << endl;
	Sleep(1500);
	
	cout << "Brand Name : " << brandname << endl;
	cout << "Year : " << year << endl;
	cout << "Speed Information : " << speed << "\n0-60 : " << zerosixty << endl;
	cout << "Transmission type : " << transmission << endl;
	cout << "The perday cost : " << perdaycost << endl;
	cout << "\n" << "Would you like to rent the car now?\n Type 1 for Yes and 2 for No : ";
	cin >> numresp;

	if (numresp == 1)
	{
		cout << "Sending you now...." << endl;
		Sleep(1000);
		rentcar();
	}
	else if (numresp == 2)
	{
		cout << "Sending you now...." << endl;
		Sleep(1000);
		frontpage();
	}
	else
		cout << "No valid responce, sending you to the home page....";
	Sleep(800);
	main();
}

void reservecar()
{
	//declaring the variables
	string brandname;
	string speed, transmission, year;
	string perdaycost; // turn into an interger from car file
	int numresp;
	int rentcost;
	int days;
	User obj2;

	//asking for user input
	cout << "              What Are you looking to reserve?" << endl;
	cout << "\n" << "\n" << "Enter the Brand name here (no spaces): " << endl;
	//taking in the brand name of the car
	cin >> brandname;

	//open the file to the specified car name
	ifstream file;
	file.open(brandname + ".txt");

	getline(file, brandname);
	getline(file, year);
	getline(file, speed);
	getline(file, transmission);
	getline(file, perdaycost);

	//number of days wanting to use the car
	cout << "How many day do you want to use the car? : ";
	cin >> days;

	//rent car data
	//converting the string value to an interger to be multiplied
	string str = perdaycost;
	int perdaycostmod = stoi(str);
	rentcost = days * perdaycostmod;
	int reservefee = rentcost + 50;
	// Output the cost and the details of the car here
	cout << "      Here are the details of the transaction and of the vehicle.....\n";
	cout << "Name : " << obj2.username << endl;
	cout << "Brand Name : " << brandname << year << endl;
	cout << "Speed Information : " << speed << endl;
	cout << "Transmission type : " << transmission << endl;
	cout << "Your total should be : $" << rentcost << " for " << days << "days, and an additional $50 for the reserve fee.\n Toal will be : $" << reservefee << "\n";
	cout << "\n" << "Would you like to go through with this purchase?\n Enter 1 for Yes & 2 for No : ";
	cin >> numresp;
	
	//taking the user input and linking functions
	if (numresp == 1)
	{
		cout << "Your transaction is completed enjoy your day :)\n";
		cout << "Sending you to the main menu....";
		Sleep(1000);
		frontpage();
	}
	else if (numresp == 2)
	{
		cout << "Were going to restart your purchase and try again\n Sending you now......";
		Sleep(800);
		reservecar();
	}
	else
		cout << "Your reponce is not valid sending you to the main menu.\n";
		frontpage();
}