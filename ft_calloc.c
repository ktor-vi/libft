#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void *ft_calloc(size_t count, size_t size) {
    size_t total_size = count * size;
    void *res = NULL;

    // Check for potential overflow
    if (count != 0 && size != 0) {
        if (total_size / count != size) {
            return NULL; // Overflow detected
        }
    }

    // Handle the case where count or size is 0
    if (count == 0 || size == 0) {
        total_size = 1; // Allocate at least 1 byte
    }

    // Allocate memory
    res = malloc(total_size);

    // Clear the allocated memory to zero
    if (res != NULL) {
        char *tmp = (char *)res;
        for (size_t i = 0; i < total_size; i++) {
            tmp[i] = 0;
        }
    }

    return res;
}

int main() {
    void *p;

    /* 1 */ p = ft_calloc(5, sizeof(int));
    /* 2 */ free(p);

    /* 3 */ p = ft_calloc(0, sizeof(int));

    /* 5 */ p = ft_calloc(INT_MIN, 1);
    if (p == NULL) {
        printf("ft_calloc(INT_MIN, 1) returned NULL as expected.\n");
    }

    return 0;
}
