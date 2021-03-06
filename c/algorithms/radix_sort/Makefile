USER_DIR = .
CPPFLAGS += -I$(GTEST_DIR)/include/
CXXFLAGS += -g -Wall -Wextra
CCFLAGS += -g -Wall -Wextra -std=c99

TESTS = test_radix_sort.out

# All Google Test headers.  DON'T TOUCH.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

all : $(TESTS)

clean : rm -f $(TESTS) gtest.a gtest_main.a *.o

# Builds gtest.a and gtest_main.a. DON'T TOUCH.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^


# Our test code starts here.
radix_sort.o : $(USER_DIR)/radix_sort.c \
	                       $(USER_DIR)/radix_sort.h $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) $(CCFLAGS) -c $(USER_DIR)/radix_sort.c

test_radix_sort.o : $(USER_DIR)/test_radix_sort.cc \
                              $(USER_DIR)/radix_sort.h \
					                    $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/test_radix_sort.cc

test_radix_sort.out : radix_sort.o \
	                              test_radix_sort.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -pthread $^ -o $@
