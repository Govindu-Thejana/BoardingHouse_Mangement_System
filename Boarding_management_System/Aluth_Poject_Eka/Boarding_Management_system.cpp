#include <iostream>
#include <string>#
#include <cstdlib>
#include <limits>
#include <fstream>
#include "Header.h"
using namespace std;

void userInterface()
{
	BoardingPlaceList UOR_FOE;
	UOR_FOE.insertBoading("nimesh", "200054321", 300, 10, 60000, "male", 0716543217, "sarasiasapiwa");
	UOR_FOE.insertBoading("apsari", "2000321654878", 200, 3, 60000, "female", 0716543217, "Kaleigana");
	UOR_FOE.insertBoading("gopal", "200032216547", 1000, 1, 5000, "male", 0716543217, "hapugala");
	UOR_FOE.insertBoading("namal", "2000654321", 100, 2, 3000, "female", 0716543217, "Wakwalla");
	UOR_FOE.insertBoading("dasanayaaka", "20003220003216547", 500, 1, 40000, "male", 0716543217, "sarasiasapiwa");
	UOR_FOE.insertBoading("sara", "2000321487545", 90, 1, 100, "female", 0716543217, "Kaleigana");

	//UOR_FOE.displayAllBoardingPlaces();

	while (true)
	{
		system("cls");
		int choice;
		cout << "\n\tWho are you?\n\t\t1) I am an authorized admin\n\t\t2) I am a boarding finder\n\t\t3) Exit\n\tSelect your choice (1, 2, 3): ";
		cin >> choice;

		if (!(cin >> choice))
		{
			cout << "Error : Enter a valid input : ";
			cin.clear();
			cin.ignore(123, '\n');
		}


		switch (choice)
		{
		case 1:
		{

			if (false == checkLogin()) {
				break;
			}
			while (true)
			{
				//system("cls");
				cout << "\n\t*********Welcome admin !********\n";
				cout << "1) Add boarding place\n";
				cout << "2) Edit an existing place\n";
				cout << "3) Delete a specific place\n";
				cout << "4) View owner places\n";
				cout << "5) Logout\n";
				cout << "Select your choice (1, 2, 3, 4, 5): ";
				cin >> choice;

				if (choice == 1)
				{
					UOR_FOE.addBoardingplaceInfo();
				}
				else if (choice == 2 || choice == 3 || choice == 4)
				{
					UOR_FOE.editBoardingPlace(choice);
				}
				else if (choice == 5)
				{
					userInterface();
				}
				else
				{
					cout << "Invalid choice. Please enter a valid option." << endl;
					continue;
				}
			}
			break;
		}
		case 2:
		{
			system("cls");

			int choice;
			cout << "\n\tDo you want to\n\t\t1) Search a suitable boarding place \n\t\t2) See all the boarding places\n\t\t3) Exit\n\tSelect your choice (1, 2, 3): ";
			cin >> choice;
			if (choice == 1)// search boarding
			{
				UOR_FOE.searchSuitablePlaces();
			}

			else if (choice == 2)// Display all the boardings
			{

				int choice;
				cout << "\n\tDo you want to see all the boardings by ascending order in:\n\t\t1) distance \n\t\t2) price\n\t\t ";
				cout << "    OR want to see available: \n\t\t 3) Male Boardig Places\n\t\t  4) Female Boardig Places\n\t\t  5) Exit\n\t\tSelect your choice (1,2,3,4,5): ";
				cin >> choice;

				if (choice == 1) // distancesort
				{
					UOR_FOE.distanceSort();
					UOR_FOE.displayAllBoardingPlaces();

				}
				else if (choice == 2) // price sort 
				{
					UOR_FOE.priceSort();
					UOR_FOE.displayAllBoardingPlaces();

				}
				else if (choice == 3) // price sort 
				{

					string gender = "male";
					UOR_FOE.displayGenderBoardingPlaces(gender);

				}
				else if (choice == 4) // price sort 
				{
					string gender = "female";
					UOR_FOE.displayGenderBoardingPlaces(gender);

				}

			}
			else if (choice == 3) {
				userInterface();
			}
		}

		case 3:
		{
			cout << "**********Existing the Programm.......Good Bye**********\n";

			break;

		}
		default:
		{
			cout << "Invalid choice. Please enter a valid option." << endl;
			continue;
		}
		break;



		}
		break;
	}
	
}

int main()
{
	intro();
	userInterface();

	return 0;
}