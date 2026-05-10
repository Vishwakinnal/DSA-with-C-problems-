#include <stdio.h>
#include <string.h>

int strStr("banana", "ana");  // returns 1 (first "ana" starts at index 1)
int strStr("banana", "nana"); // returns 2
int strStr("banana", "xyz");  // returns -1 (not found)
