#include "testing.hpp"

int main(int argc, char *argv[])
{
    (argc > 1) ? runSingleTest(argv[1]) : runAllTests();
}