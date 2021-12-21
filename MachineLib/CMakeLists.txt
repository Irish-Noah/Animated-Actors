project(MachineLib)

set(SOURCE_FILES
        pch.h
        Machine.h Machine.cpp
        MachineFactory.cpp MachineFactory.h
        MachineStandin.cpp MachineStandin.h
        MachineDialog.cpp MachineDialog.h include/machine-api.h NewMachine.cpp NewMachine.h ActualMachine.cpp ActualMachine.h MachineOneFactory.cpp MachineOneFactory.h Component.cpp Component.h Polygon.cpp Polygon.h Shape.cpp Shape.h MachineTwoFactory.cpp MachineTwoFactory.h Motor.cpp Motor.h RotationSource.cpp RotationSource.h RotationSink.cpp RotationSink.h Gear.cpp Gear.h Arm.cpp Arm.h Piston.cpp Piston.h Lever.cpp Lever.h PointSource.cpp PointSource.h PointSink.cpp PointSink.h Rod.cpp Rod.h INegotiator.cpp INegotiator.h RodSink.cpp RodSink.h RodSource.cpp RodSource.h)

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)