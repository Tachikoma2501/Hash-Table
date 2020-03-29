//Samuel Aaron Cooper
//11/04/18
//Includes the header file into the source file
#include "Header.h"

//template <typename V, typename K>
int Main(int argc, char* argv[])
{
	hashTableMap<int, int> *mainData = new hashTableMap<int, int>;
	//runs the mainMenu function
	mainMenu();
	//the defined integers for the switch case user choices/inputs
	int menuChoice;
	//int addNode;
	char insertKeyChoice;
	int insertValueChoice;
	char retrieveName;
	char deleteName;

	cin >> menuChoice;
	//return menuChoice;
	//switch statement with individual cases
	switch (menuChoice)
	{

	case 1: //User inserts a name and attached value using the switch case statement
		cout << "\nPlease choose the apropriate Name (Key) & Number (Value) to add into the hash table\n";
		cout << "The Keys and Values entered will both (Should) be numbers and not characters\n";
		cout << "Enter Name (Key): \n";
		cin >> insertKeyChoice;//Inserts the Key (Name)
		cout << "\nEnter Number (Value): \n";
		cin >> insertValueChoice; //Inserts the Value (Number)
		//Inserts the two user inputs into the hash table
		mainData->insertNode(insertKeyChoice, insertValueChoice);

		break;

	case 2: //User searches for a name within the Hash Table
		cout << "\nPlease enter the name of the person you wish to retrieve from the phone book (Hash Table)\n";
		cout << "Enter Name: \n";
		cin >> retrieveName;

		cout << mainData->searchNode<int, int>(retrieveName) << "\n";

		break;

	case 3: //User deletes a Name (Key) along with its Value from the Hash Table
		cout << "\nPlease enter a name you wish to delete from the phone book (Hash Table)\n";
		cout << "Enter Name: \n";
		cin >> deleteName;

		mainData->deleteTableEntry<int, int>(deleteName);

		break;

	case 4: //Displays the size of the Hash Table
		cout << "Number of Entries in Phone Book: " << mainData->displayMapSize() << "\n";

		break;

	case 5://Displays the current hash table/phone book
		cout << "Current Entries within the Phone Book: " << mainData->displayTable() << "\n";

		break;

	default:
		cout << "\nAn Invalid choice.\n" << endl;
	}
	while (menuChoice != 9); //while statement for when listChoice is not equal to 0
	return 0;
}

void test_function()
{
	hashTableMap<int, int> *test_Table = new hashTableMap<int, int>;

	test_Table->insertNode(8, 9);


	int value = test_Table->searchNode<int, int>(8);

	if (value == 9)
	{
		cout << "Test if Successful!";
	}
	else
	{
		cout << "Test Failure!";
	}

}