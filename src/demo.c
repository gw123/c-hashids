#include <hashids.h>
#include <stdio.h>
#include <string.h>

int main() {
    hashids_t *hashids;
    const char *salt = "123456";
    size_t min_length = 30;

    //hashids = hashids_init(NULL);
    //hashids = hashids_init2(salt, min_length);
    hashids = hashids_init3(salt, min_length, HASHIDS_DEFAULT_ALPHABET);

    size_t bytes_encoded;
    char hash[512];
    bzero(hash, sizeof(hash));
    unsigned long long numbers[] = {1ull};
    bytes_encoded = hashids_encode(hashids,
                                   hash,
                                   sizeof(numbers) / sizeof(unsigned long long),
                                   numbers);
    printf("hash1 hashdis result: %s \n", hash);

    bzero(hash, sizeof(hash));
    unsigned long long numbers2[] = {3ull, 1ull, 3ull, 1ull};
    bytes_encoded = hashids_encode(hashids,
                                   hash,
                                   sizeof(numbers2) / sizeof(unsigned long long),
                                   numbers2);
    printf("hash2 hashdis result: %s \n", hash);
    //
    hashids_free(hashids);
}