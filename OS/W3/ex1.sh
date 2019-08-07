declare -a teammates
teammates[0]="India"
teammates[1]="England"
echo "There  are ${#teammates[*]} teams"
echo "They are ${teammates[*]}"
unset teammates[*]
echo "${teammates[*]}"


