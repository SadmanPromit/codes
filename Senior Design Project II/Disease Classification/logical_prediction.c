#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1024
int main() {
    int index = 2;
    char line[MAX_LINE_LENGTH];
    FILE *file = fopen("data_set_thalBD.csv", "r"); // Have to place the data_set_thalBD.csv file in the same directory
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }
    fgets(line, sizeof(line), file);
    int correct_predictions = 0;
    int total_predictions = 0;
    printf("Errors: \n");
    while (fgets(line, sizeof(line), file)) {
        char *token;
        double hbF, hbH;
        char result[20];
        char ground_truth[20] = "";
        token = strtok(line, ",");
        for (int i = 0; i < 13 && token != NULL; i++)
            token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Unexpected CSV format.\n");
            continue;
        }
        hbF = atof(token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Unexpected CSV format.\n");
            continue;
        }
        hbH = atof(token);
        token = strtok(NULL, ",");
        if (token != NULL && strlen(token) < sizeof(ground_truth))
            strcpy(ground_truth, token);
        // Hard Codded Logic
        if (hbF == 0 && hbH < 2)
            strcpy(result, "Alpha Minor");
        else if (hbF == 0 && hbH >= 21)
            strcpy(result, "Alpha Major");
        else if (hbF > 21 && hbF < 40 && hbH == 0)
            strcpy(result, "Beta Major");
        else if (hbF < 2 && hbH == 0)
            strcpy(result, "Beta Minor");
        if (strncmp(result, ground_truth, 10) == 0)
            correct_predictions++;
        else
            printf("[%d] Predicted = %s | Actual = %s\n", index, result, ground_truth);
        total_predictions++;
        index++;
    }
    fclose(file);
    double accuracy = (double) correct_predictions / total_predictions * 100.0;
    printf("\nAccuracy: %.2lf%%\n", accuracy);
    return 0;
}
