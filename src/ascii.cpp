#include "ascii.h"

int * countFrequencies(std::ifstream& input)
{
    int * ascii = new int[128];
    char c;
    while(input >> c){
       
       if(ascii[c] == 0) {
       }

       ascii[c] +=1; 
    }
    return ascii;
}

