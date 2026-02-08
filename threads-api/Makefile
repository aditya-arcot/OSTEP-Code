CC     := gcc
CFLAGS := -Wall -Werror -I../include

SRCS   := thread_create.c \
	thread_create_simple_args.c \
	thread_create_with_return_args.c \
    thread_loop.c \
    thread_counter.c

BUILD_DIR := build
OBJS      := ${SRCS:c=o}
PROGS     := ${SRCS:.c=}
BUILD_OBJS  := ${OBJS:%=${BUILD_DIR}/%}
BUILD_PROGS := ${PROGS:%=${BUILD_DIR}/%}

.PHONY: all
all: ${BUILD_PROGS}

${BUILD_DIR}:
	mkdir -p ${BUILD_DIR}

${BUILD_PROGS} : ${BUILD_DIR}/% : ${BUILD_DIR}/%.o Makefile | ${BUILD_DIR}
	${CC} $< -o $@ -pthread

clean:
	rm -f ${BUILD_PROGS} ${BUILD_OBJS}

${BUILD_DIR}/%.o: %.c Makefile | ${BUILD_DIR}
	${CC} ${CFLAGS} -c $< -o $@
