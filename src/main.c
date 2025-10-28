#include "common.h"

void runTerminal();
void readFile(const char *fileName);
void run(const char *source);

int main(int argc, char *argv[]){
  if(argc == 1){
    runTerminal();
  }
  else if(argc == 2){
    readFile(argv[1]);
  }
  else{
    printf("Usage ./run 'file name' | ./run\n");
    exit(1);
  }
  return 0;
}

void runTerminal(){
  char *source = malloc(sizeof(char) * 1024);
  printf("> ");
  fgets(source, 1024, stdin);
  run(source);
}

void readFile(const char *fileName){
  FILE *file = fopen(fileName, "r");
  if(file == NULL){
    fprintf(stderr, "Could not open file\n");
    exit(1);
  }
  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  rewind(file);
  char *source = malloc(sizeof(char) * size + 1);
  fread(source, 1, size, file);
  source[size] = '\0';
  fclose(file);
  run(source);
}

void run(const char *source){
  printf("%s", source);
}

