#pragma once

#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;


class HashTable
{
    int numkeys;
    list<int>* hashT;

public:
    HashTable(int numkeys);
    void insertData(int data);
    int hashKey(int data);
    void displayHashTable();
    bool findValue(int data);
    bool deleteData(int data);
};
