/*
 * tarasik echo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	int i;
	size_t len;
	char *buf, *ptr;

	if (argc < 2) {
		printf("\n");
		return 0;
	}

	len = 1;
	for (i = 1; i < argc; i++)
		len += strlen(argv[i])+1;

	buf = malloc(len);
	if (buf == NULL) {
		fprintf(stderr, "techo: malloc error\n");
		return 1;
	}

	ptr = buf;
	for (i = 1; i < argc; i++) {
		strcpy(ptr, argv[i]);
		ptr += strlen(ptr);
		if (i < argc-1)
			*ptr++ = ' ';
	}

	*ptr++ = '\n';
	*ptr = '\0';

	printf("%s", buf);

	free(buf);

	return 0;
}
