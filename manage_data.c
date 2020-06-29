//
//  manage_data.c
//  Contacts
//
//  Created by Eriko Kawaguchi on 2020/05/29.
//  Copyright © 2020 Eriko Kawaguchi. All rights reserved.
//

#include <string.h>
#include <stdlib.h>
#include "manage_data.h"

static S_DATA g_list[D_NUMBER];
static S_DATA* g_p_record = NULL;
static int g_count = 0;

/* 追加 */
int addData(E_SAVE dest, S_DATA person){
    int i;
    int size = D_NUMBER;
    int ret = D_NO_CAPACITY;
    S_DATA* data = NULL;
    
    switch (dest) {
        case SAVE_HEAP:
            size = g_count;
            data = g_p_record;
            break;
        default:
            data = g_list;
            break;
        }
    for (i = 0; i < size; i++) {
        if (data[i].index != 0) {
            continue;
        }
        data[i].index = i + 1;
        strcpy(data[i].name, person.name);
        strcpy(data[i].mail, person.mail);
        strcpy(data[i].memo, person.memo);
        ret = D_SUCCESS;
        break;
    }
    return ret;
}

/* 表示 */
int getData(E_SAVE dest, S_DATA* viewdata){
    int i;
    int size = D_NUMBER;
    int ret = D_SUCCESS;
    S_DATA* data = NULL;
    
    if (viewdata == NULL) {
        return D_NULL_CHECK;
    }
    switch (dest) {
        case SAVE_HEAP:
            data = g_p_record;
            size = g_count;
            break;
            
        default:
            data = g_list;
            break;
    }
    for (i = 0; i < size; i++) {
        viewdata[i] = data[i];
    }
    return ret;
}

/* 削除 */
int deleteData(E_SAVE dest, int index){
    int ret = D_SUCCESS;
    S_DATA* data = NULL;

    switch (dest) {
        case SAVE_HEAP:
            data = g_p_record;
            break;
            
        default:
            data = g_list;
            break;
    }

    for (int i = 0; i < index; i++) {
        if (data[i].index != index) {
            ret = D_NO_DATA;
            continue;
        }
        data[i].index = 0;
        strcpy(data[i].name, "");
        strcpy(data[i].mail, "");
        strcpy(data[i].memo, "");
        ret = D_SUCCESS;
    }
    return ret;
}

/* 動的メモリ確保 */
int secureMemory(){
    int ret = D_SUCCESS;
    S_DATA* p_tmp = NULL;

    if (g_p_record == NULL) {
        // g_p_recordがnull 10件分の領域を確保、件数更新
        g_p_record = malloc(sizeof(S_DATA) * D_NUMBER);
        g_count = D_NUMBER;
    } else {
        // g_countが10件→20件分の領域を確保、件数更新
        p_tmp = realloc(g_p_record, sizeof(S_DATA) * (D_NUMBER * 2));
        g_count = D_NUMBER * 2;
        g_p_record = p_tmp;
    }
    if (!g_p_record) {
        ret = D_ERROR_MALLOC;
    }
    return ret;
}


