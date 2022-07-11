#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILE "Input.txt"
#define MAX 1000

typedef struct {
    int x1, y1;
    int x2, y2;
} coordinates;

coordinates c[MAX];
int size;
int radar[MAX][MAX] = {0};
int rows = 0;
int cols = 0;

void readCoordinates();
void fillRadar();

int main() {
    int counter;

    readCoordinates();
    fillRadar();

    counter = 0;
    for (int i = 0; i <= rows; i++)
        for (int j = 0; j <= cols; j++)
            if (radar[i][j] >= 2) counter++;

    // Result: 6397
    printf("Result: %d\n", counter);

    return 0;
}

void fillRadar() {
    int i, dot;

    for (i = 0; i < size; i++) {
        if (c[i].x1 == c[i].x2) {
            // the line is going vertically
            if (c[i].y1 > c[i].y2) {
                for (dot = c[i].y2; dot <= c[i].y1; dot++)
                    radar[dot][c[i].x1]++;
            } else {
                for (dot = c[i].y2; dot >= c[i].y1; dot--)
                    radar[dot][c[i].x1]++;
            }
        } else if (c[i].y1 == c[i].y2) {
            // the line is going horizontally
            if (c[i].x1 > c[i].x2) {
                for (dot = c[i].x2; dot <= c[i].x1; dot++)
                    radar[c[i].y1][dot]++;
            } else {
                for (dot = c[i].x2; dot >= c[i].x1; dot--)
                    radar[c[i].y1][dot]++;
            }
        }
    }
}

void readCoordinates() {
    FILE *file;
    int i;
    if ((file = fopen(INPUT_FILE, "r")) == NULL) {
        fprintf(stderr, "Error opening input file %s\n", INPUT_FILE);
        exit(-1);
    }
    i = 0;
    while (!feof(file)) {
        fscanf(file, "%d,%d -> %d,%d\n", &(c[i].x1), &(c[i].y1), &(c[i].x2), &(c[i].y2));

        // figure out how big the radar matrix should be
        if (c[i].y1 == c[i].y2) {
            if (c[i].x1 > c[i].x2 && c[i].x1 > rows)
                rows = c[i].x1;
            else if (c[i].x2 > rows)
                rows = c[i].x2;

            i++;
        } else if (c[i].x1 == c[i].x2) {
            if (c[i].y1 > c[i].y2 && c[i].y1 > cols)
                cols = c[i].y1;
            else if (c[i].y2 > cols)
                cols = c[i].y2;

            i++;
        }
    }
    size = i;
    fclose(file);
}
