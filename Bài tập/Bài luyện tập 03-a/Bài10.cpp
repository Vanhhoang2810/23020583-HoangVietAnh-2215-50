int* merge(int* firstArr, int lenArr1, int* secondArr, int lenArr2){
    int* mergedArr = new int[lenArr1 + lenArr2];

    for (int i = 0; i<lenArr1; i++) {
        mergedArr[i] = firstArr[i];
    }

    for (int i = 0; i<lenArr2; i++) {
        mergedArr[lenArr1 + i] = secondArr[i];
    }

    if (firstArr[1] > firstArr[0]) {
        sort(mergedArr, mergedArr + lenArr1 + lenArr2);
    } else if (firstArr[0] > firstArr[1]) {
        sort(mergedArr, mergedArr + lenArr1 + lenArr2, greater<int>());
    }


    return mergedArr;
}
