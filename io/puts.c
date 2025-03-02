#include <stdio.h>
#include <string.h>
#include <unistd.h>

int puts(const char *str) {
    int len = strlen(str);
    if (write(1, str, len) != len) {
        return -1;
    }

    if (write(1, "\n", 1) != 1) {
        return -1;
    }

    // Return a non-negative value on success (number of characters written)
    return len;
}
