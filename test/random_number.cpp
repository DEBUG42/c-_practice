#include <iostream>
#include <cstdlib>
#include <ctime>
int main()
{
    srand(time(0)); // seed the random number generator
    for (int i = 0; i < 10; ++i)
    {
        std::cout << rand() % 3 << " "; // generate a random number between 0 and 99
}
    return 0;
}