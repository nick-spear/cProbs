/*
** This file contains function signature and descriptions for the exercises.
**/

#include <string>

#define NUM_PROBS 20


/* PART 1: OUTPUT *************************************************************
**************************************************************************** */


/*
** Function: helloWorld
**
** Input: N/A
**
** Output:
**
**    Prints 'hello world' to standard output using std::cout.
**
** Restrictions: N/A
**
** Hint: N/A
**/
void helloWorld ();



/*
** Function: helloFilesystem
**
** Input:
**
**    A string path to a file to write to.
**
** Output:
**
**    Prints 'hello filesystem' to the file at the provided path.
**
** Restrictions: N/A
**
** Hint:
**
**    The <fstream> header in the C++ standard library contains helpful
**    classes for file I/O.
**/
void helloFilesystem (const std::string& file);



/* PART 2: ITERATING OVER ARRAYS **********************************************
**************************************************************************** */


/*
** Function: printArray1
**
** Input:
**
**    - 'array': an array of integers.
**    - 'size':  the number of elements in 'array'.
**
** Output:
**
**    Prints the contents of 'array' formatted as: [a, b, c, d, ..., z].
**
** Restrictions: N/A
**
** Hint: N/A.
**/
void printArray1 (const int array[], int size);



/*
** Function: printArray2
**
** Input:
**
**    - 'array': an array of integers.
**    - 'size': the number of elements in 'array'.
**
** Output:
**
**    Prints the contents of 'array' formatted as: [a, b, c, d, ..., z].
**
** Restrictions:
**
**    Do not use the index operator. For example, you may not use 'array[i]'.
**
** Hint:
**
**    In C, arrays are isomorphic to another primitive structure.
**/
void printArray2 (const int array[], int size);



/* PART 3: C STRINGS **********************************************************
**************************************************************************** */


/*
** Function: stringLength1
**
** Input:
**
**    - 'str': a null-terminated array of characters.
**
** Output:
**
**    Returns the length of 'str'.
**
** Restrictions: N/A
**
** Hint:
**
**    What does 'null-terminated' mean? How do you know when the string ends?
**/
int stringLength1 (const char str[]);



/*
** Function: stringLength2
**
** Input:
**
**    - 'str': a null-terminated array of characters.
**
** Output:
**
**    Returns the length of 'str'.
**
** Restrictions:
**
**    Do not use the index operator.
**
** Hint: N/A
**/
int stringLength2 (const char str[]);



/*
** Function: stringsEqual1
**
** Input:
**
**    - 'str1': a null-terminated string.
**    - 'str2': a null-terminated string.
**
** Output:
**
**    Returns true if str1 and str2 have the same contents. False otherwise.
**
** Restrictions: N/A
**
** Hint: N/A
**/
bool stringsEqual1 (const char str1[], const char str2[]);



/*
** Function: stringsEqual2
**
** Input:
**
**    - 'str1': a null-terminated string.
**    - 'str2': a null-terminated string.
**
** Output:
**
**    Returns true if str1 and str2 have the same contents. False otherwise.
**
** Restrictions:
**
**    Do not use the index operator.
**
** Hint: N/A
**/
bool stringsEqual2 (const char str1[], const char str2[]);



/*
** Function: copyString
**
** Input:
**
**    - 'src': A null-terminated string.
**    - 'dest': an empty string large enough to contain 'src'.
**
** Output:
**
**    Copies the contents of 'src' into 'dest', including the null terminator.
**
** Restrictions:
**
**    Use only one line of code, only one semicolon, and no loop bodies.
**
** Hint:
**
**    You can assign to variables during a boolean evaluation.
**/
void copyString (const char src[], char dest[]);



/*
** Function: stringToInteger
**
** Input:
**
**    - 'str': A null-terminated array of digit characters. str[0] may be either
**             '-' or a digit character '0', '1', ..., '9'. The rest of the
**             characters are only digit characters.
**
** Output:
**
**    The integer representation of 'str'.
**
** Restrictions: N/A
**
** Hint:
**
**    What is the ASCII value of '0'? Can you express the remaining ASCII digits
**    as a function of '0'? Don't forget to account for negative numbers.
**/
int stringToInteger(const char str[]);



/* PART 4: INTEGERS ***********************************************************
**************************************************************************** */


/*
** Function: countBits
**
** Input:
**
**    - 'num': An integer.
**
** Output:
**
**    The number of 1's in the binary representation of 'num'.
**
** Restrictions: N/A
**
** Remark:
**
**    This problem can be solved in exactly n time, where n is the number
**    of bits in 'num', or <= n time. What early exit condition might you use
**    to avoid unecessary work?
**/
int countBits (unsigned int num);



/*
** Function: isPowerOfTwo
**
** Input:
**
**    - 'num': An integer.
**
** Output:
**
**    Returns true if 'num' is a power of two, false otherwise.
**
** Restrictions: N/A
**
** Remark:
**
**    This can be done in O(n) and O(1) time. Can you figure out both?
**/
bool isPowerOfTwo (unsigned int num);



/* PART 5: SORTS AND SEARCHES *************************************************
**************************************************************************** */


/*
** Function: bubbleSort
**
** Input:
**
**    - 'array': An array of integers.
**    - 'size': The size of 'array'.
**
** Output:
**
**    Sorts 'array'.
**
** Restrictions:
**
**    Use bubble sort.
**
** Hint: N/A
**/
void bubbleSort (int array[], int size);



/*
** Function: selectionSort
**
** Input:
**
**    - 'array': An array of integers.
**    - 'size': The size of 'array'.
**
** Output:
**
**    Sorts 'array'.
**
** Restrictions:
**
**    Use selection sort.
**
** Hint: N/A
**/
void selectionSort (int array[], int size);



/*
** Function: insertionSort
**
** Input:
**
**    - 'array': An array of integers.
**    - 'size': The size of 'array'.
**
** Output:
**
**    Sorts 'array'.
**
** Restrictions:
**
**    Use insertion sort.
**
** Hint: N/A
**/
void insertionSort (int array[], int size);



/*
** Function: mergeSort
**
** Input:
**
**    - 'array': An array of integers.
**    - 'size': The size of 'array'.
**    - 'low': Index of the start of the subarray.
**    - 'high': Index of the end of the subarray.
**
** Output:
**
**    Sorts 'array'.
**
** Restrictions:
**
**    Use merge sort, implement it recursively.
**
** Hint:
**
**    To implement merge sort recursively, you will need to specify to each
**    recursive call the subarray that it should act on. For each call, 'low'
**    should be the index of the first element of the subarray of 'array', and
**    'high' should be the index of the last element. The first call to
**    'mergeSort' will have (low == 0), (high == size-1).
**
**    Another hint: during the merge phase, start by copying the two arrays
**    you're merging to two temp arrays, then merge back into the return array.
**/
void mergeSort (int array[], int size, int low, int high);


/*
** Function: binarySearch
**
** Input:
**
**    - 'array': A sorted array of integers.
**    - 'size': The size of 'array'.
**    - 'key': The integer you are searching for.
**
** Output:
**
**    Returns true if 'array' contains 'key', false otherwise.
**
** Restrictions:
**
**    Use an iterative implementation.
**
** Hint: N/A
**/
bool binarySearch (int array[], int size, int key);



/* PART 6: MISC ***************************************************************
**************************************************************************** */


/*
** Function: bipBop
**
** Input:
**
**    - 'iterations': An integer, the number of iterations of the loop.
**
** Output:
**
**    Loops 'iterations' times. For each iteration 'i', print "bip" if 'i'
**    is a multiple of 3, "bop" if 'i' is a multiple of 5, "bipbop" if
**    'i' is a multiple of 3 and 5, and 'i' otherwise.
**
** Restrictions: N/A
**
** Hint: N/A
**/
void bipBop (int iterations);



/*
** Function: countCalls
**
** Input: N/A
**
** Output:
**
**    Returns the number of times this function has been called since the
**    program started. This includes the current call.
**
** Restrictions:
**
**    You may not use global variables.
**
** Hint:
**
**    The list of C keywords is very short, check them all. This function
**    can be implemented in two lines.
**/
int countCalls ();



/*
** Function: breakingTheLaw
**
** Input:
**
**    - 'outer': Number of outer loops to perform.
**    - 'inner': Number of inner loops to perform.
**
** Output:
**
**    This function must loop 'outer' times, and for each iteration loop 'inner'
**    times. Every iteration of the inner loop, this function must increment an
**    integer. When the integer becomes greater than 'outer', or if you naturally
**    fall out of the loops, return the number of outer loop iterations performed.
**
** Restrictions:
**
**    You may only use one return statement, and it cannot be inside of a loop.
**    You may not perform any more iterations after the exit condition is met.
**
** Hint:
**
**    How will you break out of both loops simultaneously? What does the 'break'
**    keyword do? Is there a programming rule you could break to get a clean
**    solution?
**/
int breakingTheLaw (int outer, int inner);
