#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long int gcd_fast(long long int a,long long int b){
  if(b==0) return a;
  
  return gcd_fast(b,a%b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
