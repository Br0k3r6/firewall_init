#!/bin/bash

function banner() {
	banner_firewall=$(figlet Firewall -f slant);
	printf "$banner_firewall\n";
	return;
}

function firewall_start() {
	systemctl stop firewalld.service --now;
	firewall_status=$(systemctl status firewalld.service);

	printf "[+] Status of firewalld:\n\n";
	echo "STATUS----------------------------";
	printf "\n$firewall_status\n\n";
	echo "STATUS----------------------------";
	printf "\n[+] Starting firewalld...\n";

	systemctl start firewalld.service --now;
	systemctl enable firewalld.service --now;
	status=$(firewall-cmd --reload);

	printf "[+] Firewalld successfully started! [$status]\n";

	firewall_status=$(systemctl status firewalld.service);

	printf "\n";
	printf "[+] Status of firewalld:\n\n";
	echo "STATUS----------------------------";
	printf "\n$firewall_status\n\n";
	echo "STATUS----------------------------";
	printf "\n";

	./lib/port_killer.out;
}

banner;
read -p "Press [ENTER] to configure(init) firewall...";

firewall_start;
