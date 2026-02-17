echo "Enter the value of n:"
read n

sum=0

echo "Enter the numbers:"
for (( i=1; i<=n; i++ ))
do
    read num
    sum=$((sum + num))
done

avg=$((sum / n))

echo "Sum = $sum"
echo "Average = $avg"
