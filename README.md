# Huffman

Huffman compression implementation for Basic Data Structures II course we took on
our Computer Science graduation at  Universidade Federal do Rio Grande do Norte (UFRN).

## About

The algorithm reads a file and computes the frequencies of each character, with
this information it then constructs a [Digital Tree](https://en.wikipedia.org/wiki/Trie)
which is used to encode the paths to each leaf node, thus letting us represent
ascii characters with less bits.It saves the tree representation at the start of
each compressed file in order to allow uncompression by rebuilding the tree.
After rebuilding the tree it then reads the compressed information by searching
the tree paths simply by going left if it reads a 0 or right if it reads a 1;

## Compiling and running

In order to compile simply make sure you have clang++ and GNU Makefile instaled
and then run ```make```.
If you want to use g++ simply change the CC variable in the makefile to g++;

## Authorship

Program developed by [Max William](github.com/maxwillf) and [João Pedro de
Amorim](github.com/jpprime).
