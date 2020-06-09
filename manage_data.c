//
//  manage_data.c
//  Contacts
//
//  Created by Eriko Kawaguchi on 2020/05/29.
//  Copyright © 2020 Eriko Kawaguchi. All rights reserved.
//

#include <string.h>
#include "manage_data.h"

static S_DATA g_list[D_NUMBER];

/* 追加 */
int addData(S_DATA S_person){
    int i;
    for (i = 0; i < D_NUMBER; i++) {
        if (g_list[i].index == 0) {
            g_list[i].index = i + 1;
            strcpy(g_list[i].name, S_person.name);
            strcpy(g_list[i].mail, S_person.mail);
            strcpy(g_list[i].memo, S_person.memo);
            return 0;
        }
    }
    return 1;
}

/* 表示 */
int getData(int size, S_DATA* data){
    int i;
    int f = 1;
    for (i = 0; i < size ; i++) {
        (data + i)->index = g_list[i].index;
        strcpy((data + i)->name, g_list[i].name);
        strcpy((data + i)->mail, g_list[i].mail);
        strcpy((data + i)->memo, g_list[i].memo);
        f = 0;
    }
    if (f == 0) {
        return 0;
    } else {
        return 1;
    }
}

/* 削除 */
int deleteData(int index){
    int i;
    index = index - 1;
    for (i = 0; i == index; i++) {
        g_list[index].index = 0;
        strcpy(g_list[index].name, "");
        strcpy(g_list[index].mail, "");
        strcpy(g_list[index].memo, "");
        return 0;
    }
    return 1;
}
