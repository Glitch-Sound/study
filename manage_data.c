//
//  manage_data.c
//  Contacts
//

#include "manage_data.h"
#include <string.h>

// todo:グローバル変数に記憶用の変数を宣言
list record[NUMBER];

// todo:入力チェック
// todo:本変数を更新するための関数を定義

/* 追加 */
void addContact(list *person){

    int i;
    for (i = 0; i < NUMBER; i++) {
        if (record[i].index == 0){
            record[i].index = i + 1;
            // todo:入力用リストから挿入
            strcpy(record[i].name, person->name);
            strcpy(record[i].mail, person->mail);
            strcpy(record[i].memo, person->memo);
        }
    }
    return;
}

/* 削除 */
void delContact(int input){
    
    int i;
    input = input - 1;
    for (i = 0; i == input; i++){
        record[input].index = 0;
        strcpy(record[input].name, "");
        strcpy(record[input].mail, "");
        strcpy(record[input].memo, "");
    }
    return;
};


