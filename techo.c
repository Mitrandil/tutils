/*
 * tarasik echo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLEN 2048

int
main(int argc, char *argv[])
{
	int len;
	char line[STRLEN];

	line[0] = '\0'; /* init array for clean strcat */

	if (argc < 2) {
		printf("\n");
		exit(0);
	}
	while (*++argv) {
		strcat(line, *argv);
		strcat(line, " ");
	}
	len = strlen(line);
	line[len-1] = '\n'; /* replace last space with nline */

	printf("%s", line);

	exit(0);
}
