IMAGE_VIEWER =		feh
PLOT =			gnuplot
PLOTFLAGS =		-e "inputfile = \"$(DATADIR)/$(target).csv\"; \
			set output \"$(DATADIR)/$(target).png\";"

CXX = 			clang++
CXXFLAGS =		-std=c++17 -Wall
target ?=		shaker
SRCDIR =		src
TARGETDIR =		bin
DATADIR =		data

.DEFAULT_GOAL = 	all

.PHONY: build plot clean all

all: build run plot

build: $(TARGETDIR)/$(target)

$(TARGETDIR)/$(target): $(SRCDIR)/$(target).cpp \
$(SRCDIR)/sort_functions.* \
$(SRCDIR)/benchmark.*
	@mkdir -p $(TARGETDIR)
	@$(CXX) $(CXXFLAGS) -o $(TARGETDIR)/$(target) \
	$(SRCDIR)/sort_functions.cpp \
	$(SRCDIR)/benchmark.cpp \
	$(SRCDIR)/$(target).cpp

plot:
ifneq ($(wildcard $(DATADIR)/$(target).csv),)
	@$(PLOT) $(PLOTFLAGS) $(SRCDIR)/plot.gp
	@$(IMAGE_VIEWER) $(DATADIR)/$(target).png &
endif

clean:
	@rm $(TARGETDIR) -r

run:
	@env time -v $(TARGETDIR)/$(target)
