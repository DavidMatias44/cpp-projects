CXX=g++
CXXFLAGS=-c -g -std=c++17
OBJDIR=build
SRCDIR=src

OBJS=$(OBJDIR)/main.o $(OBJDIR)/lexer.o $(OBJDIR)/token.o $(OBJDIR)/tokenType.o
OUTPUT=output

$(OUTPUT): $(OBJS)
	$(CXX) $(OBJS) -o $(OUTPUT)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/lexer.o: $(SRCDIR)/lexer.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/lexer.cpp -o $(OBJDIR)/lexer.o

$(OBJDIR)/token.o: $(SRCDIR)/token.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/token.cpp -o $(OBJDIR)/token.o

$(OBJDIR)/tokenType.o: $(SRCDIR)/tokenType.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/tokenType.cpp -o $(OBJDIR)/tokenType.o

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJDIR)/*.o $(OUTPUT)
	