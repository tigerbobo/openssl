#pragma once

#include "openssl\des.h"

#define TYPE_DEC	0
#define TYPE_ENC	1

#define MODE_ECB	0
#define MODE_CBC	1
#define MODE_CFB	2

class COpenSSL
{
public:
	COpenSSL();
	~COpenSSL();
public:
	static void openssl_des3(const unsigned char *input, unsigned int length_input, int type, int mode, unsigned char key[24], unsigned char ivec[8], unsigned char **output, unsigned int &length_output);
};

