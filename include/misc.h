#ifndef misc_h
#define misc_h

#include "highCC.h"

/* ================================================================ */

/**
 * The `interactive_mode` function enables an interactive mode where users can input text.
 * Upon inputting text, the function processes the user's selection and returns the corresponding
 * encoded or decoded string based on the chosen action.
 */
extern void interactive_mode(int key, char* (*what_to_do)(int key, const char* string));

/* ================================ */

/**
 * The `file_encode_mode` function allows users to encode or decode entire text files.
 * The function accepts the path to both the source `in` and destination `out` files.
 * Once executed, the function reads the contents from the specified input file,
 * applies the selected encryption or decryption operation,
 * and writes the processed content to the output file.
 */
extern int file_encode_mode(int key, const char* in, const char* out, char* (*what_to_do)(int key, const char* string));

/* ================================================================ */

#endif /* misc_h */
