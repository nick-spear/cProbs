/*
** This file contains function definitions from 'problems.hpp'. Write your
** implementations here.
**/

#include <iostream>
#include <fstream>
#include <cstring>

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
  return str1 == str2;
  // This feels so wrong
}



void copyString(const char src[], char dest[])
{
  std::strcpy(dest, src);
}



int stringToInteger(const char str[])
{
  const char *iter = str;
  int output = 0,
         neg = 1;

  if (*iter == '-') {
    neg = -1;
    ++iter;
  }

  while (*iter != '\0') {
    output *= 10;
    output += (*iter - 48);
    ++iter;
  }

  if (neg == -1)
    return neg * output;
  return output;
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

void merge(int array[], int size, int low, int high) {
    int mid = (high + low) / 2,
        iterVal = low;
    int bothAr[high - low + 1];

    for(int i = low; i <= high; i++) {
      bothAr[i - low] = array[i];
    }

    // Iterative merge
    int i = low, j = mid + 1;
    while(i <= mid && j <= high) {
      if (bothAr[i - low] < bothAr[j - low]) {
        array[iterVal] = bothAr[i - low];
        iterVal++;
        i++;
      } else {
        array[iterVal] = bothAr[j - low];
        iterVal++;
        j++;
      }
    }

    // Tidy up leftover values after a subarray runs out
    while(i <= mid) {
      array[iterVal] = bothAr[i - low];
      i++;
      iterVal++;
    }

    while(j <= high) {
      array[iterVal] = bothAr[j - low];
      j++;
      iterVal++;
    }

    return;
}

void mergeSort(int array[], int size, int low, int high)
{
    // TODO
    if (high <= low)
      return;

    mergeSort(array, size, low, (high + low) / 2);
    mergeSort(array, size, ((high + low)/2) + 1, high);
    // For sake of tidyness
    merge(array, size, low, high);

    return;
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
    for(int i = 1; i <= iterations; i++) {
      if(i % 3 == 0)
        std::cout << "bip";
      if(i % 5 == 0)
        std::cout << "bop";
      else if (i % 3 != 0)
        std::cout << i;
      std::cout << std::endl;
    }
}



int countCalls()
{
    static int count = 1;
    return count++;
}



int breakingTheLaw(int outer, int inner)
{
    int o = 0, count = 0;

    outerLoop:
    while(o < outer) {
      o++;
      for(int i = 0; i < inner; i++)
        count++;
    }

    return o;
}
