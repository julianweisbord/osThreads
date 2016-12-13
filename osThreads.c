#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

void gen_files();

int main(int argc, char**argv){

    int len = 20;
    pid_t pid = getpid();

    // creating a directory for all of the folders
    char dirName[len];
    memset(dirName, '\0', len);
    char*folder = "julian.folders.";
    snprintf(dirName, len, "%s%d", folder, pid);
    printf("%s\n", dirName);
    // mkdir(dirName, 0777);
    // chdir(dirName);
    gen_files();

}

// Randomly Generate files
void gen_files(){
  srand(time(0));
  int randomNames[10] = {0};
  int randNum;
  int folder_count =0;
  int numTaken = 1;
  while(numTaken ==1){
    randNum = (rand() % 10) +1;
    int i;
    for(i=0; i<10; ++i){
      if(randNum == randomNames[i]){
        numTaken =1;
        break;
      }
      else{
        numTaken =0;
      }
    }
    printf("Random number was: %d\n", randNum);
    randomNames[folder_count] = randNum;
    ++folder_count;
    numTaken = 1; //This is just to keep looping
    if (folder_count ==7)
      break; // Only want to generate 7 random file names
  }

  // big case statement for different folder names.


  // int i;
  // for(i =0; i <10; ++i){
  //   randNum = rand() % 10;
  //   printf("%d\n", randNum);
  // }

}
