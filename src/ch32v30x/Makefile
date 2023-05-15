# ch32v30x build rules

# Setup the toolchain
# toolchain can be found at http://www.mounriver.com/download
CROSS_PREFIX=riscv-none-embed-

dirs-y += src/ch32v30x lib/ch32v30x/driver lib/ch32v30x/core lib/ch32v30x/mcu src/generic

CFLAGS += -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Isrc/ch32v30x -Ilib/ch32v30x/driver/include -Ilib/ch32v30x/core -Ilib/ch32v30x/mcu -nostartfiles

CFLAGS_klipper.elf += --specs=nano.specs --specs=nosys.specs
CFLAGS_klipper.elf += -T lib/ch32v30x/Link.ld
$(OUT)klipper.elf: lib/ch32v30x/Link.ld

# Add source files
src-y += ../lib/ch32v30x/mcu/system_ch32v30x.c
src-y += ch32v30x/main.c
src-y += ch32v30x/timer.c
src-y += generic/crc16_ccitt.c
# src-y += ch32v30x/interrupts.c
# src-y += ch32v30x/gpio.c
# src-y += ../lib/ch32v30x/mcu/common/system_hc32f460.c
# src-y += ../lib/ch32v30x/driver/src/hc32f460_clk.c
# src-y += ../lib/ch32v30x/driver/src/hc32f460_efm.c
# src-y += ../lib/ch32v30x/driver/src/hc32f460_sram.c
# src-y += ../lib/ch32v30x/driver/src/hc32f460_utility.c
# src-y += ../lib/ch32v30x/driver/src/hc32f460_gpio.c
# src-y += ../lib/ch32v30x/driver/src/hc32f460_pwc.c
# src-$(CONFIG_HAVE_GPIO_ADC) += ch32v30x/adc.c ../lib/hc32f460/driver/src/hc32f460_adc.c
# src-$(CONFIG_SERIAL) += ch32v30x/serial.c generic/serial_irq.c ../lib/hc32f460/driver/src/hc32f460_usart.c
src-$(CONFIG_SERIAL) += generic/serial_irq.c ch32v30x/serial.c
# src-$(CONFIG_HAVE_GPIO_HARD_PWM) += ch32v30x/hard_pwm.c ../lib/hc32f460/driver/src/hc32f460_timera.c
# src-y += generic/armcm_boot.c generic/armcm_irq.c generic/armcm_timer.c
# src-y += generic/armcm_reset.c generic/crc16_ccitt.c


# Build asm file
$(OUT)startup.o: lib/ch32v30x/mcu/startup_ch32v30x_D8C.S
	@echo "  Building ch32 startup $@"
	$(Q)$(CC) $(CFLAGS) -c $< -o $(OUT)startup.o
OBJS_klipper.elf += $(OUT)startup.o

# Build the additional bin output file
target-y += $(OUT)klipper.bin

$(OUT)klipper.bin: $(OUT)klipper.elf
	@echo "  Creating bin file $@"
	$(Q)$(OBJCOPY) -O binary $< $@
