/*
 ***************************************************************************
 * This software/firmware and related documentation ("MediaTek Software") 
 * are protected under relevant copyright laws. The information contained 
 * herein is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek Inc. and/or its licensors, 
 * any reproduction, modification, use or disclosure of MediaTek Software, and 
 * information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C)2014. All rights reserved.
 ***************************************************************************
 */


#ifndef SHA1_H
#define SHA1_H

#define A_SHA_DIGEST_LEN 20

typedef struct 
{
  unsigned long H[5];
  unsigned long W[80];
  int lenW;
  unsigned long sizeHi,sizeLo;
} A_SHA_CTX;

void A_SHAInit(A_SHA_CTX *ctx);
void A_SHAUpdate(A_SHA_CTX *ctx, unsigned char *dataIn, int len);
void A_SHAFinal(A_SHA_CTX *ctx, unsigned char hashout[20]);

#endif /* SHA1_H */
