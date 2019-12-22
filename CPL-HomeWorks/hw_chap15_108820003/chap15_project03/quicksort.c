//快速排序法c & c++ by Xanonymous All rights reserved.
void quicksort(int *data, int L, int R) {
    int l, r;      //定義左定位點和右定位點
    if (L < R) {   //確保參數正確，保證資料超過兩筆以上
        l = L + 1; //以最左方為基準，初始化左定位點為基準右方第一筆資料
        while (data[l] < data[L])
            l++; //從基準開始向右尋找第一個比基準大的數(移動左定位點到該位置)
        r = R;   //初始化右定位點為最右方資料
        while (data[r] > data[L])
            r--; //從最右方開始向左尋找第一個比基準小的數(移動右定位點到該位置)
        while (l < r) {
            //在左定位點小於右定位點的情況下(尚未重合)將左定位點之資料與右定位點之資料進行對調
            int tmp = data[l];
            data[l] = data[r];
            data[r] = tmp;
            l++; //移開剛才已經交換過的位置
            while (data[l] < data[L])
                l++; //從新位置開始向右尋找下一個比基準大的數(移動左定位點到該位置)
            r--;     //移開剛才已經交換過的位置
            while (data[r] > data[l])
                r--; //從新位置開始向左尋找下一個比基準小的數(移動右定位點到該位置)
        }
        //左定位點此時已與右定位點發生重合以重合位置之資料取代基準，使其與最左方資料交換
        int tmp = data[L];
        data[L] = data[r];
        data[r] = tmp;
        //以重合位置為分割點，分別向左向右發出遞迴，以分割過後的陣列重新執行快速排序(留下重合點之資料)
        quicksort(data, L, r - 1);
        quicksort(data, r + 1, R);
    }
}