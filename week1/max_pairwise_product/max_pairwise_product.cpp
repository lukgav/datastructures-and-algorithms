#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

int MaxPairwiseProduct(const std::vector<long long>& numbers) {
    long long max_product = 0;
    long long n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            if ((long long)(numbers[first]) * numbers[second] > max_product)
                max_product = (long long)numbers[first] * numbers[second];
        }
    }

    return max_product;
}


long long MaxPairwiseProductFast(const std::vector<long long>& numbers) {
    long long n = numbers.size();
    long long max_index1 = -1;
    // find max value in a vector
    for (int i=0; i<n; i++) {
        if((max_index1 == -1) || numbers[i] > numbers[max_index1])
            max_index1 = i;
            // std::cout << "Max Value: " << numbers[max_index1]<< "\n";

    }

    long long max_index2 = -1;
    for (int j = 0; j<n; j++) {
        if( numbers[j] != numbers[max_index1] && ((max_index2 == -1) || numbers[j] > numbers[max_index2]))
            max_index2 = j;
        // std::cout << "second Max Value: " << numbers[max_index2] << "\n";
    }
    return (((long long) numbers[max_index2]) * numbers[max_index1]);

}


//Simplify the above problem function: 
// 1. we want to test the function so lets make a tes_function
// 2. Lets generate some SIMPLE inputs to test the function.
// 3. Play around with some ideas of what we should test with SIMPLE INPUTS. 
// 4. Play with one idea at a time....
int test_integer_overflow(){

    //Integer overflow test
    int size = 2;
    long long firstElement;
    long long secondElement;
    std::vector<long long> numbers(size);

    firstElement = 100000;
    secondElement = 90000;
    numbers[0] = firstElement;
    numbers[1] = secondElement;

    std::cout << "Actual Value: " << MaxPairwiseProduct(numbers) << "\n";

    std::cout << std::fixed<<"Expeceted Value: " << firstElement*secondElement << "\n";

    return 0;

}

int stress_test(){
    while(true) {
        int n= rand() % 10 + 2; 
        std::cout << n << "\n";
        std::vector<long long> a;
        for (int i=0; i<n; ++i){
            a.push_back(rand() % 100000);
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

// have a run all tests procedure

int test_all(){
 test_integer_overflow();
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
    while(true) {
        int n = rand() % 10 + 2; 
        std::cout << n << "\n";
        std::vector<long long> a;
        for (int i=0; i<n; ++i){
            a.push_back(rand() % 100000);
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


    long long n;
    std::cin >> n;  
    std::vector<long long> numbers(n);
    for (long long i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    // std::cout << MaxPairwiseProductFast(numbers) << "\n";
    // std::cout << NewMaxPairwiseProduct(std::vector<long long>(10000, 0)) << "\n";
    std::cout << MaxPairwiseProductFast(std::vector<long long>(3, 3)) << "\n";

    // std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}