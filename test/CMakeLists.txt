###########################################################
function(AddOneTest test_name)
    add_executable(${test_name} ${test_name}.cc)
    add_test(
        NAME ${test_name}
        COMMAND ${test_name}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endfunction(AddOneTest test_name)

###########################################################


AddOneTest(__copy_trivial)
AddOneTest(compile)
AddOneTest(copy_backward)
AddOneTest(iter_swap)
AddOneTest(max)
AddOneTest(min)
AddOneTest(swap)
