#include "functions.h"


int main() {
    printFibonacci(50000);
    sleepAndPrint();

    inefficientFileWriting("test.txt");
    downloadFile("http://212.183.159.230/50MB.zip", "medium.zip");

    return 0;
}
