CXX       := g++
CXXFLAGS  := -Wall -Wextra -std=c++17 -Iinclude

SRCDIR    := src
OBJDIR    := obj
BINDIR    := bin

SOURCES   := $(shell find $(SRCDIR) -name '*.cpp')
OBJECTS   := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

TARGET        := $(BINDIR)/app
DEBUG_TARGET  := $(BINDIR)/app_debug

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(OBJECTS) -o $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)/* $(BINDIR)/*

run-sample: $(TARGET)
	@if [ -f $(TARGET) ]; then \
		./$(TARGET) \
		input/alignment-params.config \
		input/base-sample.fasta \
		; \
	else \
		echo "Error: Executable $(TARGET) not found. Please build it first."; \
		exit 1; \
	fi

run-brca2: $(TARGET)
	@if [ -f $(TARGET) ]; then \
		./$(TARGET) \
		input/Human-Mouse-BRCA2-cds.fasta \
		; \
	else \
		echo "Error: Executable $(TARGET) not found. Please build it first."; \
		exit 1; \
	fi

run-blind: $(TARGET)
	@if [ -f $(TARGET) ]; then \
		./$(TARGET) input/Opsin1_colorblindness_gene.fasta; \
	else \
		echo "Error: Executable $(TARGET) not found. Please build it first."; \
		exit 1; \
	fi