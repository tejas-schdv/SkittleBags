
//SkittleBagProject
//Created by Tejas Sachdeva and Luis M. Figueroa


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
//#include "Bag.h"
#include <omp.h>
#include <time.h>
#include <math.h>

#define MAX_CAPACITY_BAG 60
//IDEAL_AVERAGE is the number we though to be best average according to documentation which is a number 400-500
//this number will be used to compare each threads average and see how close it IDEAL_AVERAGE to assign bestAverage
#define IDEAL_AVERAGE 450
#define SKITTLE_NUMBER_TOTAL 6
#define INITIAL_ARRAY_CAPACITY 1000

typedef enum skittlesColor{
    RED,
    PURPLE,
    YELLOW,
    GREEN,
    ORANGE,
    BLUE,
}COLOR;


typedef struct {
    int red;
    int blue;
    int purple;
    int yellow;
    int green;
    int orange;


}SKITTLE_BAG;

//void printSkittleBag(SKITTLE_BAG *currentBag);
//SKITTLE_BAG *createBag();
//bool foundDuplicate(SKITTLE_BAG *currentBag,  SKITTLE_BAG bagArray[],int size_array);



//creates a bag of Skittles where it randomizes the a number that corresponds to a skittle color enum and increments color counter
SKITTLE_BAG *createBag(){

    SKITTLE_BAG *newBag=(SKITTLE_BAG*)malloc(sizeof(SKITTLE_BAG));



    int randomSkittle;
    for(int i=0;i<MAX_CAPACITY_BAG;i++){

        randomSkittle=random()%SKITTLE_NUMBER_TOTAL;
        if(randomSkittle==BLUE) {
            newBag->blue++;
        }else if(randomSkittle==GREEN){

            newBag->green++;
        }else if(randomSkittle==RED){
            newBag->red++;

        }else if(randomSkittle==PURPLE){
            newBag->purple++;

        }else if(randomSkittle==YELLOW){
            newBag->yellow++;
        }else if(randomSkittle == ORANGE){

            newBag->orange++;
        }

    }

    return newBag;
}


void printSkittleBag(SKITTLE_BAG *currentBag){
    printf("Blue: %d Red: %d Green: %d Purple: %d, Yellow: %d Orange: %d\n",currentBag->blue,currentBag->red,currentBag->green,currentBag->purple,currentBag->yellow,currentBag->orange);

}


//currentBag is the bag that we checking to see if there is a copy in bagArray
//bagArray is the bagArray that contains the bags of skittles
//size_bagArray is the number of bags currently in bagArray excluding currentBag
//if the quatity of all numbers match return true else false 
bool foundDuplicate(SKITTLE_BAG *currentBag,  SKITTLE_BAG bagArray[], int size_bagArray){



    int count=0;

    while(count<size_bagArray) {

        if (currentBag->blue == bagArray[count].blue) {
            if (currentBag->red == bagArray[count].red) {


                if(currentBag->green == bagArray[count].green) {
                    if(currentBag->orange == bagArray[count].orange) {
                        if (currentBag->purple == bagArray[count].purple) {
                            if (currentBag->yellow == bagArray[count].yellow) {
                                //printf("\t\t\t\tFound duplicate in bag %d out of %d bags created\n",count,size_bagArray );
                                return true;
                            }
                            else {
                                count++;
                            }
                        }
                        else {
                            count++;
                        }
                    }else {
                        count++;
                    }
                }else {
                    count++;
                }
            }else {
                count++;
            }
        }else {
            count++;
        }




    }
    return false;

}


int main() {

//bestAverage is the average that will be updated by each thread if its close to IDEAL_AVERAGE
//IDEAL_AVERAGE value is 450 since the documentation said the average was between 400-500
double bestAverage,average;
int threadId, numThreads, num_DuplicatesFound;
int totalThreads=0;
double count=0;
double elapsed;


//the simulation will run according to the users input 
printf("Enter how long to run simulation in seconds:\n");
scanf("%lf",&count);



//each thread will run the same program once a duplicate is found it computes average and compares to bestAverage 
//at end of program once the time has expired the bestAverage is printed
#pragma omp parallel shared(count,average,totalThreads,num_DuplicatesFound,bestAverage) private(threadId, numThreads)
  {
	threadId=omp_get_thread_num();
	numThreads=omp_get_num_threads();


time_t start, end;
   start = time(NULL);
   int terminate = 1;
  while (terminate) {
    
        
        SKITTLE_BAG *newBag = createBag();
        
        bool found = false;
        SKITTLE_BAG arraySkittles[INITIAL_ARRAY_CAPACITY];

        arraySkittles[0] = *newBag;
        for (int i = 1; !found && i < INITIAL_ARRAY_CAPACITY; i++) {
            newBag = createBag();
            

            if (foundDuplicate(newBag, arraySkittles, i + 1) == 1) {
                //printf("Found copy in bag %d and thread %d\n",(i+1),threadId);
                found = true;
		average+=(i+1);
		num_DuplicatesFound++;

            } else {
                arraySkittles[i] = *newBag;
            }

        }

//this section will compute the average once a bag is found and compare how close it is to IDEAL_AVERAGE
//if the currentAverage is close IDEAL_AVERAGE it will update the best_average and print the thread number the currentAverage and the previous bestAverage
	if (fabs((average/num_DuplicatesFound)-IDEAL_AVERAGE) <= (fabs(bestAverage-IDEAL_AVERAGE))) {
printf("Thread %d The current average is %lf the best average is %lf\n",threadId,average/num_DuplicatesFound,bestAverage);
bestAverage=average/num_DuplicatesFound;
}


//end of searching loop


//this section will check to see how much time has passed and compare to the users input
//if there's time remaining the program will run again else it will stop program and print stats 
end = time(NULL);
     elapsed = difftime(end, start);
     if (elapsed >= count){
       terminate = 0;
     }
	
}
//end of creating and searching for duplicates loop

}
//end of parallel loop        
	
	
	printf("Total number of Bags created: %.f\n",average);
	printf("Number of duplicates bags found: %d\n",num_DuplicatesFound);
        printf("Best Average %.f\n",bestAverage );

        printf("Complete\n");

    
    return 0;
}
