#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
  int current_gcd = 1;
  int remainder = 1;

  //1. compare a and b.
  //2. Divide smaller of the two into the other. 
  // If remainder!=0:
  //   call fast_gcd with a=b and b=remainder
  // if remainder = 0
  //    gcd = latest a
  //3 Repeat the following until remainder = 0

  if(a != 0 and b !=0){
    remainder = a % b;
    current_gcd = gcd_fast(b, remainder);
  }
  else{
    current_gcd = a;
    return current_gcd;
  }
}

// int OLD_gcd_fast(int a, int b) {
//   int current_gcd = 1;
//   int remainder = 1;
//   if(a != 0 and b !=0){
//     while (remainder != 0){
//       if(remainder = a % b != 0){
//         a = b;
//         b = remainder;
//       }
//       else{
//         current_gcd = b;
//       }
//     }
//     return current_gcd;
//   }
//   else{
//     current_gcd = a;
//     std::cout << "Inputs are outside of specifications. Must positive integers greater than 0";
//     return current_gcd;
//   }
//   //1. compare a and b.
//   //2. Divide smaller of the two into the other. 
//   // Then Set a=b and b=remainder
//   //3 Repeat the following until remainder = 0
// }

int stress_test(){

  while(true){
    int a, b;
    std::cin >> a >> b;
    std::cout << "TEST: \n";
    std::cout << gcd_fast(a, b) << std::endl;
  }
  return 0;
}

int main() {
  stress_test();
  // int a, b;
  // std::cin >> a >> b;
  // std::cout << "HELLO";
  // std::cout << gcd_naive(a, b) << std::endl;
  // return 0;
}
