#include <stdio.h>

#define MAX_CLASSES 10 // Maximum number of instruction classes

int instr_total = 0;
int mhz;
int classes;
float clock_cycles;
int array_cpi[MAX_CLASSES];
int array_instr[MAX_CLASSES];
int x;
float cpi_avg;
float cpu_total;
float mips_total;

void enter_params() {
    printf("Enter number of instruction classes: ");
    scanf("%d", &classes);

    printf("Enter frequency (MHz): ");
    scanf("%d", &mhz);

    for (x = 0; x < classes; x++) {
        printf("Enter CPI of class %d: ", x + 1);
        scanf("%d", &array_cpi[x]);
    }
    for (x = 0; x < classes; x++) {
        printf("Enter the instruction count for class %d: ", x + 1);
        scanf("%d", &array_instr[x]);
        instr_total += array_instr[x];
    }
}

void calc_CPI() {
    clock_cycles = 0;
    for (x = 0; x < classes; x++) {
        clock_cycles += array_cpi[x] * array_instr[x];
    }
    cpi_avg = clock_cycles / instr_total;
    printf("\nThe average CPI of the sequence is: %.2f\n\n", cpi_avg);
}

void calc_CPU_time() {
    cpu_total = clock_cycles / (mhz * 1000000.0); // Convert MHz to Hz
    printf("The CPU time of the sequence is: %.2f seconds\n\n", cpu_total);
}

void calc_MIPS() {
    mips_total = (instr_total * 1.0) / (cpu_total * 1000000); // Convert CPU time to seconds
    printf("The MIPS of the sequence is: %.2f\n\n", mips_total);
}

void print_params() {
    printf("---------------------\n");
    printf("| CLASS | CPI | COUNT |\n");
    printf("---------------------\n");
    for (x = 0; x < classes; x++) {
        printf("| %5d | %3d | %5d |\n", x + 1, array_cpi[x], array_instr[x]);
    }
    printf("---------------------\n");
}

void print_perform() {
    printf("------------------------\n");
    printf("| Performance | Value |\n");
    printf("|----------------------|\n");
    printf("| Average CPI | %.2f |\n", cpi_avg);
    printf("| CPU time (s)| %.2f |\n", cpu_total);
    printf("| MIPS | %.2f |\n", mips_total);
    printf("|----------------------|\n");
}

int main() {
    int choice = 0;
    while (choice != 4) {
        printf("For performance metrics, enter a number:\n"
               "1) Enter parameters\n"
               "2) Print table of parameters\n"
               "3) Print table of performance\n"
               "4) Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enter_params();
                break;
            case 2:
                print_params();
                break;
            case 3:
                calc_CPI();
                calc_CPU_time();
                calc_MIPS();
                print_perform();
                break;
            case 4:
                break;
        }
    }
    return 0;
}
