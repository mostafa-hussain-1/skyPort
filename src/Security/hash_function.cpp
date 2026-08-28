#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<random>
#include"include/hash_function.h"

using namespace std;
const long long mod = 1000000000000LL;
long long hashing(string password, int magic);

int magic() {
    static mt19937 rng(time(0));

    static uniform_int_distribution<int> dist(10000, 1000000);
    return dist(rng);
}

long long hashing(string password, int magic) {

    unsigned long long result = 1;
    for (char c : password)
    {
        result = ((result * magic) + c) % mod;
    }

    unsigned long long final_hash = result;
    for (int i = 0; i < 10000000; i++)
    {
        long long temp = final_hash;
        int size = 0;
        for (int i = 0; i < 12; i++)
        {
            if (temp > 0) {
                temp % 10;
                temp /= 10;
                size++;
            }
        }
        int current_hash[12];
        for (int j = size - 1; j >= 0; j--)
        {
            current_hash[j] = final_hash % 10;
            final_hash /= 10;
        }

        final_hash = ((current_hash[0] * magic) + current_hash[1]) % mod;
        for (int j = 1; j < size - 1; j++)
        {
            final_hash = (((final_hash % mod) * (magic % mod)) + current_hash[j + 1]) % mod;
        }
    }
    return final_hash;
}