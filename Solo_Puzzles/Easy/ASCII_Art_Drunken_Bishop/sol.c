#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define DEBUG_MODE 0 // 0:desable, 1:enable
int getIndexCharInStr(const char str[], char match)
{
    if (!str)
        return (-1);
    int len = strlen(str);
    int i = 0;
    while (i < len && str[i]!=match)
        i++;
    if (str[i]==match)
        return (i);
    return (-1);
}
void    convertHexToBinaryList(char *str, char bl[16][9])
{
    const char bin[16][5] = { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111", };
    const char digits[16] = "0123456789abcdef";
    int idx1;
    int idx2;
    int line = 0;
    int i = 0;
    while (str[i] && str[i+1] && line < 16)
    {
        idx1 = getIndexCharInStr(digits, str[i]);
        idx2 = getIndexCharInStr(digits, str[i+1]);
        if (idx1 < 0 || idx2 < 0)
            return ;
        memset(bl[line], 0, 9);
        strncpy(&bl[line][0], bin[idx1], 4);
        strncpy(&bl[line][4], bin[idx2], 4);
        i+=3;
        line++;
    }
}
void    printBinaryList(char bl[16][9])
{
    if (DEBUG_MODE)
    {
        fprintf(stderr, "|--------|\n");
        for (int i=0;i<16;i++)
            fprintf(stderr, "|%s|\n", bl[i]);
        fprintf(stderr, "|--------|\n");
    }
}
void convertBinaryListToMovList(char bl[16][9], char ml[64][3])
{
    int j = 0;
    int i = -1;
    while (++i < 16 && j < 64)
    {
        memset(ml[j], 0, 3);
        strncpy(ml[j++], &bl[i][6] ,2);
        memset(ml[j], 0, 3);
        strncpy(ml[j++], &bl[i][4] ,2);
        memset(ml[j], 0, 3);
        strncpy(ml[j++], &bl[i][2] ,2);
        memset(ml[j], 0, 3);
        strncpy(ml[j++], &bl[i][0] ,2);
    }
}
void    printMovList(char mv[64][3])
{
    if (DEBUG_MODE)
    {
        fprintf(stderr, "\n|--|\n");
        for (int i=0;i<64;i++)
            fprintf(stderr, "|%s|\n", mv[i]);
        fprintf(stderr, "|--|\n");
    }
}

void    initMaze(char maze[9][18])
{
    for (int i=0;i<9;i++)
    {
        for (int j=0;j<17;j++)
        {
            if (i == 4 && j == 8)
                maze[i][j]='S';
            else
                maze[i][j]=' ';
        }
        maze[i][17]=0;
    }
}

void    printMaze(char maze[9][18])
{
    if (DEBUG_MODE)
    {
        fprintf(stderr, "\n+---[CODINGAME]---+\n");
        for (int i=0;i<9;i++)
            fprintf(stderr, "|%s|\n", maze[i]);
        fprintf(stderr, "+-----------------+\n");
    }
}

void    printResult(char maze[9][18])
{
    printf("+---[CODINGAME]---+\n");
    for (int i=0;i<9;i++)
        printf("|%s|\n", maze[i]);
    printf("+-----------------+");
}
void    udpateMazePos(char maze[9][18], int l, int c)
{
    char const values[15] = " .o+=*BOX@\%&#/^";
    int idx = getIndexCharInStr(values, maze[l][c]);
    maze[l][c] = values[(idx + 1)%15];
}
void    moveUpLeft(char maze[9][18], int *l, int *c)
{
    if (*l > 0)
        *l = *l - 1;
    if (*c > 0)
        *c = *c - 1;
    udpateMazePos(maze, *l, *c);
}
void    moveUpRight(char maze[9][18], int *l, int *c)
{
    if (*l > 0)
        *l = *l - 1;
    if (*c + 1 < 17)
        *c = *c + 1;
    udpateMazePos(maze, *l, *c);
}
void    moveDownLeft(char maze[9][18], int *l, int *c)
{
    if (*l + 1 < 9)
        *l = *l + 1;
    if (*c > 0)
        *c = *c - 1;
    udpateMazePos(maze, *l, *c);
}
void    moveDownRight(char maze[9][18], int *l, int *c)
{
    if (*l + 1 < 9)
        *l = *l + 1;
    if (*c + 1 < 17)
        *c = *c + 1;
    udpateMazePos(maze, *l, *c);
}
void buildMaze(char maze[9][18], char mov_list[64][3])
{
    int l = 4; // bishop's position:lines
    int c = 8; // bishop's position:columns
    for (int i=0;i<64;i++)
    {
        if (!strcmp(mov_list[i], "00"))
            moveUpLeft(maze, &l, &c);
        if (!strcmp(mov_list[i], "01"))
            moveUpRight(maze, &l, &c);
        if (!strcmp(mov_list[i], "10"))
            moveDownLeft(maze, &l, &c);
        if (!strcmp(mov_list[i], "11"))
            moveDownRight(maze, &l, &c);
    }
    maze[4][8]='S';
    maze[l][c]='E';
}
int main()
{
    char str_hexa[129] = "";
    scanf("%[^\n]", str_hexa);
    if (DEBUG_MODE)
        fprintf(stderr, "STEP 0-RAW HEXA\n> %s\n", str_hexa);

    if (DEBUG_MODE)
        fprintf(stderr, "\nSTEP 1-CONVERT TO BINARY ARRAY:");
    char binary_list[16][9];
    convertHexToBinaryList(str_hexa, binary_list);
    printBinaryList(binary_list);

    if (DEBUG_MODE)
        fprintf(stderr, "\nSTEP 2-CONVERT TO MOVEMENT ARRAY:");
    char mov_list[64][3];
    convertBinaryListToMovList(binary_list, mov_list);
    printMovList(mov_list);

    if (DEBUG_MODE)
        fprintf(stderr, "\nSTEP 3-INIT MAZE:");
    char maze[9][18];
    initMaze(maze);
    printMaze(maze);

    if (DEBUG_MODE)
        fprintf(stderr, "\nSTEP 4-BUILD MAZE (MOVEMENTS):\n");
    buildMaze(maze, mov_list);
    printResult(maze);
    return (0);
}
