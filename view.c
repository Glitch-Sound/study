//
//  view.c
//  Contacts
//
//  Created by Eriko Kawaguchi on 2020/05/29.
//  Copyright © 2020 Eriko Kawaguchi. All rights reserved.
//

#include <stdio.h>
#include "manage_data.h"

static E_SAVE g_dest = SAVE_STATIC;   /* 保存先 */

/* メニュー表示 */
static int viewMenu(){
    int input = 0;  /* 選択肢 */
    
    printf("\n====================\n");
    printf("1.ADD\n");
    printf("2.VIEW\n");
    printf("3.DELETE\n");
    printf("4.MANAGE STATIC\n");
    printf("5.MANAGE HEAP\n");
    printf("6.MANAGE FILE\n");
    printf("7.MANAGE DB\n");
    printf("8.END\n");
    printf("====================\n");
    scanf("%d", &input);
    
    return input;
}

/* 追加 */
static void checkAddData(){
    S_DATA person;    /* 入力用リスト */
    
    person.index = 0;
    printf("\nPlease enter your name:");
    scanf("%16s", person.name);
    printf("Please enter your mail address:");
    scanf("%16s", person.mail);
    printf("Please enter memo:");
    scanf("%16s", person.memo);
    
    if (addData(g_dest, person) != 0) {
        printf("Can't add data");
    };
    return;
}

/* 表示 */
static void viewContats(){
    S_DATA data[D_NUMBER];
    int size = D_NUMBER;
    int i;
    
    if (getData(g_dest, data) != 0) {
        printf("Can't get data");
        return;
    };
    for (i = 0; i < size; i++) {
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
    if (deleteData(g_dest, input) != 0) {
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
                g_dest = SAVE_STATIC;
                break;          /* STATIC */
            case 5:
                g_dest = SAVE_HEAP;
                if (secureMemory() != 0) {
                    printf("can't secure memory");
                };
                break;         /* HEAP */
            case 6:
//                g_dest = SAVE_FILE;
            case 7:
//                g_dest = SAVE_DB;
                break;          /* DB */
            case 8:
                break;       /* 終了 */
            default:
                printf("Please enter a number within the range 1-8.\n");
        }
        if (input == 8) {
            return 0;
        }
    }
}
