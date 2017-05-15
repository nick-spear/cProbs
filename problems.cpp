/*
** This file contains function definitions from 'problems.hpp'. Write your
** implementations here.
**/

#include <iostream>
#include <fstream>

#include "problems.hpp"


/* PART 1: OUTPUT *************************************************************
**************************************************************************** */


void helloWorld()
{
    std::cout << "hello world" << std::endl;
}



void helloFilesystem(const std::string& file)
{
    std:: ofstream out (file);
    out << "hello filesystem";
    out.close();
}


/* PART 2: ITERATING OVER ARRAYS **********************************************
**************************************************************************** */


void printArray1(const int array[], int size)
{
    for (int i = 0; i < size; i++)
      std::cout << array[i] << ' ';
}



void printArray2(const int array[], int size)
{
    const int *iter = array;

    //for(int i = 0; i < size; i++), *(iter+i)
    for(; iter < array+size; ++iter)
      std::cout << *iter << ' ';
}


/* PART 3: C STRINGS **********************************************************
**************************************************************************** */


int stringLength1(const char str[])
{
    int count = 0;

    while(str[count] != '\0')
      count++;

    return count;
}



int stringLength2(const char str[])
{
    int count = 0;
    const char *iter = str;
    while(*(iter + count) != '\0') {
      count++;
    }

    return count;
}



bool stringsEqual1(const char str1[], const char str2[])
{
    const char *iter1 = str1,
               *iter2 = str2;

    while (*iter1 != '\0' || *iter2 != '\0') {
      if (*iter1 != *iter2)
        return false;
      ++iter1;
      ++iter2;
    }

    return true;
}



bool stringsEqual2( const char str1[], const char str2[])
{
  // Didn't use index!
  return stringsEqual1(str1, str2);
}



void copyString(const char src[], char dest[])
{
}



int stringToInteger(const char str[])
{
    return -1;
}


/* PART 4: INTEGERS ***********************************************************
**************************************************************************** */


int countBits(unsigned int num)
{
    int count = 0;

    while(num > 0) {
      if(num & 1 == 1)
        count++;
      num >>= 1;
    }

    return count;
}



bool isPowerOfTwo(unsigned int num)
{
    // 100...00 turns into 011...11 when sub'd by 1
    // 0 looks like a special case

    return (num & (num - 1)) == 0 && num > 0;
}


/* PART 5: SORTS AND SEARCHES *************************************************
**************************************************************************** */


void bubbleSort(int array[], int size)
{
    int check1, check2;
    bool hasSwapped = true;

    while (hasSwapped) {
      hasSwapped = false;
      for(int i = 0; i < size - 1; i++) {
        check1 = array[i];
        check2 = array[i + 1];
        if (check1 > check2) {
          array[i] = check2;
          array[i + 1] = check1;
          hasSwapped = true;
        }
      }
    }
}



void selectionSort(int array[], int size)
{
    int smallest, smalldex;

    for(int i = 0; i < size - 1; i++) {
      smallest = array[i];
      smalldex = i;
      for(int j = i + 1; j < size; j++) {
        if(array[j] < smallest) {
          smallest = array[j];
          smalldex = j;
        }
      }
      array[smalldex] = array[i];
      array[i] = smallest;
    }

}



void insertionSort(int array[], int size)
{
    int botBin, midBin, topBin, testVal;

    for(int i = 1; i < size; i++) {
      testVal = array[i];
      botBin = 0;
      topBin = i;

      while(topBin >= botBin) {
        midBin = (botBin + topBin) / 2;

        if(array[midBin] == testVal)
          break;
        else if (testVal > array[midBin])
          botBin = midBin + 1;
        else
          topBin = midBin - 1;

      } // End of binary search for key

      if(array[midBin] < testVal) midBin++;

      for (int j = i; j > midBin; j--) {
            array[j] = array[j-1];
      }
      array[midBin] = testVal;
    }
}



void mergeSort(int array[], int size, int low, int high)
{
    // TODO
}



bool binarySearch(int array[], int size, int key)
{
    int topBin = size,
        botBin = 0,
        midBin;

    while(topBin > botBin) {
      midBin = (botBin + topBin) / 2;

      if(key == array[midBin])
        return true;
      else if (key > array[midBin])
        botBin = midBin + 1;
      else
        topBin = midBin;
    } // End of binary search for key
    return false;
}


/* PART 6: MISC ***************************************************************
**************************************************************************** */


void bipBop(int iterations)
{
    // TODO
}



int countCalls()
{
    // TODO
    return -1;
}



int breakingTheLaw(int outer, int inner)
{
    // TODO
    return -1;
}
