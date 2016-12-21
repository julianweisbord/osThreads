#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

#define STR_LEN 400
#define MAX_ARGS 512


void gen_files();
void add_text(char* inputstr);
void shell();
void time2File(); //Outputs the current time to a file then prints it to stdout

int main(int argc, char**argv){

    int len = 20;
    pid_t pid = getpid();

    // creating a directory for all of the folders with a process id in the name
    char dirName[len];
    memset(dirName, '\0', len);
    char* folder = "julian.folders.";
    snprintf(dirName, len, "%s%d", folder, pid);
    printf("%s\n", dirName);
    mkdir(dirName, 0777);
    chdir(dirName);
    gen_files();
    shell();

}


// Decides what to do with user input
void shell(){
  char user_input[STR_LEN];

  int arg_num =0;
  int i;
  while(1 > 0){
    char* args_arr[MAX_ARGS+1];
    printf("\n");
    printf("Command > ");
    fgets(user_input, STR_LEN, stdin);
    printf("User input: %s \n", user_input);

    args_arr[0] = strdup(user_input);
    args_arr[1] = NULL;

    // printf("Arg zero: %s\n",args_arr[0]);
    if (strcmp(args_arr[0], "exit\n") ==0){
      fprintf(stdout, "exitting...\n");
      fflush(stdout);
      exit(0);
    }
    else if(strcmp(args_arr[0], "time\n") ==0){
      time2File();
    }
    else{
      // make bash handle it
      strtok(args_arr[0], "\n"); // Get rid of newline so that execvp recognizes the command

      if(execvp(args_arr[0], args_arr) < 0){ //If this program doesn't recognize the command, have your computer's shell execute it.
        fprintf(stderr, "Command not found: %s\n", args_arr[0]);
        fflush(stdout);
        fprintf(stderr, "USAGE: <time> | <exit> | <'shell-command'>\n");
        fflush(stdout);
        exit(1);
      }
    }



  }

}
// Forking isn't necessary in this function but is a test.
void time2File(){

  FILE* fp;
  char buf[1000];
  size_t len = 0;
  ssize_t read;

  time_t rawtime;
  pid_t  pid;
  struct tm* timeinfo;
  char*time_file = "time.txt";

  pid = fork();
  switch(pid){

    case 0: // child writes local time to a file then prints the file line by line
      time(&rawtime);
      timeinfo = localtime(&rawtime);
      // printf("\nCurrent local time and date: %s", asctime(timeinfo)); // prints time
      fp = fopen(time_file, "w+"); //Create, read/write and truncate new file.

      if(fp == NULL){
        printf("File pointer error!");
        return;
      }
      //Write to file
      fputs(asctime(timeinfo), fp);

      fclose(fp);
      //read file
      fp = fopen(time_file, "r");
      while(fgets(buf, 1000, fp)!=NULL){
        // printf("In while\n");
        printf("\n%s\n", buf);
      }
      fclose(fp);
      break;

    case 1: //parent
      printf("in parent!\n"); //May not need to wait() because parent process exits quickly.
      if (waitpid(pid, NULL, 0) < 0) {
        perror("Failed to collect child process");
        break;
      }
      break;

  }
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


    randomNames[folder_count] = randNum;
    ++folder_count;

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
