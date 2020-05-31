//
//  view.c
//  Contacts
//

#include <stdio.h>
#include "manage_data.h"

void addContact(list *person);
void delContact(int input);

// todo:入出力(printf, scanf)に関する処理のみ記述

/* メニュー表示 */
int viewMenu(){

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

void checkAddData(){
    
    list person;    /* 入力用リスト */

    // done:[追加]ユーザからname/mail/memoを受け取り、1つの構造体につめる
    person.index = 0;   //★
    printf("\n====================\n");
    printf("Please enter your name:");
    scanf("%16s", person.name);
    printf("Please enter your mail address:");
    scanf("%16s", person.mail);
    printf("Please enter memo:");
    scanf("%16s", person.memo);
    printf("\n====================\n");

    // done:[追加]構造体の情報をデータ管理部へ渡す
    addContact(&person);   /* 追加 */

    return;
}

// todo:[表示]構造体の配列を定義し、配列をデータ管理部に渡して、データを入れてもらう
// todo:[表示]入れてもらった内容を表示する
/* 表示 */
void viewContats(){
    
    list person[NUMBER];

    int i;
    int j = 0;
    
    for (i = 0; i < NUMBER; i++) {
        if (person[i].index > 0){
            printf("\n%d", person[i].index);
            printf("\t%s", person[i].name);
            printf("\t%s", person[i].mail);
            printf("t%s", person[i].memo);
        } else {
            j++;
        }
    }
    
    if (j == 10){
        printf("no data");
    }
    return;
};

void checkDelData(){
    
    int input;

    printf("\nWhich id do you delete?\n");
    scanf("%d", &input);
    if (input > 0){
        // done:[削除]ユーザからインデックスをもらい、インデックスをデータ管理部に渡す
        // done:[削除]削除処理はデータ管理部で実施
        delContact(input);   /* 削除 */
    } else {
        printf("\nThere is no data to delete.");
    }
    return;
}

