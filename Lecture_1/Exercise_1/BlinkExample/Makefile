# Toolchain
CC=arm-none-eabi-gcc
LD=arm-none-eabi-gcc
SIZE=arm-none-eabi-size
OBJCOPY=arm-none-eabi-objcopy
STFLASH=st-flash
OPENOCD=openocd
GDB=gdb-multiarch
REMOTE=pi

# Pathes
OBJ_DIR=./obj
BIN_DIR=./bin
PROJ_ROOT=./
#LIB_DIR=$(PROJ_ROOT)/lib
PERIPH_DIR=$(PROJ_ROOT)/STM32F30x_DSP_StdPeriph_Lib_V1.2.3
PERIPH_SRC_DIR=$(PERIPH_DIR)/Libraries/STM32F30x_StdPeriph_Driver/src
PERIPH_CMSIS_DIR=$(PERIPH_DIR)/Libraries/CMSIS
BSP_DIR=$(PROJ_ROOT)/bsp/stm32/stm32f05x/ec_drive_v2_board

# Include pathes
INCLUDE+=-I$(PROJ_ROOT)/app
INCLUDE+=-I$(PERIPH_DIR)/Libraries/STM32F0xx_StdPeriph_Driver/inc
INCLUDE+=-I$(PERIPH_CMSIS_DIR)/Include
INCLUDE+=-I$(PERIPH_CMSIS_DIR)/Device/ST/STM32F0xx/Include
INCLUDE+=-I$(PROJ_ROOT)/bsp/stm32/stm32f05x/ec_drive_v2_board
INCLUDE+=-I$(BSP_DIR)
INCLUDE+=-I$(LIB_DIR)
INCLUDE+=-I$(LIB_DIR)/abst/ringbuffer
INCLUDE+=-I$(LIB_DIR)/abst/result
INCLUDE+=-I$(LIB_DIR)/func/count
INCLUDE+=-I$(LIB_DIR)/func/led
INCLUDE+=-I$(LIB_DIR)/func/interface
INCLUDE+=-I$(LIB_DIR)/func/delay
INCLUDE+=-I$(LIB_DIR)/func/trace
INCLUDE+=-I$(LIB_DIR)/func/bldc
INCLUDE+=-I$(LIB_DIR)/func/crc
INCLUDE+=-I$(LIB_DIR)/func/pio
INCLUDE+=-I$(LIB_DIR)/protocol
INCLUDE+=-I$(LIB_DIR)/protocol/llp

# Source files
# Application source files
SRC_APP+=$(PROJ_ROOT)/app/main.c
SRC_APP+=$(PROJ_ROOT)/app/cmd_handler.c

# BSP files
SRC_BSP+=$(BSP_DIR)/stm32f0xx_it.c
SRC_BSP+=$(BSP_DIR)/led/ecd_led.c
SRC_BSP+=$(BSP_DIR)/runtime/ecd_runtime.c
SRC_BSP+=$(BSP_DIR)/clock/ecd_clock.c
SRC_BSP+=$(BSP_DIR)/main_timer/ecd_main_timer.c
SRC_BSP+=$(BSP_DIR)/dbg_uart/ecd_dbg_uart.c
SRC_BSP+=$(BSP_DIR)/bldc/ecd_bldc_hall.c
SRC_BSP+=$(BSP_DIR)/bldc/ecd_bldc_pwm.c
SRC_BSP+=$(BSP_DIR)/bldc/ecd_bldc_load.c
SRC_BSP+=$(BSP_DIR)/bldc/ecd_bldc_speed.c
SRC_BSP+=$(BSP_DIR)/bldc/ecd_bldc.c
SRC_BSP+=$(BSP_DIR)/ecd_bsp.c
SRC_BSP+=$(BSP_DIR)/man_ctl/ecd_man_ctl.c
SRC_BSP+=$(BSP_DIR)/spi/ecd_spi.c
SRC_BSP+=$(BSP_DIR)/crc/ecd_crc.c
SRC_BSP+=$(BSP_DIR)/int_pin/ecd_int_pin.c
SRC_BSP+=$(BSP_DIR)/int2_pin/ecd_int2_pin.c

# Peripheral library files
SRC_PERIPH+=$(PERIPH_CMSIS_DIR)/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_adc.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_comp.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_dac.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_exti.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_i2c.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_pwr.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_spi.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_usart.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_can.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_crc.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_dbgmcu.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_flash.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_iwdg.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_rcc.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_syscfg.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_wwdg.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_cec.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_crs.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_dma.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_gpio.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_misc.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_rtc.c
SRC_PERIPH+=$(PERIPH_SRC_DIR)/stm32f0xx_tim.c

# Embedded General Libary source
SRC_LIB+=$(LIB_DIR)/abst/ringbuffer/ringbuffer.c
SRC_LIB+=$(LIB_DIR)/abst/result/egl_result.c
SRC_LIB+=$(LIB_DIR)/func/led/egl_led.c
SRC_LIB+=$(LIB_DIR)/func/count/egl_counter.c
SRC_LIB+=$(LIB_DIR)/func/interface/egl_interface.c
SRC_LIB+=$(LIB_DIR)/func/delay/egl_delay.c
SRC_LIB+=$(LIB_DIR)/func/trace/egl_trace.c
SRC_LIB+=$(LIB_DIR)/func/bldc/egl_bldc_motor.c
SRC_LIB+=$(LIB_DIR)/func/crc/egl_crc.c
SRC_LIB+=$(LIB_DIR)/func/crc/egl_crc16_ccitt.c
SRC_LIB+=$(LIB_DIR)/func/crc/egl_crc16_xmodem.c
SRC_LIB+=$(LIB_DIR)/func/pio/egl_pio.c
SRC_LIB+=$(LIB_DIR)/protocol/egl_protocol.c
SRC_LIB+=$(LIB_DIR)/protocol/llp/egl_llp.c


SRC+=$(SRC_PERIPH)
SRC+=$(SRC_APP)
SRC+=$(SRC_BSP)
SRC+=$(SRC_LIB)

VPATH=$(sort $(dir $(SRC)))

# Startap file
STARTUP_FILE=$(PERIPH_CMSIS_DIR)/Device/ST/STM32F0xx/Source/Templates/gcc_ride7/startup_stm32f051.s
STARTUPOBJ:=$(patsubst %.s, $(OBJ_DIR)/%.o, $(notdir $(STARTUP_FILE)))

# Define objects
OBJ=$(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC)))

# Compilaitor flags
CFLAGS=                            \
-Wall                              \
-g                                 \
-mcpu=cortex-m0                    \
-mthumb                            \
-D__HEAP_SIZE=0x0000               \
-D__STACK_SIZE=0x0100              \
-mfloat-abi=soft                   \
-fno-strict-aliasing               \
-fdata-sections                    \
-ffunction-sections                \
-DSTM32F051                        \
-DUSE_STDPERIPH_DRIVER             \
-DUSE_FULL_ASSERT

# Linker flags
LDFLAGS=                           \
--specs=nano.specs                 \
--specs=nosys.specs                \
-mcpu=cortex-m0                    \
-mthumb                            \
-Wl,--defsym=__HEAP_SIZE=0x0000    \
-Wl,--defsym=__STACK_SIZE=0x0100   \
-mfloat-abi=soft                   \
-fno-strict-aliasing               \
-fdata-sections                    \
-ffunction-sections                \
-Wl,--gc-sections                  \
-Wl,-Map=$(TARGET).map             \
-Wl,-script="stm32f0xx.ld"

# Target settings
TARGET_NAME=ec_drive
TARGET_BINARY=$(TARGET_NAME).elf
TARGET_HEX=$(TARGET_NAME).hex
TARGET=$(BIN_DIR)/$(TARGET_BINARY)
HEX=$(BIN_DIR)/$(TARGET_HEX)

.PHONY: $(TARGET) clean upload debug erase check-syntax

all: $(TARGET)

$(TARGET): $(OBJ_DIR) $(OBJ) $(STARTUPOBJ) $(BIN_DIR)
	$(LD) $(LDFLAGS) -o $@ $(OBJ) $(STARTUPOBJ)
	$(SIZE) --format=berkeley $(TARGET) 

$(OBJ_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(STARTUPOBJ):
	$(CC) -c $(CFLAGS) $(INCLUDES) $(STARTUP_FILE) -o $(STARTUPOBJ)

$(HEX): $(TARGET)
	$(OBJCOPY) -O ihex $(TARGET) $(HEX)

reset: 
	$(STFLASH) reset
	
reset_remote:
	ssh $(REMOTE) $(STFLASH) reset

upload: $(HEX)
	$(STFLASH) --format ihex write $(HEX)

upload_remote: $(HEX)
	scp $(HEX) $(REMOTE):~
	ssh $(REMOTE) $(STFLASH) --format ihex write $(TARGET_HEX)

erase:
	$(STFLASH) erase

debug: $(TARGET)
	setsid xterm -e 'bash -c "$(OPENOCD) -f interface/stlink-v2-1.cfg -f target/stm32f0x.cfg"' >/dev/null 2>&1 < /dev/null &
	$(GDB) -ex "target remote localhost:3333" -ex "b main" -ex "monitor reset halt" -ex "c" $(TARGET)
	pkill xterm

debug_remote: $(TARGET)
	setsid xterm -e 'bash -c "ssh pi $(OPENOCD) -f interface/stlink-v2-1.cfg -f target/stm32f0x.cfg -f ecd_openocd.cfg"' >/dev/null 2>&1 < /dev/null &
	$(GDB) -ex "target remote 192.168.0.162:3333" -ex "b main" -ex "monitor reset halt" -ex "c" $(TARGET)
	ssh $(REMOTE) pkill $(OPENOCD)
	pkill xterm

rebuild: clean $(TARGET)

check-syntax:
	$(CC) $(CFLAGS) $(INCLUDE) -o nul -S ${CHK_SOURCES}

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(BIN_DIR):
	mkdir $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
