echo "Enter the time in seconds: "
read s
echo "HOURS : $((s/3600))"
echo "MINUTES: $(((s % 3600) / 60))"
echo "SECONDS: $((s % 60))"

