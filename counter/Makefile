# if SYSTEMC is installed in non-standard location (and environment var set)
ifneq ($(SYSTEMC),)
	# If SystemC is manually built, must match C++std
	SYSTEMC_LIBS = lib-linuxaarch64
	# SYSTEMC_CSTD ?= ${shell nm $(SYSTEMC)/$(SYSTEMC_LIBS)/libsystemc.so | grep cxx20 | head -n 1 | sed -E 's/.*cxx20([0-9]{2}).*/\1/'}
	SYSTEMC_CSTD = 17
	CFLAGS += -I$(SYSTEMC)/include -std=c$(SYSTEMC_CSTD)
	CPPFLAGS += -I$(SYSTEMC)/include -std=c++$(SYSTEMC_CSTD)
	LDFLAGS += -L$(SYSTEMC)/$(SYSTEMC_LIBS) -lsystemc
else
	# ask the system where installed
	LDFLAGS += $(shell pkg-config --libs systemc)
endif


TARGET := main
SRCS := Testbench.cpp main.cpp ClkGen.cpp Counter.cpp
OBJS := $(SRCS:.cpp=.o)

# auto generate dependenices
#see: http://www.microhowto.info/howto/automatically_generate_makefile_dependencies.html
CPPFLAGS += -MMD -MP

# debug symbols 
CPPFLAGS += -g

# default target 
all:create_results_dir $(TARGET)

# link executable 
$(TARGET): $(OBJS)
	$(CXX) $^ $(LDFLAGS) -o $@

# create results directory if it doesn't exist
create_results_dir:
	@if [ ! -d "results" ]; then \
		echo "Creating results directory"; \
		mkdir -p results; \
	fi

# execute test
test: $(TARGET)
	./$(TARGET)

# clean everyting 
clean:
	rm -rf $(SRCS:%.cpp=%.o) $(SRCS:%.cpp=%.d) $(TARGET)
	@if [ -d "results" ]; then \
		echo "Removing results directory"; \
		rm -rf results; \
	fi

.PHONY: clean

# include generated dependencies (created upon first build)
-include $(SRCS:%.cpp=%.d)