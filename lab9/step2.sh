for file in file1.bin file2.bin file3.bin file4.bin
do 
    echo "step2 $file"
    time ./step2 $file
    echo " "
done