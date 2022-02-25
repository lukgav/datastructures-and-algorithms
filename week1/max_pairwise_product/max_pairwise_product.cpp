#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<long long>& numbers) {
    long long max_product = 0;
    long long n = numbers.size();

    for (long long first = 0; first < n; ++first) {
        for (long long second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }
    return max_product;
}

long long NewMaxPairwiseProduct(const std::vector<long long>& numbers) {
    long long n = numbers.size();
    long long max_index = 0;
    long long second_max_index = 0;
    // find max value in a vector
    for (int i = 0; i<n; i++) {
        if(numbers[max_index] <= numbers[i]){
            max_index = i;
            // std::cout << "Max Value: " << numbers[max_index]<< "\n";
        }
    }

    for (int j = 0; j<n; j++) {
        if(numbers[second_max_index] >= numbers[j] || j == max_index){
            continue;
        }
        second_max_index = j;
        // std::cout << "second Max Value: " << numbers[second_max_index] << "\n";
    }
    return ((long long)(numbers[second_max_index])) * numbers[max_index];

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


//STILL WORKING ON THIS: DOES NOT WORK YET
// return several sections of data that can stress  test the MaxPairwise Product
//First: Need to make sure we have the currect data set. 
// std::tuple<int, std::vector> generate_data(std::int vectorSize){

//     //Integer overflow test
//     size = vectorSize

//     //rational numbers

//     //Character input

//     //int test_max_output(){

//     //
//     return vectorSize

// }