echo "Enter the value of a:"
read a

echo "Enter the value of n:"
read n

result=1

 for ((i=1;i<=n;i++))
 do
   result=$((result*a))
 done
echo "$a^$n = $result"
