
CC = cc
AR = ar

CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -Wshadow -O2
CPPFLAGS += -Iinclude
LDFLAGS ?=
LDLIBS ?=

SRC_DIR = src
BUILD_DIR = build

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))
DEPENDS = $(OBJECTS:.o=.d)

LIB = $(BUILD_DIR)/libsorting.a

DEMO_SRC = examples/main.c
DEMO_BIN = $(BUILD_DIR)/sorting-demo

TEST_SRC = $(wildcard tests/*.c)
TEST_BIN = $(BUILD_DIR)/test-sorting

.PHONY: all lib demo test clean

all: lib

lib: $(LIB)

$(LIB): $(OBJECTS)
	@mkdir -p $(@D)
	rm -f $@
	$(AR) rcs $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@

demo: $(DEMO_BIN)

$(DEMO_BIN): $(DEMO_SRC) $(LIB)
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $< $(LIB) $(LDLIBS) -o $@

test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_SRC) $(LIB)
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(TEST_SRC) $(LIB) $(LDLIBS) -o $@

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPENDS)
