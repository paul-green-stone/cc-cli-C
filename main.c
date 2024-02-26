#include "include/highCC.h"

#include <getopt.h>
#include <unistd.h>
#include <ctype.h>

/* ================================================================ */

int main(int argc, char** argv) {

    extern char *optarg;
    extern int optind, opterr, optopt;

    const char* optstring = ":i:o:k:dh";
    int option;

    /* An operation to perform on input. Encode by default */
    char* (*what_to_do)(int key, const char* string) = cc_encode;

    int key = 0;                /* Encryption/decryption key */
    
    char* in_name = NULL;       /* Input file name */
    char* out_name = NULL;      /* Output file name */

    int mode = 1;               /* Interactive mode by default */

    while ((option = getopt(argc, argv, optstring)) != -1) {

        switch (option) {

            case 'k':

                for (size_t i = 0; *(optarg + i); i++) {
                    if (!isdigit(*(optarg + i))) {
                        break ;
                    }

                    key = strtol(optarg, NULL, 10);
                }

                break ;

            /* ======================== */

            case 'd':

                what_to_do = cc_decode;
                break ;

            /* ======================== */

            case 'o':

                out_name = optarg;
                break ;

            /* ======================== */

            case 'i':
                
                mode = 2;
                in_name = optarg;

                break ;

            /* ======================== */

            case '?':

                printf("Unknown option: -%c\n", optopt);
                break ;

            /* ======================== */

            case ':':

                printf("Missing argument for -%c\n", optopt);
                break ;
        }
    }

    switch (mode) {

        case 2:

            return file_encode_mode(key, in_name, out_name, what_to_do);

            break ;

        /* ======================== */

        default :

            interactive_mode(key, what_to_do);

            break ;
    }

    return EXIT_SUCCESS;
}
