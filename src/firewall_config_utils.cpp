#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "kill_port.h"


int main(void) {
	char option[256];
	std::cout << "[+] Wanna close some open ports? [Y/n]: ";
	std::cin >> option;
	if (strcmp(option, "Y") == 0 || strcmp(option, "y") == 0) {
		char port[1024];
		while (1 == 1) {
			std::cout << "[+] Enter a port that you want to kill [one][Type 'NONE' when dont want to kill any port]: ";
			std::cin >> port;
			if (strcmp(port, "NONE") == 0 || strcmp(port, "none") == 0) {
				std::cout << "[+] Exiting the Port-Killer..." << std::endl;
				break;
			}
			else {
				std::cout << "[+] Killing specified port..." << std::endl;
				if (kill_port(port) == 0) {
					std::cout << "[+] Port successfully killed!" << std::endl;
				}
				else {
					std::cout << "[!] Something went wrong!" << std::endl;
					exit(EXIT_FAILURE);
				}
			}
		}
		exit(EXIT_SUCCESS);
	}
	return 0;
}
