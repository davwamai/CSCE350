#include <iostream>

int gcdConsecutiveInteger(int a, int b) {
    // Find the smallest number
    int smallest = (a < b) ? a : b; // if a < b, return a, else return b

    for (int i = smallest; i >= 1; --i) { // Start from smallest number and go down to 1
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }

    return 1; 
}

int main() {
    int num1, num2;

    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    int result = gcdConsecutiveInteger(num1, num2);
    std::cout << "The GCD of " << num1 << " and " << num2 << " is: " << result << std::endl;

    return 0;
}
