#include "rdtsc.h"
#ifdef _WIN32

//  Windows
#define rdtsc  __rdtsc

#else

//  For everything else
unsigned long long rdtsc(){
    unsigned int lo,hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long long)hi << 32) | lo;
}

int randomGen(int low, int high){
    mt19937 random;
    random.seed(rdtsc());
    std::uniform_int_distribution<int> randomNum(low, high);
    return randomNum(random);
}
#endif