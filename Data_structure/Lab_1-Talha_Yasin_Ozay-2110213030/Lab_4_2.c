#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct numbers{
    int number;
    struct numbers *next;
};
typedef struct numbers node;
node *head,*tail,*temp; 
// buradaki tail head'in yerine kulladığımız olan siz önecekinde current demiştiniz.
// Temp (temporary) yani geçici olarak tail'i tutabilmek için oluşturduğum bir pointer.

void siralama (node *head); 


int main(){
    int num;
    srand(time(NULL));
    num = rand();
    for (int i=0 ; i<100 ; i++){ // 100 tane random satı oluşturup listeye oluşturarak ekliyorum.
        num = rand();  // Random sayı üretici
        if (i == 0){
            head = (node*)malloc(sizeof(node));
            tail = head;
        }else{
            tail->next = (node*)malloc(sizeof(node));
            tail = tail->next;
        }
        tail->next = NULL;
        tail->number = num;
    }
    tail = head;

    siralama (head);

    return 0;
}

void siralama (node *head){
    int temp1;              // Burada oluşturduğum "temp1" deişkenini ileride listedeki en küçük sayı ile listenin başındaki değeri değiştirirken değeri tutabilmek için oluşturdum.
   
    node *minimum = (node*)malloc(sizeof(node)); // Minimum ile listedeki en küçük olan değeri pointer olarak tutmak için "minimum" değişkenini kullandım.
    for (int i=0 ; i<99 ; i++){    // Selection sort uyguladım. Sonuncu NULL olduğu için 99 verdim.
        temp = tail;               // Burada biz her seferinde en küçük değeri başa girdiğimizden en baş dediğimiz yeri tail ile her döngüde bir bir ilerlettim.
        minimum = temp;            // "temp" ile liste içindeki bütün node'lar içinde gezinti yapabilmek ve sorgulamak için kullandım.
        while (temp != NULL){      // Buradaki "while" ile listedeki en kçük sayıyı buluyoruz.
            if (minimum->number > temp->number){
                minimum = temp;
            }
            temp = temp->next;
        }
        temp1 = tail->number;               //Burada da son olarak en küçük değeri o anki liste başındaki değerle değiştiriyoruz.
        tail->number = minimum->number;
        minimum->number = temp1;
        tail = tail->next;
    }

    tail = head;

    printf("Cikti : ");
    while (tail->next != NULL){     // Burada en sona bir tane daha fazladan ok yazmamak için temp->next'i null'a eşitledim.
        printf("%d -> ",tail->number);
        tail = tail->next;
    
    }
    printf("%d",tail->number);  // Ve son olarak yukarıdaki temp->next'den dolayı yazılamayan son sayıyı yazdırdım.
}


