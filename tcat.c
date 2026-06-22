/*
 * tarasik cat
 */

#include <stdio.h>

void
fcpy(FILE *ifp, FILE *ofp)
{
	int c;

	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}

int
main(int argc, char *argv[])
{
	FILE *fp;

	if (argc == 1)
		fcpy(stdin, stdout);
	else
		while (--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL) {
				fprintf(stderr, "cat: can't open %s\n", *argv);
				return 1;
			} else {
				fcpy(fp, stdout);
				fclose(fp);
			}

	if (ferror(stdout)) {
		fprintf(stderr, "cat: error writing stdout\n");
		return 2;
	}

	return 0;
}
