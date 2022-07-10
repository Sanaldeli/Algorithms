#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILE "Input.txt"
#define MAX 100

const int draw[MAX] = {
    1, 76, 38, 96, 62, 41, 27, 33, 4, 2, 94, 15, 89, 25, 66, 14, 30, 0, 71, 21, 48, 44, 87, 73, 60, 50, 77, 45, 29, 18, 5, 99, 65, 16, 93, 95, 37, 3, 52, 32, 46, 80, 98, 63, 92, 24, 35, 55, 12, 81, 51, 17, 70, 78, 61, 91, 54, 8, 72, 40, 74, 68, 75, 67, 39, 64, 10, 53, 9, 31, 6, 7, 47, 42, 90, 20, 19, 36, 22, 43, 58, 28, 79, 86, 57, 49, 83, 84, 97, 11, 85, 26, 69, 23, 59, 82, 88, 34, 56, 13};

typedef struct
{
    int board[5][5];
} bingo;

int lastPicked;
int lastFinished;
bingo bingoes[MAX];
int finishedBoards[MAX] = {0};

void readFromFile();
void markDrawed();
int checkIfCompleted(int index, int row, int column);
int countFinishedBoards()
{
    int counter = 0;
    for (int i = 0; i < MAX; i++)
        counter += finishedBoards[i];
    return counter;
}

int main()
{
    int i, counter;
    readFromFile();

    i = 0;
    while (i < MAX && countFinishedBoards() < MAX)
    {
        lastPicked = draw[i];
        markDrawed();
        i++;
    }

    counter = 0;
    for (int j = 0; j < 5; j++)
    {
        for (int k = 0; k < 5; k++)
        {
            printf("%3d ", bingoes[lastFinished].board[j][k]);
            if (bingoes[lastFinished].board[j][k] != -1)
                counter += bingoes[lastFinished].board[j][k];
        }
        printf("\n");
    }

    // Result: 21070
    printf("Result: %d\n", counter * lastPicked);

    return 0;
}

void markDrawed()
{
    int counter;
    int isFound;
    int i, j, k;

    for (i = 0; i < MAX; i++)
    {
        if (!finishedBoards[i])
        {
            isFound = 0;
            j = 0;
            while (j < 5 && !isFound)
            {
                k = 0;
                while (k < 5 && bingoes[i].board[j][k] != lastPicked)
                    k++;

                if (k < 5)
                {
                    isFound = 1;
                    bingoes[i].board[j][k] = -1;

                    counter = checkIfCompleted(i, j, k);
                    if (counter == 5)
                    {
                        finishedBoards[i] = 1;
                        lastFinished = i;
                    }
                }
                j++;
            }
        }
    }
}

int checkIfCompleted(int index, int row, int column)
{
    int counter = 0;
    while (counter < 5 && bingoes[index].board[counter][column] == -1)
        counter++;

    if (counter == 5)
        return counter;

    counter = 0;
    while (counter < 5 && bingoes[index].board[row][counter] == -1)
        counter++;

    // if (counter == 5)
    // printf("Counter: %d | index: %d row: %d col: %d\n", counter, index, row, column);
    return counter;
}

void readFromFile()
{
    FILE *file;
    int i, j;
    char *trash;

    if ((file = fopen(INPUT_FILE, "r")) == NULL)
    {
        fprintf(stderr, "Error while opening file %s\n", INPUT_FILE);
        exit(-1);
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < 5; j++)
        {
            fscanf(file, "%d %d %d %d %d\n", &(bingoes[i].board[j][0]), &(bingoes[i].board[j][1]), &(bingoes[i].board[j][2]), &(bingoes[i].board[j][3]), &(bingoes[i].board[j][4]));
        }
        fscanf(file, "\n");
    }

    fclose(file);
}