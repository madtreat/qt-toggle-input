project(qt-toggle-input)

set(SOURCES
   toggle-input.cc
)

set(HEADERS
   toggle-input.hh
)

set(RESOURCES
   resources.qrc
)
qt5_add_resources(TOGGLE_IMAGES ${RESOURCES})
set_source_files_properties(${TOGGLE_IMAGES} PROPERTIES GENERATED ON)

add_library(${PROJECT_NAME} SHARED
   ${SOURCES}
   ${HEADERS}
   ${TOGGLE_IMAGES}
)

target_link_libraries(${PROJECT_NAME}
   ${Qt5Core_LIBRARIES}
   ${Qt5Widgets_LIBRARIES}
   ${Qt5Gui_LIBRARIES}
)

# For testing purposes, add the included executable
add_executable(toggle-input-test
   main.cc
   main-window.cc
   main-window.hh
)

target_link_libraries(toggle-input-test
   ${PROJECT_NAME}
)

