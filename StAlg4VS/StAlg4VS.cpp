//#define _CRT_SECURE_NO_WARNINGS
//used libraries
#include "stdafx.h"
#include <fstream>//file stream
#include <iostream>//input, output stream
#include <conio.h>//getch
#include <iomanip>//string comparison
#include <windows.h>//localization
#include <string>
#include <sstream>

//functions prototypes
void outputMainMenu();//menu and info
void aboutProgramme();//about programme

class DATA {

private:
	int key;
	int value;
public:
	DATA(int key, int value) {
		this->key = key;
		this->value = value;
	}

	int getKey() {
		return key;
	}

	int getValue() {
		return value;
	}
};

class myHashTable1 {

private:
	int size;
	DATA **hashArray;
	int hashFunction1(int key) {
		return key % size;
	}
	int hashFunction2(int key) {
		return (3-(key % 3));
	}
public:

	myHashTable1() {
		size = 101;
		hashArray = new DATA*[size];
		for (int i = 0; i < size; i++)
			hashArray[i] = NULL;
	}
	myHashTable1(int n) {
		size = n;
		hashArray = new DATA*[size];
		for (int i = 0; i < size; i++)
			hashArray[i] = NULL;
	}

	DATA* find(int key) {
		int counter = 0;
		int ihash = hashFunction1(key);
		while (hashArray[ihash] != NULL && hashArray[ihash]->getKey() != key) {
			counter++;
			ihash = (hashFunction1(ihash) + counter*hashFunction2(ihash)) % size;
			if (ihash >= size)
				ihash = ihash % size;
		}
		if (hashArray[ihash] == NULL)
			return NULL;
		else
			return hashArray[ihash];
	}

	DATA* find(int key, int &cycleCounter, int &oneCounter) {
		int counter = 0;
		int ihash = hashFunction1(key);
		while (hashArray[ihash] != NULL && hashArray[ihash]->getKey() != key) {
			counter++;
			ihash = (hashFunction1(ihash) + counter*hashFunction2(ihash)) % size;
			if (ihash >= size)
				ihash = ihash % size;
		}
		oneCounter = counter;
		cycleCounter += counter;
		//std::cout << "key: " << std::setw(6) << hashArray[ihash]->getKey() << " value: " << std::setw(6) << hashArray[ihash]->getValue() << " collisions: " << std::setw(6) << counter << std::endl;
		if (hashArray[ihash] == NULL)
			return NULL;
		else
			return hashArray[ihash];
	}

	bool remove(int key) {
		int counter = 0;
		int ihash = hashFunction1(key);
		while (hashArray[ihash] != NULL && hashArray[ihash]->getKey() != key) {
			counter++;
			ihash = (hashFunction1(ihash) + counter*hashFunction2(ihash)) % size;
			if (ihash >= size)
				ihash = ihash % size;
		}
		if (hashArray[ihash] == NULL)
			return false;
		else
		{
			delete hashArray[ihash];
			hashArray[ihash] = NULL;
			return true;
		}
	}

	void insert(DATA *tempDATA) {
		int key = tempDATA->getKey();
		int value = tempDATA->getValue();
		int counter = 0;
		int ihash = hashFunction1(key);
		//std::cout << " key:" << key << " hash" << ihash << "\n";
		while (hashArray[ihash] != NULL && hashArray[ihash]->getKey() != key) {
			counter++;
			//std::cout <<"key:" <<key << " hash" << ihash << " hf1" << hashFunction1(ihash) << " hf2" << hashFunction2(ihash)<<" counter"<<counter;
			ihash = (hashFunction1(ihash) + counter*hashFunction2(ihash))%size;
			//std::cout << "key:" << key << " hash" << ihash << " hf1" << hashFunction1(ihash) << " hf2" << hashFunction2(ihash) << " counter" << counter;
			if (ihash >= size)
				ihash = ihash % size;
			//std::cout << " key:" << key << " hash" << ihash << " hf1" << hashFunction1(ihash) << " hf2" << hashFunction2(ihash) << " counter" << counter<<"\n";
	
		}
		if (hashArray[ihash] != NULL)
			delete hashArray[ihash];
		hashArray[ihash] = new DATA(key, value);
	}

	void print() {
		for (int i = 0; i < size; i++)
			if (hashArray[i]!=NULL)
			std::cout << "key: " << hashArray[i]->getKey() << " value:" << hashArray[i]->getValue() << "\n";
			else
				std::cout << "key: " << "null" << " value:" << "null" << "\n";
	}

	~myHashTable1() {
		for (int i = 0; i < size; i++)
			if (hashArray[i] != NULL)
				delete hashArray[i];
		delete[] hashArray;
	}
};

class myHashTable2 {

private:
	int size;
	DATA **hashArray;
	int hashFunction1(int key) {
		return ((key % size)*(key % size)*key+(key%size)*key/3) %size;
	}
	int hashFunction2(int key) {
		return (5 - (key % 5));
	}
public:

	myHashTable2() {
		size = 101;
		hashArray = new DATA*[size];
		for (int i = 0; i < size; i++)
			hashArray[i] = NULL;
	}
	myHashTable2(int n) {
		size = n;
		hashArray = new DATA*[size];
		for (int i = 0; i < size; i++)
			hashArray[i] = NULL;
	}

	DATA* find(int key) {
		int counter = 0;
		int ihash = hashFunction1(key);
		while (hashArray[ihash] != NULL && hashArray[ihash]->getKey() != key) {
			counter++;
			ihash = (hashFunction1(ihash) + counter*hashFunction2(ihash)) % size;
			if (ihash >= size)
				ihash = ihash % size;
		}
		if (hashArray[ihash] == NULL)
			return NULL;
		else
			return hashArray[ihash];
	}

	DATA* find(int key, int &cycleCounter, int &oneCounter) {
		int counter = 0;
		int ihash = hashFunction1(key);
		while (hashArray[ihash] != NULL && hashArray[ihash]->getKey() != key) {
			counter++;
			ihash = (hashFunction1(ihash) + counter*hashFunction2(ihash)) % size;
			if (ihash >= size)
				ihash = ihash % size;
		}
		oneCounter = counter;
		cycleCounter += counter;
		//std::cout << "key: " << std::setw(6) << hashArray[ihash]->getKey() << " value: " << std::setw(6) << hashArray[ihash]->getValue() << " collisions: " << std::setw(6) << counter << std::endl;
		if (hashArray[ihash] == NULL)
			return NULL;
		else
			return hashArray[ihash];
	}

	bool remove(int key) {
		int counter = 0;
		int ihash = hashFunction1(key);
		while (hashArray[ihash] != NULL && hashArray[ihash]->getKey() != key) {
			counter++;
			ihash = (hashFunction1(ihash) + counter*hashFunction2(ihash)) % size;
			if (ihash >= size)
				ihash = ihash % size;
		}
		if (hashArray[ihash] == NULL)
			return false;
		else
		{
			delete hashArray[ihash];
			hashArray[ihash] = NULL;
			return true;
		}
	}

	void insert(DATA *tempDATA) {
		int key = tempDATA->getKey();
		int value = tempDATA->getValue();
		int counter = 0;
		int ihash = hashFunction1(key);
		//std::cout << " key:" << key << " hash" << ihash << "\n";
		while (hashArray[ihash] != NULL && hashArray[ihash]->getKey() != key) {
			counter++;
			//std::cout << "key:" << key << " hash" << ihash << " hf1" << hashFunction1(ihash) << " hf2" << hashFunction2(ihash) << " counter" << counter;
			ihash = (hashFunction1(ihash) + counter*hashFunction2(ihash)) % size;
			//std::cout << "key:" << key << " hash" << ihash << " hf1" << hashFunction1(ihash) << " hf2" << hashFunction2(ihash) << " counter" << counter;
			if (ihash >= size)
				ihash = ihash % size;
			//std::cout << " key:" << key << " hash" << ihash << " hf1" << hashFunction1(ihash) << " hf2" << hashFunction2(ihash) << " counter" << counter << "\n";

		}
		if (hashArray[ihash] != NULL)
			delete hashArray[ihash];
		hashArray[ihash] = new DATA(key, value);
	}

	void print() {
		for (int i = 0; i < size; i++)
			if (hashArray[i] != NULL)
				std::cout << "key: " << hashArray[i]->getKey() << " value:" << hashArray[i]->getValue() << "\n";
			else
				std::cout << "key: " << "null" << " value:" << "null" << "\n";
	}

	~myHashTable2() {
		for (int i = 0; i < size; i++)
			if (hashArray[i] != NULL)
				delete hashArray[i];
		delete[] hashArray;
	}
};

class myHashTable3 {

private:
	int size;
	DATA **hashArray;
	int hashFunction1(int key) {
		std::string strKey = std::to_string(key);
		int sum = 1;
		for (int i = 0; i < strKey.size(); i++) {
			sum *= strKey[i];
		}
		return (sum*sum*strKey.size()/2+sum/3+(sum % size))%size;
	}
	int hashFunction2(int key) {
		return (7 - (key % 7));
	}
public:

	myHashTable3() {
		size = 101;
		hashArray = new DATA*[size];
		for (int i = 0; i < size; i++)
			hashArray[i] = NULL;
	}
	myHashTable3(int n) {
		size = n;
		hashArray = new DATA*[size];
		for (int i = 0; i < size; i++)
			hashArray[i] = NULL;
	}

	DATA* find(int key) {
		int counter = 0;
		int ihash = hashFunction1(key);
		while (hashArray[ihash] != NULL && hashArray[ihash]->getKey() != key) {
			counter++;
			ihash = (hashFunction1(ihash) + counter*hashFunction2(ihash)) % size;
			if (ihash >= size)
				ihash = ihash % size;
		}
		if (hashArray[ihash] == NULL)
			return NULL;
		else
			return hashArray[ihash];
	}

	DATA* find(int key, int &cycleCounter, int &oneCounter) {
		int counter = 0;
		int ihash = hashFunction1(key);
		while (hashArray[ihash] != NULL && hashArray[ihash]->getKey() != key) {
			counter++;
			ihash = (hashFunction1(ihash) + counter*hashFunction2(ihash)) % size;
			if (ihash >= size)
				ihash = ihash % size;
		}
		oneCounter = counter;
		cycleCounter += counter;
		//std::cout << "key: " << std::setw(6) << hashArray[ihash]->getKey() << " value: " << std::setw(6) << hashArray[ihash]->getValue() << " collisions: " << std::setw(6) << counter << std::endl;
		if (hashArray[ihash] == NULL)
			return NULL;
		else
			return hashArray[ihash];
	}

	bool remove(int key) {
		int counter = 0;
		int ihash = hashFunction1(key);
		while (hashArray[ihash] != NULL && hashArray[ihash]->getKey() != key) {
			counter++;
			ihash = (hashFunction1(ihash) + counter*hashFunction2(ihash)) % size;
			if (ihash >= size)
				ihash = ihash % size;
		}
		if (hashArray[ihash] == NULL)
			return false;
		else
		{
			delete hashArray[ihash];
			hashArray[ihash] = NULL;
			return true;
		}
	}

	void insert(DATA *tempDATA) {
		int key = tempDATA->getKey();
		int value = tempDATA->getValue();
		int counter = 0;
		int ihash = hashFunction1(key);
		//std::cout << " key:" << key << " hash" << ihash << "\n";
		while (hashArray[ihash] != NULL && hashArray[ihash]->getKey() != key) {
			counter++;
			//std::cout << "key:" << key << " hash" << ihash << " hf1" << hashFunction1(ihash) << " hf2" << hashFunction2(ihash) << " counter" << counter;
			ihash = (hashFunction1(ihash) + counter*hashFunction2(ihash)) % size;
			//std::cout << "key:" << key << " hash" << ihash << " hf1" << hashFunction1(ihash) << " hf2" << hashFunction2(ihash) << " counter" << counter;
			if (ihash >= size)
				ihash = ihash % size;
			//std::cout << " key:" << key << " hash" << ihash << " hf1" << hashFunction1(ihash) << " hf2" << hashFunction2(ihash) << " counter" << counter << "\n";

		}
		if (hashArray[ihash] != NULL)
			delete hashArray[ihash];
		hashArray[ihash] = new DATA(key, value);
	}

	void print() {
		for (int i = 0; i < size; i++)
			if (hashArray[i] != NULL)
				std::cout << "key: " << hashArray[i]->getKey() << " value:" << hashArray[i]->getValue() << "\n";
			else
				std::cout << "key: " << "null" << " value:" << "null" << "\n";
	}

	~myHashTable3() {
		for (int i = 0; i < size; i++)
			if (hashArray[i] != NULL)
				delete hashArray[i];
		delete[] hashArray;
	}
};


void main()//main function
{
	short operationCode = 0;
	int quantity;
	int key = 0,value=0;
	int cycleCounter1,cycleCounter2,cycleCounter3=0;
	bool result;
	double sqrtquantity;
	DATA* tempDATA = new DATA(0,0);
	myHashTable1 *testHashTable1 = new myHashTable1();
	myHashTable2 *testHashTable2 = new myHashTable2();
	myHashTable3 *testHashTable3 = new myHashTable3();
	int keyArray[100][2];
	int counterArray[100][3];
	srand(time(NULL));//initialization of random seed
	SetConsoleOutputCP(1251);//console localization
	SetConsoleCP(1251);
	outputMainMenu();//show menu of available commands
	while (operationCode != 48)//repeat until exit
	{
		operationCode = _getch();//get command
		system("cls");//clear console screen
		switch (operationCode)//command choice
		{
		case 49://hast table creation
			std::cout << "CREATE HASH TABLE\n";
			std::cout << "Enter keys quantity:\n";//value input
			std::cin >> quantity;
			sqrtquantity = sqrt(quantity);
			for (int i = 2; i<=sqrtquantity; i++) {
				if (quantity % i == 0) {
					std::cout << "Error: quantity must be prime number!\n";
				}
				else
				{
					testHashTable1= new myHashTable1(quantity);
				}
			}
			std::cout << "Done!\n";
			break;
		case 50://insertion into hash table
			std::cout << "INSERT TO HASH TABLE\n";
			std::cout << "Enter key and value to insert:\n";
			std::cin >> key;
			std::cin >> value;
			tempDATA = new DATA(key, value);
			testHashTable1->insert(tempDATA);
			std::cout << "Done!\n";
			break;
		case 51://removal from hash table
			std::cout << "REMOVE FROM HASH TABLE\n";
			std::cout << "Enter key to remove:\n";
			std::cin >> key;
			result=testHashTable1->remove(key);
			if (!result)
				std::cout << "Error: no such key!\n";
			std::cout << "Done!\n";
			break;
		case 52://search in hash table
			std::cout << "SEARCH IN HASH TABLE\n";
			std::cout << "Enter key to search:\n";
			std::cin >> key;
			tempDATA = testHashTable1->find(key);
			if (tempDATA != NULL)
				std::cout << "key: " << std::setw(6) << tempDATA->getKey() << " value: " << std::setw(6) << tempDATA->getValue() << std::endl;
			else
				std::cout << "Not found!\n";
			std::cout << "Done!\n";
			break;
		case 53://hash table print out
			std::cout << "PRINT HASH TABLE\n";
			testHashTable1->print();
			std::cout << "Done!\n";
			break;
		case 54://program test
			std::cout << "TEST PROGRAM\n";
			delete testHashTable1;
			delete testHashTable2;
			delete testHashTable3;
			testHashTable1 = new myHashTable1(151);
			testHashTable2 = new myHashTable2(151);
			testHashTable3 = new myHashTable3(151);
			cycleCounter1 = 0;
			cycleCounter2 = 0;
			cycleCounter3 = 0;
			for (int i = 0; i < 100; i++) {
				keyArray[i][0] = rand() % 99000 + 1000;
				keyArray[i][1] = rand() % 99000 + 1000;
				tempDATA = new DATA(keyArray[i][0], keyArray[i][1]);
				testHashTable1->insert(tempDATA);
				testHashTable2->insert(tempDATA);
				testHashTable3->insert(tempDATA);
			}
			//std::cout << testHashTable->find(10);
			std::cout << "Collisions" << "   Table 1" << "   Table 2" << "   Table 3" << std::endl;
			for (int i = 0; i < 100; i++)
			{
				tempDATA = testHashTable1->find(keyArray[i][0], cycleCounter1, counterArray[i][0]);
				tempDATA = testHashTable2->find(keyArray[i][0], cycleCounter2, counterArray[i][1]);
				tempDATA = testHashTable3->find(keyArray[i][0], cycleCounter3, counterArray[i][2]);
				std::cout << std::setw(10)<< (i+1) << std::setw(10) << counterArray[i][0] << std::setw(10) << counterArray[i][1] << std::setw(10) << counterArray[i][2] << std::endl;
			}
			std::cout << "     Total"<< std::setw(10)<<cycleCounter1 << std::setw(10) <<cycleCounter2 << std::setw(10) <<cycleCounter3 << std::endl;
			std::cout << "Done!\n";
			break;
		case 57://show info about programme
			aboutProgramme();
			break;
		case 48://programme shut down
			exit;
			break;
		default://case of pressing button not assigned to commands
			outputMainMenu();//show menu of available commands
		}
	}
}


void outputMainMenu()//show menu of available commands in main menu
{
	std::cout << "MAIN MENU\n";
	std::cout << "Choose operation:\n";
	std::cout << "Press 1 to create hash table\n";
	std::cout << "Press 2 to insert value in hash table\n";
	std::cout << "Press 3 to remove value from hash table\n";
	std::cout << "Press 4 to search value in hash table\n";
	std::cout << "Press 5 to print info about hash table\n";
	std::cout << "Press 6 to test programme\n";
	std::cout << "Press 9 to get info about the programme\n";
	std::cout << "Press 0 to exit";

}

void aboutProgramme()//show info about the programme
{
	std::cout << "ABOUT PROGRAMME\n\n";
	std::cout << "Algorithms and data structures\n";
	std::cout << "Practical assignment #4\n";
	std::cout << "Variant: AD\n\n";
	std::cout << "Version 0.0.0.0(vs) build 20180519000000\n\n";
	std::cout << "Development and testing: Yaskovich Dmitry (ISBO-05-15)\n\n";
	std::cout << "Dimini Inc, 2018";
}