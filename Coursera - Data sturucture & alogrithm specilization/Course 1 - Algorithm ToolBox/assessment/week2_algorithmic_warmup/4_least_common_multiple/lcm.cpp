#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;

  return gcd(b, a % b);
}

long long int lcm_fast(long long int a,long long int b){
  return (a*b)/gcd(a,b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
