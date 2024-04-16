#include <stdio.h>


int cpi_sum = 0;
int instr_total = 0;
int mhz;
int classes;
float clock_cycles;
# define MAX_CLASSES 10
int array_cpi[MAX_CLASSES]; 
int array_instr[MAX_CLASSES];
int cpi_type;
int x;
int instr_type;
float cpi_avg;
float cpu_total;
float mips_total;


void enter_params() {
   printf("enter number of instruction classes: ");
   scanf("%d",&classes);

   printf("enter frequency");
   scanf("%d",&mhz);
   
   
   for(x = 0;x < classes; x++){
      printf("enter CPI of class %d\n",x+1);
      scanf("%d",&array_cpi[x]); 
      printf("enter the instruction count for class %d\n",x+1);
      scanf("%d",&array_instr[x]);
      instr_total = instr_total + array_instr[x];
   }
   
}

void calc_CPI() {
   clock_cycles = 0;
   for(x = 0; x < classes; x++){
      clock_cycles += array_cpi[x] * array_instr[x];
   }
   cpi_avg = clock_cycles / instr_total;
  
      printf("\nThe average CPI of the sequence is: %.2f\n\n", cpi_avg);
      return;
}
   
void calc_CPU_time() {
   cpu_total = 0;
      cpu_total = clock_cycles * 1000/ mhz;
      printf("\nThe CPU time of the sequence is: %.2f\n\n", cpu_total);
     return;
}

void calc_MIPS(){
    mips_total = instr_total /cpu_total * 1000;
    printf("\nThe MIPS of the sequence is: %.2f\n\n", mips_total);
    return;
}

void print_params(){
      printf("---------------------\n");
      printf("|CLASS|  CPI| COUNT |\n");
      for( x = 0; x < classes; x++){
         printf("---------------------\n");
         printf("|%d       |%d        %d|\n",x+1, array_cpi[x], array_instr[x]);
      }

}
   
void print_perform(){
      printf("------------------------\n");
      printf("|Performance  | value  |\n");
      printf("|----------------------|\n");
      printf("|Average CPI   |%.2f   |\n",cpi_avg);
      printf("|----------------------|\n");
      printf("|CPU time (MS) |%.2f |\n",cpu_total);
      printf("|----------------------|\n");
      printf("|MIPS          |%.2f  |\n",mips_total);
      printf("|----------------------|\n");


}
   
   int main() {
      
   int choice = 0;
      while(choice != 4){
       printf("for performance metrics enter a number\n"
               "1) enter parameters \n"
               "2) print table of parameters \n"
               "3) print table of performance \n"
               "4) Exit \n");
      scanf("%d",&choice);
      switch(choice){
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
