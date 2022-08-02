echo "Test 5 -  -----------------"
./pipex text1.txt "ping 8.8.8.8" "grep ms" test5my
echo $?
< text1.txt ping 8.8.8.8 | grep ms > test5myoriginal
echo $?
echo "MY:"
cat test5my
echo "Original:"
cat test5original

