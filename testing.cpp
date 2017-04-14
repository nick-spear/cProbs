/*
** This file contains my testing code. If you find a bug, feel free to try
** to fix it. This code isn't meant to be readable by humans.
**/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream>

#include <unistd.h> // for 'unlink()'.

#include "testing.hpp"
#include "problems.hpp"


static void test_helloWorld()
{
    std::cout << "\n* FUNCTION: helloWorld\n\n";

    std::cout << "\tThis function requires manual testing.\n\n\t- Output:\n\n\t\t";
    helloWorld();
    std::cout << "\n\n\t*** End 'helloWorld' Output ***" << std::endl;
}


static void test_helloFilesystem()
{
    std::cout << "\n* FUNCTION: helloFilesystem\n\n";

    std::string file("./hellofilesystem.txt");
    std::stringstream buffer;

    helloFilesystem(file);
    std::ifstream reader(file, std::ifstream::in);

    if( reader.fail() )
        std::cout << "\tFAILED: Your code didn't create the file!\n";

    else
    {
        buffer << reader.rdbuf();
        if( buffer.str() != "hello filesystem" )
        {
            std::cout << "\tFAILED: Your code didn't print \"hello filesystem\" to "
                << "the file! Your code printed \"" << buffer.str() << "\"\n";
        }

        else
            std::cout << "\tOK\n\n\tDeleting the file for you...\n";
    }

    if( reader.is_open() )
    {
        reader.close();
        unlink(file.c_str());
    }
}


static void test_printArray1()
{
    std::cout << "\n* FUNCTION: printArray1\n\n";

    std::cout << "\tThis function requires manual testing.\n\n";

    int array1[0] = {};
    int array2[5] = {1, 2, 3, 4, 5};
    int array3[10] = {25, 43, 859, 356, 90, 4, 78, 81, 252, 64};

    std::cout << "\t(1)\n\t\t- Input:  []\n\t\t- Output: ";
    printArray1(array1, 0);
    std::cout << "\n\n\t(2)\n\t\t- Input:  [1, 2, 3, 4, 5]\n\t\t- Output: ";
    printArray1(array2, 5);
    std::cout << "\n\n\t(3)\n\t\t- Input:  [25, 43, 859, 356, 90, 4, 78, 81, 252, 64]"
              << "\n\t\t- Output: ";
    printArray1(array3, 10);

    std::cout << "\n\n\t*** End 'printArray1' Output ***" << std::endl;
}


static void test_printArray2()
{
    std::cout << "\n* FUNCTION: printArray2\n\n";

    std::cout << "\tThis function requires manual testing.\n\n";

    int array1[0] = {};
    int array2[5] = {1, 2, 3, 4, 5};
    int array3[10] = {25, 43, 859, 356, 90, 4, 78, 81, 252, 64};

    std::cout << "\t(1)\n\t\t- Input:  []\n\t\t- Output: ";
    printArray2(array1, 0);
    std::cout << "\n\n\t(2)\n\t\t- Input:  [5, 2, 7, 3, 5]\n\t\t- Output: ";
    printArray2(array2, 5);
    std::cout << "\n\n\t(3)\n\t\t- Input:  [99, 98, 96, 93, 89, 84, 78, 72, 65, 53]"
              << "\n\t\t- Output: ";
    printArray2(array3, 10);

    std::cout << "\n\n\t*** End 'printArray2' Output ***" << std::endl;
}


static void test_stringLength1()
{
    std::cout << "\n* FUNCTION: stringLength1\n\n";

    int answer;
    bool passed = true;
    int temp;

    char str1[] = "";
    char str2[] = "Hello world";
    char str3[] = "goodnight big blue house";

    if( (answer = stringLength1(str1)) != (temp = strlen(str1)) )
    {
        std::cout << "\tFAILED on test: \"\"\n\n\t\t- Answer: " << temp
            << "\n\t\t- Your Answer: " << answer << '\n';
        passed = false;
    }

    if( (answer = stringLength1(str2)) != (temp = strlen(str2)) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"Hello world\"\n\n\t\t- Answer:" << temp
            << "\n\t\t- Your Answer: " << answer << '\n';
    }

    if( (answer = stringLength1(str3)) != (temp = strlen(str3)) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"goodnight big blue house\""
                << "\n\n\t\t- Answer: " << temp
                << "\n\t\t- Your Answer: " << answer << '\n';
    }

    if( passed )
        std::cout << "\tOK\n";
}


static void test_stringLength2()
{
    std::cout << "\n* FUNCTION: stringLength2\n\n";

    int answer;
    bool passed = true;
    int temp;

    char str1[] = "";
    char str2[] = "Hello world";
    char str3[] = "goodnight big blue house";

    if( (answer = stringLength2(str1)) != (temp = strlen(str1)) )
    {
        std::cout << "\tFAILED on test: \"\"\n\n\t\t- Answer: " << temp
            << "\n\t\t- Your Answer: " << answer << '\n';
        passed = false;
    }

    if( (answer = stringLength2(str2)) != (temp = strlen(str2)) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"Hello world\"\n\n\t\t- Answer:" << temp
            << "\n\t\t- Your Answer: " << answer << '\n';
    }

    if( (answer = stringLength2(str3)) != (temp = strlen(str3)) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"goodnight big blue house\""
                << "\n\n\t\t- Answer: " << temp
                << "\n\t\t- Your Answer: " << answer << '\n';
    }

    if( passed )
        std::cout << "\tOK\n";
}


static void test_stringsEqual1()
{
    std::cout << "\n* FUNCTION: stringsEqual1\n\n";

    bool passed = true;

    char str1[] = "";
    char str2[] = "a";
    char str3[] = "gotta go fast";
    char str4[] = "gotta go fast.";
    char str5[] = "hello world";
    char str6[] = "hello\nworld";

    if( !stringsEqual1(str1, str1) )
    {
        std::cout << "\tFAILED on test: \"" << str1 << "\", \"" << str1 << "\"\n\n"
                << "\t\t- Answer: true\n\t\t- Your Answer: false" << '\n';

        passed = false;
    }

    if( stringsEqual1(str1, str2) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"" << str1 << "\", \"" << str2 << "\"\n\n"
                << "\t\t- Answer: false\n\t\t- Your Answer: true" << '\n';
    }

    if( !stringsEqual1(str2, str2) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"" << str2 << "\", \"" << str2 << "\"\n\n"
                << "\t\t- Answer: true\n\t\t- Your Answer: false" << '\n';
    }

    if( stringsEqual1(str3, str4) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"" << str3 << "\", \"" << str4 << "\"\n\n"
                << "\t\t- Answer: false\n\t\t- Your Answer: true" << '\n';
    }

    if( stringsEqual1(str5, str6) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"" << str5 << "\", \"hello\\nworld\"\n\n"
                << "\t\t- Answer: false\n\t\t- Your Answer: true" << '\n';
    }

    if( passed )
        std::cout << "\tOK\n";
}


static void test_stringsEqual2()
{
    std::cout << "\n* FUNCTION: stringsEqual2\n\n";

    bool passed = true;

    char str1[] = "";
    char str2[] = "a";
    char str3[] = "gotta go fast";
    char str4[] = "gotta go fast.";
    char str5[] = "hello world";
    char str6[] = "hello\nworld";

    if( !stringsEqual2(str1, str1) )
    {
        std::cout << "\tFAILED on test: \"" << str1 << "\", \"" << str1 << "\"\n\n"
                << "\t\t- Answer: true\n\t\t- Your Answer: false" << '\n';

        passed = false;
    }

    if( stringsEqual2(str1, str2) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"" << str1 << "\", \"" << str2 << "\"\n\n"
                << "\t\t- Answer: false\n\t\t- Your Answer: true" << '\n';
    }

    if( !stringsEqual2(str2, str2) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"" << str2 << "\", \"" << str2 << "\"\n\n"
                << "\t\t- Answer: true\n\t\t- Your Answer: false" << '\n';
    }

    if( stringsEqual2(str3, str4) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"" << str3 << "\", \"" << str4 << "\"\n\n"
                << "\t\t- Answer: false\n\t\t- Your Answer: true" << '\n';
    }

    if( stringsEqual2(str5, str6) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"" << str5 << "\", \"hello\\nworld\"\n\n"
                << "\t\t- Answer: false\n\t\t- Your Answer: true" << '\n';
    }

    if( passed )
        std::cout << "\tOK\n";
}


static void test_copyString()
{
    std::cout << "\n* FUNCTION: copyString\n\n";

    bool passed = true;
    bool not_nt;

    char str1[] = "";
    char str1_cpy[8];
    char str2[] = "hello world";
    char str2_cpy[16];
    char str3[] = "frankly my dear, I don't give a gosh diggity doo.";
    char str3_cpy[64];

    copyString(str1, str1_cpy);
    if( (not_nt = str1_cpy[strlen(str1)] != '\0') || strcmp(str1, str1_cpy) != 0 )
    {
        std::cout << "\tFAILED on test: \"" << str1 << "\"\n\n";

        if( not_nt )
            std::cout << "\t\tCopied string is not null-terminated!\n";

        else
            std::cout << "\t\t- Original: " << str1 << '\n'
                << "\t\t- Your Copy: " << str1_cpy << '\n';

        passed = false;
    }

    copyString(str2, str2_cpy);
    if( (not_nt = str2_cpy[strlen(str2)] != '\0') || strcmp(str2, str2_cpy) != 0 )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"" << str2 << "\"\n\n";

        if( not_nt )
            std::cout << "\t\tCopied string is not null-terminated!\n";

        else
            std::cout << "\t\t- Original: " << str2 << '\n'
                << "\t\t- Your Copy: " << str2_cpy << '\n';
    }

    copyString(str3, str3_cpy);
    if( (not_nt = str3_cpy[strlen(str3)] != '\0') || strcmp(str3, str3_cpy) != 0 )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"" << str3 << "\"\n\n";

        if( not_nt )
            std::cout << "\t\tCopied string is not null-terminated!\n";

        else
            std::cout << "\t\t- Original: " << str3 << '\n'
                << "\t\t- Your Copy: " << str3_cpy << '\n';
    }

    if( passed )
        std::cout << "\tOK\n";
}


static void test_stringToInteger()
{
    std::cout << "\n* FUNCTION: stringToInteger\n\n";

    bool passed = true;
    int atoiout, answer;

    char int1[] = "0";
    char int2[] = "-0";
    char int3[] = "9";
    char int4[] = "-25";
    char int5[] = "5525";
    char int6[] = "152737";

    if( (answer = stringToInteger(int1)) != (atoiout = atoi(int1)) )
    {
        std::cout << "\tFAILED on test: \"" << int1 << "\"\n\n"
            << "\t\t- Answer: " << atoiout << '\n'
            << "\t\t- Your Answer: " << answer << '\n';

        passed = false;
    }

    if( (answer = stringToInteger(int2)) != (atoiout = atoi(int2)) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"" << int2 << "\"\n\n"
            << "\t\t- Answer: " << atoiout << '\n'
            << "\t\t- Your Answer: " << answer << '\n';
    }

    if( (answer = stringToInteger(int3)) != (atoiout = atoi(int3)) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"" << int3 << "\"\n\n"
            << "\t\t- Answer: " << atoiout << '\n'
            << "\t\t- Your Answer: " << answer << '\n';
    }

    if( (answer = stringToInteger(int4)) != (atoiout = atoi(int4)) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"" << int4 << "\"\n\n"
            << "\t\t- Answer: " << atoiout << '\n'
            << "\t\t- Your Answer: " << answer << '\n';
    }

    if( (answer = stringToInteger(int5)) != (atoiout = atoi(int5)) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"" << int5 << "\"\n\n"
            << "\t\t- Answer: " << atoiout << '\n'
            << "\t\t- Your Answer: " << answer << '\n';
    }

    if( (answer = stringToInteger(int6)) != (atoiout = atoi(int6)) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"" << int6 << "\"\n\n"
            << "\t\t- Answer: " << atoiout << '\n'
            << "\t\t- Your Answer: " << answer << '\n';
    }

    if( passed )
        std::cout << "\tOK\n";
}


static void test_countBits()
{
    std::cout << "\n* FUNCTION: countBits\n\n";

    bool passed = true;
    int answer;

    if( (answer = countBits(0)) != 0 )
    {
        std::cout << "\tFAILED on test: \"0\"\n\n"
            << "\t\t- Answer: 0\n"
            << "\t\t- Your Answer: " << answer << '\n';

        passed = false;
    }

    if( (answer = countBits(1)) != 1 )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"1\"\n\n"
            << "\t\t- Answer: 1\n"
            << "\t\t- Your Answer: " << answer << '\n';
    }

    if( (answer = countBits(32)) != 1 )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"32\"\n\n"
            << "\t\t- Answer: 1\n"
            << "\t\t- Your Answer: " << answer << '\n';
    }

    if( (answer = countBits(23)) != 4 )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"23\"\n\n"
            << "\t\t- Answer: 4\n"
            << "\t\t- Your Answer: " << answer << '\n';
    }

    if( (answer = countBits(63)) !=  6)
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test: \"63\"\n\n"
            << "\t\t- Answer: 6\n"
            << "\t\t- Your Answer: " << answer << '\n';
    }

    if( passed )
        std::cout << "\tOK\n";
}


static void test_isPowerOfTwo()
{
    std::cout << "\n* FUNCTION: isPowerOfTwo\n\n";

    bool passed = true;

    if( isPowerOfTwo(0) )
    {
        std::cout << "\tFAILED on test \"0\""
            << "\t\t- Answer: false\n"
            << "\t\t- Your Answer: true\n";

        passed = false;
    }

    if( !isPowerOfTwo(1) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test \"1\"\n\n"
            << "\t\t- Answer: true\n"
            << "\t\t- Your Answer: false\n";
    }

    if( !isPowerOfTwo(64) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test \"64\"\n\n"
            << "\t\t- Answer: true\n"
            << "\t\t- Your Answer: false\n";
    }

    if( isPowerOfTwo(27) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test \"27\"\n\n"
            << "\t\t- Answer: false\n"
            << "\t\t- Your Answer: true\n";
    }

    if( !isPowerOfTwo(256) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test \"256\"\n\n"
            << "\t\t- Answer: true\n"
            << "\t\t- Your Answer: false\n";
    }

    if( passed )
        std::cout << "\tOK\n";
}


int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

typedef void (*sortFunction) (int [], int);

static void test_sort(sortFunction f)
{
    std::cout << "\n* FUNCTION: ";

    if( f == bubbleSort)
        std::cout << "bubbleSort";
    else if( f == selectionSort)
        std::cout << "selectionSort";
    else if( f == insertionSort)
        std::cout << "insertionSort";
    else
        std::cout << "mergeSort";

    std::cout << "\n\n";

    srand(25);
    bool passed = true;
    int randnum;
    char buf[16];

    int array1[1] = {5};
    int array1_sln[1] = {5};
    int array2[5] = {1, 2, 3, 4, 5};
    int array2_sln[5] = {1, 2, 3, 4, 5};
    int array3[5] = {5, 4, 3, 2, 1};
    int array3_sln[5] = {1, 2, 3, 4, 5};
    int array4[20];
    int array4_sln[20];

    std::string array4_str("[");

    for(int i = 0; i < 20; i++) {
        array4[i] = (randnum = rand() % 150);
        array4_sln[i] = randnum;

        if( i > 0 )
            array4_str += ", ";
        sprintf(buf, "%d", array4[i]);
        array4_str += buf;
    }

    array4_str += "]";

    qsort(array4_sln, 20, sizeof(int), compare);

    f(array1, 1);
    if( memcmp(array1, array1_sln, sizeof(array1)) != 0 )
    {
        std::string answer("[");

        sprintf(buf, "%d", array1[0]);
        answer += buf;
        for(int i = 1; i < sizeof(array1)/sizeof(int); i++) {
            sprintf(buf, "%d", array1[i]);
            answer += ", ";
            answer += buf;
        }   answer += "]";

        std::cout << "\tFAILED on test [6]\n\n"
            << "\t\t- Your Answer: " << answer << '\n';

        passed = false;
    }

    f(array2, 5);
    if( memcmp(array2, array2_sln, sizeof(array2)) != 0 )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::string answer("[");

        sprintf(buf, "%d", array2[0]); answer += buf;
        for(int i = 1; i < sizeof(array2)/sizeof(int); i++) {
            sprintf(buf, "%d", array2[i]);
            answer += ", ";
            answer += buf;
        }   answer += "]";

        std::cout << "\tFAILED on test [1, 2, 3, 4, 5]\n\n"
            << "\t\t- Your Answer: " << answer << '\n';
    }

    f(array3, 5);
    if( memcmp(array3, array3_sln, sizeof(array3)) != 0 )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::string answer("[");

        sprintf(buf, "%d", array3[0]); answer += buf;
        for(int i = 1; i < sizeof(array3)/sizeof(int); i++) {
            sprintf(buf, "%d", array3[i]);
            answer += ", ";
            answer += buf;
        }   answer += "]";

        std::cout << "\tFAILED on test [5, 4, 3, 2, 1]\n\n"
            << "\t\t- Your Answer: " << answer << '\n';
    }

    f(array4, 20);
    if( memcmp(array4, array4_sln, sizeof(array4)) != 0 )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::string answer("[");

        sprintf(buf, "%d", array4[0]); answer += buf;
        for(int i = 1; i < sizeof(array4)/sizeof(int); i++) {
            sprintf(buf, "%d", array4[i]);
            answer += ", ";
            answer += buf;
        }   answer += "]";

        std::cout << "\tFAILED on test " << array4_str << "\n\n"
            << "\t\t- Your Answer: " << answer << '\n';
    }

    if( passed )
        std::cout << "\tOK\n";
}


static void test_binarySearch()
{
    std::cout << "\n* FUNCTION: binarySearch\n\n";

    bool passed = true;

    int array[16] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 22, 33, 44, 55, 66, 77, 580};
    int size = 16;

    std::cout << "\tINPUT: [1, 3, 5, 7, 9, 12, 14, 16, 18, 22, 33, 44, 55, 66, 77, 580]\n\n";

    if( binarySearch(array, size, 0) )
    {
        std::cout << "\tFAILED on test \"0\"\n\n"
            << "\t\t- Answer: false\n\t\t- Your Answer: true\n";

        passed = false;
    }

    if( !binarySearch(array, size, array[0]) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test \"" << array[0] << "\"\n\n"
            << "\t\t- Answer: true\n\t\t- Your Answer: false\n";
    }

    if( !binarySearch(array, size, array[size - 1]) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test \"" << array[size - 1] << "\"\n\n"
            << "\t\t- Answer: true\n\t\t- Your Answer: false\n";
    }

    if( !binarySearch(array, size, array[(size/2) + 1]) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test \"" << array[(size/2) + 1] << "\"\n\n"
            << "\t\t- Answer: true\n\t\t- Your Answer: false\n";
    }

    if( !binarySearch(array, size, array[(size*3)/4]) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test \"" << array[(size*3)/4] << "\"\n\n"
            << "\t\t- Answer: true\n\t\t- Your Answer: false\n";
    }

    if( binarySearch(array, size, 20) )
    {
        if(!passed) std::cout << '\n'; else passed = false;

        std::cout << "\tFAILED on test \"20\"\n\n"
            << "\t\t- Answer: false\n\t\t- Your Answer: true\n";
    }

    if( passed )
        std::cout << "\tOK\n";
}


static void test_bipBop()
{
    std::cout << "\n* FUNCTION: bipBop\n\n"
        << "\tThis function requires manual testing."
        << "\n\n\t\t-Input: 45\n\n\t\t- Output:\n\n";

    bipBop(45);

    std::cout << "\n\n\t*** End 'bipBop' Output ***\n";
}


static void test_countCalls()
{
    std::cout << "\n* FUNCTION: countCalls\n\n";

    bool passed = true;
    int ret;

    if( (ret = countCalls()) != 1 )
    {
        std::cout << "\tFAILED\n\n"
            << "\t\t- Called: 1 time\n"
            << "\t\t- Returned: " << ret << '\n';

        passed = false;
    }

    if( passed && (ret = countCalls()) != 2 )
    {
        std::cout << "\tFAILED\n\n"
            << "\t\t- Called: 2 times\n"
            << "\t\t- Returned: " << ret << '\n';

        passed = false;
    }

    for(int i = 1; i <= 48; i++)
        ret = countCalls();

    if( passed && ret != 50 )
    {
        std::cout << "\tFAILED\n\n"
            << "\t\t- Called: 50 times\n"
            << "\t\t- Returned: " << ret << '\n';

        passed = false;
    }

    if( passed )
        std::cout << "\tOK\n";
}


static void test_breakingTheLaw()
{
    std::cout << "\n* FUNCTION: breakingTheLaw\n\n"
        << "\tThis function requires manual testing.\n";
}


void runSingleTest(const std::string& id)
{
    std::cout << "Running test for '" << id << "'...\n";

    if(id == "helloWorld") test_helloWorld();
    else if(id == "helloFilesystem") test_helloFilesystem();
    else if(id == "printArray1") test_printArray1();
    else if(id == "printArray2") test_printArray2();
    else if(id == "stringLength1") test_stringLength1();
    else if(id == "stringLength2") test_stringLength2();
    else if(id == "stringsEqual1") test_stringsEqual1();
    else if(id == "stringsEqual2") test_stringsEqual2();
    else if(id == "copyString") test_copyString();
    else if(id == "stringToInteger") test_stringToInteger();
    else if(id == "countBits") test_countBits();
    else if(id == "isPowerOfTwo") test_isPowerOfTwo();
    else if(id == "bubbleSort") test_sort(bubbleSort);
    else if(id == "selectionSort") test_sort(selectionSort);
    else if(id == "insertionSort") test_sort(insertionSort);
    else if(id == "mergeSort") test_sort(mergeSort);
    else if(id == "binarySearch") test_binarySearch();
    else if(id == "bipBop") test_bipBop();
    else if(id == "countCalls") test_countCalls();
    else if(id == "breakingTheLaw") test_breakingTheLaw();

    else
        std::cout << "... No function named '" << id << "'.";

    std::cout << std::endl;
}


void runAllTests()
{
    std::cout << "Running all " << NUM_PROBS << " tests...\n";
    test_helloWorld();
    test_helloFilesystem();
    test_printArray1();
    test_printArray2();
    test_stringLength1();
    test_stringLength2();
    test_stringsEqual1();
    test_stringsEqual2();
    test_copyString();
    test_stringToInteger();
    test_countBits();
    test_isPowerOfTwo();
    test_sort(bubbleSort);
    test_sort(selectionSort);
    test_sort(insertionSort);
    test_sort(mergeSort);
    test_binarySearch();
    test_bipBop();
    test_countCalls();
    test_breakingTheLaw();
    std::cout << std::endl;
}