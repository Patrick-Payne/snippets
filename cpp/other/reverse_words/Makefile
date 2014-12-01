USER_DIR = .
CPPFLAGS += -I$(GTEST_DIR)/include/
CXXFLAGS += -g -Wall -Wextra

TESTS = test_reverse_words.out

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
reverse_words.o : $(USER_DIR)/reverse_words.cc \
	                       $(USER_DIR)/reverse_words.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) -c $(USER_DIR)/reverse_words.cc

test_reverse_words.o : $(USER_DIR)/test_reverse_words.cc \
                              $(USER_DIR)/reverse_words.h \
					                    $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/test_reverse_words.cc

test_reverse_words.out : reverse_words.o \
	                              test_reverse_words.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -pthread $^ -o $@
