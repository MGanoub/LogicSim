cmake_minimum_required(VERSION 3.16)

project(LogicSim VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        UI/disp/mainwindow.cpp
        UI/disp/mainwindow.h
        UI/disp/Forms/mainwindow.ui
)


include_directories(./)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(LogicSim
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        UI/disp/Widgets/sceneWidget.h UI/disp/Widgets/sceneWidget.cpp
        UI/disp/Widgets/listItemWidget.h UI/disp/Widgets/listItemWidget.cpp
        Resources/resources.qrc
        Resources/inputs/buttonOn.png
        UI/Controllers/sceneEditor.h  UI/Controllers/sceneEditor.cpp
        UI/disp/Widgets/draggableLabel.h UI/disp/Widgets/draggableLabel.cpp
        UI/disp/Widgets/CircuitElement/elementView.h UI/disp/Widgets/CircuitElement/elementView.cpp
        Core/Circuit/elementTypeEnum.h
        UI/disp/Widgets/CircuitElement/elementPort.h UI/disp/Widgets/CircuitElement/elementPort.cpp
        UI/disp/Widgets/CircuitElement/elementConnection.h UI/disp/Widgets/CircuitElement/elementConnection.cpp
        Core/Circuit/Components/IComponent.h
        Core/Circuit/Components/Input/VCCInput.h Core/Circuit/Components/Input/VCCInput.cpp
        Core/Circuit/Components/port.h Core/Circuit/Components/port.cpp
        Core/Circuit/Managers/circuitManager.h Core/Circuit/Managers/circuitManager.cpp
        Core/Circuit/Components/Input/inputComponent.h Core/Circuit/Components/Input/inputComponent.cpp
        Core/Circuit/Components/component.h Core/Circuit/Components/component.cpp
        Core/Circuit/Components/Output/outputComponent.h Core/Circuit/Components/Output/outputComponent.cpp
        Core/Circuit/Components/Output/led.h Core/Circuit/Components/Output/led.cpp
        UI/disp/Widgets/CircuitElement/OutputElements/ledView.h UI/disp/Widgets/CircuitElement/OutputElements/ledView.cpp
        logicSimApp.h logicSimApp.cpp
        UI/qtApp.h UI/qtApp.cpp
        UI/Controllers/mainGuiContainer.h UI/Controllers/mainGuiContainer.cpp
        UI/Controllers/componentsMenuContainer.h UI/Controllers/componentsMenuContainer.cpp
        UI/disp/Widgets/componentsMenuWidget.h UI/disp/Widgets/componentsMenuWidget.cpp
        Core/Circuit/Components/componentsFactory.h Core/Circuit/Components/componentsFactory.cpp
        UI/disp/Widgets/CircuitElement/elementFactory.h UI/disp/Widgets/CircuitElement/elementFactory.cpp
        UI/disp/Widgets/CircuitElement/InputElements/vccView.h UI/disp/Widgets/CircuitElement/InputElements/vccView.cpp
        UI/disp/Widgets/CircuitElement/LogicGates/andGateView.h UI/disp/Widgets/CircuitElement/LogicGates/andGateView.cpp
        Core/Circuit/Components/LogicGate/gate.h Core/Circuit/Components/LogicGate/gate.cpp
        Core/Circuit/Components/LogicGate/andGate.h Core/Circuit/Components/LogicGate/andGate.cpp
        Core/Circuit/Components/LogicGate/orGate.h Core/Circuit/Components/LogicGate/orGate.cpp
        UI/disp/Widgets/CircuitElement/LogicGates/orGateView.h UI/disp/Widgets/CircuitElement/LogicGates/orGateView.cpp
        UI/disp/Widgets/CircuitElement/InputElements/gndView.h UI/disp/Widgets/CircuitElement/InputElements/gndView.cpp
        Core/Circuit/Components/Input/gndInput.h Core/Circuit/Components/Input/gndInput.cpp


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET LogicSim APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(LogicSim SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(LogicSim
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(LogicSim PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.LogicSim)
endif()
set_target_properties(LogicSim PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS LogicSim
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(LogicSim)
endif()
