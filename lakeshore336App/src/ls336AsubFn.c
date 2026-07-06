#include <registryFunction.h>
#include <epicsExport.h>
#include <aSubRecord.h>

#include <stdio.h>
#include <string.h>

/* 
Parse a string to extract firmware version
Example strings are
BL05I-EA-TCTRL-02:ID           LSCI,MODEL336,336AAA7/#######,2.1
TST-EA-LS336-01:ID             LSCI,MODEL336,336A0D7/#######,2.4
*/

static long extractFirmwareVersion(aSubRecord *prec)
{
    char idstring[100];
    char * version = (char * ) prec->valb;
    char *lastComma;
    
    strncpy(idstring, (char *)prec->a, 40);
    lastComma = strrchr(idstring, ',');
    
    if (strstr(idstring, "MODEL336") != NULL && lastComma != NULL)
    {
        strcpy(version, lastComma + 1);
    }
    else
    {
        strcpy(version, "not available");
    }
    return 0;
}

/* Register the functions */
epicsRegisterFunction(extractFirmwareVersion);
