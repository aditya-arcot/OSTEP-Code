
BUILD_DIR := build
TARGETS := p1 p2 p3 p4

all: $(TARGETS:%=$(BUILD_DIR)/%)

clean:
	rm -f $(BUILD_DIR)/p1 $(BUILD_DIR)/p2 $(BUILD_DIR)/p3 $(BUILD_DIR)/p4

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/p1: p1.c | $(BUILD_DIR)
	gcc -o $(BUILD_DIR)/p1 p1.c -Wall

$(BUILD_DIR)/p2: p2.c | $(BUILD_DIR)
	gcc -o $(BUILD_DIR)/p2 p2.c -Wall

$(BUILD_DIR)/p3: p3.c | $(BUILD_DIR)
	gcc -o $(BUILD_DIR)/p3 p3.c -Wall

$(BUILD_DIR)/p4: p4.c | $(BUILD_DIR)
	gcc -o $(BUILD_DIR)/p4 p4.c -Wall
