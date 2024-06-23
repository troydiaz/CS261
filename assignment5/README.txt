Name: Troy Diaz
ONID: 934417663
Description: 

A hash table is a data structure that stores a collection of elements in an array.
Each collection is a bucket, and every element is assigned a pair with a value and a key. 
This implementation uses chaining to build a hash table. To find a particular element, the program 
finds the specific bucket using the hash function and looks for the key associated with a value.

Instructions:

To recompile
- make clean && make 

To check for memory leaks
- valgrind ./test_ht

Run test program
- ./test_ht

Limitations:

- If non-string keys are used (for comparing keys), strcmp might not work
