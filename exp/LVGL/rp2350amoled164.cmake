if (DEFINED RP2350AMOLED164_PATH)
	message("Using Given RP2350AMOLED164_PATH '${RP2350AMOLED164_PATH}')")
else ()
	set(RP2350AMOLED164_PATH "${CMAKE_CURRENT_LIST_DIR}lib/bsp/")
    message("Using local RP2350AMOLED164_PATH '${RP2350AMOLED164_PATH}')")
endif ()

add_library(RP2350AMOLED164 STATIC)
target_sources(RP2350AMOLED164 PUBLIC
  ${RP2350AMOLED164_PATH}/AMOLED/AMOLED_1in64.c
  ${RP2350AMOLED164_PATH}/Config/DEV_Config.c
  ${RP2350AMOLED164_PATH}/QMI8658/QMI8658.c
  ${RP2350AMOLED164_PATH}/QSPI_PIO/qspi_pio.c
  ${RP2350AMOLED164_PATH}/Touch/FT3168.c
)

pico_generate_pio_header(
	RP2350AMOLED164 
	${RP2350AMOLED164_PATH}/QSPI_PIO/qspi.pio
)

# Add include directory
target_include_directories(RP2350AMOLED164 PUBLIC 
	${RP2350AMOLED164_PATH}/AMOLED/
	${RP2350AMOLED164_PATH}/Config/
	${RP2350AMOLED164_PATH}/QMI8658/
	${RP2350AMOLED164_PATH}/QSPI_PIO/
	${RP2350AMOLED164_PATH}/Touch
)


target_link_libraries(RP2350AMOLED164 PUBLIC 
	pico_stdlib
	hardware_pio 
	hardware_pwm 
	hardware_dma
	hardware_spi
	hardware_i2c
	hardware_gpio
	hardware_adc
	pico_multicore
)

