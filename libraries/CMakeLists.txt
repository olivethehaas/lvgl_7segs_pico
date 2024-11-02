add_subdirectory(lvgl)
add_subdirectory(pico-displayDrivs)
add_subdirectory(pico-displayTouch)

target_include_directories(lvgl PUBLIC
    ./
)
