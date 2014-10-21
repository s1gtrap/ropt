#include <string.h>

#include "ropt.h"

unsigned int ropt_has(const char *opt_long, const char opt_short, int argc, const char **argv) {
	const char *arg;
	for (int i = 0; i < argc; i++) {
		arg = argv[i];

		if (*arg++ == '-') { // All opts start with a -
			if (*arg == '-') { // Long opts have two (i.e. one more)
				arg++; // We don't need to work with the -
				if (!*arg) return 0; // If opt is empty (entire var is --) return
				if (!opt_long) continue; // If opt_long is null, continue
				if (!strcmp(opt_long, arg)) return ++i; // if arg equals opt_long, return i
			} else { // Short opts have one -. If no 2nd - is present opt is short
				if (!opt_short) continue; // If opt_short is null, continue
				if (strchr(arg, opt_short)) return ++i; // if arg contains opt_short, return i
			}
		}
	}

	return 0;
}

const char *ropt_get(const char *opt_long, const char opt_short, int argc, const char **argv) {
	unsigned int index;
	return (index = ropt_has(opt_long, opt_short, argc, argv)) ? argv[index] : NULL;
}
