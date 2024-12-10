#include <iostream>
#include "hashTable.h"
#include <cstdlib>
#include <list>

using namespace std;

HashTable::HashTable(int numkeys)
{
    this->numkeys = numkeys;
    hashT = new list<int>[numkeys];
}

int HashTable::hashKey(int data)
{
    return data % this->numkeys;
}

void HashTable::insertData(int data)
{
    int dataKey = hashKey(data);// get the key for the data
    hashT[dataKey].push_back(data);// push the data into the list at the key
    //displayHashTable();// display the hash table after inserting the data
}

void HashTable::displayHashTable()
{
    for (int i = 0; i < numkeys; i++)// loop through the hash table (outer loop)
    {
        cout << i;
        for (auto x : hashT[i])// loop through the list at each index (each index is a list) (inner loop)
        {
            cout << "-->  " << x;
			
        }
        cout << "\n";
    }

}

bool HashTable::findValue(int data)
{
    int dataKey = hashKey(data);// get the key for the data
    bool found = false;// set found to false
    list<int>::iterator i;// create an iterator
    i = hashT[dataKey].begin();// set the iterator to the beginning of the list at the key
    while (!found && i != hashT[dataKey].end())// loop through the list at the key while found is false and the iterator is not at the end of the list
    {
        if (*i == data)// if the value at the iterator is the data
        {
            return true;
        }
        else
        {
            i++;// increment the iterator
        }
    }
    if (i != hashT[dataKey].end())// if the iterator is not at the end of the list
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool  HashTable::deleteData(int data)
{
    int dataKey = hashKey(data);// get the key for the data
    bool found = false;// set found to false
    list<int>::iterator i;// create an iterator
    i = hashT[dataKey].begin();// set the iterator to the beginning of the list at the key
    while (!found && i != hashT[dataKey].end())// loop through the list at the key while found is false and the iterator is not at the end of the list
    {
        if (*i == data)// if the value at the iterator is the data (value)
        {
            found = true;
        }
        else
        {
            i++;// increment the iterator
        }
    }
    if (i != hashT[dataKey].end())// if the iterator is not at the end of the list
    {
        hashT[dataKey].erase(i);// erase the value at the iterator index
    }
    else
    {
        return false;
    }
}