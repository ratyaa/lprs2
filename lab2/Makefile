IMAGE_VIEWER =		feh
PLOT =			gnuplot
PLOTFLAGS =		-e "inputfile = \"$(DATADIR)/$(target).csv\"; \
			set output \"$(DATADIR)/$(target).png\";"

CXX = 			clang++
CXXFLAGS =		-std=c++17 -Wall
target ?=		shaker
.DEFAULT_GOAL = 	build
SRCDIR =		src
TARGETDIR =		bin
DATADIR =		data

.PHONY: build plot clean

build: $(target)

$(target): $(SRCDIR)/shaker.cpp \
$(SRCDIR)/sort_functions.* \
$(SRCDIR)/benchmark.*
	@mkdir -p $(TARGETDIR)
	@$(CXX) $(CXXFLAGS) -o $(TARGETDIR)/$(target) \
	$(SRCDIR)/sort_functions.cpp \
	$(SRCDIR)/benchmark.cpp \
	$(SRCDIR)/$(target).cpp

plot:
	@$(PLOT) $(PLOTFLAGS) $(SRCDIR)/plot.gp
	@$(IMAGE_VIEWER) $(DATADIR)/$(target).png &

clean:
	@rm $(TARGETDIR) -r

run:
	@env time -v $(TARGETDIR)/$(target)
