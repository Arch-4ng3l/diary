#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
int main(void) {
  if (chdir("/home/moritz/Programming/C/diary/files") != 0) {
    printf("Couldnt Open The Diary\n");
    return 1;
  }
  time_t now;
  time(&now);
  struct tm *timeInfo = localtime(&now);
  char fileName[64];
  strftime(fileName, 64, "%m-%d-%Y.txt", timeInfo);
  FILE *file = fopen(fileName, "w");
  strftime(fileName, 64, "Written at : %H:%M\n", timeInfo);
  fprintf(file, "%s", fileName);
  char buffer[256];
  system("clear");

  printf("Start Typing\n");

  fprintf(file, "\n");
  while (buffer[0] != '\0') {
    memset(buffer, 0, sizeof(buffer));
    scanf("%s", buffer);
    if (strcmp(buffer, "q") == 0) {
      break;
    }
    fprintf(file, "%s\n", buffer);
  }
  fclose(file);
}
