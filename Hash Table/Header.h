#pragma once
//The include statements to properly run the functions
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <string>

using namespace std;
//Template for the tables Keys and Values
//Class for the hash table's node
template <typename TV, typename TK>
class hashTableNode
{
public://Sets the value and tableKey to public to grab from
	TV tableValue;
	TK tableKey;

public://Sets these to public
	hashTableNode(TV &tableValue, TK &tableKey)
	{
		this->tableValue = tableValue;
		this->tableKey = tableKey;

		int get_TableValue()
		{
			return tableValue();
		}

		char get_TableKey()
		{
			return tableKey
		}

	}
};
//Defines the hash table map as well as encapsulating the other functions within it
template <typename TV, typename TK>
class hashTableMap
{
public://defines the capacity and size
	hashTableNode<TV, TK> *HashArray;

	//defines the integer for the table's capacity and size
	//int tableCapacity;
	//int tableSize;

	//defines the integer and sets the size and capacity of the hash table
	int tableCapacity = 10;
	int tableSize = 0;

public://sets the capacity and size to integer values 10 & 0
	hashTableMap()
	{
		HashArray = new hashTableNode<TV, TK>*[tableCapacity]; //creates the array

		//Initializes the array 
		for (int i = 0; i < tableCapacity; i++)
			HashArray[i] = NULL;
	}
	//creates the integer function hashTableCode
	int hashTableCode(TK tableKey)
	{
		return tableKey % tableCapacity;
	}
	//function to insert an entry into the hash table/phone book
	template <typename TV, typename TK>
	void insertNode(TV tableValue, TK tableKey)
	{
		hashTableNode<TV, TK> *placeHolder = new hashTableNode<TV, TK>(tableValue, tableKey);

		// Apply hash function to find index for the given tableKey 
		int hashTableIndex = hashTableCode(tableKey);

		//find next free space inside the hash tabe using the logicasl operator && (and)
		while (hashTableIndex != NULL && hashTableIndex->tableKey != tableKey && hashTableIndex->tableKey != -1)
		{
			hashTableIndex++;
			hashTableIndex %= tableCapacity;
		}

		//if new node to be inserted increase the current size using logical operator || (or)
		if (hashTableIndex == NULL || hashTableIndex->tableKey == -1)
		{
			tableSize++;
			hashTableIndex = placeHolder;
		}
	}

	//Function to search for an entry/node
	template <typename TV, typename TK>
	TV searchNode(TK tableKey)
	{
		// searches out the index for the specified tablekey/book entry
		int hashTableIndex = hashTableCode(tableKey);
		int counter = 0;
		//using while loop to find the entry/node for the specifies tableKey in the hash table
		//while the index exists
		while (HashArray[hashTableIndex] != NULL)
		{
			int counter = 0;
			if (counter++ > tableCapacity)
			{
				return NULL;
			}
			//if node found return its value 
			if (HashArray[hashTableIndex]->tableKey == tableKey)
			{
				return HashArray[hashTableIndex]->tableValue;
				hashTableIndex++;
				hashTableIndex %= tableCapacity;
			}
			else
				//If not found return null 
				return NULL;
		}
		
	}

	//The function to delete an entry from the hash table
	template <typename TV, typename TK>
	void deleteTableEntry(TK tableKey)
	{
		// the hash index to find the specified tablekey 
		int hashTableIndex = hashTableCode(tableKey);

		//while loop to find the tableKey in the table
		while (HashArray[hashTableIndex] != NULL)
		{
			//if the table contains that node
			if (HashArray[hashTableIndex]->tableKey == tableKey)
			{
				hashTableNode<TV, TK> *placeHolder = HashArray[hashTableIndex];
				HashArray[hashTableIndex] = NULL;

				//removes table values
				tableSize--;
			}
			hashTableIndex++;
			hashTableIndex %= tableCapacity;

		}
		/*else
		//else return null 
		return NULL; */
	}

	//shows the current size of the table 
	int displayMapSize()
	{
		return tableSize;
	}

	//bool for if the table is empty
	bool emptyHashTable()
	{
		return tableSize == 0;
	}

	//Displays the values stored within the table
	int displayTable()
	{
		for (int i = 0; i < tableCapacity; i++)
		{
			if (HashArray[i] != NULL && HashArray[i]->tableKey != -1)
				cout << "TableKey = " << HashArray[i]->tableKey
				<< "  TableValue = " << HashArray[i]->tableValue;
		}
	}
};

//main menu for user interaction
void mainMenu()
{

	cout << "\nHash Table Phone Book Menu \n";
	cout << "1. Insert a Name (tableKey) and Number (Value) into the Hash Table \n";
	cout << "2. Search for a name within the phone book (Hash Table) \n";
	cout << "3. Delete a name/number from the phone book (Hash Table) \n";
	cout << "4. Display the size of the Hash Table Map\n";
	cout << "5. Display the Current Table \n";
	cout << "6. Exit\n";
}