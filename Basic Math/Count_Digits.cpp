#include <iostream>

int main()
{
    int a, b;

    // Reads two integers from input.txt
    if (std::cin >> a >> b)
    {
        int sum = a + b;
        // Writes the result to output.txt
        std::cout << "The sum of " << a << " and " << b << " is: " << sum << std::endl;
    }
    else
    {
        std::cout << "Error: Could not read numbers from input." << std::endl;
    }

    return 0;
}