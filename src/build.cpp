#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	std::cout << "[i] Make sure that you are running this script with root(superuser) privilege!" << std::endl;
	std::cout << "[+] Building project, please wait..." << std::endl;
	system("chmod +x lib/port_killer.out");
	system("chmod +x src/port_killer.out");
	system("chmod +x firewall_init.sh");
	std::cout << "[+] Project successfully build!" << std::endl;
	std::cout << "[+] Exiting..." << std::endl;
	return 0;
}
