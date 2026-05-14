//Write your code in this file
#include <stdio.h> //normal input output
#include <string.h> //for string length
#include <ctype.h> //for lower/uppercase

int main(){
    //array names, 5 rows, 11 characters per name (10 + null terminator)
    char name[5][11]; 
    //arrays for the 13 scores of each of the 5 students
    int p1[5],p2[5],p3[5],p4[5],p5[5],
    p6[5],p7[5],p8[5],p9[5],p10[5],p11[5],p12[5],p13[5]; 
    double average[5]; //to calculate the average score for each student
    double average_group; //to calculate the average score among all students
    double sum_group = 0; //to calculate the total score for all students
    int best_average = 0; //to calculate the student with the best average score

    //read input data: names and points for each student
    for (int i = 0; i<5; i++){
        scanf("%10s", name[i]); //scans the names, 10 characters each
        // scans the 13 scores for each student
        scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d",
            &p1[i],&p2[i],&p3[i],&p4[i],&p5[i],&p6[i],&p7[i],
            &p8[i],&p9[i],&p10[i],&p11[i],&p12[i],&p13[i]); 
    }

    //make names look nice with a capital letter at the beginning and the rest lowercase
    for (int i = 0;i<5;i++){ //go through all 5 candidates
        name[i][0] = toupper(name[i][0]);//change first letter (index 0) to capital letter
        //go through the rest of the letters in the name (from index 1 until end of the string)
        for (int j =1;j<strlen(name[i]);j++){ 
            //change the rest of the letters in the string to lowercase
            name[i][j] = tolower(name[i][j]); 
        }
    }

    //calculate average per student by counting all the points per student
    // and then dividing it by 13.0 (total amount of tests)
    for (int i = 0;i<5;i++){
        average [i] = (p1[i]+p2[i]+p3[i]+p4[i]+p5[i]+p6[i]
            +p7[i]+p8[i]+p9[i]+p10[i]+p11[i]+p12[i]+p13[i])/13.0;
    }

    //calculate students with highest average
    //assume student 0 has the best average (int best_average = 0, initialized at the top)
    //then loop through the rest of the students to compare their averages with the current best average   
    for (int i = 1;i<5;i++){
        if(average[i]> average[best_average]){
            best_average = i;
        }
    }
    // print the name of the student with the best average, 
    //outside of the loop to avoid multiple prints
    printf("%s\n", name[best_average]);

    //calculate total average for all students
    //loops through each student's average and adds the averages up to the sum    
    for(int i = 0;i<5;i++){
        sum_group += average[i];
    }
    //calculates the average score for the group 
    //by dividing the total averages by the number of students (5)
    average_group = sum_group/5.0;

    //calculate students with average below the group average
    for(int i = 0;i<5;i++){
        if(average[i]<average_group){
            //prints the names of students with average below the group average
            printf("%s\n", name[i]);
        }
    }
}