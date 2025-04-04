#include <stdio.h>
#include <string.h>
struct SessionLog {
    char emotion[20];
    char feedback[100];
    char activity[100];
};

void getFeedback(char emotion[], struct SessionLog *log) {
    strcpy(log->emotion, emotion);

    if (strcmp(emotion, "happy") == 0) {
        strcpy(log->feedback, "Great job! Keep smiling!");
        strcpy(log->activity, "Play a group game.");
    } else if (strcmp(emotion, "sad") == 0) {
        strcpy(log->feedback, "It's okay to feel sad. Let's cheer up!");
        strcpy(log->activity, "Watch a cartoon video.");
    } else if (strcmp(emotion, "angry") == 0) {
        strcpy(log->feedback, "Take a deep breath and relax.");
        strcpy(log->activity, "Color something you like.");
    } else if (strcmp(emotion, "surprise") == 0) {
        strcpy(log->feedback, "Wow! That’s exciting!");
        strcpy(log->activity, "Explore a new VR room.");
    } else {
        strcpy(log->feedback, "You're doing great!");
        strcpy(log->activity, "Play a fun game.");
    }
}

int main() {
    char name[50];
    char inputEmotion[20];
    char choice;
    struct SessionLog logs[100];
    int count = 0;

    printf("=== ISE: Interactive Skills Enhancer (C Version) ===\n");
    printf("Enter Child's Name: ");
    scanf("%s", name);

    do {
        printf("\nEnter detected emotion (happy/sad/angry/surprise): ");
        scanf("%s", inputEmotion);

        getFeedback(inputEmotion, &logs[count]);
        printf("\nFeedback: %s\n", logs[count].feedback);
        printf("Suggested Activity: %s\n", logs[count].activity);

        count++;

        printf("\nDo you want to input another emotion? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\n=== Session Summary for %s ===\n", name);
    for (int i = 0; i < count; i++) {
        printf("Emotion: %s | Feedback: %s | Activity: %s\n",
               logs[i].emotion, logs[i].feedback, logs[i].activity);
    }

    return 0;
}
