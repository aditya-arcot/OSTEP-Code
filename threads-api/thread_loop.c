#include "common_threads.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *threadfn(void *arg) {
  for (int i = 0; i < 1000000; i++)
    ;
  printf("thread %s\n", (char *)arg);
  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t p[10];
  char sbuf[10][5];
  printf("start\n");
  for (int i = 0; i < 10; i++) {
    sprintf(sbuf[i], "%d", i);
    Pthread_create(&p[i], NULL, threadfn, sbuf[i]);
  }
  for (int i = 0; i < 10; i++) {
    Pthread_join(p[i], NULL);
  }
  printf("done\n");
}
