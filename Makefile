
CC 			= arm-none-eabi-

LDSCRIPT 	= scripts/MKL25Z4.ld

INC = 	-Idevice \
		-Ikernel/include \
		-Ikernel/portable/GCC/ARM_CM0 \
		-Iconfig \
		-Idrivers

VPATH = device: \
		drivers: \
		kernel/portable/GCC/ARM_CM0: \
		kernel/portable/MemMang: \
		kernel:\
		app: 

CFLAGS = -g -c -Wall -Os -mthumb -mcpu=cortex-m0 $(INC)
LFLAGS = -g -Wall -Os -mthumb -mcpu=cortex-m0 -nostartfiles --specs=nano.specs -T$(LDSCRIPT)

OBJS = 	startup.o \
		system_MKL25Z4.o \
		list.o \
		queue.o \
		tasks.o \
		timers.o \
		port.o \
		heap_2.o \
		main.o \
		shift.o

OUTPUT = app.elf

all: $(OBJS)
	$(CC)gcc $(LFLAGS) $(OBJS) -o $(OUTPUT)
	$(CC)size $(OUTPUT)

startup.o: startup.c
	$(CC)gcc $(CFLAGS) $^ -o $@

system_MKL25Z4.o: system_MKL25Z4.c
	$(CC)gcc $(CFLAGS) $^ -o $@

list.o: list.c
	$(CC)gcc $(CFLAGS) $^ -o $@

queue.o: queue.c
	$(CC)gcc $(CFLAGS) $^ -o $@

tasks.o: tasks.c
	$(CC)gcc $(CFLAGS) $^ -o $@

timers.o: timers.c
	$(CC)gcc $(CFLAGS) $^ -o $@

port.o: port.c
	$(CC)gcc $(CFLAGS) $^ -o $@

heap_2.o: heap_2.c
	$(CC)gcc $(CFLAGS) $^ -o $@

main.o: main.c
	$(CC)gcc $(CFLAGS) $^ -o $@

shift.o: shift.c
	$(CC)gcc $(CFLAGS) $^ -o $@


clean: $(OBJS)
	-rm $(OBJS)
	-rm $(OUTPUT)