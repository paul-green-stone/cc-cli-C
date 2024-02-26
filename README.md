# cc-cli-C ㊙️

Caesar Cipher command line program written in C. Encrypt and decrypt messages using the classic Caesar Cipher algorithm. Easy to use and perfect for learning the basics of cryptography. To get more information, visit the [Caesar cipher](https://en.wikipedia.org/wiki/Caesar_cipher) page.

The Caesar Cipher command-line tool is designed specifically for working with the English alphabet, utilizing an ASCII table for encryption and decryption.

## 🛠️ Usage

### 1️⃣ Encrypting
Upon launching the application, you are automatically placed in an interactive mode with the default key set to 0. In this mode, any text entered by the user will be immediately echoed without altering the original input.

To customize the encryption or decryption process, you must provide the option to specify a different key via the `-k` flag followed by a numerical value. For example, `-k3` or `-k 3` would result in shifting each character three positions forward in the alphabet.

Please note that specifying keys larger than the size of the alphabet (26 in the case of English) has no effect on the encryption or decryption process; these values will be reduced modulo 26 before being applied.

### 2️⃣ Decrypting 

In addition to encoding, the application supports decryption functionality through the usage of the `-d` flag. When used, the program reverses the effects of the previously applied shift, returning the original plaintext. Similar to the encoding process, when decrypting, the key must be explicitly provided using the `-k`.

### 3️⃣ File Encryption and Decryption

The application also supports file encryption and decryption capabilities. To encrypt a file, you must specify the `-i` flag followed by the path to the input file. By default, the output file name is set to `out.txt`. However, you can customize the output file name by specifying the `-o` flag followed by the desired output file name.

Additionally, you can specify a key to use for encryption or decryption by using the `-k` flag followed by a numerical value. If no key is specified, the default key of 0 will be used. To specify the action to be taken, whether to encrypt or decrypt, use the flag `-d` flag for decryption.

For example, to encrypt a file named `input.txt` with a key of 5 and output it to a file named `output.txt`, you would use the following command:

```Bash
./hcc -i input.txt -o output.txt -k 5
```

## 📝 Summary

```usage
-k          key to use in encryption or decryption
-d          switch to decryption

-i          input file name
-o          output file name (out.txt by default)
```
