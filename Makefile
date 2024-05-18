CXX = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS =

SRCDIR = src
OBJDIR = obj

SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC))
DEP = $(OBJ:.o=.d)
EXECUTABLE = game

CPPCHECK = cppcheck
BUILD_DIR = cppcheck_build

.PHONY: all clean cppcheck

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CXX) $(LDFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c -MMD -MP $< -o $@

cppcheck:
	mkdir -p $(BUILD_DIR)
	$(CPPCHECK) --enable=all --xml --xml-version=2 --cppcheck-build-dir=$(BUILD_DIR) $(SRC) 2> $(BUILD_DIR)/cppcheck.xml
	$(CPPCHECK) --enable=all --cppcheck-build-dir=$(BUILD_DIR) $(SRC)

clean:
	rm -rf $(OBJDIR) $(EXECUTABLE) $(DEP) $(BUILD_DIR)

-include $(DEP)