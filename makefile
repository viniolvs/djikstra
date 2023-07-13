
# Requires the following project directory structure:
#  /bin
#  /obj
#  /src

# Use 'make remove' to clean up the hole project

# Name of target file
TARGET     = graph.x

CXX        = clang++
CXXFLAGS   =  -g -std=c++11 -stdlib=libc++ -Wall\
							-Wno-error=uninitialized -Wno-missing-braces\
							-Wempty-body -Wno-error=deprecated-declarations \
							-Wpointer-arith -Wcast-qual \
							# -Weverything -Wextra  \
							# -pedantic-errors -pedantic -Os \
							# -Wno-c++98-compat -Wno-c++98-compat-pedantic \
							# -Werror # doesnt compile with warnings if active

LD         = clang++ -o
LDFLAGS    = -Wall -pedantic -stdlib=libc++

SRCDIR     = src
OBJDIR     = obj
BINDIR     = bin

SOURCES   := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES  := $(wildcard $(SRCDIR)/*.h)
OBJECTS   := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

RM         = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LD) $@ $(LDFLAGS) $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(RM) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(RM) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
