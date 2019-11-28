#include <hashids.h>
#include <stdio.h>
#include <string.h>

void ByteToHexStr(const unsigned char *source, char *dest, int sourceLen) {
    short i;
    unsigned char highByte, lowByte;
    for (i = 0; i < sourceLen; i++) {
        highByte = source[i] >> 4;
        lowByte = source[i] & 0x0f;

        if (highByte > 9)
            dest[i * 2] = highByte - 10 + 'a';
        else
            dest[i * 2] = highByte;

        if (lowByte > 9)
            dest[i * 2 + 1] = lowByte - 10 + 'a';
        else
            dest[i * 2 + 1] = lowByte;
    }
    return;
}

void ByteToNumber(const unsigned char *source, unsigned long long *dest, int sourceLen) {
    short i;
    unsigned char b;
    for (i = 0; i < sourceLen; i++) {
        b = source[i];
        if (b >= '0' && b <= '9') {
            b -= '0';
        } else if (b >= 'a' && b <= 'z') {
            b -= ('a' - 0xA);
        } else if (b >= 'A' && b <= 'Z') {
            b -= ('A' - 0xA);
        }
        dest[i] = 0x10 + b;
    }
    return;
}

int main() {
    hashids_t *hashids;
    const char *salt = "123456";
    size_t min_length = 30;
    hashids = hashids_init3(salt, min_length, HASHIDS_DEFAULT_ALPHABET);


    size_t bytes_encoded;
    char hash[512];

    bzero(hash, sizeof(hash));

    char *input = "hello world";
    char buf[32];
    unsigned long long numbers[32];
    ByteToHexStr(input, buf, strlen(input));

    ByteToNumber(buf, numbers, strlen(input) * 2);

    bytes_encoded = hashids_encode(hashids, hash, strlen(input) * 2, numbers);
    printf("hash hashdis result: %s \n", hash);
    hashids_free(hashids);

    hashids_encode_hex()
}