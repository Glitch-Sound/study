//
//  manage_data.h
//  Contacts
//
//  Created by Eriko Kawaguchi on 2020/05/29.
//  Copyright © 2020 Eriko Kawaguchi. All rights reserved.
//

#ifndef manage_data_h
#define manage_data_h

#define D_NUMBER (10)      /* 登録数 */
#define D_LENGTH (16 + 1)  /* 文字数 */
#define D_SUCCESS (0)
#define D_NO_CAPACITY (1)
#define D_NULL_CHECK (2)
#define D_ERROR_SIZE (3)
#define D_ERROR_MALLOC (4)
#define D_NO_DATA (5)

typedef struct {
    int index;          /* インデックス */
    char name[D_LENGTH];  /* 名前 */
    char mail[D_LENGTH];  /* メールアドレス */
    char memo[D_LENGTH];  /* メモ */
} S_DATA;

typedef enum {
    SAVE_STATIC,
    SAVE_HEAP,
    SAVE_FILE,
    SAVE_DB
} E_SAVE;

extern int initData(void);
extern int addData(E_SAVE dest, S_DATA data);
extern int getData(E_SAVE dest, S_DATA* data);
extern int deleteData(E_SAVE dest, int index);
extern int checkMemory(void);

#endif /* manage_data_h */
