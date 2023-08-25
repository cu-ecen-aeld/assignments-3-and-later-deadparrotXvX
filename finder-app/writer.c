/**
 * A simple application writing some content to a file
 */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd, len;

	/* Init the syslog */
	openlog(NULL, 0, LOG_USER);

	/* Let's check if we have two arguments passed */
	if(argc != 3) {
		syslog(LOG_ERR, "Invalid number if arguments: %d", argc);
		syslog(LOG_ERR, "%s needs exactly two arguments:", argv[0]);
		syslog(LOG_ERR, "Usage: %s writefile writestr", argv[0]);
		return 1;
	}

	/* Okay, we have what we need, so let's write a file */
	len = strlen(argv[2]);

	fd = creat(argv[1], 0644);
	if(fd < 0) {
		syslog(LOG_ERR, "Error opening file %s: %s", argv[1], strerror(errno));
		return 1;
	}

	if(write(fd, argv[2], len) != len) {
		syslog(LOG_ERR, "Error writing to file %s: %s", argv[1], strerror(errno));
		close(fd);
		return 1;
	} else
		syslog(LOG_USER, "Writing %s to %s", argv[2], argv[1]);
	close(fd);
	return 0;
}
