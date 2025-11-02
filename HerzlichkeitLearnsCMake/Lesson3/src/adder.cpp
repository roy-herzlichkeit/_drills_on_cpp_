#include "adder.h"

int HZLCM::adder(int a, int b) {
    return a + b;
}

char HZLCM::adder(char a, char b) {
    int sum = (int)(a - 'a') + (int)(b - 'a');
    sum = ((sum % 26) + 26) % 26;
    return static_cast<char>(sum + 'a');
}