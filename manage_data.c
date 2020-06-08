//
//  manage_data.c
//  Contacts
//
//  Created by Eriko Nagano on 2020/05/29.
//  Copyright © 2020 Eriko Kawaguchi. All rights reserved.
//

#include "manage_data.h"
#include <string.h>

// done:グローバル変数に記憶用の変数を宣言
static list S_record[D_NUMBER];

// done:本変数を更新するための関数を定義
/* 追加 */
void addContact(list S_person){
    int i;
    for (i = 0; i < D_NUMBER; i++) {
        if (S_record[i].index != 0) {
                break;
        }
        S_record[i].index = i + 1;
        // done:入力用リストから挿入
        strcpy(S_record[i].name, S_person.name);
        strcpy(S_record[i].mail, S_person.mail);
        strcpy(S_record[i].memo, S_person.memo);
    }
    return;
}

/* 表示 */
// todo:ポインタで受け取ること
void checkContacts(list S_person[D_NUMBER]){
    int i;
    for (i = 0; i < D_NUMBER ; i++) {
        S_person[i].index = S_record[i].index;
        strcpy(S_person[i].name, S_record[i].name);
        strcpy(S_person[i].mail, S_record[i].mail);
        strcpy(S_person[i].memo, S_record[i].memo);
    }
    return;
}

/* 削除 */
void delContact(int input){
    int i;
    input = input - 1;
    for (i = 0; i == input; i++) {
        S_record[input].index = 0;
        strcpy(S_record[input].name, "");
        strcpy(S_record[input].mail, "");
        strcpy(S_record[input].memo, "");
    }
    return;
}
