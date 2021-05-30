# codeTrainer

This is currently a basic executable, but will likely become a library so that executables for different platforms can
easily be made from it.

## Build instructions

This project currenly uses a CMakeLists.txt. Perform the following commands.

```
mkdir build && cd build
cmake ..
make
```

### Mac

To ensure correct compilation, use:

```
cmake .. -D CMAKE_CXX_STANDARD=11
```

## Usage instructions

There are currently a few flags that are available.

```
Usage:

  codeTrainer [options]

Options:

  -h, --help              show this help message

  --test                  test library to ensure validity
  --dictionary            print dictionary of all codes except semaphore
  --semaphore             print dictionary for semaphore

  --code [codes]          select code to practice
  --mode [modes]          select mode to practice

Codes:

  braille
  morse
  nato
  semaphore

Modes:

  encode
  decode

Styles:

  unicode
  ascii
```

The `--test` flag will try encoding and decoding all the letters to ensure that the encoded versions of each letter
match with the decoded versions of the letter. Note that currently this does not check if the encoded version of a
character is correct, only that reencoding that code will return the original character.

The `--dictionary` flag currently prints out each letter, followed by the letter in braille, then morse, then NATO.

The `--semaphore` flag does the same as the `--dictionary` flag as there is no good unicode characters for semaphore
currently. There is only a bodged solution which prints out the two used (of eight possible) positions using Unicode
characters.

The `--code` flag followed by an arguement is to signal what type of code to use the trainer with on the current run. It
needs an argument if the flag is used, otherwise it defaults to braille.

The `--mode` flag followed by an argument is similar to the `--code` flag. It signals if the user wants to encode or
decode. It needs an argument if the flag is used, otherwise it defaults to decode.

The `--style` flag followed by an argument is to choose the characters used to print the encoded characters. For example
braille in unicode prints the actual unicode braille characters, but many fonts do not have these characters, so the
ascii variant prints dots across three lines instead of as a single character. It needs an argument if the flag is used,
otherwise it defaults to unicode.
