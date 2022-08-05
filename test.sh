echo "Test 1 - < infile ls -l | wc -l > test1original | Incorrect first file! -----------------------------"
./pipex infile "ls -l" "wc -l" test1my
echo $?
< infile ls -l | wc -l > test1original
echo $?
echo "MY:"
cat test1my
echo "Original:"
cat test1original
echo "Test 2 - < text1.txt ls -l | wc -l > test1original -----------------------------"
./pipex text1.txt "ls -l" "wc -l" test2my
echo $?
< text1.txt ls -l | wc -l > test2original
echo $?
echo "Notes that the original should be > in the first time running because there is more files "
echo "MY:"
cat test2my
echo "Original:"
cat test2original
echo "Test 3 - < text1.txt grep a1 | wc -w > outfile -----------------------------"
./pipex text1.txt "grep a1" "wc -w" test3my
echo $?
< text1.txt grep a1 | wc -w > test3original
echo $?
echo "MY:"
cat test3my
echo "Original:"
cat test3original
echo "Test 4 -  < text1.txt tr a b | tr b '  ' > test4myoriginal-----------------"
./pipex text1.txt "tr a b" "tr b '  '" test4my
echo $?
< text1.txt tr a b | tr b '  ' > test4original
echo $?
echo "MY:"
cat test4my
echo \n
echo "Original:"
cat test4original
echo \n
echo "Test 5 - < text1.txt comandonaoexiste | wc -w > outfile -----------------------------"
./pipex text1.txt "comandonaoexiste" "wc -w" test5my
echo $?
< text1.txt comandonaoexiste | wc -w > test5original
echo $?
echo "MY:"
cat test5my
echo "Original:"
cat test5original
echo "Test 6 - < text1.txt grep a1 | comandonaoexiste > outfile -----------------------------"
./pipex text1.txt "grep a1" "comandonaoexiste" test6my
echo $?
< text1.txt grep a1 | comandonaoexiste > test6original
echo $?
echo "MY:"
cat test6my
echo "Original:"
cat test6original
echo "Test 7 - < text1.txt comandonaoexiste | comandonaoexiste > outfile -----------------------------"
./pipex text1.txt "comandonaoexiste" "comandonaoexiste" test7my
echo $?
< text1.txt comandonaoexiste | comandonaoexiste > test7original
echo $?
echo "MY:"
cat test7my
echo "Original:"
cat test7original
echo "Test 8 - assets/deepthought.txt cat hostname outs/test-xx.txt -----------------------------"
./pipex deepthought.txt "cat" "hostname" test8my
echo $?
< deepthought.txt cat | hostname > test8original
echo $?
echo "MY:"
cat test8my
echo "Original:"
cat test8original
echo "Test 9 - ./pipex file1 cat grep x output/outfile5 -----------------------------"
./pipex file1 "cat" "grep x" test9my
echo $?
< file1 cat | grep x > test9original
echo $?
echo "MY:"
cat test9my
echo "Original:"
cat test9original





