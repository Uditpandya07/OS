echo "Enter 3 numbers: "
read a b c
if (($a > $b && $a > $c)); then
   if (($b > $c)); then
     echo "$b is second largest"
   else
     echo "$c is second largest"
   fi
elif (($b > $a && $b > $c)); then
   if (($a > $c)); then
     echo "$a is second largest"
   else
     echo "$c is second largest"
   fi
else
   if (($a > $b)); then
     echo "$a is second largest"
   else
     echo "$b is second largest"
   fi
fi

