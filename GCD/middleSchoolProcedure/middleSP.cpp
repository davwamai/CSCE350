#include <iostream>

void primeFactors(int n, int factors[], int& count) {
    count = 0;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors[count++] = i;
            n /= i;
        }
    }
    if (n > 1) {
        factors[count++] = n;
    }
}

int MiddleSchool(int a, int b) {
    int factorsA[100], factorsB[100];
    int countA = 0, countB = 0;

    primeFactors(a, factorsA, countA);
    primeFactors(b, factorsB, countB);

    int gcd = 1;
    int i = 0, j = 0;
    while (i < countA && j < countB) {
        if (factorsA[i] == factorsB[j]) {
            gcd *= factorsA[i];
            i++;
            j++;
        } else if (factorsA[i] < factorsB[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    return gcd;
}

int main() {
    int num1, num2;

    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    int result = MiddleSchool(num1, num2);
    std::cout << "The GCD of " << num1 << " and " << num2 << " is: " << result << std::endl;

    return 0;
}
