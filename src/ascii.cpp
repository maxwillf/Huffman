#include <fstream>

int * countFrequencies(std::ifstream& input)
{
    int * ascii = new int[128];
    char c;
    while(input >> c){
       ascii[c] +=1; 
    }

    return ascii;
}
