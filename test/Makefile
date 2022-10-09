# Unit Test Makefile

TEST_TARGET = ToyRobotTest
CXX = g++

PROJECT_DIR := $(shell pwd)/..
SRC_DIR := $(PROJECT_DIR)/src
CODE_DIR := $(SRC_DIR)/GameServer
TEST_DIR := $(PROJECT_DIR)/test
# BUILD_DIR := $(PROJECT_DIR)/build
BUILD_DIR := ./build

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

CXXFLAGS += -g -std=c++2a
CPPFLAGS += -I/usr/local/include $(INCLUDE_FLAGS) -std=c++2a
LD_LIBRARIES = -L/usr/local/lib -lCppUTest -lCppUTestExt

VPATH = $(SRC_DIR) $(TEST_DIR)

$(BUILD_DIR)/%.cc.o: %.cc
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

CPPFLAGS += -I.
APPLIB = GameServer.a

$(TEST_TARGET): $(TEST_OBJECTS) $(APPLIB)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $^ $(LD_LIBRARIES) $(LDFLAGS)
	./$(TEST_TARGET)

$(APPLIB): $(APPLIB_OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	rm -f *.o
	rm -f $(TEST_OBJECTS)
	rm -f $(TEST_TARGET)
	rm -f $(APPLIB)
	rm -rf $(BUILD_DIR)
