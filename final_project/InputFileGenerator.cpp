#include <iostream>
#include <fstream>
#include <random>
#include <string>

using namespace std;

void generateFile(int fileIndex, int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(-100, 100);

    string fileName = "input" + to_string(size) + "_" + to_string(fileIndex) + ".txt";
    ofstream file(fileName);

    for (int i = 0; i < size; i++) {
        file << dis(gen) << " ";
    }

    file.close();
}

int main() {
    const int sizes[] = {10, 100, 1000};

    for (int size : sizes) {
        for (int i = 0; i < 25; i++) {
            generateFile(i, size);
        }
    }

    cout << "Input files generated successfully." << endl;
    return 0;
}

