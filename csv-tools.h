#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct columns {
    int ammt;
    char **cols;
};

struct csv_t{
    struct columns cols;
    char * location;
    FILE * fp;
};


void addRow(char *values[], int colNum, FILE *fp);

struct csv_t StartCSV(char ** columns, int column_number, char* csv_location);

