#!/bin/sh
# This script generates a new C project, complete with google test program code
# and makefile.
# USAGE: ./setup_c_snippet.sh TYPE PROJECT_NAME

SUBDIR_NAME=$1
PROJECT_NAME=$2
PROJECT_DIR="$1/$2"
ALL_CAPS_PROJECT_NAME=$(echo "$PROJECT_NAME" | tr 'a-z' 'A-Z')
DATE=$(date)

# Do some basic validation on the input.
if [ -z "$PROJECT_NAME" ]; then
  echo "No project name was provided!"
  echo "Usage: $0 PROJECT_TYPE PROJECT_NAME"
  exit 1
fi

if [ -z "$PROJECT_NAME" ]; then
  echo "No snippet type was was provided!"
  echo "Usage: $0 PROJECT_TYPE PROJECT_NAME"
  exit 1
fi

if [ -e "$PROJECT_DIR" ]; then
  if [ -d "$PROJECT_DIR" ]; then
    echo "The directory $PROJECT_DIR already exists!"
  else
    echo "A file called $PROJECT_DIR already exists!"
  fi

  exit 1
fi


# Now we generate the files.
mkdir -p "$PROJECT_DIR"

# Generate the makefile.
cat << _EOF_ > "${PROJECT_DIR}/Makefile"
USER_DIR = .
CPPFLAGS += -I\$(GTEST_DIR)/include/
CXXFLAGS += -g -Wall -Wextra
CCFLAGS += -g -Wall -Wextra -std=c99

TESTS = test_${PROJECT_NAME}.out

# All Google Test headers.  DON'T TOUCH.
GTEST_HEADERS = \$(GTEST_DIR)/include/gtest/*.h \\
                \$(GTEST_DIR)/include/gtest/internal/*.h

all : \$(TESTS)

clean : rm -f \$(TESTS) gtest.a gtest_main.a *.o

# Builds gtest.a and gtest_main.a. DON'T TOUCH.
GTEST_SRCS_ = \$(GTEST_DIR)/src/*.cc \$(GTEST_DIR)/src/*.h \$(GTEST_HEADERS)

gtest-all.o : \$(GTEST_SRCS_)
	\$(CXX) \$(CPPFLAGS) -I\$(GTEST_DIR) \$(CXXFLAGS) -c \\
            \$(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : \$(GTEST_SRCS_)
	\$(CXX) \$(CPPFLAGS) -I\$(GTEST_DIR) \$(CXXFLAGS) -c \\
            \$(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	\$(AR) \$(ARFLAGS) \$@ \$^

gtest_main.a : gtest-all.o gtest_main.o
	\$(AR) \$(ARFLAGS) \$@ \$^


# Our test code starts here.
${PROJECT_NAME}.o : \$(USER_DIR)/${PROJECT_NAME}.c \\
	                       \$(USER_DIR)/${PROJECT_NAME}.h \$(GTEST_HEADERS)
	\$(CC) \$(CPPFLAGS) \$(CCFLAGS) -c \$(USER_DIR)/${PROJECT_NAME}.c

test_${PROJECT_NAME}.o : \$(USER_DIR)/test_${PROJECT_NAME}.cc \\
                              \$(USER_DIR)/${PROJECT_NAME}.h \\
					                    \$(GTEST_HEADERS)
	\$(CXX) \$(CPPFLAGS) \$(CXXFLAGS) -c \$(USER_DIR)/test_${PROJECT_NAME}.cc

test_${PROJECT_NAME}.out : ${PROJECT_NAME}.o \\
	                              test_${PROJECT_NAME}.o gtest_main.a
	\$(CXX) \$(CPPFLAGS) \$(CXXFLAGS) -pthread \$^ -o \$@
_EOF_

# Generate the Header file.
cat << _EOF_ > "${PROJECT_DIR}/${PROJECT_NAME}.h"
/******************************************************************************
 * File: ${PROJECT_NAME}.h
 * Author: Patrick Payne
 * Date Created: ${DATE}
 * Purpose:
 * Copyright ${DATE} by Patrick Payne.
 *****************************************************************************/
#ifndef SNIPPET_C_${ALL_CAPS_PROJECT_NAME}_H_
#define SNIPPET_C_${ALL_CAPS_PROJECT_NAME}_H_

#endif /* SNIPPET_C_${ALL_CAPS_PROJECT_NAME}_H_ */
_EOF_

# Generate the C implementation file.
cat << _EOF_ > "${PROJECT_DIR}/${PROJECT_NAME}.c"
/******************************************************************************
 * File: ${PROJECT_NAME}.c
 * Author: Patrick Payne
 * Date Created: ${DATE}
 * Purpose:
 * Copyright ${DATE} by Patrick Payne.
 *****************************************************************************/
#include "${PROJECT_NAME}.h"
_EOF_

# Generate the c++ test code file.
cat << _EOF_ > "${PROJECT_DIR}/test_${PROJECT_NAME}.cc"
/******************************************************************************
 * File: test_${PROJECT_NAME}.cc
 * Author: Patrick Payne
 * Date Created: ${DATE}
 * Purpose:
 * Copyright ${DATE} by Patrick Payne.
 *****************************************************************************/

extern "C" {
#include "${PROJECT_NAME}.h"
}

#include "gtest/gtest.h"

/******************************************************************************
 * Test Cases
 *****************************************************************************/ 

TEST(SUITE_NAME, TEST_NAME) {
}
_EOF_
