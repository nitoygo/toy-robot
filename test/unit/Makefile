CXX = g++

ADAPTER_TEST_OUT = test-adapter
SERVICE_TEST_OUT = test-service
DOMAIN_TEST_OUT = test-domain

ALL_TESTS = adapter-test  service-test  domain-test

SRC_DIR = ../../src
TEST_DIR = ./

INC_DIRS := $(shell find $(SRC_DIR) -type d) ./include/external
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

ADAPTER_SRC_DIR = $(SRC_DIR)/GameServer/Adapters
DOMAIN_SRC_DIR = $(SRC_DIR)/GameServer/Core/Domain
SERVICES_SRC_DIR = $(SRC_DIR)/GameServer/Core/Services

ADAPTER_TEST_DIR = $(TEST_DIR)/GameServer/Adapters
DOMAIN_TEST_DIR = $(TEST_DIR)/GameServer/Core/Domain
SERVICES_TEST_DIR = $(TEST_DIR)/GameServer/Core/Services

ADAPTER_SRCS := $(shell find $(ADAPTER_SRC_DIR) -name '*.cc')
DOMAIN_SRCS := $(shell find $(DOMAIN_SRC_DIR) -name '*.cc')
SERVICES_SRCS := $(shell find $(SERVICES_SRC_DIR) -name '*.cc')

ADAPTER_TESTS := $(shell find $(ADAPTER_TEST_DIR) -name '*.cc')
DOMAIN_TESTS := $(shell find $(DOMAIN_TEST_DIR) -name '*.cc')
SERVICES_TESTS := $(shell find $(SERVICES_TEST_DIR) -name '*.cc')

CATCH_DEPS = ./include/external/catch.hpp

CPPFLAGS := $(INC_FLAGS) -std=c++2a
CXXFLAGS := -g -Wall -Werror -fprofile-arcs -ftest-coverage

MAIN = main.o

all: $(ALL_TESTS)

main.o: $(TEST_DIR)/main.cc
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(TEST_DIR)/main.cc

adapter-test: $(CATCH_DEPS) $(MAIN) $(ADAPTER_SRCS) $(ADAPTER_TESTS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $(ADAPTER_TEST_OUT) $(MAIN) $(ADAPTER_SRCS) $(ADAPTER_TESTS)

service-test: $(CATCH_DEPS) $(MAIN) $(SERVICE_SRCS) $(SERVICE_TESTS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $(SERVICE_TEST_OUT) $(MAIN) $(SERVICE_SRCS)  $(SERVICE_TESTS)

domain-test: $(CATCH_DEPS) $(MAIN) $(DOMAIN_SRCS) $(DOMAIN_TESTS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $(DOMAIN_TEST_OUT) $(MAIN) $(DOMAIN_SRCS) $(DOMAIN_TESTS)

clean:
	rm -rf *.dSYM
	rm -f *.o *.gc* *.info
	rm $(ADAPTER_TEST_OUT) $(SERVICE_TEST_OUT) $(DOMAIN_TEST_OUT)
