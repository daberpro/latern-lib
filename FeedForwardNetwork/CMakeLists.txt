project(FeedForwardNetwork CXX)
find_package(ArrayFire REQUIRED)
add_library(${PROJECT_NAME} STATIC FeedForward.cpp)
target_include_directories(
    ${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR} "D:/v3/include"
    ${CMAKE_SOURCE_DIR}/Headers
    ${CMAKE_SOURCE_DIR}/AutoGradient
)
target_link_libraries(${PROJECT_NAME} PRIVATE ArrayFire::afcpu)