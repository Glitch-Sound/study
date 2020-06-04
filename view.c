//
//  view.c
//  Contacts
//
//  Created by Eriko Nagano on 2020/05/29.
//  Copyright © 2020 Eriko Kawaguchi. All rights reserved.
//

#include <stdio.h>
#include "manage_data.h"

void addContact(list *person);
void delContact(int input);
void checkContacts(list person[NUMBER]);

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

/* 追加 */
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

    // done:[追加]構造体の情報をデータ管理部へ渡す
    addContact(&person);

    return;
}

// done:[表示]構造体の配列を定義し、配列をデータ管理部に渡して、データを入れてもらう
// done:[表示]入れてもらった内容を表示する
/* 表示 */
void viewContats(){
    
    list person[NUMBER];
    int i;

    checkContacts(person);

    for (i = 0; i < NUMBER; i++) {
        if (person[i].index > 0) {
            printf("\n%-2d", person[i].index);
            printf("\t%-16s", person[i].name);
            printf("\t%-16s", person[i].mail);
            printf("\t%-16s", person[i].memo);
        }
    }
    return;
};

/* 削除 */
void checkDelData(){
    
    int input;

    printf("\nWhich id do you delete?\n");
    scanf("%d", &input);
    if (input > 0){
        // done:[削除]ユーザからインデックスをもらい、インデックスをデータ管理部に渡す
        // done:[削除]削除処理はデータ管理部で実施
        delContact(input);
    } else {
        printf("\nThere is no data to delete.");
    }
    return;
}

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

