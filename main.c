#include <stdio.h>
float calculateBMR(int gender , float weight , float height ,int age ){
    float BMR;
    if (gender == 1){ // Male 
    BMR = (10* weight ) + (6.25 * height ) - (5 * age )+5;
    }
    else{ // Female 
    BMR =(10 * weight ) +(6.25 * height )-(5* age ) -161;
    }
    return BMR;
}

float calculateTDEE(float BMR ,int activity ){
    float factor ; 
    switch (activity){
        case 1:factor =1.2;
        break ;
        case 2:factor =1.375;
        break ;
        case 3:factor =1.55;
        break ;
        case 4:factor =1.725;
        break ;
        case 5:factor =1.9;
        break ;
        default:factor =1.2;
    }
    return BMR * factor ;
}

float calclorietrackingn(){
    int choice ,servings;
    float totalcalories =0 ;
    do {
        printf("\n Enter food item number :  \n");
        printf("[1 ] apple     (95 cal)\n");
        printf("[2 ] sandwich  (350 cal)\n");
        printf("[3 ] soda  (150 cal)\n");
        printf("[4 ] banana  (105 cal)\n");
        printf("[5 ] pizza slice  (285 cal)\n");
        printf("[6 ] stop adding (95 cal)\n");
        printf("Enter selection (1-6):");
        scanf("%d", & choice);
        if( choice >= 1 && choice <= 5 ){
            printf("Enter number of servings : ");
            scanf("%d", & servings );
            switch( choice ){
                case 1 : totalcalories += 95 * servings ;
                break ;
                case 2 : totalcalories += 350 * servings ;
                break ;
                case 3 : totalcalories += 150 * servings ;
                break ;
                case 4 : totalcalories += 105 * servings ;
                break ;
                case 5 : totalcalories += 285 * servings ;
                break ;
            }
            printf ("current total consumed :%.2f\n" , totalcalories);
        }
    }
    while (choice !=6);
    return totalcalories;
}
int main() {
   int gender ,age ,activity;
   float weight , height;
   float BMR, TDEE ,consumed ;
   printf("## daily calories calculator ##\n ");
   printf("Enter gender  (1 for Male , 2 for female ):");
   scanf("%d", & gender );
   printf("Enter weight in Kg : ");
   scanf("%f", & weight );
   printf("Enter height in Cm : ");
   scanf("%f", & height );
   printf("Enter age in yearsn: ");
   scanf("%d", & age );
   BMR = calculateBMR (gender,weight ,height, age );
   printf("\nyour estimated BMR (calories):%.2f \n", BMR);
   
   printf("\n--- TDEE calculation--- \n");
   printf("[1] lazy (little or no exercise\n)"); 
   printf("[2]  light exercise  ( 1-2 times/week)\n");
   printf("[3] moderate exercise (3-4 times/week )\n");
   printf("[4]  active exercise  (5-6 times/week )\n");
   printf("[5]  very  active  (7 times/week )\n");
   printf(" Enter selection   (1-5) : ");
   scanf("%d", & activity  );
   
     TDEE = calculateTDEE(BMR ,activity );
     printf("your total daily energy expenditure (TDEE): %.2f\n ", TDEE);
     printf("\n--- final assessment ---\n ");
     consumed = calclorietrackingn ();
     
     printf("\n--- final assessment ---\n ");
     if (consumed < TDEE ){
         printf("Result : CUTTING plase (weight loss)\n");
     }
     else if  (consumed > TDEE ){
         printf("Result : MAINIAINING  plase \n");
    }
     else{
         printf("Result : MAINIATAINING  plase (weight loss)\n");
    }
   return 0 ;
}

