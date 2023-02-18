#ifndef KILL_PORT_
#define KILL_PORT_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int kill_port(char* port) {
	printf("[i] Make sure that no service is running that opens the port again like [ssh]!\n");
	char cmd[1024];
	strcpy(cmd, "sudo fuser -k ");
	strcat(cmd, port);
	strcat(cmd, "/tcp");
	system(cmd);
	return 0;
}

#endif
