read -r N
for ((i=0;i<$N;i++));do
    read -r Pi
    L+=("$Pi")
done
SORTED=($(printf "%s\n" "${L[@]}"|sort -n))
MIN=10000000
for ((i=0;i<$((N - 1));i++)); do
    TMP=$((SORTED[i] - SORTED[$((i+1))]));
    [[ ${TMP} -gt 0 ]]&&DIFF=${TMP}||DIFF=$((-TMP))
    [[ "${MIN}" -gt "${DIFF}" ]]&&MIN=${DIFF}
done
echo "${MIN}"
