# run test to output gcov files
cd build/test
./testExecutor

# make coverage data 
lcov -c -d ../ -o coverage.info

# remove unnecessary file paths
lcov -r coverage.info */googletest/* test/* */c++/* -o coverageFiltered.info

# make html report
genhtml -o ../lcovHtml --num-spaces 4 -s --legend coverageFiltered.info
