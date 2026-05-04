#include<cstdlib>
#include<ctime>
#include<string>
#include<chrono>
#include"hash_function.h"
using namespace std;


long long hashing (string password, int magic){

    long long result = ((password[0] * magic) + password[1]) % mod;
    for (int i = 1; i < password.size() - 1; i++)
    {
        result = (((result % mod) * (magic % mod)) + password[i + 1]) % mod;
    }

    long long final_hash = result;
    for (int i = 0; i < 10000000; i++)
    {
	    long long temp = final_hash;
	    int size = 0;
        for (int i = 0; i < 12; i++)
        {
            if (temp > 0) {
				temp /= 10;
				size++;
            }
        }
        int current_hash [12];
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