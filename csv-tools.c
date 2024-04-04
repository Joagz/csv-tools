#include "csv-tools.h"

void setColumns(struct columns *cols, char **newCols, int newColNum) {
    cols->ammt = newColNum;
    cols->cols = newCols;
}

FILE *csv_parser_init(struct columns cols, const char *loc) {
    FILE *fp;
    fp = fopen(loc, "w+"); // Open for reading and writing, file must exist

    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < cols.ammt; i++) {
        fwrite(cols.cols[i], 1, strlen(cols.cols[i]), fp);
        fwrite(",", 1, 1, fp);
        printf("[INFO] Putting column: %s\n", cols.cols[i]);
    }
    fwrite("\n", 1, 1, fp);

    printf("[INFO] csv_parser_init: done\n");

    return fp;
}

void addRow(char *values[], int colNum, FILE *fp) {
    for (int i = 0; i < colNum; i++) {
        size_t bytes_wr = fwrite(values[i], 1, strlen(values[i]), fp);
        fwrite(",", 1, 1, fp);

        if (bytes_wr == -1) {
            perror("addRow");
            exit(EXIT_FAILURE);
        }
    }
    fwrite("\n", 1, 1, fp);
}

struct csv_t StartCSV(char ** columns, int column_number, char* csv_location)
{ 
    struct columns cols;
    struct csv_t csv;

    setColumns(&cols, columns, column_number);

    FILE *fp = csv_parser_init(cols, csv_location);
    
    csv.location = csv_location;
    csv.cols = cols;
    csv.fp = fp;
    return csv;
}
