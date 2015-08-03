add_test(
    NAME runExeOutputOK
    COMMAND $<TARGET_FILE:FileExistTestMain> 
       yingyang-filtered-test-existFile.png
       ../../../Data/yingyang.png
       yingyang-filtered-test-existFile.png
       3 
        )
add_test(
    NAME runExeOutputChecked
    COMMAND $<TARGET_FILE:CompareFilesTestMain> 
       yingyang-filtered-test-compareFile.png
       ../../../Data/yingyang-filtered.png
       ../../../Data/yingyang.png
       yingyang-filtered-test-compareFile.png
       3 
        )

 add_test(
    NAME WrongFileToCompare
    COMMAND $<TARGET_FILE:CompareFilesTestMain> 
       yingyang-filtered-test-compareFile.png
       ../../../Data/yingyang.png
       ../../../Data/yingyang.png
       yingyang-filtered-test-compareFile.png
       3 
        )
 set_tests_properties(WrongFileToCompare PROPERTIES WILL_FAIL true)   
