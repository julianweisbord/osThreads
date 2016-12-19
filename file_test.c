#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

// This program prints the time out from the file 'time.txt'

int main(){
  FILE* fp;
  char buf[1000];
  size_t len = 0;
  ssize_t read;

  time_t rawtime;
  pid_t  pid;
  struct tm* timeinfo;
  char*time_file = "time.txt";

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  // printf("\nCurrent local time and date: %s", asctime(timeinfo)); // prints time
  fp = fopen(time_file, "r"); //Create, read/write and truncate new file.

  if(fp == NULL){
    printf("File pointer error!");
    return;
  }
  //Write to file
  fputs(asctime(timeinfo), fp);
  //read file
  printf("before while\n");
  while(fgets(buf, 1000, fp)!=NULL){
    printf("In while\n");
    printf("%s\n", buf);
  }

  fclose(fp);

}
