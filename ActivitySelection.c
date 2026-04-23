#include <stdio.h>

struct Activity {
    int start, finish;
};

void activitySelection(struct Activity arr[], int n) {
    printf("Selected activities:\n");

    int i = 0;
    printf("(%d, %d)\n", arr[i].start, arr[i].finish);

    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            printf("(%d, %d)\n", arr[j].start, arr[j].finish);
            i = j;
        }
    }
}

int main() {
    int n;
    printf("Enter number of activities:");
    scanf("%d", &n);

    struct Activity arr[n];
    printf("Enter start and finish times:");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].finish);
    }

    activitySelection(arr, n);
    return 0;
}
