#include "../include/highCC.h"

/* ================================================================ */

char* cc_encode(int key, const char* string) {

    char* output = NULL;
    size_t size;

    if (string == NULL) {
        return output;
    }

    size = strlen(string);

    if ((output = calloc(1, sizeof(char) * size)) == NULL) {
        return output;
    }

    for (size_t i = 0; i < size; i++) {

        // The ASCII table is used in this code.
        // First, we shift each digit to the left by 65 if it is arranged from 'a' to 'z' or from 0 to 25 (for simpler counting).
        // Then, we add a key to the character and divide (modulo) by the number of letters in the alphabet.
        // Finally, we add 65 to get the exact value in the ASCII table.

        if ((*(string + i) >= 65) && (*(string + i) <= 90)) {

            *(output + i) = (((*(string + i) - 65) + key) % 26) + 65;
        }
        else if ((*(string + i) >= 97) && (*(string + i) <= 122)) {

            *(output + i) = (((*(string + i) - 97) + key) % 26) + 97;
        }
        else {
            *(output + i) = *(string + i);
        }
    }

    return output;
}

/* ================================ */

char* cc_decode(int key, const char* string) {

    char* output = NULL;
    size_t size;

    if (string == NULL) {
        return output;
    }

    size = strlen(string);

    if ((output = calloc(1, sizeof(char) * size)) == NULL) {
        return output;
    }

    for (size_t i = 0; i < size; i++) {

        // The ASCII table is used in this code.
        // First, we shift each digit to the left by 90 if it is arranged from 'a' to 'z' or from 0 to 25 (for simpler counting).
        // Then, we subtract a key from the character and divide (modulo) by the number of letters in the alphabet.
        // Finally, we add 90 to get the exact value in the ASCII table.

        if ((*(string + i) >= 65) && (*(string + i) <= 90)) {

            *(output + i) = (((*(string + i) - 90) - key) % 26) + 90;
        }
        else if ((*(string + i) >= 97) && (*(string + i) <= 122)) {

            *(output + i) = (((*(string + i) -122) - key) % 26) + 122;
        }
        else {
            *(output + i) = *(string + i);
        }
    }

    return output;
}
