echo "Enter first distance (km m):"
read km1 m1
echo "Enter second distance (km m):"
read km2 m2

tot_m=$((m1 + m2))
tot_km=$((km1 + km2 + tot_m/1000))
tot_m=$((tot_m % 1000))

echo "Sum = ${tot_km} km ${tot_m} m"

