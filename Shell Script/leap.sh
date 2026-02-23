echo "Enter the year:"
read y

echo "Enter the value of n:"
read n

for (( i=y; i<=y+4*n; i++ ))
do
    if (( i % 4 == 0 ))
    then
        echo "$i"
    fi
done

