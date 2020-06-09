//
//  view.c
//  Contacts
//
//  Created by Eriko Kawaguchi on 2020/05/29.
//  Copyright © 2020 Eriko Kawaguchi. All rights reserved.
//

#include <stdio.h>
#include "manage_data.h"

/* メニュー表示 */
static int viewMenu(){
    int input = 0;  /* 選択肢 */
    
    printf("\n====================\n");
    printf("1.ADD\n");
    printf("2.VIEW\n");
    printf("3.DELETE\n");
    printf("4.END\n");
    printf("====================\n");
    scanf("%d", &input);
    
    return input;
}

/* 追加 */
static void checkAddData(){
    S_DATA S_person;    /* 入力用リスト */
    
    S_person.index = 0;
    printf("\nPlease enter your name:");
    scanf("%16s", S_person.name);
    printf("Please enter your mail address:");
    scanf("%16s", S_person.mail);
    printf("Please enter memo:");
    scanf("%16s", S_person.memo);

    if (addData(S_person) != 0) {
        printf("Can't add data");
    };
    return;
}

/* 表示 */
static void viewContats(){
    S_DATA data[D_NUMBER];
    int i;

    if (getData(D_NUMBER, data) != 0) {
        printf("Can't get data");
        return;
    };
    for (i = 0; i < D_NUMBER; i++) {
        if (0 < data[i].index) {
            printf("\n%-2d", data[i].index);
            printf("\t%-16s", data[i].name);
            printf("\t%-16s", data[i].mail);
            printf("\t%-16s", data[i].memo);
        }
    }
    return;
};

/* 削除 */
static void checkDelData(){
    int input = 0;
    
    printf("\nWhich id do you delete?\n");
    scanf("%d", &input);
    if (input <= 0) {
        printf("\nThere is no data to delete.");
        return;
    }
    if (deleteData(input) != 0) {
        printf("Can't delete data");
    };
    return;
}

int main(void){
    while (1){
        int input = 0;
        input = viewMenu();     /* メニュー表示 */
        switch (input){
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
                break;       /* 終了 */
            default:
                printf("Please enter a number within the range 1-4.\n");
        }
        if (input == 4) {
            return 0;
        }
    }
}
