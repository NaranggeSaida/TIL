#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
    double score;
    char grade[3];
    char name[51];
    double average = 0;
    double count = 0;
    
    for (int i = 0; i < 20; i++) {
        scanf("%s %lf %s", &name, &score, &grade);

        if (strcmp(grade, "A+") == 0) {
            average += 4.5 * score;
            count += score;
        }
        else if (strcmp(grade, "A0") == 0) {
            average += 4.0 * score;
            count += score;
        }
        else if (strcmp(grade, "B+") == 0) {
            average += 3.5 * score;
            count += score;
        }
        else if (strcmp(grade, "B0") == 0) {
            average += 3.0 * score;
            count += score;
        }
        else if (strcmp(grade, "C+") == 0) {
            average += 2.5 * score;
            count += score;
        }
        else if (strcmp(grade, "C0") == 0) {
            average += 2.0 * score;
            count += score;
        }
        else if (strcmp(grade, "D+") == 0) {
            average += 1.5 * score;
            count += score;
        }
        else if (strcmp(grade, "D0") == 0) {
            average += 1.0 * score;
            count += score;
        }
        else if (strcmp(grade, "F") == 0) {
            count += score;
        }
    }

    printf("%lf", (average / count));

    return 0;
}