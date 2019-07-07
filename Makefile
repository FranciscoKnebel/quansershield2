# Quanser Shield v.2
# Copyright (C) 2019 Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri

# Main target programs
TARGET_LIST = quanser_pwm quanser_testepin quanser_volt quanser_pwm_cycle quanser_decode quanser_pid quanser_trajectory quanser_volt_trajectory
TARGET_SRCS = $(addsuffix .c, $(addprefix src/, ${TARGET_LIST}))
TARGET_OBJS = $(TARGET_SRCS:.c=.o)

# List of module files
# MODULE_LIST contains the space-separated module list.
# MODULE_SRCS contains the MODULE_LIST items with .c suffix and src/modules prefix.
MODULE_LIST = pwm h_bridge arm signal_module decoder
MODULE_SRCS = $(addsuffix .c, $(addprefix src/modules/, ${MODULE_LIST}))
MODULE_OBJS = $(MODULE_SRCS:.c=.o)
MODULE_LIB = shieldmodules

# Build target machine to send compiled program
BUILD_TARGET = galileo.local

FLAGS=-m32 -O2 -Wall -g -MMD -lpthread
INCLUDE=-I. -I./include
LIB_DIR=-L./lib
LIB_LIST=$(MODULE_LIB) galileo2
LIBS=$(addprefix -l, ${LIB_LIST})

CC=$(CROSS_COMPILE)gcc
CCAR=$(CROSS_COMPILE)ar
CFLAGS=$(FLAGS) $(INCLUDE)
LDFLAGS=$(LIB_DIR) $(LIBS)
CCARFLAGS=-crvs

.PHONY: all
all: lib/lib$(MODULE_LIB).a $(TARGET_LIST)
	@echo "Build finished."

## Build target programs, linking main targets with module lib.
$(TARGET_LIST): % : src/%.o
	$(CC) $(CFLAGS) -o bin/$@ $^ $(LDFLAGS)

## Build lib of modules into .a file
lib/lib$(MODULE_LIB).a: $(MODULE_OBJS)
	$(CCAR) $(CCARFLAGS) $@ $^
	@echo "Module lib compiled."

## Compile and assemble modules into object files, but does not link.
%.o: %.c c
	$(CC) $(CFLAGS) -c -o $@ $<

-include $(TARGET_SRC:.c=.d)

clean:
	rm -f *~ *.bak
	rm ${TARGET_LIST} ${TARGET_OBJS} ${TARGET_OBJS:.o=.d} lib/lib${MODULE_LIB}.a ${MODULE_OBJS} ${MODULE_OBJS:.o=.d} -f

docs: Doxyfile DoxygenLayout.xml README.md LICENSE.md $(TARGET_LIST)
	@echo "Building Doxygen..."
	doxygen

send: all
	scp bin/quanser_* root@$(BUILD_TARGET):
