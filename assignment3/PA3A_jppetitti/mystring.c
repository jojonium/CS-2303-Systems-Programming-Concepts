/** mystring.c
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/

#include <string.h>
#include <stdlib.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
	or null if no memory is available
*/
char* mystrdup1(const char* src) {
	int length; // Length of the source string
	char* newstr; // Pointer to memory which will hold new string

	length = mystrlen1(src) + 1;	// Leave space for the terminator
	newstr = (char*) malloc(length); // Must cast!

	// If no memory was available, return null pointer immediately
	if (newstr == 0) return (char *) 0;

	// Otherwise, copy the string and return pointer to new string
	strcpy(newstr, src);
	return newstr;
}

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
				 or null if no memory is available
*/
char* mystrdup2(const char* src) {
	int length; // Length of the source string
	char* newstr; // Pointer to memory which will hold new string

	length = mystrlen2(src) + 1;	// Leave space for the terminator
	newstr = (char*) malloc(length); // Must cast!

	// If no memory was available, return null pointer immediately
	if (newstr == 0) return (char *) 0;

	// Otherwise, copy the string and return pointer to new string
	strcpy(newstr, src);
	return newstr;
}

/** Calculates the length of a C-style string.
 * @param s Pointer to the string to be measured
 * @return the number of characters in the string pointed to by s, excluding the null terminator
 */
size_t mystrlen1(const char *s) {
	size_t out = 0;
	char next = *s;
	while (next != '\0') {
		++out;
		next = s[out];
	}
	return out;
}

/** Calculates the length of a C-style string.
 * @param s Pointer to the string to be measured
 * @return the number of characters in the string pointed to by s, excluding the null terminator
 */
size_t mystrlen2(const char *s) {
	size_t out = 0;
	while (*s != '\0') {
		++out;
		++s;
	}
	return out;
}

/** Copies a string
 * Copies the string pointed to by src, including the terminating null byte ('\0'), to the buffer
 * 	pointed to by dest. The strings may not overlap, and the destination string dest must be
 * 	large enough to receive the copy. Beware of buffer overruns!
 * @param dest a pointer to the destination string
 * @param src a pointer to the source string
 * @return a pointer to the destination string dest
 */
char *mystrcpy(char *dest, const char *src) {
	return memcpy(dest, src, strlen(src) + 1);
}

