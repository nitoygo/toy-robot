# Unit Test Makefile

CXX = g++

PROJECT_DIR := $(shell pwd)/..
SRC_DIR := $(PROJECT_DIR)/src
CODE_DIR := $(SRC_DIR)/GameServer
TEST_DIR := $(PROJECT_DIR)/test
# BUILD_DIR := $(PROJECT_DIR)/build
BUILD_DIR := ./build

COVERAGE_INFO = $(TEST_DIR)/coverage.info
COVERAGE_HTML_OUTPUT = $(PROJECT_DIR)/reports/coverage

MEMLEAK_OUTPUT = $(PROJECT_DIR)/reports/memleak_unit_test.txt

SHARED_DIR := $(PROJECT_DIR)/include
INCLUDE_DIRS := $(shell find $(SRC_DIR) -type d)
INCLUDE_DIRS += $(SHARED_DIR)

# SRC_DIRS := 
SRC_FILES := $(shell find $(CODE_DIR) -name '*.cc')
APPLIB_OBJECTS := $(SRC_FILES:%=$(BUILD_DIR)/%.o)

# TEST_SRC_DIRS := 
TEST_SRC_FILES := $(shell find $(TEST_DIR) -name '*.cc')
TEST_OBJECTS := $(TEST_SRC_FILES:%=$(BUILD_DIR)/%.o)

INCLUDE_FLAGS := $(addprefix -I,$(INCLUDE_DIRS))

CXXFLAGS += -g -std=c++2a -fprofile-arcs -ftest-coverage
CPPFLAGS += -I/usr/local/include $(INCLUDE_FLAGS) -std=c++2a
LD_LIBRARIES = -L/usr/local/lib -lCppUTest -lCppUTestExt

VPATH = $(SRC_DIR) $(TEST_DIR)

$(BUILD_DIR)/%.cc.o: %.cc
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

TEST_TARGET = ToyRobotTest
APPLIB = libGameServer.a
LD_LIBRARIES += -L$(TEST_DIR) -lGameServer

$(TEST_TARGET): $(TEST_OBJECTS) $(APPLIB) 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $^ $(APPLIB) $(LD_LIBRARIES) $(LDFLAGS) 

$(APPLIB): $(APPLIB_OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

GCOV_SRC_FILES = $(shell find $(BUILD_DIR) -name '*.gcno')
GCOV_FILES = $(shell find $(BUILD_DIR) -name '*.gcov')

test: $(TEST_TARGET)
	./$(TEST_TARGET)

coverage: $(GCOV_SRC_FILES)
	gcov $(GCOV_SRC_FILES)
	lcov --capture --directory . --output-file $(COVERAGE_INFO)
	lcov --remove $(COVERAGE_INFO) '*/usr/include/*' '*/test/*' -o $(COVERAGE_INFO)
	mkdir -p $(COVERAGE_HTML_OUTPUT)
	genhtml $(COVERAGE_INFO) --output=$(COVERAGE_HTML_OUTPUT)

memcheck: $(TEST_TARGET)
	valgrind --log-file=$(MEMLEAK_OUTPUT) --leak-check=full ./$(TEST_TARGET)

clean:
	rm -f *.o
	rm -f $(TEST_OBJECTS)
	rm -f $(TEST_TARGET)
	rm -f $(APPLIB)
	rm -rf $(BUILD_DIR)
	rm -f $(COVERAGE_INFO)
	rm -f $(GCOV_FILES)
