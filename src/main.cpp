#include <fstream>
#include <iostream>
#include "ascii.h"

int main(int argc, char *argv[])
{
    std::ifstream input("bombom.txt");
    
    int* ascii = countFrequencies(input);
    
    for (int i = 0; i < 128; ++i) {
        if(ascii[i] != 0){
            char c = i;
            std::cout << c << " " <<  ascii[i] << std::endl; 
        }
    }

    input.close(); 
    return 0;
}
