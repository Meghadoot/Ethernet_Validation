/***************************************************************************
    Ethernet Link Detection.c
    Author: Meghadoot
    2025-01-17
    
    This is a library for the validation of Ethernet Interface.
    This validation test uses file descriptor for carrier file to check link status.
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
    FILE *file = fopen("/sys/class/net/eth0/carrier", "r");
    if (!file) {
        perror("Failed to open carrier file");
        return 1;
    }

    char link_status;
    fread(&link_status, 1, 1, file);
    fclose(file);

    if (link_status == '1') {
        printf("Ethernet link is up.\n");
    } else {
        printf("Ethernet link is down.\n");
    }

    return 0;
}
