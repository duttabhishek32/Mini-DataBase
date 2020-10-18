//C++ program for a mini-database consisting  of
//People
//Containg the following details of the person
//First name
//Sur name
//Age
//Telephone number
//Following operations can be performed in the database
//Add a person
//Show the members in database
//Save the details in a file~ database.txt
//Show a particular people in the database.txt
//Search for people in the database
//Delete a person from the database
//Modifications are opn.

//Created by Abhishek Dutt  on 26 JUNE 2020,10:56am

#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstdlib>
#include<stdlib.h>
using namespace std;
void requireEnter();
void showdata(void);
void addperson(void);
void savePeopleToFile(void);
void loadPeopleFromFile(void);
void searchDatabase(void);
void removeDatabae(void);

struct person {
	string name;
	string surname;
	short age;
	string telephone;
};


short PeopleinDatabase;
person people[20];


int main() {

	char test;

	loadPeopleFromFile();
	cout << "<<<--------WELOCOME TO MINI-DATABASE------------>>>\n";
	cout << "---------------------------------------------------\n";
	cout << "---------------------------------------------------\n";

	do {
		cout << "Number of People in database: " << PeopleinDatabase << endl;
		cout << "---------------------------------------------------\n";
		cout << "---------------------------------------------------\n";
		cout << "MENU :" << endl;

		cout << "1. Add a person: " << endl;
		cout << "2. Show all people" << endl;
		cout << "3. Save to File " << endl;
		cout << "4. Show people in database" << endl;
		cout << "5. Search for people in database" << endl;
		cout << "6. Remove a entry from database" << endl;
		cout << "7. Press esc three times  to exit\n";
		cout << "---------------------------------------------------\n";
		cout << "---------------------------------------------------\n";
		test = getch();

		switch (test) {

		case '1' :
			addperson();
			break;
		case '2':
			showdata();
			break;
		case '3':
			savePeopleToFile();
			break;
		case '4':
			loadPeopleFromFile();
			break;
		case '5':
			searchDatabase();
			break;
		case '6':
			removeDatabae();
			break;
			//case '7':
			//	 break;
		}
		test = getch();
		requireEnter();
		system("clear");

	} while (test != 27);

	cout << "<<-----------------------Thank you for using the MINI-DATABASE--------------->>\n";
	cout << "Program finished with exit status 1\n";

	return 0;

}

void requireEnter() {
	cout << "Click Enter to continue...." << endl;
	while (getch() == 13) {
		break;
	}
}
//Function to show  data
void showdata(void) {
	if (PeopleinDatabase > 0) {
		for (int i = 0; i < PeopleinDatabase ; i++) {
			cout << "Person index " << (i + 1) << endl;
			cout << "Name: " << people[i].name << endl;
			cout << "Surname: " << people[i].surname << endl;
			cout << "Age: " << people[i].age << endl;
			cout << "Telephone: " << people[i].telephone << endl;
			cout << endl << endl;
		}
	}
	else
		cout << "There is nobody in the data base";
}
//Function to add a person to database
void addperson(void) {
	cout << "Enter the name: ";
	cin >> people[PeopleinDatabase].name;

	cout << "Enter the surname: ";
	cin >> people[PeopleinDatabase].surname;

	cout << "Enter the age: ";
	cin >> people[PeopleinDatabase].age;

	cout << "Enter the telephone Number: ";
	cin >> people[PeopleinDatabase].telephone;

	PeopleinDatabase++;

}
//Function to save people to file
void savePeopleToFile(void) {

	ofstream file("database.txt");

	if (file.is_open()) {

		file << PeopleinDatabase << endl;

		for (int i = 0; i < PeopleinDatabase ; i++) {


			file << (i + 1) << endl;
			file << people[i].name << endl;
			file << people[i].surname << endl;
			file << people[i].age << endl;
			file << people[i].telephone ;

		}

		file.close();
		cout << "File succesfully stored in database" << endl;

	}
	else
		cout << "Not able to save in the file " << endl;
}
//Function to load a person from a file
void loadPeopleFromFile(void) {

	ifstream file("database.txt");

	if (file.is_open()) {

		file >> PeopleinDatabase;

		if (PeopleinDatabase > 0) {

			for (int i = 0; i  < PeopleinDatabase; i++) {

				//file << (i + 1) << endl;
				file >> people[i].name ;
				file >> people[i].surname ;
				file >> people[i].age ;
				file >> people[i].telephone ;
			}
		}
		else

			cout << "Database doens't exist" << endl;

	}

	else
		cout << "The file database.txt doesn't exist" << endl;
}
//Function to search a database
void searchDatabase(void) {

	if (PeopleinDatabase > 0) {

		string name;
		cout << "Type a name of the person you wan to look for : ";
		cin >> name;

		for (int i = 0; i < PeopleinDatabase; i++) {

			if (name == people[i].name) {

				cout << "Person index " << (i + 1) << endl;
				cout << "Name: " << people[i].name << endl;
				cout << "Surname: " << people[i].surname << endl;
				cout << "Age: " << people[i].age << endl;
				cout << "Telephone: " << people[i].telephone << endl;

			}
		}
	}
}
//Function to remeove person from database
void removeDatabae(void) {

	if (PeopleinDatabase > 0) {
		short index;
		cout << "Who do you want to remove: (Type the index)" << endl;
		cin >> index;

		if (PeopleinDatabase >= index) {

			for (short k = index; k < index; k++) {
				people[k - 1].name = people[k].name;
				people[k - 1].surname = people[k].surname;
				people[k - 1].age = people[k].age;
				people[k - 1].telephone = people[k].telephone;
			}

			PeopleinDatabase--;
		}
		else
			cout << "There is nobody like that" << endl;
	}

	else
		cout << "There is nothing to remove" << endl;

}
