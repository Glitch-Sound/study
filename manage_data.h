//
//  manage_data.h
//  Contacts
//
//  Created by Eriko Kawaguchi on 2020/05/29.
//  Copyright © 2020 Eriko Kawaguchi. All rights reserved.
//

#ifndef manage_data_h
#define manage_data_h

#define D_NUMBER  10  /* 登録数 */
#define D_LENGTH  16  /* 文字数 */

typedef struct {
    int index;          /* インデックス */
    char name[D_LENGTH];  /* 名前 */
    char mail[D_LENGTH];  /* メールアドレス */
    char memo[D_LENGTH];  /* メモ */
} S_DATA;

extern int addData(S_DATA data);
extern int getData(int size, S_DATA* data);
extern int deleteData(int index);

#endif /* manage_data_h */
