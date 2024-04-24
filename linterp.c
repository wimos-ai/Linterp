#include <stdio.h>  //printf
#include <stdlib.h> // strtold

long double safe_get(const char *ptr)
{
    char *endptr = NULL;
    long double value = strtold(ptr, &endptr);
    if (value == 0.0 && endptr == ptr)
    {
        printf("%s could not be interperted as a float", ptr);
        exit(EXIT_FAILURE);
    }

    return value;
}

const int main(int argc, const char **argv)
{
    if (argc == 6)
    {
        long double x1 = safe_get(argv[1]);
        long double y1 = safe_get(argv[2]);
        long double x2 = safe_get(argv[3]);
        long double y2 = safe_get(argv[4]);
        long double xf = safe_get(argv[5]);

        long double result = y1 + (((xf - x1) * (y2 - y1)) / (x2 - x1));
        printf("yf: %Lf\n", result);
    }
    else
    {
        printf("%s", "Useage is linterp x1 y1 x2 y2 xf\n");
    }
    return EXIT_SUCCESS;
}
