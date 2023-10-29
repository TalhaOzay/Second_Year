#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // Bu kütüphaneyi ileride kullanacağım "strlen" ve "strcmp" fonksiyonlarını kullanabilmek için ekledim.

struct student {
    char name[25];
    int age;
    int number;
    struct student *next;
};

typedef struct student node;
node *head,*tail;

void longest (node *head);
node *delete (node*head);
void search (node *head);
void write (node *head);

int main(){
    int num;
    printf("How many student will you enter the list ?\nAnswer : ");
    scanf("%d",&num);
    for (int i=0 ; i<num ; i++){      // Burada listeye istediğiniz kadar kişi girmeniz için bir liste oluşturucu yaptım.
        if (i == 0){      // En baş head'i oluşturuyoruz.
            head = (node*)malloc(sizeof(node));
            tail = head;
        }else{
            tail->next = (node*)malloc(sizeof(node));  // Sonrasınde ise tail in devamını oluşturup tail'i ona eşitliyoruz.
            tail = tail->next;
        }
        printf("-------------------------------------\n");
        printf("Enter %d. student's number : ",i+1);
        scanf("%d",&tail->number);
        printf("Enter %d. student's name : ",i+1);
        scanf("%s",tail->name);
        printf("Enter %d. student's age : ",i+1);
        scanf("%d",&tail->age);
    }
    tail->next = NULL;
    tail = head;

    int choice;
    while (choice != 5){     // Burada seçenekleri ekledim menü oluşturdum.
        printf("------------------------------------\n");   // Görsellik için ekledim
        printf("\nMenu :\n1-Longest name\n2-Deleting sutudent\n3-Searching student\n4-Showing whole list\n5-Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        printf("------------------------------------\n");   // Görsellik için ekledim

        switch (choice){
            case 1:
                longest(head);
                break;
            case 2:
                head = delete(head);
                break;
            case 3:
                search(head);
                break;
            case 4:
                write(head);
                break;
            case 5:
                printf("Program closing ...");   // Bitirmek için "5" giriyoruz.(Görsellik için ekledim) 
                break;
        }
        tail = head; // Bütün seçenekelerde tail değiştiği için her fonksiyonun içine ayrı ayrı "tail = head" yazmamak için buraya yazdım.
    }
    return 0;
}

void longest (node *head){      // En uzun isimli kişiyi bulduğumuz fonksiyon.
    int lenght = 0;
    node *longName = (node*)malloc(sizeof(node));

    while (tail != NULL){
        if (lenght < strlen(tail->name)){       // Burada strlen fonksiyonu ile en uzun ismi buldum.
            lenght = strlen(tail->name);        // Bize herhangi bir kısıtlama konmadığından kullandım.
            longName = tail;
        }
        tail = tail->next;
    }
    printf("Longest name = %s\nLenght = %d\n",longName->name,lenght);
}

node *delete (node *head){      // Girilen kişinin isminden sonraki kişiyi silen fonksiyon.
    char stdName[25];
    printf("Enter student name for deleting next student of entered student : ");
    scanf("%s",stdName);
    node *stdDelete = (node*)malloc(sizeof(node));     // Burada silinecek kişinin indisini tutmak için struct oluşturdum.

    while (tail != NULL){
        if (strcmp(stdName,tail->name) == 0){      // Burada strcmp fonksiyonu ile girilen isim ile listedeki isimleri karşılaştırdım.
            if (tail->next == NULL){              // Burada tail silinecek öğrenciden bir önceki öğrencinin değerini tutarak öğrenci silindiğinde listeyi devamına bağlamak için var.
                printf("There is no next student !!!");     // Bu kod ismi girilen öğrenciden sonra başka öğrencinin olmadığı durum için var.
                return head; 
            }
            stdDelete = tail->next;   
            tail->next = tail->next->next;    // Burada silinecek öğrenciden önceki öğrencinin next'ini silinecek öğrenciden sonrakine bağladım.
            free(stdDelete);                  // Daha sonrada öğrenciyi sildim.
            return head;
        }
        tail = tail->next;
    }
    if (tail == NULL){
        printf("There is no student with \"%s\" name !!!",stdName);  // İsmi gilen öğrencinin listede olamdığı durum için var.
    }
    return head;
}

void search (node *head){      // İsim girilen öğrencinin listede aranıp bilgilerinin yazdırıldığı fonksiyon.
    char stdName[25];
    printf("Enter student name for search : ");
    scanf("%s",stdName);
    while (tail != NULL){
        if (strcmp(stdName,tail->name) == 0){       // Burada yine strcmp fonksiyonu ile girilen öğrencinin ismi ile listedeki isimler karşılaştırdım.
            printf("%s\t%d\t%d\n",tail->name,tail->age,tail->number);
            return;
        }
        tail = tail->next;
    }
    printf("There is no student with \"%s\" name !!!",stdName);     // İsmi girilen öğrencinin litede olmadığı durum için var.
}

void write (node *head){     // Linked listler için olan listedeki herkezi yazdırdığımız fonksiyon.
    int counter = 1;        // Listedeki kişileri sayması için oluşturduğum değişken.
    while (tail != NULL){
        printf("%d - %s\t%d\t%d\n",counter,tail->name,tail->age,tail->number);
        counter++;
        tail = tail->next;
    }
}