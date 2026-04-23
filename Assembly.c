#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int assemblyLineScheduling(int a1[], int a2[], int t1[], int t2[], int e1, int e2, int x1, int x2, int n) {
    int f1[n], f2[n];
  
    f1[0] = e1 + a1[0];
    f2[0] = e2 + a2[0];

    for (int i = 1; i < n; i++) {
        f1[i] = min(f1[i-1] + a1[i], f2[i-1] + t2[i-1] + a1[i]);
        f2[i] = min(f2[i-1] + a2[i], f1[i-1] + t1[i-1] + a2[i]);
    }

    return min(f1[n-1] + x1, f2[n-1] + x2);
}

int main() {
    int n;
    printf("Enter number of stations:");
    scanf("%d", &n);

    int a1[n], a2[n], t1[n-1], t2[n-1];
    int e1, e2, x1, x2;

    printf("Enter entry times for line1 and line2:");
    scanf("%d %d", &e1, &e2);

    printf("Enter exit times for line1 and line2:");
    scanf("%d %d", &x1, &x2);

    printf("Enter processing times for line1:");
    for (int i = 0; i < n; i++) scanf("%d", &a1[i]);

    printf("Enter processing times for line2:");
    for (int i = 0; i < n; i++) scanf("%d", &a2[i]);

    printf("Enter transfer times from line1 to line2:");
    for (int i = 0; i < n-1; i++) scanf("%d", &t1[i]);

    printf("Enter transfer times from line2 to line1:");
    for (int i = 0; i < n-1; i++) scanf("%d", &t2[i]);

    int result = assemblyLineScheduling(a1, a2, t1, t2, e1, e2, x1, x2, n);
    printf("Minimum time to complete assembly = %d", result);

    return 0;
}
