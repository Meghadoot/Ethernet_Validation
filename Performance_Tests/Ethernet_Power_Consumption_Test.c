/***************************************************************************
    Ethernet Power Consumption Test.c
    Author: Meghadoot
    2025-03-02
    
    This is a library for the validation of Ethernet Interface.
    This validation test uses iperf to test power consumption.
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

void simulate_ethernet_activity() {
    char command[256];
    snprintf(command, sizeof(command), "iperf -c %s -t 30 > /dev/null", SERVER_IP);
    system(command);
}

int main() {
    printf("Starting Ethernet Power Consumption Test...\n");

    for (int i = 0; i < 10; i++) {
        printf("Iteration %d: Simulating Ethernet activity...\n", i + 1);
        simulate_ethernet_activity();
        sleep(10);  // Sleep to allow power measurements
    }

    printf("Ethernet Power Consumption Test completed.\n");
    return 0;
}
