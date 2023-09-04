#include <iostream>
#include <vector>

int main(){
    int ret = 0;
    int n, r;

    std::cout << "Enter # of lockers: ";
    std::cin >> n;
    std::cout << "Enter # of passes: ";
    std::cin >> r;

    std::vector<bool> locker(n, false); // init locker container, false = closed

    for(int i = 1; i <= r; i++){
        for(int j = i - 1; j < n; j+= i){ //update j depending on i to determine whether to open/close door
            locker[j] = !locker[j]; //fun little boolean op for vector<bool> i tried on a whim. actually works which is nice. 
        }
    }

    int nOpen = 0;
    for(int i = 0; i < n; i++){
        std::cout << "Locker number " << i+1 << ": " << (locker[i] ? "Open" : "Closed") << std::endl;
        if(locker[i]){
            nOpen++;
        }
    }

    std::cout << "NUmber of lockers open: " << nOpen << std::endl;

    return ret;
}
