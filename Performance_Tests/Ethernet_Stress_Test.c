/***************************************************************************
    Ethernet Stress Test.c
    Author: Meghadoot
    2025-03-03
    
    
    This is a library for the validation of Ethernet Interface.
    This validation test uses iperf for stress testing.
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

#define SERVER_IP "192.168.1.100"  // Replace with your iperf server IP

int main() {
    printf("Starting Ethernet Stress Test...\n");
    char command[256];
    snprintf(command, sizeof(command), "iperf -c %s -t 300 -P 10 > ethernet_stress_test.log", SERVER_IP);
    system(command);

    printf("Ethernet Stress Test completed. Results:\n");
    system("cat ethernet_stress_test.log");

    return 0;
}
