#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${GREEN}Welcome to the _printf function installation and test script!${NC}"

# Compile the project
echo -e "\n${YELLOW}Compiling the project...${NC}"
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o printf_test
if [ $? -eq 0 ]; then
    echo -e "${GREEN}Compilation successful!${NC}"
	echo -e "\n${YELLOw}You can run the program using : "./printf_test""
else
    echo -e "${RED}Compilation failed. Please check your code and try again.${NC}"
    exit 1
fi

# Install man page
echo -e "\n${YELLOW}Do you want to install the man page for _printf? (y/n)${NC}"
read -r install_man

if [[ $install_man == "y" || $install_man == "Y" ]]; then
    echo -e "${RED}WARNING: You are about to install a program from the internet. Always verify the content of scripts before running them with root privileges.${NC}"
    echo -e "${YELLOW}Please enter your root password to install the man page:${NC}"
	if [!-d /usr/local/man/man3 ] then
	sudo mkdir /usr/local/man/man3
	fi
    sudo install -g 0 -o 0 -m 0644 man_3_printf /usr/local/man/man3/_printf.3
	sudo gzip /usr/local/man/man3/_printf.3
    sudo mandb

    echo -e "\n${YELLOW}Do you want to view the man page now? (y/n)${NC}"
    read -r view_man
    if [[ $view_man == "y" || $view_man == "Y" ]]; then
        man _printf
    else
        echo -e "${GREEN}You can view the man page later by running: ${YELLOW}man _printf${NC}"
    fi
else
    echo -e "${GREEN}Man page installation skipped.${NC}"
fi

echo -e "\n${GREEN}Installation and setup complete!${NC}"
echo -e "${YELLOW}You can now run the test program by executing: ${GREEN}./printf_test${NC}"
echo -e "\n${GREEN}Thank you for using my script ! and have a nice day ;)