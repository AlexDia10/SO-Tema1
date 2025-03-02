// SPDX-License-Identifier: BSD-3-Clause

//https://tutoriale-pe.net/siruri-de-caractere-functii-predefinite-in-c/
//https://aticleworld.com/

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	int i;
	for (i = 0; source[i] != '\0'; i++) {
		destination[i] = source[i];
	}
	destination[i] = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	size_t i = 0;
	while (source[i] != '\0' && i < len) {
		destination[i] = source[i];
		i++;
	}
	while (i < len) {
		destination[i] = '\0';
		i++;
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int i, j;
	for (i = 0; destination[i] != '\0'; i++) {} //end of destination string
	for (j = 0; source[j] != '\0'; j++) {
		destination[i++] = source[j];
	}
	destination[i] = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	size_t i = 0, j = 0;
	while (destination[i] != '\0') {
		i++;
	}
	while (source[j] != '\0' && j < len) {
		destination[i++] = source[j++];
	}
	destination[i] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	size_t i;
	for (i = 0; str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]; i++) {}

	if (str1[i] == '\0' && str2[i] == '\0') {
		return 0;
	} else if (str1[i] > str2[i]) {
		return 1;
	} else {
		return -1;
	}
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	size_t i;
	for (i = 0; str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]; i++) {}

	if (i == len) {
		return 0;
	} else if (str1[i] > str2[i]) {
		return 1;
	} else {
		return -1;
	}
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	size_t i;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == c) {
			return (char *) (str + i);
		}
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	int i;
	char *last = NULL;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == c) {
			last = (char *) (str + i);
		}
	}
	if (last != NULL) {
		return (char *) last;
	} else {
		return NULL;
	}
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	int i, j, k, found;
	for (i = 0; haystack[i] != '\0'; i++) {
		if (haystack[i] == needle[0]) {
			k = i + 1;
			found = 1;
			for (j = 1; needle[j] != '\0'; j++) {
				if (haystack[k] != needle[j]) {
					found = 0;
					break;
				}
				k++;
			}
			if (found == 1) {
				return (char *) (haystack + i);
			}
		}
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	int haystack_len = strlen(haystack);
	int needle_len = strlen(needle);

	int i, j, k, found;
	for (i = haystack_len - needle_len; i >= 0; i--) {
		if (haystack[i] == needle[0]) {
			k = i + 1;
			found = 1;
			for (j = 1; needle[j] != '\0'; j++) {
				if (haystack[k] != needle[j]) {
					found = 0;
					break;
				}
				k++;
			}
			if (found == 1) {
				return (char *) (haystack + i);
			}
		}
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *src_char = (char *) source;
	char *dst_char = (char *) destination;

	size_t i;
	for (i = 0; i < num; i++) {
		dst_char[i] = src_char[i];
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	if (destination == source) {
		return destination;
	}

	char *src_char = (char *) source;
	char *dst_char = (char *) destination;

	size_t i;
	if (dst_char < src_char) {
        for (i = 0; i < num; i++) {
            dst_char[i] = src_char[i];
        }
    } else {
        for (i = num; i > 0; i--) {
            dst_char[i - 1] = src_char[i - 1];
        }
    }

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	if (ptr1 == ptr2) {
		return 0;
	}

	const char *p = ptr1;
	const char *q = ptr2;

	size_t i;
	for (i = 0; i < num; i++) {
		if (*p != *q) {
			if (*p > *q) {
				return 1;
			} else {
				return -1;
			}
		}
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *p = source;
	while (num--) {
		*p++ = value;
	}

	return source;
}
