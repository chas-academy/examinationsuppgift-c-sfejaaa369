//Write your code in this file
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char name[5][11];
    int p1[5],p2[5],p3[5],p4[5],p5[5],
    p6[5],p7[5],p8[5],p9[5],p10[5],p11[5],p12[5],p13[5];
    double average[5];
    double average_group;
    double sum_group = 0;
    int best_average = 0;

    //read input data
    for (int i = 0; i<5; i++){
        scanf("%10s", name[i]);
        scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d",
            &p1[i],&p2[i],&p3[i],&p4[i],&p5[i],&p6[i],&p7[i],
            &p8[i],&p9[i],&p10[i],&p11[i],&p12[i],&p13[i]);
    }

    //make names look nice with a capital letter at the beginning and the rest lowercase
    for (int i = 0;i<5;i++){
        name[i][0] = toupper(name[i][0]);
        for (int j =1;j<strlen(name[i]);j++){
            name[i][j] = tolower(name[i][j]);
        }
    }

    //calculate average
    for (int i = 0;i<5;i++){
        average [i] = (p1[i]+p2[i]+p3[i]+p4[i]+p5[i]+p6[i]
            +p7[i]+p8[i]+p9[i]+p10[i]+p11[i]+p12[i]+p13[i])/13.0;
    }

    //calculuate best average
    for (int i = 1;i<5;i++){
        if(average[i]> average[best_average]){
            best_average = i;
        }
    }
    printf("%s\n", name[best_average]);

    //calculate group average
    for(int i = 0;i<5;i++){
        sum_group += average[i];
    }

    average_group = sum_group/5.0;

    //print names of students with average below group average
    for(int i = 0;i<5;i++){
        if(average[i]<average_group){
            printf("%s\n", name[i]);
    }
}

}