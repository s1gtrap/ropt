/**
 * Checks if specified option is present in the specified arguments. Returns 
 * greater than 0 if present, 0 if not. The returned value is equal to the
 * option's value's index in argv.
 */
unsigned int ropt_has(const char *opt_long, const char opt_short, int argc, const char **argv);

/**
 * Gets the given option's value from the specified arguments. Returns NULL if
 * option is not present.
 */
const char *ropt_get(const char *opt_long, const char opt_short, int argc, const char **argv);
