cmake_minimum_required(VERSION 2.8)

project(FileExistTestMain)

#For tests 
include(CTest)

#Find ITK 
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

#File exists
add_executable(FileExistTestMain FileExistTestMain.cxx)
#Change the path of the librairies for use a filter 
target_link_libraries(FileExistTestMain /NIRAL/work/danaele/ExercicesTuto/CTest-exercices/Pgr1-build/libErodeFilterLib.a ${ITK_LIBRARIES} )

#Files to compare
add_executable(CompareFilesTestMain CompareFilesTestMain.cxx)
#Change the path of the librairies for use a filter 
target_link_libraries(CompareFilesTestMain /NIRAL/work/danaele/ExercicesTuto/CTest-exercices/Pgr1-build/libErodeFilterLib.a ${ITK_LIBRARIES} )


#add tests
option(BUILD_TESTING "Build the testing tree" ON)

if(BUILD_TESTING)
 add_subdirectory(Testing)
endif(BUILD_TESTING)



