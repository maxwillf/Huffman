# Huffman

Huffman compression implementation for Basic Data Structures II course we took on
our Computer Science graduation at  Universidade Federal do Rio Grande do Norte (UFRN).

## About

The algorithm reads a file and computes the frequencies of each character in the
file, with this information it then constructs a [Digital
Tree](https://en.wikipedia.org/wiki/Trie) which is used to encode the paths to
each leaf node, thus letting us represent ascii characters with less bits. It
saves the tree representation at the start of each compressed file in order to
allow uncompression by rebuilding the tree. After rebuilding the tree it then
reads the compressed information by searching the tree paths simply by going
left if it reads a 0 or right if it reads a 1;

## Compiling and running

In order to compile simply make sure you have `clang++` and GNU Makefile
installed and then run `make run` (or `gmake run` in case you're using a BSD),
this will compile and run the program. If you went to use `g++` simply change
the `CC` variable in the makefile to `g++`. The file to be compacted is stored
inside the `res/` folder and should be named `input.txt`; the compacted file
will be on the same folder under the name `output.txt`; the unpacked file, after
the `input.txt` got compacted to `output.txt` is under the same folder with the
name `unpacked.txt`.

## Details of implementation

### Node

To implement the huffman algorithm, we had to create a class `Node` for the
nodes of the trees. Each node stores a frequency of appearance of characters, a
letter and its left and right child. The `Node` class has, besides the getters
and setters, an auxiliary function to insert in order, given a vector of any
type, a new object; this function receives a function that will return a boolean
indicating if the first argument is the predecessor of the second, as parameter.

### HuffmanTree

As for the digital tree, we created a class called `HuffmanTree`. To actually
create the tree, we need to first read the file and create a node for each
character in the file with the frequency it appears there. Reading the file is
actually done by another class, `IOManager`, that manages every action of input
and output. The method `readFile()` receives a file stream as input and, as a
first step, generates an array of `int` containing the amount of times each char
occurred in the file. That is done by the `countFrequencies()` method, of the
same class. This method creates a new array of `int` containing 128 positions,
each representing a character code from the ASCII table; then it reads the file
char by char incrementing 1 on the position of the char it is reading on the
array. At last, it returns the array to the `readFile()` method. Following that,
inside `readFile()`, we loop through the array containing the total occurrences
of each char in the file and create a new node with the char and its total
occurrences as the frequency of that node; after that, we use the `insertOrd()`
method from `node.h` to insert the new node on a array of nodes. Using this
array of nodes we can create a digital tree in which all of the nodes containing
characters will be leaves and the parent of two nodes is always a node without a
character stored in which the frequency is the sum of its two childs (that means
that the root has the total frequency of the tree). The `HuffmanTree` class also
has a method to populate a maps of chars and strings in which for every
character on the tree, we have a string of 0's and 1's corresponding to the path
one has to take from the root to that leaf containing that character; 0 means
you have to go the left and 1 means you should go to the right child. This way
of representing the path from the root to the leaf containing that character is
how we will represent it in the compacted file. So, for example, lets suppose
you have a `'b'` stored in your tree, and the path from the root to the node
with the `'b'` is right, left, right, right; that means that the character
`'b'`, on the compacted file, will be represented as 1011. The characters that
appear the most have the smallest path from the root, with the two smallest
possible paths being 00 and 01. That way we can be as efficient as possible on
our encoding.

### Compact

After all that is done, we need to compact the file. Since this is an IO action,
it is done on the `IOManager` class. To compact, we use the `compact()` method,
in which we pass the input file and the output file as parameters. This method
calls `encodeTree()`, a method that encodes the tree as the header of the output
file. After that we encode the message itself using the same method of the
encoding of the tree. The message and the tree are encoded/compacted using bit
manipulation; after everything has been converted to its binary format and
concatenated on a single string, we run through this string, char by char, until
we have 8 char (or 8 bits), which constitute a byte, which in turn is a char, at
this point we create a new char using the 8 bits already read from the string,
and output this new char, no matter if its an ASCII char or not, to the output
file.

### Decoding the tree

To unpack the compacted information, first we need to decode the header of the
file and with that recreate the digital tree, this time we won't need the
frequencies of each character, just its original place on the tree. The decoding
of the tree is done by the `decodeTree()` method from `IOManager`. The
`decodeTree()` method only calls the `binaryToString()` method, which in turn
reads each bit of the compacted file and store them as a 0 or 1 in a string.
This string is then stored in a vector of strings by the `stringToVec()` method;
this method goes identifies what is a character and what is not, and stores
characters in a vector as strings of 8 characters (all of them being 0's or
1's). This string is them used, still inside the `binaryToString()` method, by
the `constructTree()` method to generate nodes with the vector of strings,
returning the root to be used to build a new tree.

## Authorship

Program developed by [Max William](github.com/maxwillf) and [João Pedro de
Amorim](github.com/jpprime).
