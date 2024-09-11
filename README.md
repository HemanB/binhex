# Lab 03

This lab is similar to the encoder/decoder ring in that you write procedures to
translate input lines one at a time for output.  As with the ring program,
`main()` is provided for you, this time in the file `convert.c`. In this lab you
write procedures to translate between representations of integer values as
strings of digits in binary and hexadecimal, in both directions.

## Objectives

- Get familiar with representations of unsigned (positive) integers.
- Understand hexadecimal (base 16) and binary (base 2) number systems.
- Gain experience with the C `switch` statement (if you choose to use it).

---

### Overview

As for previous labs, fork and clone the lab repository to your container.

The main program in `convert.c` handles the details of argument processing and
input from `stdin` and output to `stdout`. Do not modify this program.

You are to fill in the code for two functions in `convert_student.c`:

* `binaryHex()` and 
* `hexBinary()`. 

You can build the program by typing `make` or `make convert`. The `Makefile`
compiles both source files and links them together into an executable program
called `convert`.  You can run it with a line like:

* `./convert -b` to convert binary to hexadecimal by calling `binaryHex()`.
* `./convert -h` to convert hexadecimal to binary by calling `hexBinary()`.

You must provide one of these option switches `-b` or `-h` to specify the input
representation, and which direction to convert.

Note that `convert` follows design conventions for terminal-oriented Unix
(Linux) programs: it reads from `stdin` and writes to `stdout`.  That makes it
easy to redirect input or output to operate on files instead of the terminal.
Or you can pipe the output of one process to the input of another to convert and
then convert back to the original input. For example:

```bash
convert -b <input.txt | convert -h >output.txt
```

Then the input and output files should be identical. For example, the `diff`
command should show no difference (empty output):

```bash
diff input.txt output.txt
```

The `diff` command is a useful utility.  You might want to play around to
familiarize yourself with its style of output. The Gradescope autograder often
uses `diff` to check that your programs produce the expected output. If any part
of the output is unexpected, Gradescope gives you output of the `diff` program
showing you the differences. 

The autograder tests your program only on correct input.  But you should handle
incorrect input gracefully. In this lab, you are to validate that each input
line is legal.  In particular, each line contains only valid digits in hex or
binary, an optional trailing linefeed (`'\n'`), and a null terminator character
at the end (`'\0'`). If you encounter unexpected input, stop processing, leave
the partial output in place, add a null terminator character to the output,
print a message to `stderr`, and return, discarding the rest of the input on
that line.

Take care not to overflow the output buffer.  As with the `ring` program, your
functions receive a parameter with the size in bytes (type `size_t`) of the
input buffer and output buffer, which are the same size.  The output must be
null-terminated in all cases.

---

### `binHex()`

The input for the `binHex()` function is a string of characters `'0'` or `'1'`
representing bits (binary digits). There is no other indicator that the string
represents a binary number.  The input line has an optional linefeed (`'\n'`) as
the last character, which you may ignore.  The input line is null-terminated.

The output for `binHex()` is a string of characters where each character is a
hexadecimal digit. If the input is legal binary, then the output is a
hexadecimal representation of the same integer number value as represented in
binary on the input.    The input and output are both unsigned.  The output must
be null-terminated in all cases.  The output should include no other characters,
e.g., no linefeed.  To make autograding easier, please do not capitalize your
hex digits.

To simplify this problem, testing for input is guaranteed to contain a multiple
of four bits.  Consider why the problem is harder without this assurance, and
how your output might be incorrect if the input contains e.g. an odd number of
bits.  We invite you to handle the more general case: it is a good interview
question or exam question!

Do not use any library routines to assist with the conversion.  Your `binHex()`
function should use a loop to process the input character by character using
simple C code without calls to library routines, except `fprintf(stderr, ...)`
for error cases.

---

### `hexBin()`

The input for `hexBin()` is a string of characters representing hexadecimal
digits.  Where letters are allowable, they may or may not be capitalized.  There
is no other indicator that the string represents a hexadecimal number, e.g., no
`0x` prefix.  The input line has an optional linefeed  (`'\n'`) as the last
character, which you may ignore.  The input line is null-terminated.

The output for `hexBin()` is a string of characters where each character is a
`'0'` or `'1'` representing a bit. If the input is legal hex, then the output is
a binary representation of the same integer number value as represented in
hexadecimal on the input. The input and output are both unsigned. The output
must be null-terminated in all cases. The output should include no other
characters, e.g., no linefeed. 

Do not use any library routines to assist with the conversion.  Your `hexBin()`
function should use a loop to process the input character by character using
simple C code without calls to library routines, except `fprintf(stderr, ...)`
for error cases. 

---

### Local Testing and Submission

1. Run `make` to compile your program. Changing your program's C code will not
   have any effect until you save your changes and recompile/rebuild.

2. Run the local Python test script by running the following on the Unix command
   line:
   ```bash
   python3 test_kit.py ALL
   ```
   If all tests are passing, they should also pass on Gradescope. If a test is
   failing, you can see exactly which one and find its corresponding input file
   in the `tests` folder for further debugging.

   It is important that the output of your program matches exactly what is shown
   in the description above (this are also provided in the
   `tests/*_expected_*.txt` files).

4. Add, commit, and push your file to your git repo:

   * `convert_student.c`

   In future labs, you will be responsible for typing the commands to add,
   commit, and push your files. We still provide you with some command for this
   lab.

   ```bash
   git add convert_student.c
   git commit -m "Finished with the lab."
   git push
   ```

5. Submit your completed lab to Gradescope via the GitLab submission button.
