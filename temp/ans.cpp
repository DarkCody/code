/*
Có n bạn nam và m bạn nữ tham gia một lễ hội ở vùng quê. Họ được sắp xếp thành một vòng tròn bao quanh lửa trại. Để các bạn nữ tập trung làm quen với các bạn nam, người tổ chức muốn sắp xếp các chỗ sao cho giữa hai bạn nữ bất kỳ đều có tối thiểu 2 bạn nam. Hãy giúp người tổ chức đếm số cách sắp xếp thỏa mãn.

Đầu vào
Một dòng duy nhất chứa hai số nguyên n và m(n <= 1e9 và m <= 1e9).
Đầu ra
Một số nguyên duy nhất là số cách sắp xếp thỏa mãn theo modulo 1e9 + 7.
Ví dụ
Input	Output
5 2   240
15 6	691447003
*/

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

// Function to compute modular exponentiation
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to compute factorial % MOD
long long factorial(long long x) {
    if (x == 0 || x == 1) return 1;
    long long result = 1;
    for (long long i = 2; i <= x; ++i) {
        result = (result * i) % MOD;
    }
    return result;
}

// Function to compute modular inverse of x % MOD
long long mod_inv(long long x) {
    return mod_pow(x, MOD - 2, MOD);
}

// Function to compute binomial coefficient C(n, k) % MOD
long long binomial_coefficient(long long n, long long k) {
    if (k > n) return 0;
    long long num = factorial(n);
    long long denom = (factorial(k) * factorial(n - k)) % MOD;
    return (num * mod_inv(denom)) % MOD;
}

long long count_arrangements(long long n, long long m) {
    if (n < 2 * (m - 1)) {
        return 0;
    }

    // Compute (n-1)! % MOD
    long long perm_males = factorial(n - 1);

    // Compute binomial coefficient C(n, m) % MOD
    long long ways_to_place_females = binomial_coefficient(n, m);

    // Calculate the number of valid arrangements
    return (perm_males * ways_to_place_females) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;

    cout << count_arrangements(n, m) << endl;

    return 0;
}

