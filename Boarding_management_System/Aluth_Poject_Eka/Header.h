#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

using namespace std;

// Define a class to represent a boarding place
class BoardingPlace
{
public:
	string name;
	string idNumber;
	int distanceFromFaculty;
	double price;
	int capacity;
	int phnNumber;
	string address;
	string details;
	string gender;
	BoardingPlace* next;

	BoardingPlace()
	{
		name = "NONE";
		idNumber = "None";
		distanceFromFaculty = -1;
		capacity = -1;
		price = -1.0;
		gender = "None";
		phnNumber = -1;
		address = "None";
		next = NULL;
	}
	BoardingPlace(string n, string id, int dist, int cap, int prc, string g, int num, string adr) { //overloaded constructor
		name = n;
		idNumber = id;
		distanceFromFaculty = dist;
		capacity = cap;
		price = prc;
		gender = g;
		phnNumber = num;
		address = adr;
		next = NULL;
	}

};

class BoardingPlaceList
{
private:
	BoardingPlace* head;
	BoardingPlace* tail;
	int size;


public:
	BoardingPlaceList()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}




	// Function to insert a new BoardingPlace into a sorted linked list
	void insertBoading(string n, string id, int dist, int cap, int prc, string g, int num, string adr)
	{
		BoardingPlace* newplace = new BoardingPlace(n, id, dist, cap, prc, g, num, adr);
		if (head == NULL)
		{
			head = newplace;
			tail = newplace;
		}
		else
		{ // non empty list
			newplace->next = head;
			head = newplace;
		}
		size++;

	}

	void displayAllBoardingPlaces()
	{
		BoardingPlace* current = head;
		while (current != nullptr)
		{
			cout << "Name: " << current->name << ", Distance: " << current->distanceFromFaculty << ", Gender: " << current->gender << ", Price: " << current->price << ", Capacity: " << current->capacity << endl;
			current = current->next;
		}
	}

	void displayGenderBoardingPlaces(string gender)
	{
		BoardingPlace* current = head;
		while (current != nullptr)
		{
			if (gender == "male" && current->gender == "male")
			{

				cout << "Name: " << current->name << ", Distance: " << current->distanceFromFaculty << ", Gender: " << current->gender << ", Price: " << current->price << ", Capacity: " << current->capacity << endl;

			}
			else if (gender == "female" && current->gender == "female")
			{

				cout << "Name: " << current->name << ", Distance: " << current->distanceFromFaculty << ", Gender: " << current->gender << ", Price: " << current->price << ", Capacity: " << current->capacity << endl;

			}

			current = current->next;
		}


	}

	void addBoardingplaceInfo()
	{

		int Gender, intCapacity, intphnNumber, intDistanceFromFaculty;
		double doubleprice;

		string gender, stringprice, stringPhnNumber, stringCapacity, details, address, name, idNumber, stringDistanceFromFaculty, stringPrice;

		cout << "Enter your Boarding place details       : " << endl;
		cout << "\tEnter Boarding Owner Name             : ";
		cin >> name;
		cout << "\tEnter Boarding Owner id Number        : ";
		cin >> idNumber;
		cout << "\tEnter distance from the university (m): ";
		cin >> stringDistanceFromFaculty;
		intDistanceFromFaculty = stoi(stringDistanceFromFaculty);
		cout << "\n\tThis place for?:\n\t\t1) male students\n\t\t2) female students\n\tSelect your choice (1,2): ";
		cin >> Gender;
		switch (Gender)
		{
		case 1:
			gender = "male";
			break;
		case 2:
			gender = "female";
			break;
		default:
			cout << "Invalid choice. Please enter a valid option." << endl;
			gender = "Not Given";
		}

		cout << "\tEnter capacity                   : ";
		cin >> stringCapacity;
		intCapacity = stoi(stringCapacity);
		cout << "\tEnter monthly rental fee (Rs)    : ";
		cin >> stringprice;
		doubleprice = stoi(stringprice);
		cout << "\tEnter phone number               : ";
		cin >> stringPhnNumber;
		intphnNumber = stoi(stringPhnNumber);
		cout << "\tEnter address: ";
		cin >> address;
		cout << "\tYou can type more specific details: ";
		cin >> details;

		// BoardingPlace *newplace = new BoardingPlace(string name, double distanceFromFaculty, double price, int capacity, int phnNumber, string gender, string address, string details, string username, string password);
		BoardingPlace* newPlace = new BoardingPlace();
		newPlace->name = name;
		newPlace->idNumber = idNumber;
		newPlace->distanceFromFaculty = intDistanceFromFaculty;
		newPlace->price = doubleprice;
		newPlace->capacity = intCapacity;
		newPlace->phnNumber = intphnNumber;
		newPlace->gender = gender;
		newPlace->address = address;
		newPlace->details = details;
		newPlace->next = nullptr;
		cout << " \nyour data has been recorded...........\n";
		printPlace(newPlace);
		cout << "Thank you......\n" << endl;


		if (head == nullptr)
		{
			newPlace->next = head;
			head = newPlace;
		}
		else
		{
			BoardingPlace* current = head;
			while (current != nullptr && current->distanceFromFaculty < newPlace->distanceFromFaculty)
			{
				current = current->next;
			}
			newPlace->next = current->next;
			current->next = newPlace;
		}
		size++;

	}

	BoardingPlace* findOwnerPlace()
	{
		string name, id;
		cout << "\tEnter the name of boarding owner                      : ";
		cin >> name;
		cout << "\tEnter the idNumber of the Boarding place to be deleted: ";
		cin >> id;
		BoardingPlace* current = head;
		BoardingPlace* prev = nullptr;

		while (current != nullptr && current->idNumber != id)
		{
			prev = current;
			current = current->next;
		}
		return current, prev;
	}

	void printPlace(BoardingPlace* current) {

		cout << "\t Owner Name         : " << current->name << endl;
		cout << "\t Owner idNumber     : " << current->idNumber << endl;
		cout << "\t Distance           : " << current->distanceFromFaculty << endl;
		cout << "\t Capacity           : " << current->capacity << endl;
		cout << "\t Monthly rental fee : " << current->price << endl;
		cout << "\t Owner phone number : " << current->phnNumber << endl;
		cout << "\t Gender             : " << current->gender << endl;
		cout << "\t Address            : " << current->address << endl;
		cout << "\t Extra details      : " << current->details << endl;
	}

	void editBoardingPlace(int choice)
	{
		string name, id;
		cout << "\tEnter the name of boarding owner                     : ";
		cin >> name;
		cout << "\tEnter the idNumber of the Boarding place to be edited: ";
		cin >> id;
		BoardingPlace* current = head;
		BoardingPlace* prev = nullptr;

		while (current != NULL && current->idNumber != id)
		{
			prev = current;
			current = current->next;
		}

		// Check if the idNumber was found
		if (current == nullptr)
		{
			cout << "**********Boarding place not found...Existing Programm***********" << endl;
		}
		else
		{

			if (choice == 2)
			{
				cout << "\t\n********Your Boarding details:************ \n";
				printPlace(current);
				cout << "\tEnter new details for your Boarding: " << endl;
				cout << "\tEnter new distance from the uni (m): ";
				cin >> current->distanceFromFaculty;
				cout << "\tEnter new capacity                 : ";
				cin >> current->capacity;
				cout << "\tEnter new monthly rental fee (Rs)  : ";
				cin >> current->price;
				cout << "\tEnter new phone number             : ";
				cin >> current->phnNumber;
				cout << "\tEnter new address                  : ";
				cin >> current->address;
				cout << "\tEnter new details                  : ";
				cin >> current->details;
				cout << "\t*************Your New deatails Edited successfully***********\n";
				printPlace(current);
			}
			else if (choice == 3)
			{
				// Perform the deletion
				if (prev != nullptr)
				{
					prev->next = current->next;

				}
				else
				{

					head = current->next;
				}
				// Free the memory of the deleted node
				delete current;
				cout << "\n****Boarding place deleted successfully.***\n" << endl;
			}
			else if (choice == 4)
			{
				cout << " The Boarding Details: " << endl;
				cout << "\t Owner idNumber: " << current->idNumber << endl;
				printPlace(current);

			}
		}
	}



	void distanceSort()
	{
		head = mergeSort(head);
	}

	// Helper functions for sorting
	BoardingPlace* findMiddle(BoardingPlace* head)
	{
		if (!head || !head->next)
		{
			return head;
		}

		BoardingPlace* slow = head;
		BoardingPlace* fast = head->next;

		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		return slow;
	}

	BoardingPlace* merge(BoardingPlace* list1, BoardingPlace* list2)
	{
		BoardingPlace* dummy = new BoardingPlace();
		BoardingPlace* current = dummy;

		while (list1 && list2)
		{
			if (list1->distanceFromFaculty < list2->distanceFromFaculty)
			{
				current->next = list1;
				list1 = list1->next;
			}
			else
			{
				current->next = list2;
				list2 = list2->next;
			}

			current = current->next;
		}

		if (list1)
		{
			current->next = list1;
		}
		else
		{
			current->next = list2;
		}

		return dummy->next;
	}

	BoardingPlace* mergeSort(BoardingPlace* head)
	{
		if (!head || !head->next)
		{
			return head;
		}

		// Find the middle of the linked list
		BoardingPlace* middle = findMiddle(head);
		BoardingPlace* secondHalf = middle->next;
		middle->next = nullptr;

		// Recursively sort each half
		BoardingPlace* sortedFirstHalf = mergeSort(head);
		BoardingPlace* sortedSecondHalf = mergeSort(secondHalf);

		// Merge the sorted halves
		return merge(sortedFirstHalf, sortedSecondHalf);

	}

	void priceSort()
	{
		head = mergeSortPrice(head);
	}

	BoardingPlace* mergeSortPrice(BoardingPlace* head)
	{
		if (!head || !head->next)
		{
			return head;
		}

		// Find the middle of the linked list
		BoardingPlace* middle = findMiddle(head);
		BoardingPlace* secondHalf = middle->next;
		middle->next = nullptr;

		// Recursively sort each half
		BoardingPlace* sortedFirstHalf = mergeSortPrice(head);
		BoardingPlace* sortedSecondHalf = mergeSortPrice(secondHalf);

		// Merge the sorted halves
		return mergePrice(sortedFirstHalf, sortedSecondHalf);
	}

	BoardingPlace* mergePrice(BoardingPlace* list1, BoardingPlace* list2)
	{
		BoardingPlace* dummy = new BoardingPlace();
		BoardingPlace* current = dummy;

		while (list1 && list2)
		{
			if (list1->price < list2->price)
			{
				current->next = list1;
				list1 = list1->next;
			}
			else
			{
				current->next = list2;
				list2 = list2->next;
			}

			current = current->next;
		}

		if (list1)
		{
			current->next = list1;
		}
		else
		{
			current->next = list2;
		}

		return dummy->next;

	}

	// Function to search for a suitable boarding place
	void searchSuitablePlaces()
	{

		double maxDistance = 0;
		double maxPrice = 0;
		int minCapacity = 0;
		string gender = "";

		cout << "Enter your specifications:" << endl;
		cout << "Enter maximum distance: ";
		cin >> maxDistance;
		cout << "Enter maximum price per month for the place: ";
		cin >> maxPrice;
		cout << "Nubmber of members: ";
		cin >> minCapacity;
		cout << "\n\tDo you search for:\n\t\t1) male students\n\t\t2) female students\n\tSelect your choice (1,2): ";
		int Gender;
		cin >> Gender;
		switch (Gender)
		{
		case 1:
			gender = "male";
			break;
		case 2:
			gender = "female";
			break;
		default:
			cout << "*************Invalid choice. Please enter a valid option.***********" << endl;
		}
		cout << "*************WAIITING FOR SUITABLE PLACES.............**************" << endl;

		BoardingPlace* current = new BoardingPlace(); // initialize current
		BoardingPlace* suitablePlace = nullptr;       // initialize suitablePlace

		while (current != nullptr)
		{
			if (current->distanceFromFaculty <= maxDistance && current->price <= maxPrice && current->capacity >= minCapacity && current->gender == gender)
			{
				/*cout << "Name: " << current->name << ", Distance: " << current->distanceFromFaculty << ", Price: " << current->price << ", Capacity: " << current->capacity << endl;
				suitablePlace = current;*/
				cout << "Name: " << current->name << ", Distance: " << current->distanceFromFaculty << ", Price: " << current->price << ", Capacity: " << current->capacity << endl;
				suitablePlace = current;
			}
			current = current->next;
		}

		if (suitablePlace == nullptr)
		{
			cout << "**************No suitable place found*************" << endl;

		}
	}

};

bool checkLogin()
{
	string enteredUsername, enteredPassword;

	cout << "\tEnter your username: ";
	cin >> enteredUsername;
	cout << "\tEnter your password: ";
	cin >> enteredPassword;
	if (enteredUsername == "admin" && enteredPassword == "admin") {
		cout << "\n....Login Successfull....!!!\n";
		return true;
	}
	else {
		cout << "***********WARNING <<< Invalid username or password >>> Try again...!!!********\n";
		return false;
	}

}

void intro()
{

	std::cout << "\n\n  BBBBB    OOO  AAAAA RRRR  DDDD   II  N   N  GGG        SSSs Y   Y SSSSS TTTTTT  EEEEE M   M " << std::endl;
	std::cout << "  B   B   O   O A   A R   R D   D  II  NN  N G           S     Y Y  S       TT    E     MM MM " << std::endl;
	std::cout << "  BBBBB   O   O AAAAA RRRR  D   D  II  N N N G   G       sSSS   Y    SSSS   TT    EEEEE M M M " << std::endl;
	std::cout << "  B   B   O   O A   A R  R  D   D  II  N  NN G   G           S  Y        S  TT    E     M   M " << std::endl;
	std::cout << "  BBBBB    OOO  A   A R   R DDDD   II  N   N  GGG        SSSs   Y   SSSSS   TT    EEEEE M   M " << std::endl;

	cout << "\n\nThis console-based boarding management system bridges the gap between boarding owners and boarding finders.\n";
	cout << "Boarding finders can easily search for the best boardings based on their requirements, while admins can add and update owner's boarding details. This user-friendly application streamlines the boarding search and booking process for a convenient and efficient experience.\n";
	cout << "\n\tCreated by\t:  Name\t B.P.G.L.  THEJANA   EG/2021/4828\n\t\t\t:  Name\t K.M.K.N.C FERNANDO  EG/2021/4508\n\t\t\t:  Name\t M.D.Y.B   KULARATHNE EG/2021/4620\n";
	cout << "\n\tPress enter to begin......";
	cin.ignore();
}

void printBoardingManagementSystem() {
	std::cout << "  BBBBB    OOO  AAAAA RRRR  DDDD   II  N   N  GGG        SSSs Y   Y SSSSS TTTTTT  EEEEE M   M " << std::endl;
	std::cout << "  B   B   O   O A   A R   R D   D  II  NN  N G           S     Y Y  S       TT    E     MM MM " << std::endl;
	std::cout << "  BBBBB   O   O AAAAA RRRR  D   D  II  N N N G   G       sSSS   Y    SSSS   TT    EEEEE M M M " << std::endl;
	std::cout << "  B   B   O   O A   A R  R  D   D  II  N  NN G   G           S  Y        S  TT    E     M   M " << std::endl;
	std::cout << "  BBBBB    OOO  A   A R   R DDDD   II  N   N  GGG        SSSs   Y   SSSSS   TT    EEEEE M   M " << std::endl;
}