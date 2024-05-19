#include <iostream>
#include <vector>
using namespace std;

long long fibonacci_modulo(long long n, long long m) {
    vector<long long> fib_mod(m * m);

    fib_mod[0] = 0;
    fib_mod[1] = 1;

    for (long long i = 2; i < m * m; ++i) {
        fib_mod[i] = (fib_mod[i-1] + fib_mod[i-2]) % m;

        if (fib_mod[i] == 1 && fib_mod[i-1] == 0) {
            break;
        }
    }

    return fib_mod[n % 60];
}

long long last_digit_sum_of_squares_fibonacci(long long n) {
    long long last_digit_fib_n = fibonacci_modulo(n, 10);
    long long last_digit_fib_n_plus_1 = fibonacci_modulo(n + 1, 10);
    return (last_digit_fib_n * last_digit_fib_n_plus_1) % 10;
}

int main() {
    long long n;
    cin >> n;
    cout << last_digit_sum_of_squares_fibonacci(n) << endl;
    return 0;
}
