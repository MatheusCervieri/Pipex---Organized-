echo "Test 1 - Incorrect first file! -----------------------------"
./pipex infile "ls -l" "wc -l" test1my
echo $?
< infile ls -l | wc -l > test1original
echo $?
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