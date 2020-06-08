//
//  manage_data.h
//  Contacts
//
//  Created by Eriko Nagano on 2020/05/29.
//  Copyright © 2020 Eriko Kawaguchi. All rights reserved.
//

#ifndef manage_data_h
#define manage_data_h

#include <stdio.h>

#define D_NUMBER  10  /* 登録数 */
#define D_LENGTH  16  /* 文字数 */

// done:構造体を宣言
typedef struct {
    int index;          /* インデックス */
    char name[D_LENGTH];  /* 名前 */
    char mail[D_LENGTH];  /* メールアドレス */
    char memo[D_LENGTH];  /* メモ */
} list;

#endif /* manage_data_h */
