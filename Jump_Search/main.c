#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void display(int arr[], int sizee){

    int i;
    printf("Arama yapilacak dizi: ");
    printf("[");
    for(i = 0; i < sizee; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// Linear Searching Algorithm.
int linearsearching(int arr[], int start, int end, int value){

    int i;
    for(i = start; i <= end; i++){  // Sadece belirlenen blok icerisinde arama yapar. [start,end]
        if(arr[i] == value){
            return i;
        }
    }

    return -1;

}

// Jump Searching Algorithm.
int jumpsearching(int arr[], int sizee, int blocksizee, int value){

    int start = 0, end = blocksizee;    // Blok baslangiç noktasi ve bitis noktasi

    while(arr[end] <= value && end < sizee){    // dizinin end konumundaki deger aranan ogeden kucuk ve end degeri dizinin boyutundan kucuk ise islem yapar.
                                                // Aksi halde blok ya liste disina cikar ya da aranan ogeeden buyuk olursa arama yapamaz.
        start = end;        // eger kosul saglanirsa start degerini end degeri olarak ayarlar.
        end += blocksizee;    // end degerini atlama degeri kadar artirir ve bu sayede blogu ileriye kaydirmis olur.

        if (end > sizee - 1){   // end degeri dizi boyutunu asabilir. end degerini ona gore ayarlar.
            end = sizee;
        }

    }

    return linearsearching(arr, start, end, value);  // while dongusune girmediðine gore aranan oge belirtilen blok icerisinde olur ve Linear search yapilabilir.
}

int main()
{
    int array[] = {0, 1, 9, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int sizee, blocksizee, value, index;

    sizee = sizeof(array) / sizeof(int);    // dizi boyutu
    blocksizee = sqrt(sizee);     // blok atlama degeri
    display(array, sizee);

    printf("Aranan deger: "); scanf("%d", &value);

    index = jumpsearching(array, sizee, blocksizee, value);
    printf("%d", index);

    (index != -1) ? printf("Aranan ogenin index'i: %d", index) : printf("Aranan oge liste icerisinde bulunmuyor!");








    return 0;
}
