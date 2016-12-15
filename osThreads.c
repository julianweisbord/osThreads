#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#define STR_LEN 40


void gen_files();
void add_text(char* inputstr);

int main(int argc, char**argv){

    int len = 20;
    pid_t pid = getpid();

    // creating a directory for all of the folders
    char dirName[len];
    memset(dirName, '\0', len);
    char*folder = "julian.folders.";
    snprintf(dirName, len, "%s%d", folder, pid);
    printf("%s\n", dirName);
    mkdir(dirName, 0777);
    chdir(dirName);
    gen_files();


}

// Randomly Generate files
void gen_files(){
  srand(time(0));
  int randomNames[10] = {0};
  int randNum;
  int folder_count =0;
  int numTaken = 1;

  char inputstr[STR_LEN]; //string for adding to the first line of a file.
  memset(inputstr, '\0', STR_LEN);

  while(numTaken ==1){
    randNum = (rand() % 10) +1;
    int i;
    for(i=0; i<10; ++i){
      if(randNum == randomNames[i]){
        numTaken =1;
        // --folder_count
        break;
      }
      else{
        numTaken =0;
      }
    }
    if(numTaken ==1)
      continue;

    printf("Random number was: %d\n", randNum);
    randomNames[folder_count] = randNum;
    ++folder_count;
    printf("Folder Count %d\n", folder_count);
    numTaken = 1; //This is just to keep looping
    // big case statement for different folder names.

    switch(randNum){
      case 1:
        strncpy(inputstr, "C_is_Awesome", STR_LEN);
        inputstr[STR_LEN-1] = '\0';
        add_text(inputstr);
        memset(inputstr, '\0', STR_LEN);
        break;
      case 2:
        strncpy(inputstr, "Linux_v_Windows", STR_LEN);
        inputstr[STR_LEN-1] = '\0';
        add_text(inputstr);
        memset(inputstr, '\0', STR_LEN);
        break;
      case 3:
        strncpy(inputstr, "AudiRS5", STR_LEN);
        inputstr[STR_LEN-1] = '\0';
        add_text(inputstr);
        memset(inputstr, '\0', STR_LEN);
        break;
      case 4:
        strncpy(inputstr, "Dual4K", STR_LEN);
        inputstr[STR_LEN-1] = '\0';
        add_text(inputstr);
        memset(inputstr, '\0', STR_LEN);
        break;
        case 5:
        strncpy(inputstr, "It's_Snowing!", STR_LEN);
        inputstr[STR_LEN-1] = '\0';
        add_text(inputstr);
        memset(inputstr, '\0', STR_LEN);
        break;
      case 6:
        strncpy(inputstr, "Running_Out_of_String_Ideas", STR_LEN);
        inputstr[STR_LEN-1] = '\0';
        add_text(inputstr);
        memset(inputstr, '\0', STR_LEN);
        break;
      case 7:
        strncpy(inputstr, "This_is_A_Long_Function", STR_LEN);
        inputstr[STR_LEN-1] = '\0';
        add_text(inputstr);
        memset(inputstr, '\0', STR_LEN);
        break;
      case 8:
        strncpy(inputstr, "Seatle", STR_LEN);
        inputstr[STR_LEN-1] = '\0';
        add_text(inputstr);
        memset(inputstr, '\0', STR_LEN);
        break;
      case 9:
        strncpy(inputstr, "Silicon_Valley", STR_LEN);
        inputstr[STR_LEN-1] = '\0';
        add_text(inputstr);
        memset(inputstr, '\0', STR_LEN);
        break;
      case 10:
        strncpy(inputstr, "Programming", STR_LEN);
        inputstr[STR_LEN-1] = '\0';
        add_text(inputstr);
        memset(inputstr, '\0', STR_LEN);
        break;

      default:
        // print error to stderr
        fprintf(stderr, "Problem naming files, file_num: %d\n", randNum);
        fflush(stdout);
        exit(1);
    }

    if (folder_count ==7)
      break; // Only want to generate 7 random file names
  }



}

void add_text(char* inputstr){
  FILE* fp;
  fp = fopen(inputstr, "w+");
  fputs("Just A File...\n", fp);
  fclose(fp);
}
