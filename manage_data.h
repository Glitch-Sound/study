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

#define NUMBER  10  /* 登録数 */
#define LENGTH  16  /* 文字数 */

// todo:構造体を宣言
typedef struct {
    int index;          /* インデックス */
    char name[LENGTH];  /* 名前 */
    char mail[LENGTH];  /* メールアドレス */
    char memo[LENGTH];  /* メモ */
} list;

#endif /* manage_data_h */
