CXX=g++
CXXFLAGS=-c -g -std=c++17
OBJDIR=build
SRCDIR=src

OBJS=$(OBJDIR)/main.o $(OBJDIR)/task.o $(OBJDIR)/taskList.o $(OBJDIR)/utils.o
OUTPUT=output

$(OUTPUT): $(OBJS)
	$(CXX) $(OBJS) -o $(OUTPUT)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/utils.o: $(SRCDIR)/utils.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/utils.cpp -o $(OBJDIR)/utils.o

$(OBJDIR)/task.o: $(SRCDIR)/task.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/task.cpp -o $(OBJDIR)/task.o

$(OBJDIR)/taskList.o: $(SRCDIR)/taskList.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/taskList.cpp -o $(OBJDIR)/taskList.o

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJDIR)/*.o $(OUTPUT)
