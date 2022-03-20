#include <iostream>
#include <cassert>
#include <vector>
// #include <limits>

// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.

int fibonacci_naive(int n) {
    
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long long fibonacci_fast(long long n) {

    // letzte_fib_iterator
    long long fMinusTwo = 1LL;
    // aktuell_fib_iterator
    long long fCurrent = 1LL;
    // old_aktuell_fib_iterator
    long long fMinusOne = 1LL;

    if (n <= 1){
        return n;
    }
    else{

        for(long long i=2;i<=n;++i){
                
                // long long y = aktuell_fib_iterator;
                // long long x = letzte_fib_iterator;
                // Check for INteger OVerflow code
                // if ((y >= 0 && x >= 0 && (x > LLP64_MAX - y)) || (y < 0 && x < 0 && (x < INT32_MIN - y)))
                // {
                //     /* Oh no, overflow */
                //     std::cout << "|\n" << i << ": !OVERFLOW ERROR!: " << aktuell_fib_iterator << ' ' <<INT32_MAX << ' ' << INT32_MIN << '|';
                //     break;
                // }
                // else
                // {
                //     long long sum = x + y;
                // }
                // if(old_aktuell_fib_iterator <= 0){
                //     std::cout << "Interger Overflow: "<< i << ": " << aktuell_fib_iterator << " + " << letzte_fib_iterator << " = " << aktuell_fib_iterator <<'\n';
                //     break;
                // }
                // std::cout << i << ": " << fMinusTwo;
                fMinusOne = fCurrent;    
                fCurrent = (fMinusTwo + fMinusOne) % 10;
                fMinusTwo = fMinusOne;

                // std::cout << " + " << fMinusOne << " = " << fCurrent <<'\n';
        }
        // std::cout << '\n';
    }
    return fMinusOne;
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n){
        // std::cout << fibonacci_naive(n) << '\n';
        // std::cout << fibonacci_fast(n) << '\n';
        assert(fibonacci_fast(n) == fibonacci_naive(n));
    }
    std::cout << "Testing DONE"<< '\n';

}

void test_long_long(){
    long long x = 1000000000LL*99999;
    std::cout << x;
}

int main() {
    long long n = 0;
    std::cin >> n;
    // fibonacci_fast(n);
    // std::cout << fibonacci_naive(n) << '\n';
    std::cout << fibonacci_fast(n) << '\n';

    // test_long_long()
    // test_solution();
    return 0;
}


// write your code here

//Pseudo code:
//Method 1:  
// Use Formula with (1/sqrt(5))*((pow((1+sqrt(5))/2), n)*(pow((1+sqrt(5))/2), n))

//Method 2: 
// Benutz ein dynamic fibonacci_array
//fib_arr[int] =
//for loop to populate the array with fibonnaci iterator
//Brauchen eins mit ersten Wert und der naechste mit dem vorherige Wert.
//return last element in fibbonnaci array. That should be the last value for the array 

// long fib_arr[0];
// std::vector<long long> fib_arr;
// fib_arr.push_back(0);
// fib_arr.push_back(1);

// // if (i=0)
// //         fib_arr.push_back(0);
// //         continue;
// //------ TESTING CODE
// // std::cout << "Aktuell Bevor: "<<aktuell_fib_iterator << '\n';
// // std::cout << "Letzte Bevor: "<<letzte_fib_iterator << '\n';
// // fib_arr.push_back(aktuell_fib_iterator);
// old_aktuell_fib_iterator = aktuell_fib_iterator;
// aktuell_fib_iterator = letzte_fib_iterator + aktuell_fib_iterator;
// letzte_fib_iterator = old_aktuell_fib_iterator;


// //------ TESTING CODE
// // std::cout << "Aktuell: "<<aktuell_fib_iterator << '\n';
// // std::cout << "Letzte: "<<letzte_fib_iterator << '\n';
// // aktuell_fib_iterator = neue_fib_iterator;
// // fib_arr.push_back(neue_fib_iterator);
// // // std::cout << fibonacci_naive(fib_arr[i]) << '\n';
// // std::cout << "New fibbonacci num:  " << fib_arr[i] << '\n';
// // std::cout << "-----------------------" << '\n';

// //------ TESTING CODE: Check every elementin array
// // for(long long i: fib_arr){
// //     std::cout << i << ' ';
// // }
// // std::cout << '\n';

// // This doe snot work for vectors
// // int arrSize = sizeof(fib_arr)/sizeof(fib_arr[0]);
// // std::cout <<  "Array Size: "<< arrSize << '\n';

// //     for (int i=0;i<arrSize;i++)
// //         std::cout << fib_arr[i] << '\t';
// //     std::cout << '\n';
