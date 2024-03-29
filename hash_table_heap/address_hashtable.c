
#define MULTIPLIER (37)

unsigned long
hash(const char *number_key)
{
    unsigned long h;
    const char *us;

    /* cast s to unsigned const char * */
    /* this ensures that elements of s will be treated as having values >= 0 */
    us = (unsigned const char *)number_key;

    h = 0;
    while (*us != '\0')
    {
        h = h * MULTIPLIER + *us;
        us++;
    }

    return h;
}