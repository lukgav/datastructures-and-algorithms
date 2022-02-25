#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<long long>& numbers) {
    long long max_product = 0;
    long long n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            if ((long long)(numbers[first]) * numbers[second] > max_product)
                max_product = (long long)numbers[first] * numbers[second];
        }
        // std::cout << "Max Value: " << numbers[second]<< "\n";
    }

    return max_product;
}


long long MaxPairwiseProductFast(const std::vector<long long>& numbers) {
    long long n = numbers.size();
    long long max_index1 = -1;
    // find max value in a vector
    for (int i=0; i<n; ++i) {
        if((max_index1 == -1) || numbers[i] > numbers[max_index1])
            max_index1 = i;
        // std::cout << "Max Value: " << numbers[max_index1]<< "\n";

    }

    long long max_index2 = -1;
    for (int j = 0; j<n; ++j) {
        if( j != max_index1 && ((max_index2 == -1) || numbers[j] > numbers[max_index2]))
            max_index2 = j;
        // std::cout << "second Max Value: " << numbers[max_index2] << "\n";
    }
    return (((long long) numbers[max_index2]) * numbers[max_index1]);
}
int stress_test(){
    while(true) {
        int n= rand() % 10000 + 2; 
        std::cout << n << "\n";
        std::vector<long long> a;
        for (int i=0; i<n; ++i){
            a.push_back(rand() % 100000000000);
        }
        for (int i=0; i<n; ++i){
            std::cout << a[i] << ' ';
        }
        std::cout << "\n";
        long long res1 = MaxPairwiseProduct(a);
        long long res2 = MaxPairwiseProductFast(a);

        if(res1 != res2){
            std::cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
            break;
        }
        else
            std::cout << "OK\n";
    }
    return 0;
}

int original_main(){
    long long n;
    std::cin >> n;  
    std::vector<long long> numbers(n);
    for (long long i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}

int main() {
    stress_test();

    long long n;
    std::cin >> n;  
    std::vector<long long> numbers(n);
    for (long long i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    // std::cout << NewMaxPairwiseProduct(std::vector<long long>(10000, 0)) << "\n";
    // std::cout << MaxPairwiseProductFast(std::vector<long long>(3, 3)) << "\n";

    // std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}