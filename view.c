//
//  view.c
//  Contacts
//
//  Created by Eriko Nagano on 2020/05/29.
//  Copyright © 2020 Eriko Kawaguchi. All rights reserved.
//

#include <stdio.h>
#include "manage_data.h"

void addContact(list S_person);
void delContact(int input);
void checkContacts(list person[D_NUMBER]);

// todo:入出力(printf, scanf)に関する処理のみ記述
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
    list S_person;    /* 入力用リスト */

    // done:[追加]ユーザからname/mail/memoを受け取り、1つの構造体につめる
    S_person.index = 0;   //★
    printf("\n====================\n");
    printf("Please enter your name:");
    scanf("%16s", S_person.name);
    printf("Please enter your mail address:");
    scanf("%16s", S_person.mail);
    printf("Please enter memo:");
    scanf("%16s", S_person.memo);

    // done:[追加]構造体の情報をデータ管理部へ渡す
    addContact(S_person);
    return;
}

// done:[表示]構造体の配列を定義し、配列をデータ管理部に渡して、データを入れてもらう
// done:[表示]入れてもらった内容を表示する
/* 表示 */
static void viewContats(){
    list S_person[D_NUMBER];
    int i;

    checkContacts(S_person);

    for (i = 0; i < D_NUMBER; i++) {
        if (S_person[i].index > 0) {
            printf("\n%-2d", S_person[i].index);
            printf("\t%-16s", S_person[i].name);
            printf("\t%-16s", S_person[i].mail);
            printf("\t%-16s", S_person[i].memo);
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
    // done:[削除]ユーザからインデックスをもらい、インデックスをデータ管理部に渡す
    // done:[削除]削除処理はデータ管理部で実施
    delContact(input);
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

