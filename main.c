//
//  main.c
//  Contacts
//

#include <stdio.h>

int viewMenu(void);
void checkAddData(void);
void viewContats(void);
void checkDelData(void);

int main(void){

    while(1){
        
        int input = 0;
        
        input = viewMenu();     /* メニュー表示 */
        
        switch(input){
            case 1:
                checkAddData(); /* 追加 */
                break;
            
            case 2:
                viewContats();  /* 表示 */
                break;

            case 3:
                checkDelData(); /* 削除 */
                break;

            case 4:
                return 0;       /* 終了 */

            default:
                printf("Please enter a number within the range 1-4.\n");
        }
    }
}
