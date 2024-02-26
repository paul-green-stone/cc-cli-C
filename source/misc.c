#include "../include/highCC.h"

/* ================================================================ */

void interactive_mode(int key, char* (*what_to_do)(int key, const char* string)) {

    /* A buffer of predifined size containing a portion of input from the standard input stream */
    char buffer[BUFSIZ];

    /* A dynamically allocated buffer containing modified string */
    char* b = NULL;

    int c = 0, i = 0;

    /* I guess automatic variables is zeroed out */
    for (i = 0; i < BUFSIZ; i++) {
        *(buffer + i) = '\0';
    }

    while (1) {

        i = 0;

        printf("> ");

        while ((c = getchar()) != '\n') {

            if (c == EOF) {
                return ;
            }

            if (i < BUFSIZ) {
                *(buffer + i++) = c;
            }
        }

        buffer[i] = '\0';

        /* Encode or decode the string with the given key. `b` is a dynamically returned string */
        b = what_to_do(key, buffer);

        printf("%s%d => %s\n", (what_to_do == cc_encode) ? "+" : "-", key, b);

        /* Free the previously allocated string to prevent memory leak */
        free(b);
    }

    return ;
}

/* ================================ */

int file_encode_mode(int key, const char* in, const char* out, char* (*what_to_do)(int key, const char* string)) {

    FILE* input = NULL;
    FILE* output = NULL;

    /* The same as for `interactive_mode` */
    char buffer[BUFSIZ];
    char* b = NULL;

    int i;

    for (i = 0; i < BUFSIZ; i++) {
        *(buffer + i) = '\0';
    }

    if (in == NULL) {
        return EXIT_FAILURE;
    }

    if ((input = fopen(in, "rb")) == NULL) {
        return EXIT_FAILURE;
    }

    if ((output = fopen(out ? out : "out.txt", "w")) == NULL) {

        fclose(input);
        return EXIT_FAILURE;
    }

    while (!feof(input)) {

        fread(buffer, BUFSIZ - 1, 1, input);

        b = what_to_do(key, buffer);

        fprintf(output, "%s", b);

        free(b);

        /* Empty the buffer before next read */
        for (i = 0; i < BUFSIZ; i++) {
            *(buffer + i) = '\0';
        }
    }

    fclose(input);
    fclose(output);

    return EXIT_SUCCESS;
}

