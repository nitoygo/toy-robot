TARGET_EXEC := ToyRobotDemo

BUILD_DIR := ./build
SRC_DIR := .

SRCS := $(shell find $(SRC_DIR) -name '*.cc')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIR) -type d)
INC_DIRS += ../include
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# The -MMD and -MP flags together generate Makefiles for us
# These files will have .d instead of .o as the output.
CPPFLAGS := $(INC_FLAGS) -MMD -MP -std=c++2a
CXXFLAGS := -g -Wall

# The final build step.
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Build step for C++ source
$(BUILD_DIR)/%.cc.o: %.cc
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

STATIC_OUTPUT_DIR = ../reports/static
STATIC_OUTPUT_README = $(STATIC_OUTPUT_DIR)/README.md
STATIC_TEXT_OUTPUT = $(STATIC_OUTPUT_DIR)/cppcheck_report.txt

static-check:
	mkdir -p $(STATIC_OUTPUT_DIR)
	cppcheck --std=c++20 --enable=all --suppress=missingInclude $(SRC_DIR) 2> $(STATIC_TEXT_OUTPUT)
	echo "## Static Code Analaysis Report  " > $(STATIC_OUTPUT_README)
	echo '```' >> $(STATIC_OUTPUT_README)
	cat $(STATIC_TEXT_OUTPUT) >> $(STATIC_OUTPUT_README)
	echo '```' >> $(STATIC_OUTPUT_README)

-include $(DEPS)
