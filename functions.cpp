#include "functions.h"

void printFibonacciHelper(unsigned int n, unsigned int a, unsigned int b) {
    if (n == 0)
        return;
    std::cout << a << ' ';
    printFibonacciHelper(n-1, b, a+b);
}

void printFibonacci(unsigned int n) {
    printFibonacciHelper(n, 0, 1);
    std::cout << '\n';
}

void sleepAndPrint() {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Slept for 5 seconds.\n";
}

void inefficientFileWriting(const std::string& filePath) {
    auto start = std::chrono::steady_clock::now();
    while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - start).count() < 3) {
        std::ofstream file(filePath, std::ios::app);
        file << "a";
        file.close();
    }
}

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

void downloadFile(const std::string& url, const std::string& output) {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(output.c_str(),"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
}
