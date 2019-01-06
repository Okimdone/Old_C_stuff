#include <err.h>
int main(void)
{
    char* start_time_string="let s go baby";
    if (1 <2)
        errx(1, "too early, wait until %s", start_time_string);
}