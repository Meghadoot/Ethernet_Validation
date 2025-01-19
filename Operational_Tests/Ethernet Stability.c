/***************************************************************************
    Ethernet Stability.c
    Author: Meghadoot
    2025-01-19
    
    This is a library for the validation of Ethernet Interface.
    This validation test uses systemcall to interface to check 
    packets (loss) status.
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

int main() {
    printf("Starting Ethernet Stability Test for 3600 seconds...\n");
    system("ping -I eth0 -c 3600 -i 1 8.8.8.8 > ethernet_stability_test.log");

    if (system("grep -q '100% packet loss' ethernet_stability_test.log") == 0) {
        printf("Ethernet Stability Test failed.\n");
    } else {
        printf("Ethernet Stability Test passed.\n");
    }

    return 0;
}
