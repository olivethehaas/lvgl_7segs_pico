add_library(xpt2046
	xpt2046.c
	pio_spi.c
)

target_include_directories(xpt2046 PUBLIC
	.
)

pico_generate_pio_header(xpt2046 ${CMAKE_CURRENT_LIST_DIR}/spi.pio)

target_link_libraries(xpt2046 pico_stdlib hardware_spi hardware_dma hardware_pwm hardware_pio lvgl)
