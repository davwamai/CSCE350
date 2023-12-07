#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <sys/stat.h>

using namespace std;
using namespace std::chrono;

int medianOfThree(int left, int right, vector<float>& arr) {
    int mid = left + (right - left) / 2;
    if (arr[left] > arr[mid])
        swap(arr[left], arr[mid]);
    if (arr[left] > arr[right])
        swap(arr[left], arr[right]);
    if (arr[mid] > arr[right])
        swap(arr[mid], arr[right]);
    return mid;
}

void quickSort(vector<float>& arr, int left, int right) {
    if (left < right) {
        int pivotIndex = medianOfThree(left, right, arr);
        swap(arr[pivotIndex], arr[right]);  
        float pivot = arr[right];
        int i = left;

        for (int j = left; j < right; j++) {
            if (arr[j] <= pivot) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[right]);

        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }
}

 int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <inputfile> <outputfile>" << endl;
        return 1;
    }

    const string outputDir = "output_files/";
    const string timeDir = "time_files/";
    mkdir(outputDir.c_str(), 0777);
    mkdir(timeDir.c_str(), 0777);
    
    string arg2 = argv[2];
    string inputFile = argv[1];
    string outputFile = outputDir + argv[2];  
    string notxt = arg2.substr(0, arg2.size() - 4); 
    string timeFile = timeDir + notxt + "_time.txt"; 

    ifstream in(inputFile);
    ofstream out(outputFile);
    ofstream timeOut(timeFile);

    if (!in) {
        cerr << "Error opening input file: " << inputFile << endl;
        return 1;
    } 
    if (!out) {
        cerr << "Error opening output file: " << outputFile << endl;
        return 1;
    }

    if (!in || !out) {
        cerr << "File could not be opened." << endl;
        return 1;
    }

    vector<float> numbers;
    float number;

    while (in >> number) {
        numbers.push_back(number);
    }

    auto start = high_resolution_clock::now();

    quickSort(numbers, 0, numbers.size() - 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    for (float num : numbers) {
        out << num << " ";
    }

    timeOut << duration.count() << " microseconds";

    in.close();
    out.close();
    timeOut.close();

    return 0;
}
