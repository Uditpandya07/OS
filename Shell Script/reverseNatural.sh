echo "Enter the postive range of numbers:"
read a b
i=$b
while (($i >= $a))
 do
   echo $i
 ((i--))
done
