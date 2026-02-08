#include "common_threads.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int max;
// shared global variable
int counter = 0;

void *threadfn(void *arg) {
  int id = (intptr_t)arg;
  // private local variable
  int i;
  printf("%d: start [addr of i: %p]\n", id, &i);
  for (i = 0; i < max; i++)
    counter++;
  printf("%d: done [counter: %d]\n", id, counter);
  return NULL;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s <max>\n", argv[0]);
    return 1;
  }
  max = atoi(argv[1]);

  pthread_t p1, p2;
  printf("main: start [counter: %d]\n", counter);

  Pthread_create(&p1, NULL, threadfn, (void *)0);
  Pthread_create(&p2, NULL, threadfn, (void *)1);

  Pthread_join(p1, NULL);
  Pthread_join(p2, NULL);

  printf("main: done [counter: %d] [exp: %d]\n", counter, 2 * max);
}