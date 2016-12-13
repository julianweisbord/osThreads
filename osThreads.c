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
  while(numTaken ==1){
    randNum = (rand() % 10) +1;
    int i;
    for(i=0; i<10; ++i){
      if(randNum == ranomNames[i]){
        numTaken =1;
        break;
      }
      else{
        numTaken =0;
      }
    }
    printf("Random number was: %d", randNum);
    ++folder_count;
    randomNames[count] = randNum;
  }

  // big case statement for different folder names.


  // int i;
  // for(i =0; i <10; ++i){
  //   randNum = rand() % 10;
  //   printf("%d\n", randNum);
  // }

}
