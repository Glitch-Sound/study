//
//  managedata.c
//  Contacts
//

#include <stdio.h>
#include <string.h>

#define NUMBER  10  /* 登録数 */
#define LENGTH  16  /* 文字数 */

void addContact(void);
void viewContats(void);
void delContact(void);

typedef struct {
    int index;          /* インデックス */
    char name[LENGTH];  /* 名前 */
    char mail[LENGTH];  /* メールアドレス */
    char memo[LENGTH];  /* メモ */
} list;

list record[NUMBER];

//todo:入力チェック

/* アドレス追加 */
void addContact(){
    
    int i;
    for (i = 0; i < NUMBER; i++) {
        if (record[i].index == 0){
            record[i].index = i + 1;
            printf("Please enter your name:");
            scanf("%s", record[i].name);
            printf("Please enter your mail address:");
            scanf("%s", record[i].mail);
            printf("Please enter memo:");
            scanf("%s", record[i].memo);
            
            int flag;
            printf("\nDo you want to add another? 1:yes 2:no\n");
            scanf("%d", &flag);
            if (flag == 2) {
                break;
            }
        }
    }
    return;
}

/* 表示 */
void viewContats(){

    int j;
    int cnt = 0;
    
    for (j = 0; j < NUMBER; j++) {
        if (record[j].index > 0){
            printf("\nid:%d\n", record[j].index);
            printf("name:%s\n", record[j].name);
            printf("mail:%s\n", record[j].mail);
            printf("memo:%s\n", record[j].memo);
        } else {
            cnt++;
        }
    }
    
    if (cnt == 10){
        printf("no data");
    }
    return;
};

/* 削除 */
void delContact(){
    
    int input;
    
    printf("\nWhich id do you delete?\n");
    scanf("%d", &input);
    
    if (input > 0){
        input = input - 1;
        record[input].index = 0;
        strcpy(record[input].name, "");
        strcpy(record[input].mail, "");
        strcpy(record[input].memo, "");
    } else {
        printf("\nThere is no data to delete.");
    }
    return;
};

