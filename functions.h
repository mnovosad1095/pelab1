// functions.h

#include <chrono>
#include <thread>
#include <fstream>
#include <iostream>
#include <curl/curl.h>

void printFibonacci(unsigned int n);
void sleepAndPrint();
void inefficientFileWriting(const std::string& filePath);
void downloadFile(const std::string& url, const std::string& output);
