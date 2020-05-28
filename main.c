//
//  main.c
//  Contacts
//

#include <stdio.h>

void addContact(void);
void viewContats(void);
void delContact(void);

int main(void){

    while(1){
        
        int input = 0;  /* 選択肢 */

        /* メニュー選択 */
        printf("\n====================\n");
        printf("1.ADD\n");
        printf("2.VIEW\n");
        printf("3.DELETE\n");
        printf("4.END\n");
        printf("====================\n");

        scanf("%d", &input);

        switch(input){
            case 1:
                addContact();
                break;
            
            case 2:
                /* 表示 */
                viewContats();
                break;

            case 3:
                /* 削除 */
                delContact();
                break;

            case 4:
                /* 終了 */
                return 0;

            default:
                printf("Please enter a number within the range 1-4.\n");
        }
    }
}
