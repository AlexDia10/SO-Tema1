// SPDX-License-Identifier: BSD-3-Clause

//https://codereview.stackexchange.com/questions/276869/implementing-malloc-with-mmap
//https://medium.com/a-42-journey/how-to-create-your-own-malloc-library-b86fedd39b96

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
    size_t *ptr;
	size_t ptr_size = size + sizeof(size);

    if (size > 0) {
        ptr = (size_t *)mmap(NULL, ptr_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

		if (ptr == MAP_FAILED) {
			return NULL;
		}
	}

	*ptr = ptr_size;
    return (void *)(&ptr[1]);
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t total_size = nmemb * size;
    void *ptr = malloc(total_size);

    if (ptr != NULL) {
        memset(ptr, 0, total_size);
    }

    return ptr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr != NULL) {
        size_t *size_ptr = (size_t*)ptr - 1;
        munmap(size_ptr, *size_ptr);
    }
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (size == 0) {
		free(ptr);
		return NULL;
	}

	if (ptr == NULL) {
		return malloc(size);
	} else {
		void *new_ptr = malloc(size);

		if (new_ptr != NULL) {
			memcpy(new_ptr, ptr, size);
			free(ptr);
			return new_ptr;
		}
	}

	return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	if (size == 0 || nmemb == 0) {
		free(ptr);
		return NULL;
	}

	size_t new_size = nmemb * size;

	if (ptr == NULL) {
		return malloc(new_size);
	} else {
		void *new_ptr = realloc(ptr, new_size);

		if (new_ptr != NULL) {
			return new_ptr;
		}
	}

	return NULL;
}
