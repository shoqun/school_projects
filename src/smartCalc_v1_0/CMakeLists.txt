cmake_minimum_required(VERSION 3.5)

project(smartCalc_v1_0 VERSION 1.0) # LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Указываем путь к корневой папке Qt
set(Qt6_DIR "/Users/shogun/Qt")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets PrintSupport)

set(QCUSTOMPLOT_SOURCES
       qcustomplot.cpp
)


set(QCUSTOMPLOT_HEADERS
       qcustomplot.h
)


set(PROJECT_SOURCES
        main.cpp
        graph.cpp
        calculator.cpp
)

set(SOURCES_C
    ../s21_smartCalc.h
    ../s21_preprocess.c
    ../s21_evaluate.c
    ../s21_infixToPolish.c
    ../s21_smartCalc.c
    ../s21_differential.c
    ../s21_deposit.c

)


set(HEADERS
    calculator.h
    graph.h

)

set(UI_FILES
    calculator.ui
    graph.ui
)

set_source_files_properties(${SOURCES_C} PROPERTIES LANGUAGE C)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(smartCalc_v1_0
        MANUAL_FINALIZATION
        ${QCUSTOMPLOT_SOURCES}
        ${QCUSTOMPLOT_HEADERS}
        ${SOURCES_C}
        ${PROJECT_SOURCES}
        ${HEADERS}
        ${UI_FILES}

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET smartCalc_v1_0 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(smartCalc_v1_0 SHARED
            ${SOURCES_C}
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(smartCalc_v1_0
            ${SOURCES_C}
            ${PROJECT_SOURCES}
            ${HEADERS}
            ${UI_FILES}
        )
    endif()
endif()

target_link_libraries(smartCalc_v1_0 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::PrintSupport)


set_target_properties(smartCalc_v1_0 PROPERTIES

    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(smartCalc_v1_0)
endif()
