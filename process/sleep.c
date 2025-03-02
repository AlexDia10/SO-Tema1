#include <time.h>
#include <unistd.h>
#include <errno.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec req, rem;

    req.tv_sec = seconds;
    req.tv_nsec = 0;

    while (nanosleep(&req, &rem) == -1) {
        if (errno == EINTR) {
            // nanosleep was interrupted, so we need to continue sleeping
            req = rem;
        } else {
            return req.tv_sec;
        }
    }

    return 0;
}
