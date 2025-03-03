/***************************************************************************
    Ethernet Memory Consumption Test.c
    Author: Meghadoot
    2025-03-02
    
    This is a library for the validation of Ethernet Interface.
    This validation test uses /proc/meminfo interface to track memory consumption.
    Designed specifically to work with the Embedded Boards/devices working with 
    Yocto Linux or other distros. 
    
    Copyright (C) 2025  Meghadoot Gardi.  All right reserved.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

 ***************************************************************************/

/** TODO
* Create Automation with global configs
**/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SERVER_IP "192.168.1.100"  // Replace with your iperf server IP

void log_memory_usage(const char *label) {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        return;
    }

    printf("%s Memory Usage:\n", label);
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strncmp(buffer, "MemFree:", 8) == 0 || strncmp(buffer, "MemAvailable:", 13) == 0) {
            printf("%s", buffer);
        }
    }

    fclose(fp);
}

void simulate_ethernet_activity() {
    char command[256];
    snprintf(command, sizeof(command), "iperf -c %s -t 30 > /dev/null", SERVER_IP);
    system(command);
}

int main() {
    printf("Starting Ethernet Memory Consumption Test...\n");

    log_memory_usage("Before Ethernet activity");

    simulate_ethernet_activity();

    log_memory_usage("After Ethernet activity");

    printf("Ethernet Memory Consumption Test completed.\n");
    return 0;
}
